#ifndef _BOTS_H_INCLUDED_
#define _BOTS_H_INCLUDED_

#include <map>
#include <iostream>
#include <random>
#include <memory>

enum direction { N, NE, E, SE, S, SW, W, NW };


class too_many_bots : std::exception {

};

class bot
{
public:

    typedef unsigned short status;

    typedef unsigned int bot_id ;

    bot (bot_id id) : mId(id), mBaseAttack(2), mBaseDefense(1), mExperience(0), mEnergy(100) {};
    virtual ~bot () {};

    status get_energy() const {};

    inline status get_base_attack() const {
        return mBaseDefense;
    };

    status get_attack() const {};

    inline status get_base_defense() const {
        return mBaseDefense;
    };

    status get_defense() const {};

    status get_experience() const {};

private:
    status mBaseAttack;
    status mBaseDefense;
    status mExperience;
    status mEnergy;
    bot_id mId;
    
};

class bots
{

public:
    typedef unsigned int team_id ;

    typedef unsigned int field_size ;
private:

    typedef std::map<std::pair<field_size, field_size>, std::shared_ptr<bot> > team;

public:

    bots (const bots & b){};

    bots (field_size width, field_size height) : mWidth(width), mHeight(height)
    {
    };

    void generate(size_t number_teams, size_t bots_per_team) throw (too_many_bots) {

        std::random_device rd;
        std::mt19937 gen(rd());
        std::mt19937 gen2(rd());
        std::uniform_int_distribution <field_size> random_width(0, mWidth - 1);
        std::uniform_int_distribution <field_size> random_height(0, mHeight - 1);

        if(number_teams * bots_per_team > mWidth * mHeight) {
            throw new too_many_bots;
        }

        bot::bot_id id = 0;
        for (size_t i = 0; i < number_teams; ++i)
        {
            
            for(size_t j = 0; j < bots_per_team; j++) {

                field_size x;
                field_size y;
                do {
                    x = random_width(gen);
                    y = random_height(gen2);
                    //std::cout << x << ", " << y << std::endl;
                } while(!empty(x, y));

                create_bot(x, y, i, id++);

            }
            
        }
    }

    virtual ~bots () {};


    std::shared_ptr<bot> find_at(field_size x, field_size y) const {

        for(auto kv : mMap) {
            auto team = kv.second;
            auto bot_it = team.find({x, y});
            if(bot_it != team.end()) {
                return (*bot_it).second;
            }

        }
        return nullptr;
    }

    bool empty(field_size x, field_size y) const {
        return find_at(x, y) == nullptr;
    }

    bool can_move(bot::bot_id bot, direction dir) const {}

    void move(bot::bot_id bot, direction dir) {}

    void attack(bot::bot_id bot, direction dir) {}

    void step(int time) {
        std::cout << time << std::endl;
    };


    // move!
    inline const team & get_team(team_id the_team) const {
        return mMap[the_team];

    };

private:


    //void 

    /**
     * beware, there are no emptiness checking!
     */
    inline void create_bot(field_size x, field_size y, team_id team, bot::bot_id id) {
        mMap[team][{x, y}] = std::shared_ptr<bot>(new bot(id));
    }

    field_size mWidth;
    field_size mHeight;
    std::map <team_id, team> mMap;

};


#endif
