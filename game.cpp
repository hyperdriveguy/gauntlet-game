/* The Gauntlet - A small battle gauntlet game to demonstrate C++ knowledge.
(c) 2023 Carson Bush - MIT License */

#include <iostream>
#include <string>

enum class StatusEffect {
    Normal,
    Poisoned,
    Burned,
    Frozen,
    Paralyzed,
    Andrenaline,
    Dazed
};

struct BaseStats {
    int health;
    int attack;
    int defense;
    int sp_attack;
    int sp_defense;
};

class Contestant {
    public:
        int level;
        BaseStats base_stats;
        StatusEffect status;
        // Default constructor so it doesn't completely break
        Contestant() : level(1), base_stats({1, 1, 1, 1, 1}), status(StatusEffect::Normal) {}
        // Constructor with passed in values
        Contestant(int lev, BaseStats b_stats) :
            level(lev), base_stats(b_stats),
            status(StatusEffect::Normal) {

        }
};


int main() {
    return 0;
}
