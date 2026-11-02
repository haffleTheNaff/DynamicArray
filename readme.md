
# My own implementation of Tsoding's Dynamic Array System
For use in C and C++ Projects 
(Although the utility in C++ is pretty questionable as Dynamic Arrays and Templates are a standard part of C++)

## Functions


#### da_define
- **type** : The Type of Data to be stored 

	Defines a new dynamic array struct for use in the various macros. *Only needs to be done once!*

#### da_append
- **xs** : A Dynamic Array of Type T
- **v** : A Value of type T

	Appends a value to the end of a Dynamic Array, may trigger reallocation

#### da_reserve
- **xs** : A Dynamic Array of Type T
- **cap_req** : The maximum amount of memory allocated, exceeding will trigger reallocation

	Reserves a chunk of memory for the Dynamic Array

#### da_extend
- **xs** : A Dynamic Array of Type T
- **ys** : A Second Array of Type T

	 Extends a Dynamic Array by an Array of Fixed Size.

#### da_extend_len
- **xs** : A Dynamic Array of Type T
- **ys** : A Second Array/Pointer of Type T
- **len** : The length of array **ys**

	 Extends a Dynamic Array by an Array/Pointer with a length supplied.

#### da_print
- **xs** : A Dynamic Array of Type T
- **fs** : The format specifier for values of Type T

	 Prints a standard representation of the Dynamic Array to the Console

#### da_swap
- **xs** : A Dynamic Array of Type T
- **x** : An Index into **xs**
- **y** : A Secondary Index into **xs**

	 Swaps two elements of the Dynamic Array, appends to the end for a temporary variable

#### da_pop
- **xs** : A Dynamic Array of Type T
- **x** : An Index into **xs**

	 Deletes an element of the Dynamic Array, shifting all after it back one.

#### da_repr
- **xs** : A Dynamic Array of Type T

	 An alias of da_print that is specifically for strings.
