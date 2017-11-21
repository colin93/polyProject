#include "poly.h"
#include <stdlib.h>

void goToHead(polynomial *poly){
  poly->structure->current=poly->structure->head;
  }

eleError nextElement(polynomial *poly){
  eleError result = okay;
  if (poly->structure->current != NULL)
    poly->structure->current=poly->structure->current->next;
  else 
    result = invalidElement;
  return result;
    
}

int getPower(polynomial *poly){
  if (poly->structure->current == poly->structure->head || poly->structure->current == NULL)
    return -1;
  else 
    return poly->structure->current->element->power;
}

inputError setPower(polynomial *poly, int power){
  inputError result = ok;
  if (poly->structure->current!=NULL && poly->structure->current != poly->structure->head)
    poly->structure->current->element->power=power;
  else 
    result = invalidElement;
  return result;
}


double getCoeffecient (polynomial *poly){
  if (poly->structure->current == poly->structure->head || poly->structure->current == NULL)
    return 0;
  else 
    return poly->structure->current->element->coeffecient;
}

inputError setCoeffecient(polynomial *poly,double coeff){
  inputError result = ok;
  if (poly->structure->current!=NULL && poly->structure->current != poly->structure->head)
    poly->structure->current->element->coeffecient=coeff;
  else 
    result = invalidElement;
  return result;  
}

