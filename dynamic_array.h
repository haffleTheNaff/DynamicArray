


#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY 

/*
Defines Dynamic Arrays for use in other code

Invoke the da_define macro with a type of your choice to initialise a struct type for later use

Includes:
	da_define	: Defines a new dynamic array struct for use in the various macros
	da_append	: Appends a value to the end of a Dynamic Array
	da_reserve	: Reserves a chunk of memory for the Dynamic Array
	da_extend	: Extends a Dynamic Array by an Array of Fixed Size.
	and others
*/

#include <stdio.h>
#include <stdlib.h>

#define a_len(xs) sizeof(xs)/sizeof(xs[0])

#define scope(expr) do {expr} while(0)

//Defines a new dynamic array struct for use in the various macros
#define da_define(type) typedef struct da_##type {\
	type* items;\
	size_t count;\
	size_t capacity;\
} da_##type

//Appends a value to the end of a Dynamic Array, may trigger reallocation
#define da_append(xs,x) do {\
	if (xs.count >= xs.capacity) {\
		if (xs.capacity == 0) {xs.capacity = 256;}\
		else {xs.capacity *= 2;}\
		xs.items = realloc(xs.items,sizeof(xs.items[0]) * xs.capacity);\
	}\
	xs.items[xs.count] = x;\
	xs.count ++;\
} while(0)

//Reserves a chunk of memory for the Dynamic Array
#define da_reserve(xs,cap_req) scope(\
	if (xs.capacity >= cap_req) {break;}\
	xs.capacity = cap_req;\
	xs.items = realloc(xs.items,sizeof(xs.items[0]) * xs.capacity);\
)

// Extends a Dynamic Array by an Array of Fixed Size.
#define da_extend(xs,ys) do {\
	da_extend_len(xs,ys,a_len(ys));\
} while (0)

// Extends a Dynamic Array by an Array/Pointer with a length supplied.
#define da_extend_len(xs,ys,len) do {\
for (size_t y = 0; y < len; ++y) {\
	da_append(xs,ys[y]);\
}} while (0)

// Prints a standard representation of the Dynamic Array to the Console
#define da_print(xs,fs) do {\
		printf("[");\
		for (size_t x = 0; x < xs.count; ++x) {\
			printf(fs",",xs.items[x]);\
		}\
		printf("]\n");\
	} while(0)

// Swaps two elements of the Dynamic Array, appends to the end for a temporary variable
#define da_swap(xs,x,y) do {\
		da_append(xs,xs.items[x]);\
		xs.items[x] = xs.items[y];\
		xs.items[y] = xs.items[xs.count-1];\
		--xs.count;\
	} while(0)

// Deletes an element of the Dynamic Array, shifting all after it back one.
#define da_pop(xs,x) do {\
		for (size_t y = x + 1; y < xs.count; ++y) {\
			xs.items[y - 1] = xs.items[y];\
		}\
		--xs.count;\
	} while(0)

// An alias of da_print that is specifically for strings.
#define da_repr(xs) scope(\
	for (size_t x = 0; x < xs.count; ++x) {\
		printf("%c",xs.items[x]);\
	}\
)
#endif