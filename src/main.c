#include <stdio.h>
#include <stdlib.h>

#include "array.h"
#include "intType.h"
#include "nAngle.h"

int main(int argc,char* argv[]){

	const int testSize=10;
	//medium tNAngle
	tNAngle* triange1=allocNAngle();
	tPoint t1,t2,t3;
	setPoint(&t1,1,1);
	setPoint(&t2,2,2);
	setPoint(&t3,3,3);
	setTriangle(triange1,t1,t2,t3);

	tNAngle* triange2=allocNAngle();
	setPoint(&t1,-1,-1);
	setPoint(&t2,-2,-2);
	setPoint(&t3,-3,-3);
	setTriangle(triange2,t1,t2,t3);

	tNAngle* triange3=allocNAngle();

	stdArray test=createArray(testSize,allocNAngle,putNAngle,freeNAngle);	
	assertArray(setArray(test,0,triange1));	
	assertArray(setArray(test,1,triange2));	

	assertArray(getArray(test,1,triange3));
	printNAngle(triange3);

	freeArray(test);

	//sample int
	stdArray test2=createArray(testSize,allocInt,putInt,freeInt);
	int tmp=9;
	assertArray(setArray(test2,1,&tmp));
	tmp=0;
	assertArray(getArray(test2,-1,&tmp));
	printf("%d\n",tmp);
	freeArray(test);

	return 0;
}
