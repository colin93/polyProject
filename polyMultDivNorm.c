#include "poly.h"
#include <stdlib.h>
#include <stdio.h>




inputError polyMultiply(polynomial *polyIn,double mult)
{ 
  //Check if input llist is empty
  if (polyIn->structure->head->next == NULL){
    printf("Supplied polynomial is empty\n");
    return NullPoly;
  }
  else{

    //goes to first element in polyIn
    goToHead(polyIn);
    nextElement(polyIn);

    //while not at tail
    while (polyIn->structure->current != NULL){

      /*
	if coefficent value for current element is not 0
	update coefficent value of current element to
	be coeffecient * mult
	sets current pointer to next element in polynomial
      */
      if (getCoeffecient(polyIn)!=0)
	{
	  setCoeffecient(polyIn,(getCoeffecient(polyIn))*mult);
	  nextElement(polyIn);
	}
      
      else //sets current pointer to next element in polynomial
	nextElement(polyIn);
    }
    return ok;
  }
}

inputError polyDivide(polynomial *polyIn,double divide)
{
  //stop divide by 0
  if(divide!=0)
    {
      double inv = 1.0/divide; //invert input
      return polyMultiply(polyIn,inv); //perform multiply with inverse of input
    }
  else
    {
      return zeroInput;
    }
}

inputError polyNormalise(polynomial *polyIn)
{
  //go to first & highest power element of input poly
  goToHead(polyIn);
  nextElement(polyIn);
  
  //perform division with coeffecient of that element
  return polyDivide(polyIn,getCoeffecient(polyIn));
}
