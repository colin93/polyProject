#include "poly.h"
#include <stdlib.h>
#include <stdio.h>

/*
  Things to check/create/add
  1) could create errors
  2) change pointers to reflect actual contents of final structure
  3) make sure can create result polys as I've currently done
  4) potentially spread the functions into other files
 */


void polyMultiply(polynomial *polyIn,double mult)
{
  //Check if input llist is empty
  if (polyn->head->next == NULL){
    printf("Supplied polynomial is empty");
    return polyIn;
    }
  else{
    goToHead(polyIn);
    nextElement(polyIn);
    while (polyIn->structure->current != NULL){    //Stops when reaches tail

      /*
	if coefficent value for current node is not 0
	update coefficent value of current node to
	be coeffecient * mult
	sets current node to next node in list
       */
      if (getCoeffecient(polyIn)!=0)
	{
	setCoeffecient(polyIn,(getCoeffecient(polyIn))*mult);
	nextElement(polyIn);
	}
      else //sets current node to next node in list
	nextElement(polyIn);
      }
    return;
    }
  
}

inputError *polyDivide(polynomial *polyIn,double divide)
{
  inputError result = ok;
  if(divide!=0) //to stop divide by 0
    {
      double inv = 1.0/divide; //invert input
      polyMultiply(polyIIn,inv); //perform multiply with inverse of input
    }
  else
    {
      result= zeroInput;
    }
  result;
}

void polyNormalise(llist *polyIn)
{
  goToHead(polyIn);
  nextElement(polyIn);
  polyDivide(polyIn,getCoeffecient(polyIn));
}
