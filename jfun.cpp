////////////////////////////////////////////////////////////////////////////////
//
// compiling:
//
// g++ -o jfun jfun.cpp
// ./jfun
//
// generate static library from the above compiled file:
// g++ -o jfun jfun.cpp
// ar rcs jfun.a jfun
// or
// g++ -o jfun.o jfun.cpp
// ./jlu10array.o
// ar rcs jfun.a jfun.o
//
// generate shared library from the complied objective file
// g++  -o jfun.o -fPIC jfun.cpp // position independent code
// g++ -shared jfun.o -o jfun.so 
// g++ -shared jfun -o jfun.so 
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
// C++ Functions Summary:
//
// - built-in or system supported functions, e.g., sqr(), 
// - user defined functions
//
// This code example focuses on user-defined functions.
//
// Types of user-defined functions:
// - Function with no arguments and no return value  0 0 
// - Function with no arguments and a return value   0 1
// - Function with arguments and no return value     1 0
// - Function with arguments and a return value      1 1
//
// Types of user-defined functions with arguments
// - Call by value
// - Call by poiter
// - Call by reference
//
// Types of user-define functions with return value
// - Return by value
// - Return by pointer
// - Return by reference
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#define CASE 14

#if CASE == 0
///////////////////////////////////////////////////////////////////////////////
//
// 0. Library Functions
//    Built-in Function
//    System Supported Functions
//
// They are all the same and just different names
// Those functions might be collected in different libraries:
// abs() - <cstdlib>
// getline()
// ceil() - <cmath>
// cos()
// exp()
// fabs()
// floor()
// pow(x,y)
// sqr()
// tolower() - <cctype>
// toupper()
#endif

#if CASE == 1
/////////////////////////////////////////////////////////////////////////////
// 
// 1. Inline Function 
//
// C++ provides an inline functions to reduce the function call overhead. 
// Inline function is a function that is expanded in line when it is called. 
// When the inline function is called whole code of the inline function gets 
// inserted or substituted at the point of inline function call. This substitution
// is performed by the C++ compiler at compile time. Inline function may increase 
// efficiency if it is small. The syntax for defining the function inline is:
//inline return-type function-name(parameters)
//{
//    // function code
//}  
//Compiler may not perform inlining in such circumstances like:
//1) If a function contains a loop. (for, while, do-while)
//2) If a function contains static variables.
//3) If a function is recursive.
//4) If a function return type is other than void, and the return statement 
//doesn’t exist in function body.
//5) If a function contains switch or goto statement.
//
// It is also possible to define the inline function inside the class. In fact, all the
// functions defined inside the class are implicitly inline. Thus, all the restrictions of
// inline functions are also applied here. If you need to explicitly declare inline function
// in the class then just declare the function inside the class and define it outside the 
// class using inline keyword.
// 
// - It can be defined inside or outside the class.
// - It evaluates the argument only once.
// - The short functions, defined inside the class are automatically made onto 
//   inline functions.
// - An inline member function can access the data members of the class.
// - Debugging is easy for an inline function as error checking is done during compilation.
//
class operation 
{ 
    int a,b,add,sub,mul; 
    float div; 
public: 
    void get(); 
    void sum(); 
    void difference(); 
    void product(); 
    void division(); 
}; 
inline void operation :: get() 
{ 
    cout << "Enter first value:"; 
    cin >> a; 
    cout << "Enter second value:"; 
    cin >> b; 
} 
inline void operation :: sum() 
{ 
    add = a+b; 
    cout << "Addition of two numbers: " << a+b << "\n"; 
} 
inline void operation :: difference() 
{ 
    sub = a-b; 
    cout << "Difference of two numbers: " << a-b << "\n"; 
} 
inline void operation :: product() 
{ 
    mul = a*b; 
    cout << "Product of two numbers: " << a*b << "\n"; 
} 
inline void operation ::division() 
{ 
    div=a/b; 
    cout<<"Division of two numbers: "<<a/b<<"\n" ; 
} 
  
