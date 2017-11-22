#include "poly.h"
#include <stdlib.h>

int polyOrder(polynomial *poly){
  //go to first element in poly
  goToHead(poly);
  nextElement(poly);

  //return power of that element
  return getPower(poly);
}
