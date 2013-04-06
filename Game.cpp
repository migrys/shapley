/* *************** *
 * Game.cpp        *
 * Author: natalia * 
 * *************** */

#include "Game.h"
#include <iostream>

Game::SingleRule::SingleRule() {};

Game::SingleRule::SingleRule(unsigned int _positive,
		                     unsigned int _negative, double _value) :
		          positive(_positive), negative(_negative), value(_value) {};

Game::SingleRule::SingleRule(unsigned int used_positive) {};

bool Game::SingleRule::being_satisfied(unsigned int coalition) const {
  return Utils::players_in_coalition(positive, coalition);
}

double Game::SingleRule::get_value() const {
  return value;
}

Game::Game(int _players) : players(_players) {
  rules.resize(6);
  rules[0] = SingleRule(3, 0, 5); // 1 i 2 -> 5
  rules[1] = SingleRule(1, 0, 4); // 1 -> 4
  rules[2] = SingleRule(4, 0, 1); // 3 -> 1
  rules[3] = SingleRule(10, 0, 3); // 2 i 4 -> 3
  rules[4] = SingleRule(11, 0, 2); // 1, 2 i 4 -> 2
  rules[5] = SingleRule(12, 0, 1); // 3 i 4 -> 1
}

int Game::number_of_players() const { return players; }

double Game::value_this_vs_rest(unsigned int coalition) const {
  double value = 0.0;

  for (int i = 0; i < (int) rules.size(); i++)
	if (rules[i].being_satisfied(coalition))
	  value += rules[i].get_value();
  return value;
};

double Game::value_grand_coalition() const { return 0.0; };
