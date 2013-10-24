#ifndef _BOTS_H_INCLUDED_
#define _BOTS_H_INCLUDED_

#include <map>
#include <iostream>
#include <random>
//#include <algorithm>
//#include <functional>
//#include <iterator>

enum direction { N, NE, E, SE, S, SW, W, NW };

class Bot
{
public:

    typedef unsigned short status;

    Bot () {};
    virtual ~Bot () {};

    status GetEnergy() const {};

    status GetAttack() const {};

    status GetDefense() const {};

    status GetExperience() const {};

private:
    
};

class Bots
{
public:
    typedef unsigned int team_id ;

    typedef unsigned int bot_id ;

    typedef unsigned int field_size ;

    Bots (field_size width, field_size height) : mWidth(width), mHeight(height)
    {};

    void Generate(size_t number_teams, size_t bots_per_team) {

        random_device rd;
        std::mt19937 gen(rd());
        std::mt19937 gen2(rd());
        uniform_int_distribution <usigned int> random_width(0, mWidth - 1);
        uniform_int_distribution <usigned int> random_height(0, mHeight - 1);

        if(number_teams * bots_per_team > mWidth * mHeight) {
            throw something;
        }

        bot_id id = 0;
        for (size_t i = 0; i < number_teams; ++i)
        {
            
            for(size_t j = 0; j < bots_per_team; j++) {

                field_size x;
                field_size y;
                do {
                    field_size x = random_width(gen);
                    field_size y = random_height(gen2);
                } while(Empty(x, y));

                CreateBot(x, y, i, id++);

            }
            
        }
    }

    virtual ~Bots () {};

    bool Empty(field_size x, field_size y) {}

    bool CanMove(bot_id bot, direction dir) const {}

    void Move(bot_id bot, direction dir) {}

    void Attack(bot_id bot, direction dir) {}

    void Step(int time) {
        std::cout << time << std::endl;
    };

    void CreateBot(field_size x, field_size y, team_id team, bot_id bot) {}

    // move!
    const std::map<bot_id, Bot> & GetBots(team_id team) const {};

private:
    field_size mWidth;
    field_size mHeight;
    Bot mMap[][];
};


#endif
