//	characters boolean checks:
//	------------------------------------------------------
	output 'H' < 'W';						//	Output: true
	output 'W' < 'H';						//	Output: false
	output 'H' < 'H';						//	Output: false

//	words boolean checks:
//	------------------------------------------------------
	output "Hello" < "World";				//	Output: true
	output "World" < "Hello";				//	Output: false
	output "Hello" < "Hello";				//	Output: false	

//	sentences boolean checks:
//	------------------------------------------------------
	output ^Hello World^ < ^World Hello^;	//	Output: true
	output ^World Hello^ < ^Hello World^;	//	Output: false
	output ^Hello World^ < ^Hello World^;	//	Output: false

//	numbers boolean checks:
//	------------------------------------------------------
	output 4 < 5;							//	Output: true
	output 5 < 5;							//	Output: false
	output 6 < 5;							//	Output: false