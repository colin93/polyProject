#ifndef POLY_H
#define POLY_H

//Things to add / can be added
//1) enumerator for errors
//2) All other function declerations


typedef struct {
  int order;
  double coeffecient;
}poly;

typedef struct n {
  poly a;
  struct n *successor; 
} llnode;

typedef struct {
  llnode *head;
  llnode *current;
} llist;

llist polyMultiply(llist *poly,double mult);
llist polyDivide(llist *poly,double divide);
llist polyNormalise(llist *poly);





#endif
