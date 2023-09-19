//	characters boolean checks:
//	------------------------------------------------------
	output !'H' == 'W';						//	Output: true
	output !'W' == 'H';						//	Output: true
	output !'H' == 'H';						//	Output: false

//	words boolean checks:
//	------------------------------------------------------
	output !"Hello" == "World";				//	Output: true
	output !"World" == "Hello";				//	Output: true
	output !"Hello" == "Hello";				//	Output: false

//	sentences boolean checks:
//	------------------------------------------------------
	output !^Hello World^ == ^World Hello^;	//	Output: true
	output !^World Hello^ == ^Hello World^;	//	Output: true
	output !^Hello World^ == ^Hello World^;	//	Output: false

//	numbers boolean checks:
//	------------------------------------------------------
	output !5 == 6;							//	Output: true
	output !6 == 5;							//	Output: true
	output !5 == 5;							//	Output: false