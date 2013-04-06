/* *************** *
 * EffAxiom.cpp    *
 * Author: natalia * 
 * *************** */

#include "EffAxiom.h"
const double ACCURACY = 0.01;


bool EffAxiom::check_axiom(Game g, ShapleyValue * sh) const {
  return (abs(sh->sum_values() - g.value_grand_coalition()) < ACCURACY);
}
