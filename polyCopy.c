#include "poly.h"
#include <stdlib.h>

//Too add in checks for memory in creation of polyCopy and elementCopy.

polynomial *copyPoly(polynomial *polyIn){

  polynomial *polyCopy; //Creates linked list for copying
  polyCopy = (polynomial*)malloc(sizeof(polynomial)); //Allocates memory for polyCopy
  
  polyIn->structure->current = polyIn->structure->head->next; //Sets node of poly to be copied to first element in list
  polyCopy->structure->current = polyCopy->structure->head; //Sets node of list for copying to head
  
  while (polyIn->structure->current != NULL) //Continues if not at tail of input llist
  {
    llnode *elementCopy; //Creates node for copying elements
    elementCopy = (*llnode)malloc(sizeof(llnode)); //allocates memory for new node
    
    elementCopy->element->coeffecient = getCoeffecient(polyIn); //copies values for coeffecient of input poly
    elementCopy->element->power = getPower(polyIn);   //Copies values of powers for input polynomial
    elementCopy->next = polyCopy->structure->current->next;  //Sets next pointer of new node to tail of copy polynomial
    polyCopy->structure->current->next = elementCopy; //Sets pointer for next node in polyCopy to new node
    nextElement(polyCopy); //Sets current in polyCopy to new node
    nestElement(polyIn); //Moves to next element in input polynomial
  }
  
  return polyCopy; //Returns the copied polynomial
}
