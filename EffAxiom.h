/* *************** *
 * EffAxiom.h    *
 * Author: natalia * 
 * *************** */

#ifndef EFFAXIOM_H_
#define EFFAXIOM_H_

#include "Axiom.h"
#include <cmath>

class EffAxiom: protected Axiom {
public:
  bool check_axiom(Game g, ShapleyValue * sh) const;
};

#endif /* EFFAXIOM_H_ */
