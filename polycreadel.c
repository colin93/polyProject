polynomial *createPoly(){
    polynomial *polyNew;
    polyNew = (polynomial*)malloc(sizeof(polynomial));
    if(polyNew!=NULL){
    	polyNew->structure->head=(llnode*)malloc(sizeof(llnode));
	if(polyNew->structure->head!=NULL){
    		polyNew->structure->head->next = NULL;
		goToHead(polyNew);
	}
	else{
		free(polyNew);
		polyNew=NULL;
	}
    return polyNew;
}

void deletePoly( polynomial *poly ){
    llnode *p,*q;
    p = poly->structure->head;
    while( p->next != NULL ){
        q = p->next;
        p->next = q->next;
        free(q);
    }
    free(p);
    free(poly);
    printf("You have successfully deleted.\n");
}
