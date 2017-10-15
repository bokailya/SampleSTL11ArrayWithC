#include <stdlib.h>
#include <stdio.h>
#include "array.h"

void assertArray(int error){
	switch (error){
		case 1: fprintf(stderr,"out of range\n");exit(0);

	}
}

stdArray createArray(int n,allocator alloc,copy cp,freeLocal clean){
	stdArray container;
	container.alloc=alloc;
	container.cp=cp;
	container.clean=clean;

	container.n=n;
	container.arr=malloc(sizeof(void*)*n);	
	int i;
	for(i=0;i<container.n;i++)
		container.arr[i]=NULL;
	#ifdef DEBUG
	fprintf(stderr,"create\n");
	#endif
	return container;
}

void freeArray(stdArray container){
	int i;
	for(i=0;i<container.n;i++)
		if(container.arr[i]!=NULL)
			container.clean(container.arr[i]);
	#ifdef DEBUG
	fprintf(stderr,"free\n");
	#endif
	free(container.arr);
}

int setArray(stdArray container,int pos,void* data){
	if(pos<0 || pos>=container.n)return 1;
	if(container.arr[pos]==NULL)
		container.arr[pos]=container.alloc();
	container.cp(container.arr[pos],data);

	return 0;		
}

int getArray(stdArray container, int pos,void* data){
	if(pos<0 || pos>=container.n)return 1;
	container.cp(data,container.arr[pos]);

	return 0;
}
