#ifndef _BOTS_H_INCLUDED_
#define _BOTS_H_INCLUDED_

#include <map>
#include <iostream>
#include <random>
#include <memory>

#include "bot.h"

enum direction { N, NE, E, SE, S, SW, W, NW };

class too_many_bots : std::exception {};

class bots
{

public:

    typedef unsigned int team_id ;

    typedef unsigned int field_size ;

    typedef std::pair<field_size, field_size> position ;

private:

    typedef std::map<position, std::shared_ptr<bot> > team;

    /**
     * beware, there is no emptiness checking!
     */
    inline void create_bot(position position, team_id team, bot::bot_id id) {
        mMap[team][position] = std::shared_ptr<bot>(new bot(id));
    }

    field_size mWidth;
    field_size mHeight;
    std::map <team_id, team> mMap;

public:

    bots (field_size width, field_size height);

    virtual ~bots ();

    void generate(size_t number_teams, size_t bots_per_team) throw (too_many_bots);

    std::shared_ptr<bot> find_at(field_size x, field_size y) const;

    bool empty(field_size x, field_size y) const;

    bool can_move(bot::bot_id bot, direction dir) const;

    void move(bot::bot_id bot, direction dir);

    void attack(bot::bot_id bot, direction dir);

    void step(int time);

    void for_each_bot(std::function<void(team_id team, const position& pos, std::shared_ptr<bot> const)> fun);

};


#endif
