#include "poly.h"
#include <stdlib.h>
#include <stdio.h>

eleError insertElement(int power, double coeffecient,polynomial *poly){
  
  eleError result = okay;

  //stop user from entering a negative power
  if(power < 0)
    result = negativePower;
  else{
    polyElement *newElement; //element for storing power and coeffecient
	 
    newElement = (polyElement *) malloc(sizeof(polyElement)); //allocate memory
    
    //if memory is allocated
    if(newElement!=NULL){
      newElement->power = power; //set power of element to input power
      newElement->coeffecient = coeffecient; //set coeffecient of element to input coeffecient
      llnode *newNode; //node for polynomial

      newNode = (llnode *) malloc(sizeof(llnode)); //allocate memory for node

      //if memory is allocated
      if (newNode !=NULL) {
	newNode->element=newElement; //set element of newNode to created element

	//link newNode into polynomial
	newNode->next=poly->structure->current->next;
	poly->structure->current->next=newNode;
	nextElement(poly); //move to newNode
      }
      else{
	result = noMemory; //memory not allocated
	free(newElement);
	newElement = NULL;
      }
    }
    else
      result=noMemory; //memory not allocated
  }
  return result; //return relevant error message
}




