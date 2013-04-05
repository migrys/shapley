/* *************** *
 * Axiom.h    *
 * Author: natalia * 
 * *************** */

#ifndef AXIOM_H_
#define AXIOM_H_

#include "ShapleyValue.h"
#include "Game.h"

class Axiom {
public:
  virtual bool check_axiom(Game g, ShapleyValue * sh) const = 0;
};

#endif /* AXIOM_H_ */
