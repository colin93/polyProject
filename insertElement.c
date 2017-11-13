#include "poly.h"
#inlcude <stdlib.h>

void insertElement(int power, int coeffecient,llist *poly){

  polyElement *newelement;

  newelement = (polyElement *) malloc(sizeof(polyElement));

  if (newelement !=NULL) {
    newelement->power = power;
    newelement->coeffecient = coeffecient;

    newelement->next = poly->current->next;
    poly->current->next = newelement;
  }
  

}
