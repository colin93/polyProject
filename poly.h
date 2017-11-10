#ifndef POLY_H
#define POLY_H

//Things to add / can be added
//1) enumerator for errors
//2) All other function declerations


typedef struct n {
  int power; //Power of polynomial
  double coeffecient //Coeffecient of polynomial
  struct n *next; //Pointer to next element of polynomial
} polyElement; //Name for creating an element of the polynomial

typedef struct {
  polyElement *head; //Creates a pointer to head of linked list
  polyElement *current; //Creates a pointer to current polynomial element you are at
} llist;

llist polyMultiply(llist *poly,double mult);
llist polyDivide(llist *poly,double divide);
llist polyNormalise(llist *poly);


#endif
