#include "mypoly.h"
#include <stdlib.h>
#include <stdio.h>

/*
  Things to check/create/add
  1) could create errors
  2) change pointers to reflect actual contents of final structure
  3) make sure can create result polys as I've currently done
  4) potentially spread the functions into other files
 */


llist polyMultiply(llist *polyn,double mult)
{
  //Check if input llist is empty
  if (polyn->head->next == NULL){
    printf("Supplied polynomial is empty");
    return polyn;
    }
  else{
    llist result = polyn; //Copy input poly to result may need to change this to do a malloc
    result->current = result->head->next; //Set current node to first node
    while (result->current != NULL){    //Stops when reaches tail

      /*
	if coefficent value for current node is not 0
	update coefficent value of current node to
	be coeffecient * mult
	sets current node to next node in list
       */
      if (result->current->poly.coeff!=0)
	{
	result->current->coeff=result->current->poly.coeff*mult;
	result->current=result->current->next;
	}
      else //sets current node to next node in list
	result->current=result->current->next;
      }
    return result; //returns value of poly after multiplication
    }
  
}

llist polyDivide(llist *polyn,double divide)
{
  if(divide!=0) //to stop divide by 0
    {
      double inv = 1.0/divide; //invert input
      llist result = polyMultiply(&polyn,inv); //perform multiply with inverse of input
    }
  else
    {
      printf("Can not divide by 0");
      llist result = NULL;
    }
  return result;
}

llist polyNormalise(llist *polyn)
{
  double first = polyn->head->next->poly.coeff; //gets coeffecient of highest order term
  llist result = polyDivide(&polyn,first); //divides poly by that coeffecient
  return result;
}
