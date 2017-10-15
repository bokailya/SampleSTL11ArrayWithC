#include <stdio.h>
#include "tPoint.h"

void printPoint(tPoint p,char end){
	printf("x=%3.2f y=%3.2f%c",p.x,p.y,end);
}

void setPoint(tPoint* p,float x, float y){
	p->x=x;
	p->y=y;
}
