#include "poly.h"
#include <stdlib.h>

//Would like to use insertElement function for this
//but for whatever reason it doesn't allocate the memory required properly

eleError fillPoly (polynomial *poly){

  polyElement *newElement; //element values for filling poly
  llnode *newNode; //llnode for adding information to polynomial

  eleError result = okay; //return value for function
  poly->structure->current=poly->structure->head->next; //Go to first element
  int i; //counter

  //while not at last element and memory available
  while (poly->structure->current->next!=NULL && result==okay){
    
    //if there is a gap in power between 2 elements
    for(i=(getPower(poly))-1;i>(poly->structure->current->next->element->power);i--){
      newElement = (polyElement *) malloc(sizeof(polyElement));//create new element

      //if memory is allocated
      if(newElement!=NULL){
	newElement->power = i; //set power to i
	newElement->coeffecient = 0; //set coeffecient to 0
	      
	newNode = (llnode *) malloc(sizeof(llnode)); //allocate memory for node

	//if memory is allocated
	if (newNode !=NULL) {
	  newNode->element=newElement; //set element of node to created element
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
    nextElement(poly); //moves to next element that was already defined
  }

  //if at last element and its power is not 0
  if(getPower(poly)!=0){ 
    for(i=(getPower(poly))-1;i>=0;i--){
      //fills in values down to and including x^0 with coeffecient 0
      newElement = (polyElement *) malloc(sizeof(polyElement)); //allocate memory for element
      if(newElement!=NULL){
	newElement->power = i;
	newElement->coeffecient = 0;
	      

	newNode = (llnode *) malloc(sizeof(llnode)); //allocate memory for node

	if (newNode !=NULL) {
	  newNode->element=newElement; //set element of node to created element
	  //link newNode into polynomial
	  newNode->next=poly->structure->current->next;
	  poly->structure->current->next=newNode;
	  nextElement(poly);
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
    nextElement(poly); //moves to inserted element
      
  }
  return result; //return relevant error message

}
