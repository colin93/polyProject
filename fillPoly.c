#include "poly.h"
#include <stdlib.h>


eleError fillPoly (polynomial *poly){

  eleError result = okay; //return value for function
  poly->structure->current=poly->structure->head->next; //Go to first element
  int i; //counter

  //while not at last element and memory available
  while (poly->structure->current->next!=NULL && result==okay){
    
    //if there is a gap in power between 2 elements
    for(i=(getPower(poly))-1;i>(poly->structure->current->next->element->power);i--){
      //insert elements with coeffecient 0
      result=insertElement(i,0,poly); 
    }
    nextElement(poly); //moves to next element that was already defined
  }

  //if at last element and its power is not 0
  if(getPower(poly)!=0){ 
    for(i=(getPower(poly))-1;i>=0;i--){
      //fills in values down to and including x^0 with coeffecient 0
      result=insertElement(i,0,poly);
    }
    nextElement(poly); //moves to tail
      
  }
  return result; //return relevant error message

}
