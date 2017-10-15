#ifndef __NANGLE__
#define __NANGLE__

#include "tPoint.h"

typedef struct {
	int n;
	tPoint* arr;
}tNAngle;

#define MaxAngles 100

void* allocNAngle();
void putNAngle(void* to,void* from);
void freeNAngle(void* pointer);
void printNAngle(const tNAngle* const obj);
void setTriangle(tNAngle* const obj,tPoint t1,tPoint t2,tPoint t3);

#endif
