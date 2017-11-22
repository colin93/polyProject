#include "poly.h"
#include <stdlib.h>

/*
  functions for frequently used pointers
  Helps tidy up code a little
 */

void goToHead(polynomial *poly){
  poly->structure->current=poly->structure->head; //go to head of polynomial
  }

eleError nextElement(polynomial *poly){
  eleError result = okay;
  
  //check if at tail
  if (poly->structure->current != NULL)
    //if no move to next element
    poly->structure->current=poly->structure->current->next;
  else
    //if yes set result to show at invalid element
    result = invalidElement; 
  return result;
    
}

int getPower(polynomial *poly){
  //check if at head or tail
  if (poly->structure->current == poly->structure->head || poly->structure->current == NULL)
    return -1; //return -1 if yes
  else 
    return poly->structure->current->element->power; //return power of current element if no
}

inputError setPower(polynomial *poly, int power){
  inputError result = ok;

  //check if at head or tail
  if (poly->structure->current!=NULL && poly->structure->current != poly->structure->head)
    poly->structure->current->element->power=power; //if no set power of current element to input power
  else 
    result = invalidElement; //if yes set result to appropriate error message
  return result;
}


double getCoeffecient (polynomial *poly){
  //check if at head or tail
  if (poly->structure->current == poly->structure->head || poly->structure->current == NULL)
    return 0; //if yes return 0
  else 
    return poly->structure->current->element->coeffecient; //if no return coeffecient of current element
}

inputError setCoeffecient(polynomial *poly,double coeff){
  inputError result = ok;
  //check if at head or tail
  if (poly->structure->current!=NULL && poly->structure->current != poly->structure->head)
    poly->structure->current->element->coeffecient=coeff; //if no set coeffecient of current element to input coeffecient
  else 
    result = invalidElement; //if yes set result to appropriate error message
  return result;  
}

