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
while(result->structure->current->element->power > poly2->structure->current->element->power)
result->stucture->currrent->element = result->structure->current->element->next;
while(result->structure->current->element != NULL)
result->structure->current->element->coeffecient = result->strucutre->current->element->coeffecient - poly2->structure->current-
>element->coeffecient;//change to -
poly2->structure->currrent->element = poly2->structure->current->element->next
result->structure->currrent->element = result->structure->current->element->next;
printf(" %lf is coeficient of first poly and %lf is the coeficient of second poly", poly1->structure->current-
>element->coeffecient , poly2->structure->current->element->coeffecient);

}else{result = copyPoly1(poly2)

while(result->sturcture->current->element->power > poly1->structure->current->element->power)
result->structure->currrent->element = result->structure->current->element->next;
while(result->structure->current != NULL)
result->structure->current->element->coeffecient = - result->structure->current->element->coeffecient + poly1->structure->current-
>element->coeffecient;
poly1->structure->currrent = poly1->structure->current->element->next
result->structure->currrent-element = result->structure->current->element->next;
}

}
  
  return result; //returns value of poly after multiplication
}
