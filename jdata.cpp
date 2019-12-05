////////////////////////////////////////////////////////////////////////////////
//
// VARIABLES 
//
// Including standard vector variable, pointer variables, array variables, etc.
//
// compiling:
// g++ -o jdata jdata.cpp
// ./jdata
//
// generate static library from the above compiled file:
// g++ -o jdata jdata.cpp
// ar rcs jdata.a jdata
// or
// g++ -o jdata.o jdata.cpp
// ./jdata.o
// ar rcs jdata.a jdata.o
//
// generate shared library from the complied objective file
// g++  -o jdata.o -fPIC jdata.cpp // position independent code
// g++ -shared jdata.o -o jdata.so 
// g++ -shared jdata -o jdata.so 
//
////////////////////////////////////////////////////////////////////////////////

//#include <fstream>
//#include <string>
//#include <ctime>
//#include <cstdlib>
//#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

#define CASE 2

#if CASE==1
////////////////////////////////////////////////////////////////////////////////
//
// 1. ASCII Chart
/*
dec 	oct 	hex 	ch 		        dec 	oct 	hex 	ch 	dec 	oct 	hex 	ch 	dec 	oct 	hex 	ch
0 	0 	00 	NUL (null) 	        32 	40 	20 	(space) 64 	100 	40 	@ 	96 	140 	60 	`
1 	1 	01 	SOH (start of header) 	33 	41 	21 	! 	65 	101 	41 	A 	97 	141 	61 	a
2 	2 	02 	STX (start of text) 	34 	42 	22 	" 	66 	102 	42 	B 	98 	142 	62 	b
3 	3 	03 	ETX (end of text) 	35 	43 	23 	# 	67 	103 	43 	C 	99 	143 	63 	c
4 	4 	04 	EOT (transmission end) 	36 	44 	24 	$ 	68 	104 	44 	D 	100 	144 	64 	d
5 	5 	05 	ENQ (enquiry) 	        37 	45 	25 	% 	69 	105 	45 	E 	101 	145 	65 	e
6 	6 	06 	ACK (acknowledge) 	38 	46 	26 	& 	70 	106 	46 	F 	102 	146 	66 	f
7 	7 	07 	BEL (bell) 	        39 	47 	27 	' 	71 	107 	47 	G 	103 	147 	67 	g
8 	10 	08 	BS (backspace) 	        40 	50 	28 	( 	72 	110 	48 	H 	104 	150 	68 	h
9 	11 	09 	HT (tab) 	        41 	51 	29 	) 	73 	111 	49 	I 	105 	151 	69 	i
10 	12 	0a 	LF (line feed new line) 42 	52 	2a 	* 	74 	112 	4a 	J 	106 	152 	6a 	j
11 	13 	0b 	VT (vertical tab) 	43 	53 	2b 	+ 	75 	113 	4b 	K 	107 	153 	6b 	k
12 	14 	0c 	FF (form feed new page) 44 	54 	2c 	, 	76 	114 	4c 	L 	108 	154 	6c 	l
13 	15 	0d 	CR (carriage return) 	45 	55 	2d 	- 	77 	115 	4d 	M 	109 	155 	6d 	m
14 	16 	0e 	SO (shift out) 	        46 	56 	2e 	. 	78 	116 	4e 	N 	110 	156 	6e 	n
15 	17 	0f 	SI (shift in) 	        47 	57 	2f 	/ 	79 	117 	4f 	O 	111 	157 	6f 	o
16 	20 	10 	DLE (data link escape) 	48 	60 	30 	0 	80 	120 	50 	P 	112 	160 	70 	p
17 	21 	11 	DC1 (device control 1) 	49 	61 	31 	1 	81 	121 	51 	Q 	113 	161 	71 	q
18 	22 	12 	DC2 (device control 2) 	50 	62 	32 	2 	82 	122 	52 	R 	114 	162 	72 	r
19 	23 	13 	DC3 (device control 3) 	51 	63 	33 	3 	83 	123 	53 	S 	115 	163 	73 	s
20 	24 	14 	DC4 (device control 4) 	52 	64 	34 	4 	84 	124 	54 	T 	116 	164 	74 	t
21 	25 	15 	NAK (negative acknowle) 53 	65 	35 	5 	85 	125 	55 	U 	117 	165 	75 	u
22 	26 	16 	SYN (synchronous idle) 	54 	66 	36 	6 	86 	126 	56 	V 	118 	166 	76 	v
23 	27 	17 	ETB (end trans block) 	55 	67 	37 	7 	87 	127 	57 	W 	119 	167 	77 	w
24 	30 	18 	CAN (cancel) 	        56 	70 	38 	8 	88 	130 	58 	X 	120 	170 	78 	x
25 	31 	19 	EM (end of medium) 	57 	71 	39 	9 	89 	131 	59 	Y 	121 	171 	79 	y
26 	32 	1a 	SUB (substitute) 	58 	72 	3a 	: 	90 	132 	5a 	Z 	122 	172 	7a 	z
27 	33 	1b 	ESC (escape) 	        59 	73 	3b 	; 	91 	133 	5b 	[ 	123 	173 	7b 	{
28 	34 	1c 	FS (file separator) 	60 	74 	3c 	< 	92 	134 	5c 	\ 	124 	174 	7c 	|
29 	35 	1d 	GS (group separator) 	61 	75 	3d 	= 	93 	135 	5d 	] 	125 	175 	7d 	}
30 	36 	1e 	RS (record separator) 	62 	76 	3e 	> 	94 	136 	5e 	^ 	126 	176 	7e 	~
31 	37 	1f 	US (unit separator) 	63 	77 	3f 	? 	95 	137 	5f 	_ 	127 	177 	7f 	DEL (delete)
*/
#include <stdio.h>
int main (void)
{
  char x = 'A';
  printf("'A' = %d", int(x));
  long long y = 'ab';
  printf("'ab' = %l", y);

}
#endif