int main() 
{ 
    cout << "Program using inline function\n"; 
    operation s; 
    s.get(); 
    s.sum(); 
    s.difference(); 
    s.product(); 
    s.division(); 
    return 0; 
}
#endif

#if CASE == 2
//////////////////////////////////////////////////////////////////////////////
// 
// 2. Macro Function
//
// Macro is a “preprocessors directive”. Before compilation, the program is 
// examined by the preprocessor and where ever it finds the macro in the program, 
// it replaces that macro by its definition. Hence, the macro is considered as 
// the “text replacement”.
//
// - Debugging becomes difficult for macros as error checking does not occur 
//   during compilation.
// - Macros can never be the members of the class and can not access the data 
//   members of the class.
// - Macros are expanded by the preprocessor and are always expanded.
// - It is always defined at the start of the program.
// - It evaluates the argument each time it is used in the code.
// - Definition of macro terminates with the new line. Hence it faces the binding 
//   problem if it has more than one statement, as it has no termination symbol.
//
#define max(a, b) ((a < b) ? b : a)
int main( void)
{
  cout << "Greater of 10 and 20 is " << max("20", "10") << "\n";
    return 0;
}

#endif

#if CASE == 3
//////////////////////////////////////////////////////////////////////////////
// 
// 3. Function Prototype
//
// The prototype of a function can be declared without actually defining the 
// function completely, giving just enough details to allow the types involved 
// in a function call to be known. Naturally, the function shall be defined 
// somewhere else, like later in the code. But at least, once declared like this, 
// it can already be calledefine function before it is called. you can define it
// later, but you need to use funtion profile 
//
void odd (int x); // function prototype
void even (int x); // function prototype
 
int main()
{
  int i;
  do {
    cout << "Please, enter number (0 to exit): ";
    cin >> i;
    odd (i);
  } while (i!=0);
  return 0;
}

void odd (int x)
{
  if ((x%2)!=0) cout << "It is odd.\n";
  else even (x);
}

void even (int x)
{
  if ((x%2)==0) cout << "It is even.\n";
  else odd (x);
}
#endif

#if CASE == 4
///////////////////////////////////////////////////////////////////////////////
// 
// 4. Function Type Based on Arguments
//
//    Different functions based on different argument-passing methods
//    or Different functions based on different calling methods
//
// - Call by Value: copies the actual value of an argument into the formal 
//   parameter of the function. Changes made to the parameter 
//   inside the function have no effect on the argument. 
// - Call by Pointer: copies the address of an argument into the formal parameter. 
//   Inside the function, the address is used to access the actual argument 
//   used in the call. Changes made to the parameter affect the argument.
// - Call by Reference: copies the reference of an argument into the formal parameter. 
//   Inside the function, the reference is used to access the actual argument used 
//   in the call. Changes made to the parameter affect the argument.
//
void swap_pbv(int x, int y) // calling or passing by value
{ 
    int z = x; 
    x = y; // put y into x
    y = z; // put z into y

    return;
}
//there is no change in the values though they had been changed inside the function.
  
void swap_pbp(int* x, int* y) // calling or passing by pointer
{ 
    int z = *x; 
    *x = *y; 
    *y = z; 
} 
  
void swap_pbr(int& x, int& y) // calling or passing by reference
{ 
    int z = x; 
    x = y; 
    y = z; 
} 

int f_pbvr(int &x, int c) {
   c  = c - 1;
   if (c == 0) return 1;
   x = x + 1;
   return f_pbvr(x, c) * x;
} 

int main() 
{ 
    int i = 2;
    int a = 45, b = 35; 
    cout << "Before Swap\n"; 
    cout << "a = " << a << " b = " << b << "\n"; 
    swap_pbv(a,b);
    cout << "After Swap with pass by value\n"; 
    cout << "a = " << a << " b = " << b << "\n"; 

    cout << "Before Swap\n"; 
    cout << "a = " << a << " b = " << b << "\n"; 
    swap_pbp(&a, &b); 
    cout << "After Swap with pass by pointer\n"; 
    cout << "a = " << a << " b = " << b << "\n"; 

    cout << "Before Swap\n"; 
    cout << "a = " << a << " b = " << b << "\n"; 
    swap_pbr(a, b); 
    cout << "After Swap with pass by reference\n"; 
    cout << "a = " << a << " b = " << b << "\n"; 

    cout << "f_bpvr(i,i) = "<< f_pbvr(i,i) << "\n";

} 
#endif

