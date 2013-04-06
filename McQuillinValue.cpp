/* *************** *
 * McQuillinValue.cpp    *
 * Author: natalia * 
 * *************** */

#include "McQuillinValue.h"

vector <double> McQuillinValue::compute_values(Game const& g) {
  int players = g.number_of_players(), size;
  double coef;

  values.resize(players, 0.0);
  for (int player = 0; player < players; player++) {
	unsigned int coalition_max = (unsigned int) Utils::power_of_two(players) - 1;
	for (unsigned int coalition = 1; coalition <= coalition_max; coalition++) {
	  if (coalition == Utils::power_of_two(player)) continue;
	  size = Utils::size_of_coalition(coalition);
	  cout << "computing for player = "<<player <<"and coalition ="<<coalition<<" adding ";
	  if (Utils::player_in_coalition(player, coalition)) {
		coef = Utils::shapley_coefficients(size, players);
	    values[player] += coef * g.value_this_vs_rest(coalition);
	    cout << "coef "<<coef<<"value"<< g.value_this_vs_rest(coalition)<<" all "<<coef * g.value_this_vs_rest(coalition) << endl;
	  } else {
		coef = Utils::shapley_coefficients(players - size, players);
        values[player] -= coef * g.value_this_vs_rest(coalition);
	    cout << "coef "<<coef<<"value"<< g.value_this_vs_rest(coalition)<<" all "<<
	    		coef * g.value_this_vs_rest(coalition) *(-1) << endl;
	  }
	}
  }
  return values;
}

void McQuillinValue::print_values() {
  cout << "McQuillin value (" << description() <<")" << endl;
  for (int i = 0; i < (int) values.size(); i++)
	cout << values[i] << " ";
}

string McQuillinValue::description() {
  return "my coalition against the rest of the world";
}
