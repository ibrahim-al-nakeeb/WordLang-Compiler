	output ("Hello" # "World") : 1;		// Output: e
	output ("Hello" # "World") : -1;	// Output: d
	output ("Hello" # "World") : 7;		// Output: r
	
	output (^Hello^ # "World") : 0;		// Output: Hello
	output (^Hello^ # "World") : 1;		// Output: World
	output (^Hello^ # "World") : 2;		// Output: 
	
	output ("Hello" # ^World^) : 0;		// Output: Hello
	output ("Hello" # ^World^) : 1;		// Output: World
	output ("Hello" # ^World^) : 2;		// Output: 