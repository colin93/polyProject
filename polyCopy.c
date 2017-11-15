#include "poly.h"
#include <stdlib.h>

//Too add in checks for memory in creation of polyCopy and elementCopy.

polynomial *copyPoly(polynomial *polyIn){

  polynomial *polyCopy; //Creates linked list for copying
  polyCopy = (polynomial*)malloc(sizeof(polynomial)); //Allocates memory for polyCopy
  
  goToHead(polyIn);//Sets node of poly to be copied to first element in list
  nextElement(polyIn);
  goToHead(polyCopy); //Sets node of list for copying to head
  
  while (polyIn->structure->current != NULL) //Continues if not at tail of input llist
  {
    insertElement(getPower(polyIn),getCoeffecient(polyIn),polyCopy);
    
    nextElement(polyCopy); //Sets current in polyCopy to new node
    nextElement(polyIn); //Moves to next element in input polynomial
  }
  
  return polyCopy; //Returns the copied polynomial
}
