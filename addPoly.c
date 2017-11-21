//addPoly.c
#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

inputError polyAdd(polynomial *poly1,polynomial*poly2)
{
  inputError result = ok;//This is creating Polynominal

  //Check if either poly llist is empty
  if (poly1->head->next == NULL || poly2->head->next == NULL){
    printf("Both supplied polynomials are empty");
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
    if(polyPower1 >= polyPower2){
      while(getPower(poly1) > polyPowers2)
        nextElement(poly1);
      while(setCoeffecient(poly1,getCoeffecient(poly1)+getCoeffecient(poly2))==ok){
        nextElement(poly1);
        nextElement(poly2);
      }
    }
    else{
      goToHead(poly1);
      while(getPower(poly2) > polyPowers1){
        insertElement(getPower(poly2),getCoeffecient(poly2),poly1);
        nextElement(poly1);
        nextElement(poly2);
      };
      while(setCoeffecient(poly1,getCoeffecient(poly1)+getCoeffecient(poly2))==ok){
        nextElement(poly1);
        nextElement(poly2);
      }
    }

  }
  
  return result; //returns value of poly after multiplication
}
//Copy input poly to result may need to change this to do a malloc
// result->current = result->head->next; //Set current node to first node
/*
//Check if input llist is empty
if (polyn->head->next == NULL){
printf("Supplied polynomial is empty");
return polyn;
}
else{
llist *result = copyPoly(polyn); //Copy input poly to result may need to change this to do a malloc
result->current = result->head->next; //Set current node to first node
while (result->current != NULL){ //Stops when reaches tail
//if coefficent value for current node is not 0
//update coefficent value of current node to
//be coeffecient * mult
//sets current node to next node in list
if (result->current->coeffecient!=0)
{
result->current->coeffecient=(result->current->coeffecient)*mult;
result->current=result->current->next;
}
else //sets current node to next node in list
result->current=result->current->next;
}
*/
