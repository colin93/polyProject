#include "poly.h"
#include <stdlib.h>

void fillPoly (llist *poly){

	poly->current=poly->head->next;
	int i;
	while (poly->current !=NULL){
		if (poly->current->next!=NULL){
			while (poly->current->next!=NULL){
				for(i=(poly->current->power)-1;i>(poly->current->next->power);i--){
					insertElement(&i,&0,poly);
					poly->current=poly->current->next;
					}
				poly->current=poly->current->next;
			if (poly->current->power!=0)
				for(i=(poly->current->power)-1;i>=0;i--){
					insertElement(&i,&0,poly);
					poly->current=poly->current->next;
					}
				poly->current=poly->current->next;
			}		
		}
		else if((poly->current->next == NULL) && (poly->current->power !=0)){
			for(i=(poly->current->power)-1;i>=0;i--){
				insertElement(&i,&0,poly);
				poly->current=poly->current->next;
				}
			poly->current=poly->current->next;
		}
		else
			poly->current=poly->current->next;
	}
	

}
