#include "bots.h"
#include <algorithm>

bots::bots (bot::field_size width, bot::field_size height) : _width(width), _height(height)
{
}

void bots::generate(size_t number_teams, size_t bots_per_team) throw (too_many_bots) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::mt19937 gen2(rd());
    std::uniform_int_distribution <bot::field_size> random_width(0, _width - 1);
    std::uniform_int_distribution <bot::field_size> random_height(0, _height - 1);

    if(number_teams * bots_per_team > _width * _height) {
        throw new too_many_bots;
    }

    for (size_t i = 0; i < number_teams; ++i)
    {

        for(size_t j = 0; j < bots_per_team; j++) {

            bot::field_size x;
            bot::field_size y;
            do {
                x = random_width(gen);
                y = random_height(gen2);
            } while(!empty({x, y}));

            create_bot({x, y}, i);

        }

    }
}

bots::~bots () {}


const bot * const bots::find_at(const bot::position & pos) const {
    auto it = std::find_if(_bots.begin(), _bots.end(), 
            [&pos](const bot & bot){
            return bot.get_position() == pos;
            });

    if(it != _bots.end()) {
        return &(*it);
    }
    else {
        return nullptr;
    }

}

bool bots::empty(const bot::position & pos) const {
    return find_at(pos) == nullptr;
}

bool bots::can_move(const bot & the_bot, const direction & dir) const {
    return true;
}

//void bots::move(const bot::position & pos, const direction & dir) {

//// this isn't a good idea
//// redefine it all
//_bots.erase(pos)


//}

void bots::attack(const bot & the_bot, const direction & dir) {}

void bots::step(int time) {
    static int acc_time = 0;
    acc_time += time;
    if(acc_time % 1000 == 0) {
        for_each_bot([this] ( const bot & the_bot ) {
                if(can_move(the_bot, S)) {
                    move(the_bot, S);
                }
                });
        acc_time = 0;
    }

}


// move!
//inline const team & get_team(team_id the_team) const {
//return mMap.at(the_team); // at is const, [] isn't

//}


//void bots::for_each_bot(std::function<void(const bot::position& pos, std::shared_ptr<bot> const)> fun) {
void bots::for_each_bot(std::function<void(const bot& the_bot)> fun) {
    for(auto bot : _bots) {
        fun(bot);
    }
}

