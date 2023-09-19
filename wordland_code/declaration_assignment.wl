int _i1, a2345678923456789234567891234567, i3_3;
word w1, w2, w3;
sentence s1, s2;
// sentence s1;								//	Error: Variable s1 already exists in the symbol table
char c1, c2, c3, c4;

_i1 = 5;
a2345678923456789234567891234567 = 10;
i3_3 = _i1;
c1 = '4';
c2 = 'c';
w1 = "hello";
w2 = "world";
s1 = ^hello world!^;
s2 = ^Whats up^;

output _i1;										//	Output: 5
output a2345678923456789234567891234567;		//	Output: 10
output i3_3;									//	Output: 5
output c1;										//	Output: 4
output c2;										//	Output: c
output w1;										//	Output: hello
output w2;										//	Output: world
output s1;										//	Output: hello world!\n
output s2;										//	Output: Whats up\n
// output s6;									//	Error: Variable s6 not declared