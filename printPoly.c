#include "poly.h"
#include <stdio.h>
#include <stdlib.h>

void printPoly(polynomial *poly){

  goToHead(poly);
  while(nextElement(poly)==okay){
    if(getCoeffecient(poly)!=0)
      printf("%.2fx^%d",getCoeffecient(poly),getPower(poly));
  }
}
