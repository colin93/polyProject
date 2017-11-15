#ifndef POLY_H
#define POLY_H

//Things to add / can be added
//1) enumerator for errors
typedef struct n{
  polyElement *element;
  struct n *next;
}llnode

typedef struct{
  llnode *current;
  llnode *head;
}llist


typedef struct {
  int power; //Power of polynomial
  double coeffecient //Coeffecient of polynomial
} polyElement; //Name for creating an element of the polynomial

typedef struct {
  llist *structure;
} polynomial;



//Function declerations
polynomial *createPoly();
void deletePoly(polynomial *poly);
void polyOrder(polynomial *poly);
void printPoly(polynomial *poly);
polynomial *polyAdd(polynomial *poly1,polynomial *poly2);
polynomial *polySub(polynomial *poly1,polynomial *poly2);
polynomial *polyMultiply(polynomial *poly,double mult);
polynomial *polyDivide(polynomial *poly,double divide);
polynomial *polyNormalise(polynomial *poly);
void goToHead(polynomial *poly);
void nextElement(polynomial *poly);
int getPower(polynomial *poly);
void setPower(polynomial *poly,int power);
double getCoeffecient(polynomial *poly);
void setCoeffecient(polynomial *poly,double coeffecient);

#endif
