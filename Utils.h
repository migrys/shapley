/* *************** *
 * Utils.h    *
 * Author: natalia * 
 * *************** */

#ifndef UTILS_H_
#define UTILS_H_

#include <vector>

using namespace std;

class Utils {
  static const int max_players = 20;
  static vector < int > power;
  static vector < int > factorial;
  static vector < vector < double > > shapley_coef;
  static vector < int > compute_power();
  static vector < int > compute_factorial();
  static vector < vector < double > > compute_coef();
public:
  Utils() {};

  /* @return (size!) * (N-size-1)! / N! */
  static double shapley_coefficients(int size, int players);

  static int power_of_two(int exponent);

  static int size_of_coalition(unsigned int coalition);

  static bool player_in_coalition(int player, unsigned int coalition);
  static bool players_in_coalition(unsigned int players, unsigned int coalition);
};

#endif /* UTILS_H_ */
