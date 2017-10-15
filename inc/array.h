#ifndef __ARRAY__
#define __ARRAY__

typedef void* (*allocator)();
typedef void (*copy)(void*,void*);
typedef void (*freeLocal)(void*);

typedef struct {
	int n;
	void** arr;
	allocator alloc;
	copy cp;
	freeLocal clean;
} stdArray;

void assertArray(int error);


stdArray createArray(int n,allocator alloc,copy cp,freeLocal clean);
void freeArray(stdArray f);
int setArray(stdArray container,int pos,void* data);
int getArray(stdArray container, int pos,void* data);

#endif
