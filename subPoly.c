//subPoly.c
//Author: Diarmuid McCarthy
//To subtract two polynomial


#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

inputError polySub(polynomial *poly1,polynomial*poly2)
{
  inputError result = ok;//error message for returning

  //Check if both input polys are empty
  if (poly1->structure->head->next == NULL && poly2->structure->head->next == NULL){
    result = NullPoly; //set error message to show both inputs is null
  }

  else{
    int polyPowers1 = polyOrder(poly1); //get highest power of poly1
    int polyPowers2 = polyOrder(poly2); //get highest power of poly2

    //if order poly1 is higher than order of poly2
    if(polyPowers1 >= polyPowers2){
      //while power of current element in poly1 is greater than order of poly2
      while(getPower(poly1) > polyPowers2)
        nextElement(poly1); //go to next element in poly1

      //while not at tail set coeffecient of current element in poly1
      //to the value of its current coeffecient minus the coeffecient of poly 2
      while((setCoeffecient(poly1,getCoeffecient(poly1)-getCoeffecient(poly2)))==ok){
        nextElement(poly2); //move to next element in poly2
        nextElement(poly1); //move to next element in poly1
      }
    }
    
    else{
      goToHead(poly1); //go to head for inserting new nodes

      //while power of current element in poly2 is greater than order of poly1
      while(getPower(poly2) > polyPowers1){
	//insert new element into poly1 equal to the negative of the same element from poly2 
        insertElement(getPower(poly2),-getCoeffecient(poly2),poly1);
	//move to next element in poly2
        nextElement(poly2);
      }
      nextElement(poly1); //moves to element that was the highest power of poly1

      //while not at tail set coeffecient of current element in poly1
      //to the value of its current coeffecient minus the coeffecient of poly 2
      while(setCoeffecient(poly1,getCoeffecient(poly1)-getCoeffecient(poly2))==ok){
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

  return result; //returns value of poly after multiplication
}
