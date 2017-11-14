#include "poly.h"
#include <stdlib.h>

void fillPoly (llist *poly){

	poly->current=poly->head->next; //Go to first element
	int i; //counter
	while (poly->current !=NULL){ //While not at tail
		while (poly->current->next!=NULL){ //While not at last element
			for(i=(poly->current->power)-1;i>(poly->current->next->power);i--){
				//fill in powers between two elements with coeffecient 0
				insertElement(i,0,poly);
				poly->current=poly->current->next;
				}
			poly->current=poly->current->next; //move to next element
		if (poly->current->power!=0){ 
			//goes here if at last element and its order is higher than 0
			for(i=(poly->current->power)-1;i>=0;i--){
				//fills in values down to and including x^0 with coeffecient 0
				insertElement(i,0,poly); 
				poly->current=poly->current->next;
				}
			poly->current=poly->current->next; //moves to tail
			}
		else 
			poly->current=poly->current->next; //moves to tail
		}

}
