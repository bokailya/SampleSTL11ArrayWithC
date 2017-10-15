#include <stdlib.h>
#include <stdio.h>

#include "tPoint.h"
#include "nAngle.h"

void* allocNAngle(){
	    tNAngle* res=malloc(sizeof(tNAngle));
		    res->n=MaxAngles;
			    res->arr=malloc(sizeof(tPoint)*MaxAngles);
				    return res;
}

void putNAngle(void* to,void* from){
	    tNAngle* toN=to;
		    tNAngle* fromN=from;

			    int i;
				    toN->n=fromN->n;
					    for(i=0;i<fromN->n;i++)
							        toN->arr[i]=fromN->arr[i];
}

void freeNAngle(void* pointer){
	    tNAngle* pt=pointer;
		    free(pt->arr);
			    free(pt);
}

void printNAngle(const tNAngle* const obj){
	int i=0;
	for(i=0;i<obj->n;i++)
		printPoint(obj->arr[i],',');
	printf("\n");
}

void setTriangle(tNAngle* const obj,tPoint t1,tPoint t2,tPoint t3){
	obj->n=3;
	obj->arr[0]=t1;
	obj->arr[1]=t2;
	obj->arr[2]=t3;
}
