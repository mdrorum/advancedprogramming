#ifndef _BOT_H_INCLUDED_
#define _BOT_H_INCLUDED_

class bot
{
public:

    typedef unsigned short status;

    typedef unsigned int bot_id ;

    bot (bot_id id);

    virtual ~bot ();

    status get_energy() const;

    inline status get_base_attack() const {
        return mBaseDefense;
    };

    status get_attack() const;

    inline status get_base_defense() const {
        return mBaseDefense;
    };

    status get_defense() const;

    status get_experience() const;

private:
    status mBaseAttack;
    status mBaseDefense;
    status mExperience;
    status mEnergy;
    bot_id mId;
    
};

#endif
