#include "bot.h"

bot::bot (bot_id id) : mId(id), mBaseAttack(2), mBaseDefense(1), mExperience(0), mEnergy(100) {}

bot::~bot () {}

bot::status bot::get_energy() const {}

bot::status bot::get_attack() const {}

bot::status bot::get_defense() const {}

bot::status bot::get_experience() const {}

