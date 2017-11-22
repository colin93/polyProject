#include "poly.h"
#include <stdlib.h>
#include <stdio.h>

polynomial *createPoly(){
  polynomial *polyNew;
  polyNew = (polynomial*)malloc(sizeof(polynomial)); //allocate memory for polynomial

  //if memory is allocated
  if(polyNew!=NULL){
    polyNew->structure = (llist *) malloc(sizeof(llist)); //allocate memory for structure

    //if memory is allocated
    if (polyNew->structure !=NULL){
      polyNew->structure->head=(llnode*)malloc(sizeof(llnode)); //allocate memory for head

      //if memory is allocated
      if(polyNew->structure->head!=NULL){
	polyNew->structure->head->next = NULL;//set next for head to tail
	polyNew->structure->current=polyNew->structure->head; //set current for polynomial to head
      }
      else{//memory not allocated
	free(polyNew->structure); //delete llist
	free(polyNew); //delete polynomial
	polyNew=NULL; //set polynomial to null
      }
    }
    else{//memory not allocated
      free(polyNew);//delete polynomial
      polyNew=NULL;//set polynomial to null
    }
  }
  return polyNew; //return created polynomial
}

void deletePoly(polynomial *poly){
  llnode *p,*q;
  p = poly->structure->head; //set p to head 
  while( p->next != NULL ){ //while elements remain
    q = p->next; //set q to first element after head
    p->next = q->next; //set heads next pointer to second element after head
    free(q); //delete node corresponding to q
  }
  free(p); //delete head
  free(poly); //delete poly
  printf("You have successfully deleted.\n");
  return;
}
