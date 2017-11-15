//addPoly.c
#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

polynomial *polyAdd(polynomial *poly1,polynomial*poly2)
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
while(result->structure->current->element->power > poly2->current->power)
result->stucture->currrent->element = result->structure->current->element->next;
while(result->structure->current->element != NULL)
result->structure->current->element->coeffecient = result->strucutre->current->element->coeffecient + poly2->current-
>coeffecient;//change to -
poly2->currrent = poly2->current->next
result->currrent = result->current->next;
printf(" %lf is cooficient of first poly and %lf is the cooficient of second poly", poly1->current-
>coeffecient , poly2->current->coeffecient);

}else{result = copyPoly1(poly2)

while(result->current->power > poly1->current->power)
result->structure->currrent->element = result->structure->current->element->next;
while(result->current != NULL)
result->structure->current->element->coeffecient = result->structure->current->element->coeffecient + poly1->current-
>coeffecient;
poly1->currrent = poly1->current->next
result->structure->currrent-element = result->structure->current->element->next;
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
