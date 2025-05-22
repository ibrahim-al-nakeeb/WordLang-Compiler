// Concatenate: concatenate characters to form a word; concatenate words to form a sentence
// <lval> # <rval> -> Concatenate <lval> and <rval>. Result in the higher level
// Examples:

	output 'H' # 'W';			//	Output: HW			//		char + char 	= word
	output "Hello" # "World";	//	Output: HelloWorld	//		word + word 	= word
	output 'H' # "World";		//	Output: HWorld		//		char + word 	= word
	output "Hello" # 'W';		//	Output: HelloW		//		word + char 	= word
	output ' ' # 'W';			//	Output:  W			//		char + char 	= sentence
	output 'H' # ' ';			//	Output: H 			//		char + char 	= sentence
	output ' ' # ' ';			//	Output:   			//		char + char 	= sentence
	output ' ' # "World";		//	Output:  World		//		char + word 	= sentence
	output "Hello" # ' ';		//	Output: Hello 		//		word + char 	= sentence
	output 'H' # ^World^;		//	Output: HWorld		//		char + sentence = sentence
	output "Hello" # ^World^;	//	Output: Hello World	//		word + sentence = sentence
	output ^Hello^ # 'W';		//	Output: HelloW		//	sentence + char 	= sentence
	output ^Hello^ # "World";	//	Output: Hello World	//	sentence + word 	= sentence

	output 'H' # ' ' # 'O';		//	Output: H O
	output 'H' # ' ' # "O";		//	Output: H  O
	output "H" # ' ' # 'O';		//	Output: H O
	output "H" # ' ' # "O";		//	Output: H  O
	output ^Hello^ # '' # "World";	//	Output: Hello World