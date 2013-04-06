/* *************** *
 * ShapleyValue.h    *
 * Author: natalia * 
 * *************** */

#ifndef SHAPLEYVALUE_H_
#define SHAPLEYVALUE_H_

#include <string>
#include <vector>
#include "Game.h"

using namespace std;

class ShapleyValue {
protected:
  vector < double > values;
  /* additional table of bools so that it will be easier to determine *
   * whether there is a null-player in this game                      */
  vector < bool > marginal_zero;
public:
  virtual vector <double> compute_values(Game const& g) = 0;
  virtual void print_values() = 0;
  double sum_values() const {
    double result = 0.0;
    for (int i = 0; i < (int) values.size(); i++)
      result += values[i];
    return result;
  }
};

#endif /* SHAPLEYVALUE_H_ */
