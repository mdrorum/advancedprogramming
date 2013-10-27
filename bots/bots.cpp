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

            // reasonably efficient for sparse distributions
            std::pair<int, int> position;
            do {
                position.first = random_width(gen);
                position.second = random_height(gen2);
            } while(!empty(position));

            create_bot(position, i);

        }

    }
}

bots::~bots () {}


const bot * bots::find_at(const bot::position & pos) const {
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

// FIXME: try not to copy here!!
bool bots::can_move(const bot & the_bot, const direction & dir) const {
    bot copy_bot(the_bot);
    copy_bot.move(dir);
    return true;
}

bool bots::can_attack(const bot & the_bot, const direction & dir) const {
    return true;
}

// replace switch by something w/out comparisons!
void bots::perform_action(bot & the_bot) {
    int x_offset[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int y_offset[] = {1, 1, 0, -1, -1, -1, 0, 1};
    const action & action = the_bot.get_next_action();
    direction dir = action.get_direction();
    bot::position & pos = the_bot._position;
    switch(action.get_kind()) {
        case action::MOVE:
            pos.first += x_offset[dir];
            pos.second += y_offset[dir];
            break;
        case action::ATTACK:
            break;
        case action::NOTHING;
            break;
    }
}

void bots::move(bot & the_bot, const direction & dir) {
    the_bot.move(dir);
}

void bots::attack(bot & the_bot, const direction & dir) {
    the_bot.attack(dir);
}

void bots::step(int time) {
    static int acc_time = 0;
    acc_time += time;
    if(acc_time > 1000) {
        for_each_bot([this] ( bot & the_bot ) {
                perform_action(the_bot);
        });
        acc_time = 0;
    }

}


