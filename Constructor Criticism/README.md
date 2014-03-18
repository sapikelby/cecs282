Lab 4 – Constructor Criticism 
Construct: 1.5+2i 	// line 9
Construct: -3+4i	// line 10

Copy construct: -3+4i		// line 16
Construct: 5+5i	// line 17 ( “newed” object goes on the heap and not the stack)
Conjugate	// Conjugate function called at line 19
Construct: -3-4i 	// return Complex value from Conjugate function
The conjugate of -3+4i is -3-4i	// line 18 and 19
Destruct: -3-4i  //out scope due to curly braces-Complex return value of conjugate fn. destructed)
Destruct: -3+4i // Destructor executes again (destroys local c3 object after it goes out of scope)

Copy construct: -3+4i		// line 23
Mutate -3+4i to 10+4i		// line 24
Copy construct: 10+4i		// line 25

Operator = 10+4i ==> -3+4i	// line 28 (Operator overloading)
Conjugate	// line 29 - Conjugate function called
Construct: -3-4i	// line 29 (Conjugate return value invokes constructor)
Operator = -3+4i ==> -3-4i	// line 29 (Operator = overloading)
Destruct: -3-4i		// Destructor pops Conjugate function return value

Construct: -3-4i	// line 32
Copy construct: -3-4i 		// Copy constructor is called	
1			// line 33 – returns 1 or true since c3 and copy1 are equal
Destruct: -3-4i		// main ends and c3 is popped off the stack

Destruct: -3-4i 	// main ends and all objects that went on the stack go out of scope 
Destruct: 10+4i	// and get popped off 
Destruct: -3-4i
Destruct: -3+4i
Destruct: 1.5+2i
Press any key to continue . . .

// memory is freed for “newed” object in the heap after program ends

2.) Line 17 – Constructing cPtr = new Complex(5,5)
The object is constructed using the keyword “new” which means that it will not go on the stack. Instead memory is allocated for in the heap. For that reason, it is not destroyed when cPtr goes out of scope in line 20 since the keyword “delete” has not been used to delete it from memory. This object stays in memory until the program ends. 


