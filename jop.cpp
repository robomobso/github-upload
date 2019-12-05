////////////////////////////////////////////////////////////////////////////////
//
// compiling:
//
// g++ -o jop jop.cpp
// ./jop
//
// generate static library from the above compiled file:
// g++ -o jop jop.cpp
// ar rcs jop.a jop
// or
// g++ -o jop.o jop.cpp
// ./jlu10array.o
// ar rcs jop.a jop.o
//
// generate shared library from the complied objective file
// g++  -o jop.o -fPIC jop.cpp // position independent code
// g++ -shared jop.o -o jop.so 
// g++ -shared jop -o jop.so 
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#define CASE 4

#if CASE==1
////////////////////////////////////////////////////////////////////////////////
// dot and arrow operator: the dot operator is applied to the actual 
// object. The arrow operator is used with a pointer to an object. 

#include <iostream>
using namespace std;

struct Employee {
   char first_name[16];
   int  age;
}  emp;

class People {
   char first_name[16];
   int  age;
}  peo;

// 1. A class has all members private by default. A struct is a class
// where members are public by default.
// 2. Class can create a subclass that will inherit parent's
// properties and methods, whereas Structure does not support the
// inheritance. 

// To assign the value "zara" to the first_name member of object emp, you 
// would write something as follows −

strcpy(emp.first_name, "zara");


//If p_emp is a pointer to an object of type Employee, then to assign the 
// value "zara" to the first_name member of object emp, you would write 
// something as follows −

strcpy(p_emp->first_name, "zara");

//The -> is called the arrow operator. It is formed by using the minus sign
// followed by a greater than sign.

//Simply saying: To access members of a structure, use the dot operator.
// To access members of a structure through a pointer, use the arrow operator.
#endif