#if CASE == 5
//////////////////////////////////////////////////////////////////////////////////
//
// 5. Function Type Based on Returning: 
//
//    functions with returning by values
//
// - Returning as Value
// - Returning as Pointer
// - Returning as Reference
//
//
int sum(); 
int main() 
{ 
    int num; 
    num = sum(); 
    printf("\nSum of two given values = %d", num); 
    return 0; 
} 
  
int sum() 
{ 
    int a = 50, b = 80, sum; 
    sum = sqrt(a) + sqrt(b); 
    return sum; 
} 
#endif

#if CASE == 6
//////////////////////////////////////////////////////////////////////////////////
//
// 6. Function Type Based on Returning: 
//
//    functions with returning by pointer
//
// - Returning as Value
// - Returning as Pointer
// - Returning as Reference
//
// function to generate and retrun random numbers.
#include <stdio.h>      //printf, NULL
#include <stdlib.h>     //srand, rand
#include <time.h>  
int * getrandom( ) {
   static int  r[10];
   // set the seed
   srand((unsigned)time(NULL)); // initialize random number generator
                                    // The pseudo-random number generator is 
                                    // initialized using the argument passed as
                                    // seed.
                                    // 1. For every different seed value used in a 
                                    // call to srand, the pseudo-random number 
                                    // generator can be expected to generate a 
                                    // different succession of results in the 
                                    // subsequent calls to rand.
                                    // 2. Two different initializations with the 
                                    // same seed will generate the same succession 
                                    // of results in subsequent calls to rand.
                                    // 3. If seed is set to 1, the generator is 
                                    // reinitialized to its initial value and 
                                    // produces the same values as before any 
                                    // call to rand or srand.
                                    // 3. In order to generate random-like numbers, 
                                    // srand is usually initialized to some distinctive 
                                    // runtime value, like the value returned by 
                                    // function time (declared in header <ctime>). 
                                    // This is distinctive enough for most trivial 
                                    // randomization needs.
   for (int i = 0; i < 10; ++i) {
      r[i] = rand(); // rand uses the seed setup by the srand function call
      cout << r[i] << endl;
   }
   return r;
}
 
// main function to call above defined function.
int main () {
   // a pointer to an int.
   int *p;
   p = getrandom();
   for ( int i = 0; i < 10; i++ ) {
      cout << "*(p + " << i << ") : ";
      cout << *(p + i) << endl;
   }
   return 0;
}
#endif

#if CASE == 7
//////////////////////////////////////////////////////////////////////////////////
//
// 7. Function Type Based on Returning: 
//
//    functions with returning by reference
//
// - Returning as Value
// - Returning as Pointer
// - Returning as Reference
//
#include <array> // array size
double a[] = {1.0, 2.0, 4.0, 8.0, 16.0,32.0,64.0};

double& seta( int i ) {
   return a[i];   // return a reference to the ith element
}

int main () {
   cout << "initial array:" << endl;
   cout << "size of a in bytes = " << sizeof(a) << '\n';
   cout << "size of a in number of elements = " << sizeof(a)/sizeof(a[0]) << '\n';
   for ( int i = 0; i < 7; i++ ) {
      cout << "a[" << i << "] = ";
      cout << a[i] << endl;
   }
   // change a through changing the elements of its alias
   // through reference, hence indirectly changing the values of a
   seta(0) = 100;
   seta(1) = 200; 
   seta(6) = -700;
   cout << "a after changing the reference of a, hence indirectly changing:" << endl;
   cout << "size of a in bytes = " << sizeof(a) << '\n';
   cout << "size of a in number of elements = " << sizeof(a)/sizeof(a[0]) << '\n';
   for ( int i = 0; i < sizeof(a)/sizeof(a[0]); i++ ) {
      cout << "a[" << i << "] = ";
      cout << a[i] << endl;
   }
   return 0;
}
#endif

