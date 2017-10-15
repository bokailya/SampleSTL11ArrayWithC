#ifndef __TPOINT__
#define __TPOINT__

typedef struct {
	float x,y;
}tPoint;

void printPoint(tPoint p,char end);
void setPoint(tPoint* p,float x, float y);

#endif
