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

int Contestant::getAttackDamage(int attack_index) {
	Attacks atk = all_attacks->at(attack_index);
	string atk_stat = ATTACK_LIST[int(atk)].attacking_stat;
	return getStat(atk_stat);
}

void Contestant::applyAttackDamage(int raw_damage) {
	float defense = getStat("stamina");
	float final_damage = raw_damage - defense;
	if (final_damage < 1) {
		final_damage = 1;
	}
	current_health -= final_damage;
}