#if CASE == 8
/////////////////////////////////////////////////////////////////////////////
// 
// 8. Function with Overloading: 
//
//    same name but different operations with different arguments
//
// Two different functions can have the same name 
// if their parameters are different; either because they 
// have a different number of parameters, or because any 
// of their parameters are of a different type. For example:  
// 
int operate (int a, int b)
{
  return (a*b);
}
double operate (double a, double b)
{
  return (a/b);
}
int main ()
{
  int x=5,y=2;
  double n=5.0,m=2.0;
  cout << operate (x,y) << '\n';
  cout << operate (n,m) << '\n';
  return 0;
}
// In this example, there are two functions called operate, 
// but one of them has two parameters of type int, while the 
// other has them of type double. The compiler knows which one 
// to call in each case by examining the types passed as arguments 
// when the function is called. If it is called with two int arguments, 
// it calls to the function that has two int parameters, and if 
// it is called with two doubles, it calls the one with two doubles.
#endif

#if CASE == 9
///////////////////////////////////////////////////////////////////////////////
// 
// 9. Function with Overloading
//
//    functions may have the same definition but with different arguments
//
int sum (int a, int b)
{
  return a+b;
}
double sum (double a, double b)
{
  return a+b;
}

int main ()
{
  cout << sum (10,20) << '\n';
  cout << sum (1.0,1.5) << '\n';
  return 0;
}
// Here, sum is overloaded with different parameter types, 
// but with the exact same body. The function sum could be 
// overloaded for a lot of types, and it could make sense 
// for all of them to have the same body. For cases such as 
// this, C++ has the ability to define functions with generic 
// types, known as function templates. Defining a function 
// template follows the same syntax as a regular function, 
// except that it is preceded by the template keyword and a 
// series of template parameters enclosed in angle-brackets <>:

#endif

#if CASE == 10
////////////////////////////////////////////////////////////////////////////////
// 
// 10. Function Template
//    
// Function templates are special functions that can operate with
// generic types. This allows us to create a function template whose
// functionality can be adapted to more than one type or class without
// repeating the entire code for each type.
// In C++ this can be achieved using template parameters. A template 
// parameter is a special kind of parameter that can be used to pass a
// type as argument: just like regular function parameters can be used
// to pass values to a function, template parameters allow to pass also
// types to a function. These function templates can use these
// parameters as if they were any other regular type.
//
// 
// The format for declaring function templates with type parameters is:
//
//    template <class identifier> function_declaration;
//    template <typename identifier> function_declaration;
//
// The only difference between both prototypes is the use of either the
// keyword class or the keyword typename. Its use is indistinct, since
// both expressions have exactly the same meaning and behave exactly the
// same way.
//
// For example, to create a template function that returns the greater
// one of two objects we could use:
//
// template <class myType>
// myType getmax (myType a, myType b) {
// return (a>b?a:b);
// }
// 
// template parameter = myType, it represents a type that hasn't been specified,
// but that can be used in the template function as if it were a regular
// type. As you can see, the function template getmax returns the greater
// of two parameters of this still-undefined type. Template parameters
// can be used for returning and/or passing. 
//
// To use this function template we use the following format for the
// function call:
//
// function_name <type> (function arguments);
// 
// int x,y;
// getmax <int> (x,y);
//
// A function template by itself is not a type, or a function, or any other entity. 
// No code is generated from a source file that contains only template definitions. 
// In order for any code to appear, a template must be instantiated: the template 
// arguments must be determined so that the compiler can generate an actual function 
// (or class, from a class template). 
//
// template        return-type name < argument-list > ( parameter-list ) ; 	(1) 	
// template        return-type name                   ( parameter-list ) ; 	(2) 	
// extern template return-type name < argument-list > ( parameter-list ) ; 	(3) 	(since C++11)
// extern template return-type name                   ( parameter-list ) ; 	(4) 	(since C++11)
//
// template void f<double>(double); // instantiates f<double>(double)
// template void f<>(char);         // instantiates f<char>(char), template argument deduced
// template void f(int);            // instantiates f<int>(int), template argument deduced
//

