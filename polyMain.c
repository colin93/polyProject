#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

//Will need to update all functions here to reflect all the functions that will be create

int main(){
 
  printf("Creating poly1:\n");
  polynomial *poly1 = createPoly();
  insertElement (6,3.2,poly1);
  insertElement (4,-1.5,poly1);
  insertElement (3,6.0,poly1);
  insertElement (0,-3.0,poly1);
  printf("\nAttempt to input negative power\n");
  if(insertElement(-1,2.0,poly1)==okay)
    printf("Test failed\n");
  else
    printf("Test passed\n");
  printf("\npoly1 has order %d\n",polyOrder(poly1));
  fillPoly(poly1);

  printf("\nCreating poly2:\n");
  polynomial *poly2 = createPoly();
  insertElement (8,-3.2,poly2);
  insertElement (4,1,poly2);
  insertElement (3,-2.0,poly2);
  insertElement (0,1.67,poly2);
  fillPoly(poly2);
	
  printf("\n\nValue of poly1 is:\n");
  printPoly(poly1);
  printf("\n\nValue of poly2 is :\n");
  printPoly(poly2);
	
  printf("\n\nAdding poly2 to poly1 results in:\n");
  polyAdd(poly1,poly2);
  printPoly(poly1);
	
  printf("\n\nSubtracting poly2 from this results in:\n");
  polySub(poly1,poly2);
  printPoly(poly1);
	
  printf("\n\nMultiplying by 5 results in:\n");
  polyMultiply(poly1,5.0);
  printPoly(poly1);
	
  printf("\n\nAttempt to divide by 0\n");
  if(polyDivide(poly1,0)==ok)
    printf("Test failed\n");
  else
    printf("Test passed\n");
	
  printf("\n\nDividing poly1 by 5 results in\n");
  polyDivide(poly1,5.0);
  printPoly(poly1);
  
  printf("\n\nNormalising results in:\n");
  polyNormalise(poly1);
  printPoly(poly1);
	 	
  printf("\n\nDeleting polys\n");
  deletePoly(poly1);
  deletePoly(poly2);
	
	
  return 0; //Exit main
}
