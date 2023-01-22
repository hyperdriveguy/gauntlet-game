#include "contestant.h"

float Contestant::getStat(string stat) {
	return (level - 1) * 0.2 + base_stats[stat];
}

bool Contestant::isNormalStatus() {
	return status != StatusEffect::Normal;
}

string Contestant::getStatusEffect() {
	return StatusEffectString[int(status)];
}

int Contestant::getCurrentHealth() {
	return current_health;
}