//     name <template-arguments> (function-arguments) 
// x = sum  <int>                (int x, int y);
//
template<typename D> // R is not specialized and can be anything, but we still
                     // want to use it to define the other functions and classes
                     // namely to use this template type to define things 
                     // such as the function return type, the function 
                     // argument type, etc. As soon as we use the template 
                     // keyword to link with D, we can use D for anything else. 
void display(D s)
{
    std::cout << s << '\n';
}

template<typename D> 
D diff(D a, D b)
{
   return a-b;
}
// the template D is overloaded with two different functions.

template <class S>   // S is not specialized and can be anything, but we still
                     // want to use it to define the other functions and classes
                     // namely to use this template type to define things 
                     // such as the function return type, the function 
                     // argument type, etc. As soon as we use the template 
                     // keyword to link with S, we can use S for anything else. 
S sum (S a, S b)
{
  return a+b;
  //   S result;
  //   result = a*b;
  //   return result;
}

template <class S>
S times (S a, S b)
{
  S result;
  result = a * b;
  return result;
  // return a*b; // to replace the last three line of code
}
// the template S is overloaded with two different classes.

// multiple tamplate for one class or function:
template<class T1, class T2> 
class print_w_type 
{ 
        T1 a; 
        T2 b; 
    public: 
        print_w_type(T1 x, T2 y) 
        { 
            a = x; 
            b = y; 
        } 
        void show() 
        { 
            cout << a << " and " << b << endl; 
        } 
}; 


int main () {
  double a=10.0, b=20.0, c=30.0; 
  int i=11, j=22, k=33;
  char t[]={'a','b','c','i','j','k'};
  display<int>(j);
  display<double>(a);
  display<char>(t[1]);

  cout << "diff<double>(a,b) = " << diff<double>(a,b) << '\n';
  cout << "diff<int>(i,j) = " << diff<int>(i,j) << '\n';

  cout << "sum<double>(a,b) = " << sum<double>(a,b) << '\n';
  cout << "sum<int>(i,j) = " << sum<int>(i,j) << '\n';

  // multiple template case:
  print_w_type <float, int> t1 (1.1, 10.0); 
  print_w_type <int, char> t2 (10.1, 'W');    
  print_w_type <float, char> t3 (1.1, 'A'); 
  t1.show(); 
  t2.show(); 
  t3.show(); 

  return 0;
}
#endif

#if CASE == 11
////////////////////////////////////////////////////////////////////////////////
//
// 11. Friend Functions
//
// In principle, private and protected members of a class cannot be accessed
// from outside the same class in which they are declared. However, this rule
// does not apply to "friends".
//
// Friends are functions or classes declared with the friend keyword.
//
// A non-member function can access the private and protected members of a
// class if it is declared a friend of that class. That is done by including a
// declaration of this external function within the class, and preceding it
//  with the keyword friend:
//
class R {
    int w, h;
  public:
    // R() // call this, area will be computed with any left-over values in w and h
    R() {w=0; h=0;} // calling this leads to initialization to w=0, h=0
    R (int x, int y) : w(x), h(y) {} // calling this leads to the computation using 
                                     // arguments passing by values
    int area() {return w * h;}
    friend R duplicate (const R&);
};

R duplicate (const R& param) // 1. R here is used to define the return type of duplicate
                             // 2. duplicate is called through reference, namely 
                             // param, which has the type of R, namely, 
                             // param has 2 private variables w and h
                             //           1 initializing function
                             //           1 parameterized function
                             //           1 function returning a value
                             //           1 function doing something returns to type R
                             // param and the internal r are the same with
                             // only the private variables are doubled in r 
{
  R r;
  r.w = param.w*2;
  r.h = param.h*2;
  return r;                  // notice that r has the type of class R, hence
                             // it has all the other members of R, but only with 
                             // 2 private variables getting changed.
}

