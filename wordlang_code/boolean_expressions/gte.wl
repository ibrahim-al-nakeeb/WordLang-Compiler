//	characters boolean checks:
//	------------------------------------------------------
	output 'W' >= 'H';						//	Output: true
	output 'H' >= 'H';						//	Output: true
	output 'H' >= 'W';						//	Output: false

//	words boolean checks:
//	------------------------------------------------------
	output "World" >= "Hello";				//	Output: true
	output "Hello" >= "Hello";				//	Output: true
	output "Hello" >= "World";				//	Output: false

//	sentences boolean checks:
//	------------------------------------------------------
	output ^World Hello^ >= ^Hello World^;	//	Output: true
	output ^Hello World^ >= ^Hello World^;	//	Output: true
	output ^Hello World^ >= ^World Hello^;	//	Output: false

//	numbers boolean checks:
//	------------------------------------------------------
	output 5 >= 5;							//	Output: true
	output 5 >= 4;							//	Output: true
	output 5 >= 6;							//	Output: false