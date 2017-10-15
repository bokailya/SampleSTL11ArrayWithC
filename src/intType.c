#include <stdlib.h>

void* allocInt(){
	return malloc(sizeof(int));
}

void putInt(void* to, void* from){
	*(int*)to=*(int*)from;
}

void freeInt(void* el){
	free(el);
}
