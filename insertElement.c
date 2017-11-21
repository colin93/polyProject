#include "poly.h"
#inlcude <stdlib.h>

eleError insertElement(int power, double coeffecient,polynomial *poly){
  
  eleError result = ok;
  
  if(power < 0)
    result = negPower;
  else{

    llnode *newelement; //create new element

    newelement = (llnode *) malloc(sizeof(llnode)); //allocate memory for element

    if (newelement !=NULL) {
      newelement->element->power = power; //set power of new element to input power
      newelement->element->coeffecient = coeffecient; //set coeffecient of element to input coeffecient

      newelement->next = poly->structure->current->next //set next in new element to next pointer in poly
      poly->structure->current->next = newelement; //link new elemnet into poly
    }
    else 
      result = noMemory;
  }
  return result;
}
