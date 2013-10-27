#ifndef _BOT_H_INCLUDED_
#define _BOT_H_INCLUDED_

#include <vector>

class bots;

enum direction { N, NE, E, SE, S, SW, W, NW };


// union or "either" can be used here
class action {
    public:
        enum kind { MOVE, ATTACK, NOTHING };

        inline kind get_kind() const {
            return _kind;
        }

        inline direction get_direction() const {
            return _direction;
        }

        action() : _kind(NOTHING), _direction(N) {}

        inline void attack(const direction & dir) {
            _kind = ATTACK;
            set_direction(dir);
        }

        inline void move(const direction & dir) {
            _kind = MOVE;
            set_direction(dir);
        }

        inline void set_direction(const direction & dir) {
            _direction = dir;
        }

    private:
        kind _kind;
        direction _direction;

};

class bot
{
    public:

        typedef unsigned short status;

        typedef unsigned int team_id ;

        typedef unsigned int field_size ;

        typedef std::pair<field_size, field_size> position ;

        bot (team_id id, const position & pos);

        virtual ~bot ();

        status get_energy() const;

        inline status get_base_attack() const {
            return _base_attack;
        };

        status get_attack() const;

        inline status get_base_defense() const {
            return _base_defense;
        };

        inline team_id get_team() const {
            return _team;
        }

        status get_defense() const;

        status get_experience() const;

        inline const position & get_position() const {
            return _position;
        }

        inline const action & get_next_action() const {
            return _next_action;
        }

    private:

        friend class bots;

        status _base_attack;
        status _base_defense;
        status _experience;
        status _energy;
        team_id _team;
        position _position;
        action _next_action;


        inline void attack(const direction & dir) {
            _next_action.attack(dir);
        }

        inline void move(const direction & dir) {
            _next_action.move(dir);
        }
};

#endif
