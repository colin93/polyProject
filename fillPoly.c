#include "poly.h"
#include <stdlib.h>

void fillPoly (polynomial *poly){

   poly->structure->current=poly->structure->head->next; //Go to first element
   int i; //counter
   while (poly->structure->current->next!=NULL){ //While not at last element
      for(i=(getPower(poly))-1;i>(poly->structure->current->next->power);i--){
	 //fill in powers between two elements with coeffecient 0
 	 insertElement(i,0,poly);
	 nextElement(poly);//moves to inserted node
      }
      nextElement(poly); //move to next element that was already defined
   }
   if (getPower(poly)!=0){ 
      //goes here if at last element and its order is higher than 0
      for(i=(getPower(poly))-1;i>=0;i--){
         //fills in values down to and including x^0 with coeffecient 0
         insertElement(i,0,poly); 
         nextElement(poly); //moves to inserted element
      }
   }

}
