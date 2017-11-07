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


llist polyMultiply(llist *poly,double mult)
{
  //Check if input llist is empty
  if (poly->head->next == NULL){
    printf("Supplied polynomial is empty");
    return poly;
    }
  else{
    llist result = poly; //Copy input poly to result
    result->current = result->head->next; //Set current node to first node
    while (result->current != NULL){    //Stops when reaches tail

      /*
	if coefficent value for current node is not 0
	update coefficent value of current node to
	be coeffecient * mult
	sets current node to next node in list
       */
      if (result->current->coeff!=0)
	{
	result->current->coeff=result->current->coeff*mult;
	result->current=result->current->next;
	}
      else //sets current node to next node in list
	result->current=result->current->next;
      }
    return result; //returns value of poly after multiplication
    }
  
}

llist polyDivide(llist *poly,double divide)
{
  if(divide!=0) //to stop divide by 0
    {
      double inv = 1.0/divide; //invert input
      llist result = polyMultiply(&poly,inv); //perform multiply with inverse of input
    }
  else
    {
      printf("Can not divide by 0");
      llist result = NULL;
    }
  return result;
}

llist polyNormalise(llist *poly)
{
  double first = poly->head->next->coeff; //gets coeffecient of highest order term
  llist result = polyDivide(&poly,first); //divides poly by that coeffecient
  return result;
}
