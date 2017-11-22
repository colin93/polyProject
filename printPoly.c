#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

void printPoly(polynomial *poly){

  if (poly->structure->head->next == NULL) //if supplied poly is empty
    printf("0");
  
  else{
    //go to first element
    goToHead(poly);
    nextElement(poly);

    //checks if power not 0
    if(getPower(poly)!=0){
      //prints out element in form ax^n
      printf("%.2fx^%d",getCoeffecient(poly),getPower(poly));
      nextElement(poly);
    
      //while not at element with power of 0
      while(poly->structure->current->next!=NULL){
	//if positive print out + ax^n
	if(getCoeffecient(poly)>0){
	  printf(" + %.2fx^%d",getCoeffecient(poly),getPower(poly));
	  nextElement(poly); //move to next element
	}
	//if negative print out - ax^n
	else if(getCoeffecient(poly)<0){
	  printf(" - %.2fx^%d",-getCoeffecient(poly),getPower(poly));
	  nextElement(poly); //move to next element
	}
	else
	  nextElement(poly); //coeffecient is 0 just move to next element
       
      }
      if (getCoeffecient(poly)>0)
	printf(" + %.2f",getCoeffecient(poly)); //prints + coeff if positive
      else if(getCoeffecient(poly)<0)
	printf(" - %.2f" ,-getCoeffecient(poly)); //prints - coeff if negative
    }
    else //power of highest element is 0
      printf("%.2f",getCoeffecient(poly)); //just prints out value of coeffecient
  }
}


