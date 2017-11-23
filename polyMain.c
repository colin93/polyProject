#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

int main(){
 
  printf("Creating poly1:\n");
  //create poly1
  polynomial *poly1 = createPoly();
	
  //insert elements into poly1	
  insertElement (6,3.2,poly1);
  insertElement (4,-1.5,poly1);
  insertElement (3,6.0,poly1);
  insertElement (0,-3.0,poly1);
  

  printf("\nAttempt to input negative power\n");
  //test 1 try input an element with a negative power
  if(insertElement(-1,2.0,poly1)==okay)
    printf("Test failed\n");
  else
    printf("Test passed\n");
	
  //print order of poly1
  printf("\npoly1 has order %d\n",polyOrder(poly1));
  //fill any gaps in powers in poly1
  fillPoly(poly1);

  printf("\nCreating poly2:\n");
  //create poly2
  polynomial *poly2 = createPoly();
	
  //insert elements into poly2
  insertElement (8,-3.2,poly2);
  insertElement (4,1,poly2);
  insertElement (3,-2.0,poly2);
  insertElement (0,1.67,poly2);
	
  //fill any gaps in powers in poly2
  fillPoly(poly2);
	
  //print out a string of poly1
  printf("\n\nValue of poly1 is:\n");
  printPoly(poly1);
	
  //print out a string of poly2
  printf("\n\nValue of poly2 is :\n");
  printPoly(poly2);
	
  
  printf("\n\nAdding poly2 to poly1 results in:\n");
  //add poly2 to poly1 and print out the result (poly1)
  polyAdd(poly1,poly2);
  printPoly(poly1);
	
  printf("\n\nSubtracting poly2 from this results in:\n");
  //subtract poly2 from poly1 and print out the result(poly1)
  polySub(poly1,poly2);
  printPoly(poly1);
	
  printf("\n\nMultiplying by 5 results in:\n");
  //multiply poly1 by 5 and print out the result
  polyMultiply(poly1,5.0);
  printPoly(poly1);
	
  printf("\n\nAttempt to divide by 0\n");
  //test 2 try to divide by 0
  if(polyDivide(poly1,0)==ok)
    printf("Test failed\n");
  else
    printf("Test passed\n");
	
  printf("\n\nDividing poly1 by 5 results in\n");
  //divide poly1 by 5 and print out result
  polyDivide(poly1,5.0);
  printPoly(poly1);
  
  printf("\n\nNormalising results in:\n");
  //normalise poly1 and print out result
  polyNormalise(poly1);
  printPoly(poly1);
	 	
  printf("\n\nDeleting polys\n");
  //delete poly1 and poly2
  deletePoly(poly1);
  deletePoly(poly2);
	
	
  return 0; //Exit main
}

