#include "poly.h"
#include <stdlib.h>

int polyOrder(polynomial *poly){
  goToHead(poly);
  nextElement(poly);
  return getPower(poly);
}
