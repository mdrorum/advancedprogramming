#include "bots.h"
#include <algorithm>

bots::bots(bot::field_size width, bot::field_size height):_width(width),
    _height(height)
{
}

void bots::generate(size_t number_teams,
        size_t bots_per_team) throw(too_many_bots)
{

    std::random_device rd;
    std::mt19937 gen(rd());
    std::mt19937 gen2(rd());
    std::uniform_int_distribution < bot::field_size > random_width(0, _width - 1);
    std::uniform_int_distribution < bot::field_size > random_height(0, _height - 1);

    if (number_teams * bots_per_team > _width * _height) {
        throw new too_many_bots;
    }

    // reasonably efficient for sparse distributions
    // a las vegas algorithm!!
    for (size_t i = 0; i < number_teams; ++i) {

        for (size_t j = 0; j < bots_per_team; j++) {

            std::pair < int, int >position;
            do {
                position.first = random_width(gen);
                position.second = random_height(gen2);
            } while (!empty(position));

            create_bot(position, i);

        }

    }
}

bots::~bots()
{
}


bot *bots::find_at(const bot::position & pos)
{
    auto it = std::find_if(_bots.begin(), _bots.end(), 
            [&pos] (bot & the_bot) { 
                the_bot.get_position() == pos; 
            });


    if (it != _bots.end()) {
        return &(*it);
    } else {
        return nullptr;
    }

}

bool bots::empty(const bot::position & pos)
{
    return find_at(pos) == nullptr;
}

// TODO check whether the other bot is moving (you can move if the other guy is moving
bool bots::can_move(const bot & the_bot, const direction & dir)
{
    //auto & pos = the_bot.get_position();
    return !empty(bot::new_position(the_bot.get_position(), dir));
}

// replace switch by something w/out comparisons!
void bots::perform_action(bot & the_bot)
{

    bot::position & pos = the_bot._position;
    const direction & dir = the_bot.get_next_direction();

    // TODO check attacks and act!
    if (bot * victim = attacks(the_bot, dir)) {
        victim->_energy = std::min(0, 
                victim->_energy - std::min(0, 
                    the_bot.get_attack () - victim-> get_defense ()));

    } else if (can_move(the_bot, dir)) {

        pos = bot::new_position(pos, dir);
        //pos.first += bot::x_offset[dir];
        //pos.second += bot::y_offset[dir];
    }
}


bot *bots::attacks(const bot & the_bot, const direction & dir)
{
    return find_at(bot::new_position(the_bot.get_position(), dir));
}

// FIXME test implementation, doesn't have any sense at all
void bots::step(int time)
{
    static int acc_time = 0;
    acc_time += time;
    if (acc_time > 1000) {
        // acting and dying in the same loop changes the semantics
        // currently, a bot can be dead but kill and move during the current
        // turn
        for_each_bot([this] (bot & the_bot) {
                perform_action(the_bot);}
                );

        // remove dead bots
        for (auto it = _bots.begin(); it != _bots.end(); it++) {
            if ((*it).get_energy() <= 0) {
                _bots.erase(it);
            }
        }

        acc_time = 0;
    }

}
