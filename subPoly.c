//subPoly.c
//Author: Diarmuid McCarthy
//To subtract two polynomial


#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

inputError polySub(polynomial *poly1,polynomial*poly2)
{
  inputError result = ok;//This is creating Polynominal

  //Check if both poly llist is empty
  if (poly1->structure->head->next == NULL || poly2->structure->head->next == NULL){
    result = NullPoly;
    //return any of supplied polinomials as both are empty
  }
  /*//Check if only first poly llist is empty
  else if (poly1->head->next == NULL && poly2->head->next != NULL){
  printf("First supplied polynomial is empty");
  return poly2; //return the second supplied polinomian as first is empty
  }
  //Check if only second poly llist is empty
  else if (poly1->head->next != NULL && poly2->head->next == NULL){
  printf("Second supplied polynomial is empty");
  return poly1; //return the first supplied polinomian as second is empty
  }*/
  else{
    int polyPowers1 = polyOrder(poly1);
    int polyPowers2 = polyOrder(poly2);
    if(polyPowers1 >= polyPowers2){
      while(getPower(poly1) > polyPowers2)
        nextElement(poly1);
      while((setCoeffecient(poly1,getCoeffecient(poly1)-getCoeffecient(poly2)))==ok){
        nextElement(poly2);
        nextElement(poly1);
        }
      }
    else{
      goToHead(poly1);
      while(getPower(poly2) > getPower(poly1)){
        insertElement(getPower(poly2),-getCoeffecient(poly2),poly1);
        nextElement(poly1);
        nextElement(poly2);
        }
      while(setCoeffecient(poly1,getCoeffecient(poly1)-getCoeffecient(poly2))==ok){
        nextElement(poly1);
        nextElement(poly2);
        }
      }

    }

  return result; //returns value of poly after multiplication
}
