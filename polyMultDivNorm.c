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


polynomial *polyMultiply(polynomial *polyIn,double mult)
{
  //Check if input llist is empty
  if (polyn->head->next == NULL){
    printf("Supplied polynomial is empty");
    return polyn;
    }
  else{
    polynomial *result = copyPoly(polyIn); //Copy input poly to result may need to change this to do a malloc
    result->structure->current = result->structure->head->next; //Set current node to first node
    while (result->structure->current != NULL){    //Stops when reaches tail

      /*
	if coefficent value for current node is not 0
	update coefficent value of current node to
	be coeffecient * mult
	sets current node to next node in list
       */
      if (result->structure->current->element->coeffecient!=0)
	{
	result->structure->current->element->coeffecient=(result->structure->current->element->coeffecient)*mult;
	result->structure->current=result->structure->current->next;
	}
      else //sets current node to next node in list
	result->structure->current=result->structure->current->next;
      }
    return result; //returns value of poly after multiplication
    }
  
}

polynomial *polyDivide(polynomial *polyIn,double divide)
{
  if(divide!=0) //to stop divide by 0
    {
      double inv = 1.0/divide; //invert input
      polynomial *result = polyMultiply(polyIIn,inv); //perform multiply with inverse of input
    }
  else
    {
      printf("Can not divide by 0");
      polynomial *result = NULL;
    }
  return result;
}

polynomial *polyNormalise(llist *polyIn)
{
  double first = polyIn->structure->head->next->element->coeffecient; //gets coeffecient of highest order term
  polynomial *result = polyDivide(polyIn,first); //divides poly by that coeffecient
  return result;
}
