#include "poly.h"
#include <stdlib.h>

eleError fillPoly (polynomial *poly){

   polyElement *newElement;
   llnode *newNode;

   eleError result = okay;
   poly->structure->current=poly->structure->head->next; //Go to first element
   int i; //counter
   while (poly->structure->current->next!=NULL && result==okay){ //While not at last element
      for(i=(getPower(poly))-1;i>(poly->structure->current->next->element->power);i--){
	 //fill in powers between two elements with coeffecient 0
 	 newElement = (polyElement *) malloc(sizeof(polyElement));
	    if(newElement!=NULL){
	      newElement->power = i;
	      newElement->coeffecient = 0;
	      
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
      nextElement(poly); //move to next element that was already defined
   }
   if(getPower(poly)!=0){ 
      //goes here if at last element and its order is higher than 0
      for(i=(getPower(poly))-1;i>=0;i--){
         //fills in values down to and including x^0 with coeffecient 0
         newElement = (polyElement *) malloc(sizeof(polyElement));
	    if(newElement!=NULL){
	      newElement->power = i;
	      newElement->coeffecient = 0;
	      

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
         nextElement(poly); //moves to inserted element
      
   }
   return result;

}