int main () {
  R a;
  cout << "R a; a.area() = " << a.area() << '\n';

  R b (2,3);
  cout << "R b (2,3); b.area() = " << b.area() << '\n';

  a = duplicate (b);
  cout << "a = duplicate (b); a.area() = " << a.area() << '\n';

  return 0;
}
/*
The duplicate function is a friend of class Rectangle. Therefore, function duplicate is able to access the members width and height (which are private) of different objects of type Rectangle. Notice though that neither in the declaration of duplicate nor in its later use in main, function duplicate is considered a member of class Rectangle. It isn't! It simply has access to its private and protected members without being a member.

Typical use cases of friend functions are operations that are conducted between two different classes accessing private or protected members of both. 
*/
#endif

#if CASE == 12
////////////////////////////////////////////////////////////////////////////////
//
// 12. Virtual Functions
//

// A virtual function a member function which is declared within a base class 
// and is re-defined(Overriden) by a derived class. When you refer to a derived 
// class object using a pointer or a reference to the base class, you can call 
// a virtual function for that object and execute the derived class’s version of 
// the function. CALL VIRTUAL FUNCTION BUT EXECUTE DERIVED CLASS VERSION

// Virtual functions ensure that the correct function is called for an object,
// regardless of the type of reference (or pointer) used for function call.
// They are mainly used to achieve Runtime polymorphism Functions are declared 
// with a virtual keyword in base class. The resolving of function call is done 
// at Run-time.

// Rules for Virtual Functions
// - Virtual functions cannot be static and also cannot be a friend function of 
// another class.
// - Virtual functions should be accessed using pointer or reference of base class 
// type to achieve run time polymorphism.
// - The prototype of virtual functions should be same in base as well as derived 
// class.
// - They are always defined in base class and overridden in derived class. It is 
// not mandatory for derived class to override (or re-define the virtual function), 
// in that case base class version of function is used.
// - A class may have virtual destructor but it cannot have a virtual constructor.

// Compile-time(early binding) VS run-time(late binding) behavior of Virtual 
// Functions

// Consider the following simple program showing run-time behavior of virtual 
// functions. CPP program to illustrate  concept of Virtual Functions 

class base 
{ 
public: 
    virtual void print () 
    { cout<< "print base class" <<endl; } 
  
    void show () 
    { cout<< "show base class" <<endl; } 
}; 
  
class derived:public base 
{ 
public: 
    void print () 
    { cout<< "print derived class" <<endl; } 
  
    void show () 
    { cout<< "show derived class" <<endl; } 
}; 
  
int main() 
{ 
    base *bptr; 
    derived d; 
    bptr = &d; 
      
    //virtual function, binded at runtime 
    bptr->print();  
      
    // Non-virtual function, binded at compile time 
    bptr->show();  
} 
#endif

#if CASE == 13
////////////////////////////////////////////////////////////////////////////////
//
// 13. Lambda Expressions
//
// C++ 11 introduced lambda expression to allow us write an inline function 
// which can be used for short snippets of code that are not going to be 
// reuse and not worth naming. In its simplest form lambda expression can 
// be defined as follows:
/*
[ capture clause ] (parameters) -> return-type  
{   
   definition of method   
} 
*/
// Generally return-type in lambda expression are evaluated by compiler 
// itself and we don’t need to specify that explicitly and -> return-type 
// part can be ignored but in some complex case as in conditional statement, 
// compiler can’t make out the return type and we need to specify that.
// Various uses of lambda expression with standard function are given below :

// Function to print vector 
#include <bits/stdc++.h> 
void printVector(vector<int> v) 
{ 
    // lambda expression to print vector 
    for_each(v.begin(), v.end(), [](int i){std::cout << i << " ";}); 
    cout << endl; 
} 
  
