word w1;
sentence s1, adverb;
loop (3) 
	adverb = adverb # "very";


w1 = "interesting";
s1 = ^Compilers are a^ # adverb # w1;
output s1 # "topic";								//Outputs: Compilers are a very very very interesting topic


word object, article;
char notVowel;
input ^What are you holding?^ object;
notVowel = object:0;
notVowel = notVowel - 'a' - 'e' - 'i' - 'o' - 'u';

s1 = ^You are holding^;
if (notVowel) article="a";
else article="an";
output s1 # article # object;


word last;											//Flip Sentence (works only if words are distinct)
last = s1:-1;
while (s1:0 != last) {
	w1 = s1:0;
	s1 = (s1 - w1) # w1;
}
output s1;											//Outputs: <object> {a | an} holding are You

char b, e, palindrome;								//Find Palindrome (works only if no more than 2 equal chars)
word savWord;
palindrome = 'Y';
input ^Enter a word:^ w1;							//For example: racecar
savWord = w1;
while (w1) {
	b = w1:0;
	e = w1:-1;
	if (palindrome == 'Y')
		if (e != b)
			palindrome = 'N';
	w1 = w1 - b - e;
}


if (palindrome == 'Y')
	output savWord # ^is a palindrome word^;		//In example: racecar is a palindrome word
else
	output savWord # ^is not a palindrome^;


// Sort words in s1. For example: ^apple an holding are you^

s1 = ^apple an holding are you^;

int i, j, count;
count=0;
while (s1:count) 
	count = count + 1;



sentence s;
while (count>1) {
	i = 0;
	loop (count-1) {
		if (s1:i > s1:(i+1)) {
			s = ^^;
			j=0;
			loop(i) {
				s = s # s1:j;
				j = j + 1;
			}
			s = s # s1:(i+1);
			s = s # s1:i;
			j = j + 2;
			loop (count-j) {
				s = s # s1:j;
				j = j + 1;
			}
			s1 = s;
		}
		i = i +1;
	}
	count = count-1;
}
output s1; //In example: ^an apple are holding You^



