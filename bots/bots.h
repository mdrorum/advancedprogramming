#ifndef _BOTS_H_INCLUDED_
#define _BOTS_H_INCLUDED_

#include <map>
#include <iostream>
#include <random>
#include <memory>

#include "bot.h"

enum direction { N, NE, E, SE, S, SW, W, NW };


class bots
{


private:

    //typedef std::map<position, std::shared_ptr<bot> > field_bots;
    //typedef std::vector <std::shared_ptr<bot> > field_bots;
    typedef std::vector <bot> field_bots;

    /**
     * beware, there is no emptiness checking!
     */
    inline void create_bot(bot::position position, bot::team_id team) {
        //mMap[team][position] = std::shared_ptr<bot>(new bot(team));
        //_bots[team][position] = std::shared_ptr<bot>(new bot(team));
        //_bots[position] = std::shared_ptr<bot>(new bot(team));
        bot new_bot(team, position);
        _bots.push_back(std::move(new_bot));
    }
    //inline void create_bot(position position, team_id team, bot::bot_id id) {
        //mMap[team][position] = std::shared_ptr<bot>(new bot(id));
    //}

    bot::field_size _width;
    bot::field_size _height;
    field_bots _bots;

public:

    class too_many_bots : std::exception {};

    bots (bot::field_size width, bot::field_size height);

    virtual ~bots ();

    void generate(size_t number_teams, size_t bots_per_team) throw (too_many_bots);

    const bot * const find_at(const bot::position & p) const;

    bool empty(const bot::position & p) const;

    bool can_move(const bot & the_bot, const direction & dir) const;

    void move(bot & the_bot, const direction & dir);

    void attack(const bot & the_bot, const direction & dir);

    void step(int time);

    void for_each_bot(std::function<void(const bot & the_bot)> fun);

};


#endif