int main() 
{ 
    vector<int> v {4, 1, 3, 5, 2, 3, 1, 7}; 
    printVector(v); 
  
    // find first number > 4 
    // find_if searches for an element for which function(third argument) returns true 
    vector<int>:: iterator p = find_if(v.begin(), v.end(), [](int i){return i > 4;}); 
    cout << "1st number >4 is : " << *p << endl; 
  
    // sort vector in non-decreasing order 
    // Compiler can make out return type as bool, but shown here just for explanation 
    sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool{return a > b;}); 
    printVector(v); 
  
    // function to count numbers >= 5 
    int count_5 = count_if(v.begin(), v.end(), [](int a){return (a >= 5);}); 
    cout << "The number of elements >= 5 is : "<< count_5 << endl; 
  
    // function for removing duplicates (after sorting all duplicate comes together) 
    p = unique(v.begin(), v.end(), [](int a, int b){return a == b;}); 
  
    // resizing vector to make size equal to total different number 
    v.resize(distance(v.begin(), p)); 
    printVector(v); 
  
    // accumulate the container on the basis of function provided as 3rd argument 
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int f = accumulate(arr, arr + 10, 1, [](int i, int j){return i * j;}); 
    cout << "Factorial of 10 is : " << f << endl; 
  
    // We can also access function by storing this into variable 
    auto square = [](int i) { return i * i; }; 
    cout << "Square of 5 is : " << square(5) << endl; 
} 
#endif

#if CASE == 14
////////////////////////////////////////////////////////////////////////////////
//
// 14. Lambda Expressions: How to Capture External Variables
//
// A lambda expression can have more power than an ordinary function 
// by having access to variables from the enclosing scope. We can 
// capture external variables from enclosing scope by three ways :

//      Capture by reference
//      Capture by value
//      Capture by both (mixed capture)

// Syntax used for capturing variables :
//      [&] : capture all external variable by reference
//      [=] : capture all external variable by value
//      [a, &b] : capture a by value and b by reference

// A lambda with empty capture clause [ ] can access only those 
// variable which are local to it. Capturing ways are demonstrated below :
#include <bits/stdc++.h> 
void printVector(vector<int> v) 
{ 
    // lambda expression to print vector 
    for_each(v.begin(), v.end(), [](int i){std::cout << i << " ";}); 
    cout << endl; 
} 
int main() 
{ 
    vector<int> v1 = {3, 1, 7, 9}; 
    printVector(v1);

    vector<int> v2 = {10, 2, 7, 16, 9}; 
    printVector(v2);

    //  access v1 and v2 by reference 
    auto pushinto = [&] (int m, int n){v1.push_back(m); v2.push_back(n);}; 
    // it pushes 20 in both v1 and v2 
    pushinto(20,30); 
    cout<<"after pushinfo(20,30): "<< '\n';
    printVector(v1);
    printVector(v2);

    // access v1 by copy 
    [v1](){ for (auto p = v1.begin(); p != v1.end(); p++) { cout << *p << " ";} }; 
    cout<<"after access v1 by copy - [v1]: "<< '\n';
    printVector(v1);
    printVector(v2);

    int N = 5; 
    // find first number > N. [N] denotes, it can only access N by value 
    vector<int>:: iterator p = find_if(v1.begin(), v1.end(), [N](int i) { return i > N;}); 
    cout << "1st number greater than 5 is : " << *p << endl; 
   
    // function to count numbers >= N. [=] denotes, it can access all variable 
    int count_N = count_if(v1.begin(), v1.end(), [=](int a) { return (a >= N);}); 
  
    cout << "The number of elements >= 5 is : "<< count_N << endl; 
} 
#endif

