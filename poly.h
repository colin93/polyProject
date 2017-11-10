#ifndef POLY_H
#define POLY_H

//Things to add / can be added
//1) enumerator for errors
//2) All other function declerations

typedef struct n {
  int power;
  double coeffecient
  struct n *next; 
} polyFactor;

typedef struct {
  polyFactor *head;
  polyFactor *current;
} llist;

llist polyMultiply(llist *poly,double mult);
llist polyDivide(llist *poly,double divide);
llist polyNormalise(llist *poly);





#endif
