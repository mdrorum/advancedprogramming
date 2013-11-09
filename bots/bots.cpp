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


const bot *bots::find_at(const bot::position & pos) const
{
    auto it = std::find_if(_bots.begin(), _bots.end(), 
            [&pos] (const bot & the_bot) { 
                return the_bot.get_position() == pos; 
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

    //// TODO check attacks and act!
    if (const bot * victim_bot = attacks(the_bot, dir)) {
        // hack to keep a 'const' api
        auto victim = find_if(_bots.begin(), _bots.end(), [&victim_bot](bot & the_bot) { 
                return the_bot.get_position() == victim_bot->get_position();
            });
        (*victim)._energy = std::min(0, 
                (*victim)._energy - std::min(0, 
                    the_bot.get_attack () - (*victim).get_defense()));
    } 
    else if (can_move(the_bot, dir)) {
        the_bot._position = bot::new_position(pos, dir);
    }
}


const bot *bots::attacks(const bot & the_bot, const direction & dir) const
{
    return find_at(bot::new_position(the_bot.get_position(), dir));
}

// FIXME test implementation, doesn't have any sense at all
void bots::step(int time)
{
    // acting and dying in the same loop changes the semantics
    // currently, a bot can be dead but kill and move during the current
    // turn
    for_each_bot([this] (bot & the_bot) { perform_action(the_bot); });

    // remove dead bots
    for (auto it = _bots.begin(); it != _bots.end(); it++) {
        if ((*it).get_energy() <= 0) {
            _bots.erase(it);
        }
    }
}

std::map <bot::team_id, size_t> bots::bot_count() const {
    std::map <bot::team_id, size_t> result;
    for_each_bot([&result] (const bot & the_bot)  {
            const auto & t = the_bot.get_team();

            if(result.count(t) == 0) {
                result[t] = 1;
            }
            else {
                result[t] += 1;
            }
        });

    // move constructor of map is called!
    return std::move(result);
}

bool bots::game_over() const {
    return bot_count().size() < 2;
}

