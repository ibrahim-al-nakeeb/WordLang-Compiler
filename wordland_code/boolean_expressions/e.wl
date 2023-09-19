//	characters boolean checks:
//	------------------------------------------------------
	output 'H' == 'H';						//	Output: true
	output 'H' == 'W';						//	Output: false
	output 'W' == 'H';						//	Output: false

//	words boolean checks:
//	------------------------------------------------------
	output "Hello" == "Hello";				//	Output: true
	output "Hello" == "World";				//	Output: false
	output "World" == "Hello";				//	Output: false

//	sentences boolean checks:
//	------------------------------------------------------
	output ^Hello World^ == ^Hello World^;	//	Output: true
	output ^Hello World^ == ^World Hello^;	//	Output: false
	output ^World Hello^ == ^Hello World^;	//	Output: false

//	numbers boolean checks:
//	------------------------------------------------------
	output 5 == 5;							//	Output: true
	output 5 == 4;							//	Output: false
	output 4 == 5;							//	Output: false