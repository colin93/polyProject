#include "poly.h"
#inlcude <stdlib.h>

void insertElement(int power, int coeffecient,llist *poly){

  polyElement *newelement; //create new element

  newelement = (polyElement *) malloc(sizeof(polyElement)); //allocate memory for element

  if (newelement !=NULL) {
    newelement->power = power; //set power of new element to input power
    newelement->coeffecient = coeffecient; //set coeffecient of element to input coeffecient

    newelement->next = poly->current->next; //set next in new element to next pointer in poly
    poly->current->next = newelement; //link new elemnet into poly
  }
  

}
