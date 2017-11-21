#include "poly.h"
#include <stdlib.h>
#include <stdio.h>

eleError insertElement(int power, double coeffecient,polynomial *poly){
  
  eleError result = okay;
  
  if(power < 0)
    result = negativePower;
  else{
    polyElement *newElement;
	 
    newElement = (polyElement *) malloc(sizeof(polyElement));
    if(newElement!=NULL){
      newElement->power = power;
      newElement->coeffecient = coeffecient;
      llnode *newNode; //create new element

      newNode = (llnode *) malloc(sizeof(llnode)); //allocate memory for element

      if (newNode !=NULL) {
	newNode->element=newElement;
	newNode->next=poly->structure->current->next;
	poly->structure->current->next=newNode;
	nextElement(poly);
      }
      else 
	result = noMemory;
    }
    else
      result=noMemory;
  }
  return result;
}




