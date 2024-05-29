#ifndef POWER_H
#define POWER_H

#include "Operation.h"
#include <cmath>

class Power : public Operation {
public:
  // Constructor that takes a base and an exponent
  Power(int op1, int op2) : Operation(op1, op2) {}

  // Override the operation() function to perform exponentiation
  int operation() const override {
    return static_cast<int>(pow(get_op1(), get_op2()));
  }
};

#endif // POWER_H
