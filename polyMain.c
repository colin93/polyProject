#inlcude <stdio.h>
#include <stdlib.h>
#include "poly.h"

//Will need to update all functions here to reflect all the functions that will be create

int main(){

  int option=9; //choice for switch
  llist *poly1 = createPoly(); //polynomial for performing various functions

  while (option!=8){
    //table of operations
    printf("\n\nPick an operation \n");
    printf("\t1)Print poly\n");
    printf("\t2)Print order of poly\n");
    printf("\t3)Add two polynomials\n");
    printf("\t4)Subtract two polynomials\n");
    printf("\t5)Multiply polynomial by a number\n");
    printf("\t6)Divide polynomial by a number\n");
    printf("\t7)Normalise polynomial\n");
    printf("\t8)Delete polynomial and exit\n");
    scanf("%d",&option);

    switch (option) {

    case 1: //Print out polynomial
      printPoly(poly1);
      break;
      
    case 2: //Print order of polynomial
      polyOrder(poly1);
      break;
      
    case 3:
      //Creates second polynomial and adds it to first
      //Prints out result then deletes resultant and second polynomial
      printf("Create a second polynomial\n");
      llist *poly2 = createPoly();
      llist *poly3 = polyAdd(poly1,poly2);
      printPoly(poly1);
      printf("+");
      printPoly(poly2);
      printf("=");
      printPoly(poly3);
      deletePoly(poly2);
      deletePoly(poly3);
      break;
      
    case 4:
      //Creates second polynomial and subtracts it from first
      //Prints result and deletes resultant and second polynomial
      printf("Create a second polynomial\n");
      llist *poly2 = createPoly();
      llist *poly3 = polySub(poly1,poly2);
      printPoly(poly1);
      printf("-");
      printPoly(poly2);
      printf("=");
      printPoly(poly3);
      deletePoly(poly2);
      deletePoly(poly3);
      break;
      
    case 5:
      //takes in value and multiplies polynomial by that value
      //Prints result and deletes resultant polynomial
      double mult;
      printf("Please enter a value for multiplication");
      scanf("%lf",&mult);
      llist *poly2 = polyMultiply(poly1,mult);
      printPoly(poly1);
      printf("multiplied by %f is",mult);
      printPoly(poly2);
      deletePoly(poly2);
      break;
      
    case 6:
      //takes in value and divides polynomial by that value
      //Prints result and deletes resultant polynomial
      double div;
      printf("Please enter a value for division");
      scanf("%lf",&mult);
      llist *poly2 = polyDivide(poly1,div);
      printPoly(poly1);
      printf("divided by %f is",div);
      printPoly(poly2);
      deletePoly(poly2);
      break;
      
    case 7:
      //Normalise and print poly
      //Then deletes normalised polynomial
      llist *poly2 = polyNormalise(poly1);
      printPoly(poly1);
      printf("\nNormalised is");
      printPoly(poly2);
      deletePoly(poly2);
      break;
      
    case 8:
      //Deletes original polynomial and exits program
      polyDelete(poly1);
      printf("Exiting program\n");
      break
	
      
    }
    

  }
  return 0; //Exit main
}
