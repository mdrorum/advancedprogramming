#include "bot.h"

const int bot::x_offset[] = { 0, 0, 1, 1, 1, 0, -1, -1, -1 };
const int bot::y_offset[] = { 0, 1, 1, 0, -1, -1, -1, 0, 1 };

bot::bot(team_id team, const position & pos):_position(pos), _team(team),
_attack(2), _defense(1), _experience(0), _energy(100), _kills(0)
{
}

bot::~bot()
{
}

void bot::kills_bot(const bot & victim) {
    _experience += victim.get_experience() + 1;
    _kills++;
    if(_kills % 3 == 0) {
        _energy = 100;
    }
    _attack = 3 * _experience;
    _defense = 2 * _experience;
}

