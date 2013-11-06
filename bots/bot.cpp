#include "bot.h"

// add a move constructor
bot::bot(team_id team, const position & pos):_position(pos), _team(team),
_base_attack(2), _base_defense(1), _experience(0), _energy(100)
{
}

bot::~bot()
{
}

bot::status bot::get_energy() constconst
{
}

bot::status bot::get_attack() constconst
{
}

bot::status bot::get_defense() constconst
{
}

bot::status bot::get_experience() constconst
{
}
