#ifndef POLY_H
#define POLY_H

typedef enum { ok, negPower , zeroInput, NullPoly, invalidElement} inputError;

typedef enum { okay,  noMemory, negativePower} eleError;

//Things to add / can be added
//1) enumerator for errors
typedef struct {
  int power; //Power of polynomial
  double coeffecient; //Coeffecient of polynomial
} polyElement; //Name for creating an element of the polynomial

typedef struct n{
  polyElement *element;
  struct n *next;
}llnode;

typedef struct{
  llnode *current;
  llnode *head;
}llist;


typedef struct {
  llist *structure;
} polynomial;



//Function declerations
polynomial *createPoly();
void deletePoly( polynomial *poly );
int polyOrder(polynomial *poly);
eleError insertElement(int power, double coeffecient, polynomial *poly);
void printPoly(polynomial *poly);
void fillPoly(polynomial *poly);
inputError polyAdd(polynomial *poly1,polynomial *poly2);
inputError polySub(polynomial *poly1,polynomial *poly2);
inputError polyMultiply(polynomial *poly,double mult);
inputError polyDivide(polynomial *poly,double divide);
inputError polyNormalise(polynomial *poly);
void goToHead(polynomial *poly);
eleError nextElement(polynomial *poly);
int getPower(polynomial *poly);
inputError setPower(polynomial *poly,int power);
double getCoeffecient(polynomial *poly);
inputError setCoeffecient(polynomial *poly,double coeffecient);

#endif
