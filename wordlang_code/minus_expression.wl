output -10;
output -5;																						//	Output: -5
output -4 - 3;																					//	Output: -7
output ^We live in a wonderful world!^ - 'w';													//	Output: We live in a onderful world!
output ^We live in a wonderful world!^ - "wonderful" - 'w';										//	Output: We live in a  orld
output ^Hello World^ - "World" - 'l' - 'o' - 'W' - ' ' - 'e' - 'H' - 'l' - 'l';					//	Output: 
output ^Hello World^ - 'l' - 'd' - 'o' - 'W' - ' ' - 'e' - 'H' - 'l' - 'l' - '';				//	Output: or
output "HelloWorld" - "World";																//	Error: Invalid operation on types word - word
// output 14 - '1';																			//	Error: Invalid operation on types int - char
// output ^Hello World^ - ^World^;															//	Error: Invalid operation on types sentence - sentence