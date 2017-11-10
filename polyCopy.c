#inlcude "poly.h"
#include <stdlib.h>

//Too add in checks for memory in creation of polyCopy and elementCopy.

llist *copyPoly(llist *polyIn){

  llist *polyCopy; //Creates linked list for copying
  polyCopy = (llist*)malloc(sizeof(llist)); //Allocates memory for polyCopy
  
  polyIn->current = polyIn->head->next; //Sets node of poly to be copied to first element in list
  polyCopy->current = polyCopy->head; //Sets node of list for copying to head
  
  while (polyIn->current != NULL) //Continues if not at tail of input llist
  {
    polyElement *elementCopy; //Creates node for copying elements
    elementCopy = (*polyElement)malloc(sizeof(polyElement)); //allocates memory for new node
    
    elementCopy->coeffecient = polyIn->current->coeffecient; //copies values for coeffecient of input poly
    elementCopy->power = polyIn->current->power;   //Copies values of powers for input polynomial
    elementCopy->next = polyCopy->current->next;  //Sets next pointer of new node to tail of copy polynomial
    polyCopy-current->next = elementCopy; //Sets pointer for next node in polyCopy to new node
    polyCopy->current = polyCopy->current->next; //Sets current in polyCopy to new node
    polyIn->current = polyIn->current->next; //Moves to next element in input polynomial
  }
  
  return polyCopy; //Returns the copied polynomial
}