/*Functions in <algorithm>
Non-modifying sequence operations:

all_of
    Test condition on all elements in range (function template )

any_of
    Test if any element in range fulfills condition (function template )

none_of
    Test if no elements fulfill condition (function template )

for_each
    Apply function to range (function template )

find
    Find value in range (function template )

find_if
    Find element in range (function template )

find_if_not
    Find element in range (negative condition) (function template )

find_end
    Find last subsequence in range (function template )

find_first_of
    Find element from set in range (function template )

adjacent_find
    Find equal adjacent elements in range (function template )

count
    Count appearances of value in range (function template )

count_if
    Return number of elements in range satisfying condition (function template )

mismatch
    Return first position where two ranges differ (function template )

equal
    Test whether the elements in two ranges are equal (function template )

is_permutation
    Test whether range is permutation of another (function template )

search
    Search range for subsequence (function template )

search_n
    Search range for elements (function template )


Modifying sequence operations:

copy
    Copy range of elements (function template )

copy_n
    Copy elements (function template )

copy_if
    Copy certain elements of range (function template )

copy_backward
    Copy range of elements backward (function template )

move
    Move range of elements (function template )

move_backward
    Move range of elements backward (function template )

swap
    Exchange values of two objects (function template )

swap_ranges
    Exchange values of two ranges (function template )

iter_swap
    Exchange values of objects pointed to by two iterators (function template )

transform
    Transform range (function template )

replace
    Replace value in range (function template )

replace_if
    Replace values in range (function template )

replace_copy
    Copy range replacing value (function template )

replace_copy_if
    Copy range replacing value (function template )

fill
    Fill range with value (function template )

fill_n
    Fill sequence with value (function template )

generate
    Generate values for range with function (function template )

generate_n
    Generate values for sequence with function (function template )

remove
    Remove value from range (function template )

remove_if
    Remove elements from range (function template )

remove_copy
    Copy range removing value (function template )

remove_copy_if
    Copy range removing values (function template )

unique
    Remove consecutive duplicates in range (function template )

unique_copy
    Copy range removing duplicates (function template )

reverse
    Reverse range (function template )

reverse_copy
    Copy range reversed (function template )

rotate
    Rotate left the elements in range (function template )

rotate_copy
    Copy range rotated left (function template )

random_shuffle
    Randomly rearrange elements in range (function template )

shuffle
    Randomly rearrange elements in range using generator (function template )


Partitions:

is_partitioned
    Test whether range is partitioned (function template )

partition
    Partition range in two (function template )

stable_partition
    Partition range in two - stable ordering (function template )

partition_copy
    Partition range into two (function template )

partition_point
    Get partition point (function template )


Sorting:

sort
    Sort elements in range (function template )

stable_sort
    Sort elements preserving order of equivalents (function template )

partial_sort
    Partially sort elements in range (function template )

partial_sort_copy
    Copy and partially sort range (function template )

is_sorted
    Check whether range is sorted (function template )

is_sorted_until
    Find first unsorted element in range (function template )

nth_element
    Sort element in range (function template )


Binary search (operating on partitioned/sorted ranges):

lower_bound
    Return iterator to lower bound (function template )

upper_bound
    Return iterator to upper bound (function template )

equal_range
    Get subrange of equal elements (function template )

binary_search
    Test if value exists in sorted sequence (function template )


Merge (operating on sorted ranges):

merge
    Merge sorted ranges (function template )

inplace_merge
    Merge consecutive sorted ranges (function template )

includes
    Test whether sorted range includes another sorted range (function template )

set_union
    Union of two sorted ranges (function template )

set_intersection
    Intersection of two sorted ranges (function template )

set_difference
    Difference of two sorted ranges (function template )

set_symmetric_difference
    Symmetric difference of two sorted ranges (function template )


Heap:

push_heap
    Push element into heap range (function template )

pop_heap
    Pop element from heap range (function template )

make_heap
    Make heap from range (function template )

sort_heap
    Sort elements of heap (function template )

is_heap
    Test if range is heap (function template )

is_heap_until
    Find first element not in heap order (function template )


Min/max:

min
    Return the smallest (function template )

max
    Return the largest (function template )

minmax
    Return smallest and largest elements (function template )

min_element
    Return smallest element in range (function template )

max_element
    Return largest element in range (function template )

minmax_element
    Return smallest and largest elements in range (function template )


Other:

lexicographical_compare
    Lexicographical less-than comparison (function template )

next_permutation
    Transform range to next permutation (function template )

prev_permutation
    Transform range to previous permutation (function template )*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>

int main()
{
    typedef list<int> L;
    L l(5);

    typedef L::const_iterator CI;
    CI cb = l.begin(), ce = l.end();
    typedef L::iterator I;
    I b = l.begin();

    transform(cb, --ce, ++b, [] (CI::value_type n) { return ++n; });
    copy(l.begin(), l.end(), ostreamterator<CI::value_type>(cout));
    cout << endl;

    return 0;
}
#endif