#if CASE==2
////////////////////////////////////////////////////////////////////////////////
//
// 2. Runtime Format
/*
C-runtime Format Types:
d, i
Decimal or integer. The argument must be an integer value. The value is converted to a string of decimal digits. If the format string contains a precision specifier, it indicates that the resulting string must contain at least the specified number of digits; if the value has less digits, the resulting string is left-padded with zeros.

u
Unsigned int. Similar to "d" and "i", but it has no sign.

o
Octal. The argument must be an integer value. The value is converted to a string of octal digits. If the format string contains a precision specifier, it indicates that the resulting string must contain at least the specified number of digits; if the value has less digits, the resulting string is left-padded with zeros.

x,X
Hexadecimal. The argument must be an integer value. The value is converted to a string of decimal digits. If the format string contains a precision specifier, it indicates that the resulting string must contain at least the specified number of digits; if the value has less digits, the resulting string is left-padded with zeros.

f
Floating point. The argument must be a floating-point value. The value is converted to a string of the form "-ddd.ddd...". The resulting string starts with a minus sign if the number is negative. The number of digits after the decimal point is given by the precision specifier in the format string; a default of 2 decimal digits is assumed if no precision specifier is present.

e
Scientific. The argument must be a floating-point value. The value is converted to a string of the form "-d.ddd...E+ddd". The resulting string starts with a minus sign if the number is negative. One digit always precedes the decimal point. The total number of digits in the resulting string (including the one before the decimal point) is given by the precision specifier in the format string; a default precision of 15 is assumed if no precision specifier is present. The "E" exponent character in the resulting string is always followed by a plus or minus sign and at least 3 digits.

g
Double. The argument must be a floating-point value. The value is converted to the shortest possible decimal string using fixed or scientific format. The number of significant digits in the resulting string is given by the precision specifier in the format string; a default precision of 15 is assumed if no precision specifier is present. Trailing zeros are removed from the resulting string, and a decimal point appears only if necessary. The resulting string uses fixed point format if the number of digits to the left of the decimal point in the value is less than or equal to the specified precision, and if the value is greater than or equal to 0.00001. Otherwise the resulting string uses scientific format.

c
Character. The argument must be a single character value.

s
String. The argument must be a character, a string, or a char* value. The string or character is inserted in place of the format specifier. The precision specifier, if present in the format string, specifies the maximum length of the resulting string. If the argument is a string that is longer than this maximum, the string is truncated.

n
Pointer to int. Stores (in the location pointed to by the input argument) a count of the chars written so far.

p
Pointer. Prints the input argument as a pointer; format depends on which memory model was used. It will be either XXXX:YYYY or YYYY (offset only).
*/
#include <iostream> 
#include <ctime>
#include <cstdlib>
int main (void)
{
 printf("1.0/3.0 = %f\n", 1.0/3.0); //0.333333
 printf("1.0/3.0 = %-5.1f\n", 1.0/3.0); //0.3
 printf("1.0/3.0 = %5.1f\n", 1.0/3.0);  //  0.3--Two white spaces at the start
 printf("'a' = %c\n",'a');
 printf(" \"string\" = %s\n","string");
 printf("%%f is : %f\n", 1.0/3.0); //0.333333
 printf("%%lf is : %lf\n", 5000000000000000.0/2.3); //A big number
 printf("15 = %x\n", 15); //f
 printf("15 = %X\n", 15); //F
 printf("-5 = %d\n", -5); //-5
 printf("-5 = %i\n", -5); //-5
 printf("5 = %u\n", 5); //5
 printf("9 = %o\n", 9); //11
 int x=3;
 int y=x*5; // y is int, but it equals to a flot x*3.5
 cout <<"int y=x*5 leads to "<< y << endl;
 int z=x*4.1; 
 cout<<"int z=x*3.5 leads to "<< z << endl;
 cout<< "5*0.7 = " << 5*0.7 << endl;
 cout<< "static_cast<int>(5*0.7) = " << static_cast<int>(5*0.7) <<endl;
 
 // rand() function <-- must used with srand(time(0))
 srand(time(0)); 
 int dice = 1 + rand()%6;
 cout << "dice = " << dice << endl;
 
 
}
#endif

