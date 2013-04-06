/* *************** *
 * Game.h          *
 * Author: natalia * 
 * *************** */

#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include "Utils.h"

using namespace std;

class Game {

  class SingleRule {
    unsigned int positive;
    unsigned int negative;
    unsigned int value;
  public:
    SingleRule();
    SingleRule(unsigned int _positive, unsigned int _negative, double _value);
    SingleRule(unsigned int used_positive);
    bool being_satisfied(unsigned int coalition) const; // CHANGE!
    double get_value() const;
  };

  int players;
  vector < SingleRule > rules;
public:
  Game(int _players);
  int number_of_players() const;
  double value_this_vs_rest(unsigned int coalition) const;
  double value_grand_coalition() const;
};

#endif /* GAME_H_ */
