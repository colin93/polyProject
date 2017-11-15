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

void setPower(polynomial *poly, int power){
  poly->structure->current->element->power=power;
}


double getCoeffecient (polynomial *poly){
  return poly->structure->current->element->coeffecient;
}

void setCoeffecient(polynomial *poly,double coeff){
  poly->structure->current->element->coeffecient = coeff;  
}

