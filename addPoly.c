//addPoly.c
#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

inputError polyAdd(polynomial *poly1,polynomial*poly2)
{
  inputError result = ok;//This is creating Polynominal

  //Check if both polynomials are NULL
  if (poly1->structure->head->next == NULL && poly2->structure->head->next == NULL){
    result = NullPoly; //set result to show that supplied polys are null
  }
  else{
    int polyPowers1 = polyOrder(poly1); //get highest power of poly1
    int polyPowers2 = polyOrder(poly2); //get highest power of poly2
    
    if(polyPowers1 >= polyPowers2){ //check which poly has higher power

      //move down through poly1 until at same power as highest power in poly2
      while(getPower(poly1) > polyPowers2)
        nextElement(poly1);

      //while not at tail
      //set coeffecient of poly1 to the addition of the two coeffecient in poly1 &poly2
      while(setCoeffecient(poly1,getCoeffecient(poly1)+getCoeffecient(poly2))==ok){
        nextElement(poly1); //move to next element in poly1
        nextElement(poly2); //move to next element in poly2
      }
    }
    else{
      goToHead(poly1); //move to head for inserting new elements

      //while power of poly2 is greater than order of poly1
      while(getPower(poly2) > polyPowers1){
	//inserts new element into poly1 that is equal to same element from poly2
        insertElement(getPower(poly2),getCoeffecient(poly2),poly1);
        nextElement(poly2); //move poly2 to next element
      }
      nextElement(poly1);//moves to element that was the order of poly1

      //while not at tail
      //set coeffecient of poly1 to the addition of the two coeffecient in poly1 &poly2  
      while(setCoeffecient(poly1,getCoeffecient(poly1)+getCoeffecient(poly2))==ok){
        nextElement(poly1); //move to next element in poly1
        nextElement(poly2); //move to next element in poly2
      }
    }

  }

  llnode *delete;
  //while element after head has coeffecient 0 and polynomial is not empty remove the element after head
  while(poly1->structure->head->next != NULL){
    if(poly1->structure->head->next->element->coeffecient == 0){
	delete = poly1->structure->head->next;
	poly1->structure->head->next= delete->next;
        free(delete);
    }
    else
      break;
  }
  
  return result; //returns resulting error value
}

