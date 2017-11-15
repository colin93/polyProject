//subPoly.c
//Author: Diarmuid McCarthy
//To subtract two polynomial


#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

polynomial *polySub(polynomial *poly1,polynomial*poly2)
{
  polynomial *result;//This is creating Polynominal

  //Check if both poly llist is empty
  if (poly1->head->next == NULL || poly2->head->next == NULL){
    printf("Both supplied polynomials are empty");
    result = NULL;
    return result;
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
    if(polyPower1 >= polyPower2){
      result = copyPoly1(poly1)
      while(getPower(result) > polyPowers2)
      nextElement(result);
      while(result->structure->current != NULL)
      setCoeffecient(result,getCoeffecient(result)-getCoeffecient(poly2));//change to -
      nextElement(poly2);
      nextElement(result);
      }
    else{
      result = copyPoly1(poly2)
      while(getPower(result) > getPower(poly1)){
        setCoeffecient(result,-(getCoeffecient(result));
        nextElement(result);
        }
      while(result->structure->current != NULL){
        setCoeffecient(result,getCoeffecient(poly1)-getCoeffecient(result));
        nextElement(poly1);
        nextElement(result);
        }
      }

    }

  return result; //returns value of poly after multiplication
}
