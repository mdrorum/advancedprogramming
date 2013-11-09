#ifndef _BOT_H_INCLUDED_
#define _BOT_H_INCLUDED_

#include <vector>

class bots;

enum direction { NOTHING, N, NE, E, SE, S, SW, W, NW };

/**
 * Non-const methods are private and container class is declared as a friend.
 * This enforces a very strict encapsulation pattern.
 */
class bot
{
    public:

        static const int x_offset[];
        static const int y_offset[];


        typedef unsigned short status;

        typedef unsigned int team_id ;

        typedef unsigned int field_size ;

        typedef std::pair<field_size, field_size> position ;

        bot (team_id id, const position & pos);

        static position new_position(const position &pos, const direction& dir) {
            return {pos.first + x_offset[dir], pos.first + y_offset[dir]};
        }

        virtual ~bot ();

        status get_energy() const {
            return _energy;
        }

        inline status get_attack() const {
            return _attack;
        };

        inline status get_defense() const {
            return _defense;
        };

        inline team_id get_team() const {
            return _team;
        }

        inline status get_experience() const {
            return _experience;
        }

        inline const position & get_position() const {
            return _position;
        }

        inline const direction & get_next_direction() const {
            return _next_direction;
        }

        inline status get_kills() const {
            return _kills;
        }

        inline void try_to_do(const direction & dir) {
            _next_direction = dir;
        }

    private:

        friend class bots;

        status _attack;
        status _defense;
        status _kills;
        //status _base_attack;
        //status _base_defense;
        status _experience;
        status _energy;
        team_id _team;
        position _position;
        direction _next_direction;

        void kills_bot(const bot & victim);

        /**
         * this enforces modification of the data structure through container class
         */
        //inline void move(const direction & dir) {
            //_next_direction = dir;
        //}
};


#endif