#if CASE == 2
//////////////////////////////////////////////////////////////////////////////
//
// 2.
//
int main()
{

	// it's just that, at post increment you get the value before 
        // you incremented and with pre-increment you get the value
	// after you incremented. pre-increment is a tiny little bit 
        // faster because you don't have to store the previous value
	int a = 5;
    	int b = ++a; // b = 6 | a = 6 --> a=a+1, b=a
    	int c = a++; // c = 6 | a = 7 --> c=a, a=a+1
	cout << ++a << endl; // a = 8 --> a = a+1

	int n = -1;
	int k = n++ * -3; // k = n * 3; n = n + 1;
	cout << ++n * 4 + k << endl; // n = n + 1; n * 4 + k

	// Remembering operator precedence rules, we can recall that 
        // postfix operators, such as increment and decrement, have
	// higher precedence than prefix operators, such as the dereference operator (*). 
	// Therefore, the following expression: *p++
	//

	int initarray[]={0,1,2,3,4};
	
	int N =5;
	int *p=initarray,*q=initarray,*r=initarray,*s=initarray,*t=initarray;

        for (int i=0; i<N; i++)
		cout<<"*p++ = "<<*p++<<", ";
	cout<<endl;

	//
	// is equivalent to *(p++). And what it does is to increase the value 
        // of p (so it now points to the next element), but
	// because ++ is used as postfix, the whole expression is evaluated 
        // as the value pointed originally by the pointer (the
	// address it pointed to before being incremented).

	// Essentially, these are the four possible combinations of the 
        // dereference operator with both the prefix and suffix
	// versions of the increment operator (the same being applicable also to the decrement operator):
	//
	// *p++   - same as *(p++): increment pointer, and dereference unincremented address
	// *++p   - same as *(++p): increment pointer, and dereference incremented address
	// ++*p   - same as ++(*p): dereference pointer, and increment the value it points to
	// (*p)++ - dereference pointer, and post-increment the value it points to 

        for (int i=0; i<N; i++)
		cout<<"*q++ = "<<*q++<<", "; // *q, q=q+1 --> print *q
	cout<<endl;
   	
	for (int i=0; i<N; i++)
		cout<<"++*r = "<<++*r<<", "; // *r, *r=*r+1 --> print *r
	cout<<endl;

   	for (int i=0; i<N; i++)
		cout<<"*++s = "<<*++s<<", "; // s = s + 1; *s --> print *s
	cout<<endl;

   	for (int i=0; i<N; i++)
		cout<<"(*t)++ = "<<(*t)++<<", "; // *t = *t + 1; --> print *t
	cout<<endl;

	// A typical -but not so simple- statement involving these operators is:
	// 	
	//	*p++ = *q++;
	//
	// Because ++ has a higher precedence than *, both p and q are incremented, 
        // but because both increment operators (++)
	// are used as postfix and not prefix, the value assigned to *p is *q before 
        // both p and q are incremented. And then 
	// both are incremented. It would be roughly equivalent to:
	//
	//	*p = *q;
	//	++p;
	//	++q;
	
	// Pointers and const
	//
	// Pointers can be used to access a variable by its address, and 
        // this access may include modifying the value pointed.
	// But it is also possible to declare pointers that can access 
        // the pointed value to read it, but not to modify it. For
	// this, it is enough with qualifying the type pointed to by 
        // the pointer as const. For example:
	//	int x;
	//	int y = 10;
	//	const int * p = &y;
	//	x = *p;          // ok: reading p
	//	*p = x;          // error: modifying p, which is const-qualified 
	// Here p points to a variable, but points to it in a const-qualified
        // manner, meaning that it can read the value
	// pointed, but it cannot modify it. Note also, that the expression 
        // &y is of type int*, but this is assigned to a
	// pointer of type const int*. This is allowed: a pointer to 
        // non-const can be implicitly converted to a pointer to
	// const. But not the other way around! As a safety feature,
        // pointers to const are not implicitly convertible to
	// pointers to non-const. One of the use cases of pointers to
        // const elements is as function parameters: a function that
	// takes a pointer to non-const as parameter can modify the 
        // value passed as argument, while a function that takes a
	// pointer to const as parameter cannot.
	
	// Pointers to functions
	// C++ allows operations with pointers to functions. The typical
        // use of this is for passing a function as an argument to
	// another function. Pointers to functions are declared with 
        // the same syntax as a regular function declaration, except
	// that the name of the function is enclosed between parentheses 
        // () and an asterisk (*) is inserted before the name:
	/*
	// pointer to functions
int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
  g = (*functocall)(x,y);
  return (g);
}

int main ()
{
  int m,n;
  int (*minus)(int,int) = subtraction;

  m = operation (7, 5, addition);
  n = operation (20, m, minus);
  cout <<n;
  return 0;
}
	*/

	// In the example above, minus is a pointer to a function that has two parameters of type int. It is directly 	
	// initialized to point to the function subtraction:
	// int (* minus)(int,int) = subtraction;

	// Pointers to pointers
	// C++ allows the use of pointers that point to pointers, that these, in its turn, point to data (or even to other

/*	// pointers). The syntax simply requires an asterisk (*) for each level of indirection in the declaration of the pointer:
char a;
char * b;
char ** c;
a = 'z';
b = &a;
c = &b;
*/
	return 0;
}
#endif

#if CASE==4
////////////////////////////////////////////////////////////////////////////////
//
// 4. mixed use of pre and post ops
//
main() 
{ 
    int x = 41, y = 43; 
    printf ("%d %d", x , y); cout <<'\n';
    x = y++ + x++; 
    printf ("%d %d", x , y); cout <<'\n';
    y = ++y + ++x; 
    printf ("%d %d", x , y); cout <<'\n';
    
    int x = 100, y = 200; 
    if ( ++x || ++y) 
        printf ("x = %d, y = %d", x, y); 
    else
        printf ("condition failed"); 

    int i = 0; 
    if (i = 55, 0, 10, 0) 
        printf ("Test Skills %d", i); 
    else
        printf ("C Programing %d", i); 

    int j; 
    for( i = 0, j = 5; j>0, i<10 ; i++, j--) 
        printf ("GeeksforGeeks.org"); 
    return 0; 
} 
#endif

