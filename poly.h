#ifndef POLY_H
#define POLY_H

typedef enum { ok, negPower , zeroInput} inputError;

typedef enum { ok, endOfPoly, noMemory} eleError;

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
int polyOrder(polynomial *poly);
void printPoly(polynomial *poly);
void fillPoly(polynomial *poly);
polynomial *polyAdd(polynomial *poly1,polynomial *poly2);
polynomial *polySub(polynomial *poly1,polynomial *poly2);
inputError *polyMultiply(polynomial *poly,double mult);
inputError *polyDivide(polynomial *poly,double divide);
void *polyNormalise(polynomial *poly);
void goToHead(polynomial *poly);
eleError nextElement(polynomial *poly);
int getPower(polynomial *poly);
eleError setPower(polynomial *poly,int power);
double getCoeffecient(polynomial *poly);
eleError setCoeffecient(polynomial *poly,double coeffecient);

#endif
