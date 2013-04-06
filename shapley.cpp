//============================================================================
// Name        : shapley.cpp
// Author      : Natalia Sakowska
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Utils.h"
#include "Game.h"
#include "ShapleyValue.h"
#include "McQuillinValue.h"

using namespace std;

int main(void) {


  int i=5000;
cout << Utils::size_of_coalition(i) <<endl;
cout << Utils::player_in_coalition(1, 16) <<endl;

  Game g = Game(4);
  McQuillinValue sh = McQuillinValue();
  sh.compute_values(g);
  sh.print_values();
  return 0;
}
