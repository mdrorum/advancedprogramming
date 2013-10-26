#include "bots.h"


//bots::bots (const bots & b){}

bots::bots (field_size width, field_size height) : mWidth(width), mHeight(height)
{
}

void bots::generate(size_t number_teams, size_t bots_per_team) throw (too_many_bots) {

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
            } while(!empty(x, y));

            create_bot({x, y}, i, id++);

        }

    }
}

bots::~bots () {}


std::shared_ptr<bot> bots::find_at(field_size x, field_size y) const {

    for(auto kv : mMap) {
        auto team = kv.second;
        auto bot_it = team.find({x, y});
        if(bot_it != team.end()) {
            return (*bot_it).second;
        }

    }
    return nullptr;
}

bool bots::empty(field_size x, field_size y) const {
    return find_at(x, y) == nullptr;
}

bool bots::can_move(bot::bot_id bot, direction dir) const {}

void bots::move(bot::bot_id bot, direction dir) {}

void bots::attack(bot::bot_id bot, direction dir) {}

void bots::step(int time) {
    //std::cout << time << std::endl
}


    // move!
    //inline const team & get_team(team_id the_team) const {
        //return mMap.at(the_team); // at is const, [] isn't

    //}


void bots::for_each_bot(std::function<void(team_id team, const position& pos, std::shared_ptr<bot> const)> fun) {
    for(auto kv : mMap) {
        for(auto b : kv.second){
            fun(kv.first, b.first, b.second);
        }
    }
}

