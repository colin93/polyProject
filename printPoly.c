#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

void printPoly(polynomial *poly){

  goToHead(poly);
  nextElement(poly);
  if(getPower(poly)!=0)
    printf("%.2fx^%d",getCoeffecient(poly),getPower(poly));
  else
    printf("%.2f",getCoeffecient(poly));
  nextElement(poly);
  while(poly->structure->current->next!=NULL){
    if(getCoeffecient(poly)>0){
      printf(" + %.2fx^%d",getCoeffecient(poly),getPower(poly));
      nextElement(poly);
    }
    else if(getCoeffecient(poly)<0){
      printf(" - %.2fx^%d",-getCoeffecient(poly),getPower(poly));
      nextElement(poly);
    }
    else
      nextElement(poly);
       
  }
  if (getCoeffecient(poly)>0)
      printf(" + %.2f",getCoeffecient(poly));
  else if(getCoeffecient(poly)<0)
    printf(" - %.2f" ,-getCoeffecient(poly));
}
