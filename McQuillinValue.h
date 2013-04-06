/* *************** *
 * McQuillinValue.h    *
 * Author: natalia * 
 * *************** */

#ifndef MCQUILLINVALUE_H_
#define MCQUILLINVALUE_H_

#include <iostream>
#include "ShapleyValue.h"
#include "Utils.h"

class McQuillinValue : public ShapleyValue {
public:
  vector < double > compute_values(Game const& g);
  void print_values();
  static string description();
};

#endif /* MCQUILLINVALUE_H_ */