#if CASE==3
////////////////////////////////////////////////////////////////////////////////
//
// 3. Data Type
/*
DATA TYPE	        SIZE(BYTES)	RANGE
--------------------------------------------------------------------------------
bool 
signed char	        1	        -128 to 127
unsigned char	        1	        0 to 255
char
wchar_t	                2 or 4	        1 wide character

short int	        2	        -32,768 to 32,767
signed short int        2	        -32,768 to 32,767
unsigned short int	2	        0 to 65,535

int	                4	        -2,147,483,648 to 2,147,483,647
signed int	        4	        -2,147,483,648 to 2,147,483,647
unsigned int	        4	        0 to 4,294,967,295

long int	        4	        -2,147,483,648 to 2,147,483,647
signed long int	        4	        -2,147,483,648 to 2,147,483,647
unsigned long int	4	        0 to 4,294,967,295

long long int	        8	        -(2^63) to (2^63)-1
unsigned long long int	8	        0 to 18,446,744,073,709,551,615

float	                4

double	                8	
long double	        16	
--------------------------------------------------------------------------------*/
// C++ code to demonstrate the macros for data types 
#include<limits.h> // for int,char macros 
#include<float.h> // for float,double macros 
using namespace std; 
int main() 
{ 
    cout << "char: " << sizeof(char) << " byte: " << CHAR_MIN << " to " << CHAR_MAX<<endl; 
      
    cout << "signed char: " << sizeof(signed char) << " byte: " << CHAR_MIN << " to " << CHAR_MAX<<endl; 
    
    cout << "unsigned char: " << sizeof(unsigned char) << " byte: " << 0 << " to " << UCHAR_MAX << endl;
    
    cout << "Size of wchar_t: " << sizeof(wchar_t)  << " bytes" <<endl; 
     
    cout << "short int: " << sizeof(short int)  << " byte: "  << SHRT_MIN << " to " << SHRT_MAX << endl; 
    
    cout << "signed short int: " << sizeof(signed short int)  << " byte: " << SHRT_MIN << " to " << SHRT_MAX << endl;
        
    cout << "unsigned short int: " << sizeof(unsigned short int)  << " byte: " << 0 << " to " << USHRT_MAX << endl; 
       
    cout << "int: " << sizeof(int)  << " bytes:  " << INT_MIN << " to " << INT_MAX << endl;
    
    cout << "signed int:" << sizeof(signed int)  << " bytes: " << INT_MIN << " to " << INT_MAX << endl;
    
    cout << "unsigned int : " << sizeof(unsigned int)  << " bytes " << 0 << " to " << UINT_MAX << endl;
         
    cout << "long int: " << sizeof(long int)  << " bytes: " << LONG_MIN << " to " << LONG_MAX << endl; 
    
    cout << "Size of signed long int : " << sizeof(signed long int) << " bytes: " << LONG_MIN << " to " << LONG_MAX << endl;  
    
    cout << "Size of unsigned long int : " << sizeof(unsigned long int)  << " bytes" << endl; 
    
    cout << "float : " << sizeof(float)  << " bytes " << FLT_MIN << " to " << FLT_MAX <<endl; 
    
    cout << "long long int : " << sizeof(long long int)  << " bytes " << LLONG_MIN << " to " << LLONG_MAX << endl; 
    
    cout << "Size of signed long long int : " << sizeof(signed long long int)  << " bytes" << endl; 
    
    cout << "unsigned long long int : " << sizeof(unsigned long long int)  << " bytes " << 0 << " to " << ULLONG_MAX<< endl; 
      
    cout << "double : " << sizeof(double)  << " bytes " << DBL_MIN << " to " << +DBL_MAX << endl; 
    
    cout << "Size of long double : " << sizeof(long double)  << " bytes" << endl; 

    return 0; 
} 
#endif
