#include "poly.h"
#include <stdlib.h>

void goToHead(polynomial *poly){
  poly-structure->current=poly->structure->head;
  }

void nextElement(polynomial *poly){
  poly->structure->current=poly->structure->current->next
}

int getPower(polynomial *poly){
  return poly->structure->current->element->power;
}

double getCoeffecient (polynomial *poly){
  return poly->structure->current->element->coeffecient;
}
