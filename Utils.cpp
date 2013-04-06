/* *************** *
 * Utils.cpp       *
 * Author: natalia * 
 * *************** */

#include "Utils.h"

vector < int > Utils::power = Utils::compute_power();
vector < int > Utils::factorial = Utils::compute_factorial();
vector < vector < double > > Utils::shapley_coef = Utils::compute_coef();

vector < int > Utils::compute_power() {
  vector < int > result;

  result.resize(max_players + 1, 1);
  int pow = 1;
  for (int i = 1; i <= max_players; i++) {
    pow *= 2;
    result[i] = pow;
  }
  return result;
}

vector < int > Utils::compute_factorial() {
  vector < int > result;

  result.resize(max_players + 1, 1);
  int fact = 1;
  for (int i = 1; i <= max_players; i++) {
    fact *= i;
    result[i] = fact;
  }
  return result;
}

vector < vector < double > > Utils::compute_coef() {
  vector < vector < double > > result;

  result.resize(max_players + 1);
  for (int i = 0; i < max_players + 1; i++)
    result[i].resize(max_players + 1, 0.0);
  for (int players = 1; players <= max_players; players++)
    for (int size = 1; size <= players; size++) {
	  result[size][players] = (double) factorial[size-1] * factorial[players - size];
	  result[size][players] /= (double) factorial[players];
	}
  return result;
}


double Utils::shapley_coefficients(int size, int players) {
  return shapley_coef[size][players];
}

int Utils::power_of_two(int exponent) {
  return power[exponent];
}

/* @return number of ones in binary representation of integer 'coalition' */
/* in line with
 * http://stackoverflow.com/questions/109023/how-to-count-the-number-of-set-bits-in-a-32-bit-integer */
int Utils::size_of_coalition(unsigned int coalition) {
  unsigned int size = coalition = coalition - ((coalition >> 1) & 0x55555555);
  size = (size & 0x33333333) + ((size >> 2) & 0x33333333);
  size = (((size + (size >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;

  return (int) size;
}

/* @return true if player is in coalition (i-th number in binary representation is 1) */
bool Utils::player_in_coalition(int player, unsigned int coalition) {
  player = power[player];
  return !((coalition | player) ^ coalition);
}

bool Utils::players_in_coalition(unsigned int players, unsigned int coalition) {
  return !((coalition | players) ^ coalition);
}

