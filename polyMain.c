#inlcude <stdio.h>
#include <stdlib.h>
#include "poly.h"

//Will need to update all functions here to reflect all the functions that will be create

int main(){
 
  printf("Creating poly1:\n");
  polynomial *poly1 = createPoly();
  insertElement (,,poly1);
  insertElement (,,poly1);
  insertElement (,,poly1);
  insertElement (,,poly1);
  printf("Attempt to input negative power\n");
  insertElement(-1,2,poly1);
  fillPoly(poly1);
  printf("poly1 has order %d",polyOrder(poly1));
	
  printf("Creating poly2:\n");
  polynomial *poly2 = createPoly();
  insertElement (,,poly2);
  insertElement (,,poly2);
  insertElement (,,poly2);
  insertElement (,,poly2);
  fillPoly(poly2);
	
  printf("Value of poly1 is:\n");
  printPoly(poly1);
  printf("\nValue of poly2 is :\n");
  printPoly(poly1);
	
  printf("Adding poly2 to poly1 results in:");
  printPoly(poly1);
	
  printf("Subtracting poly2 from this results in:");
  printPoly(poly1);
	
  printf("Multiplying by 5 results in:\n");
  polyMultiply(poly1,5.0);
  printPoly(poly1);
	
  printf("Attempt to divide by 0")
  polyDivide(poly1,0);
	
  printf("Dividing poly1 by 5 results in\n");
  polyDivide(poly1,5.0);
  
  printf("Normalising results in:\n")
  polyNormalise(poly1);
  printf(poly1);
	 	
	
	
	
  return 0; //Exit main
}
