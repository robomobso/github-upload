
#include <iostream>
using namespace std;

#define CASE 15

// Type Conversion in C++

//////////////////////////////////////
//
// Implitcity vs. Explicity Conversion
//
//////////////////////////////////////
//
// A type cast is basically a conversion from one type to another. There are two
// types of type conversion:

// - Implicit Type Conversion: ‘automatic type conversion’. Done by
//   the compiler on its own, without any external trigger from the user.
//   Generally takes place when in an expression more than one data type is
//   present. In such condition type conversion (type promotion) takes place to
//   avoid lose of data. All the data types of the variables are upgraded to the
//   data type of the variable with largest data type.
//
//bool>char>short int>int>unsigned int>long>unsigned long>float>long long>double>long double
// 1  > 1  >     2   > 4 >      4     > 4  >     4       >  4  >    8    >  8   >     8
//
//   It is possible for implicit conversions to lose information, signs can be
//   lost (when signed is implicitly converted to unsigned), and overflow can
//   occur (when long long is implicitly converted to float).

#if CASE == 1
////////////////////////////////////////////////////////////////////////////////
// 
// 1. Implicit Conversion: Simple Example
//
int main() 
{ 
    int x = 10; // integer x 
    cout<< "int x = 10, char(x) = "<<char(x)<< endl; // this does not work!

    char y = 'a'; // character c 
    cout<< "char y='a'; int(y) = "<<int(y)<< endl; //ASCII value of 'a' is 97 
 
    x = x + y;  // y implicitly converted to int. 
    cout<< "10 + int('a') = "<< x << endl; //ASCII value of 'a' is 97 

    float z = x + 1.5;  // x is implicitly converted to float 
    cout<< "float z = x + 1.0 = "<< z << endl;

    return 0; 
} 
#endif

#if CASE == 2
////////////////////////////////////////////////////////////////////////////////
// 
// 2. Implicit Conversion
//
// Implicit conversions also include constructor or operator conversions, which
// affect classes that include specific constructors or operator functions to
// perform conversions. For example:
/*
class A {};
class B { public: B (A a) {} };
A a;
B b=a;
*/
// Here, an implicit conversion happened between objects of class A and class B,
// because B has a constructor that takes an object of class A as parameter.
// Therefore implicit conversions from A to B are allowed.

// - Explicit Type Conversion: This process is also called type casting and it is
//   user-defined. Here the user can typecast the result to make it of a particular
//   data type.

// In C++, it can be done by two ways:
   /* Converting by assignment: This is done by explicitly defining the required
    type in front of the expression in parenthesis. This can be also considered
    as forceful casting.
    		Syntax: (type) expression
    where type indicates the data type to which the final result is converted.*/
// C++ program to demonstrate explicit type casting 
int main() 
{ 
    double x = 1.6; 
    int y = 2;
     cout << "x = " << x << "; y = " << y << endl; 
    int sum1 = (int)x + y;// Explicit conversion from double to int 
    double sum2 = x + (double)y;// Explicit conversion from int to double
    cout << "int sum1 = (int)x + y = " << sum1 << endl; 
    cout << "double sum2 = x + (double)y = " << sum2 << endl; 
    return 0; 
} 
#endif

#if CASE == 3
////////////////////////////////////////////////////////////////////////////////
// 
// 3. Explicit Conversion with Casting
//
// - Conversion using Cast operator: A Cast operator is an unary operator which
// - forces one data type to be converted into another data type.
//  
// C++ supports four types of casting:
//    Static Cast
//    Dynamic Cast
//    Const Cast
//    Reinterpret Cast
int main() 
{ 
    float x = 1.6; 
    int y = 2;
     cout << "x = " << x << "; y = " << y << endl; 
    int sum1 = static_cast<int>(x) + y;// Explicit conversion from double to int 
    float sum2 = x + static_cast<double>(y);// Explicit conversion from int to double
    cout << "int sum1 = static_cast<int>(x) + y = " << sum1 << endl; 
    cout << "float sum2 = x + static_cast<double>(y) = " << sum2 << endl; 
    return 0; 
} 
// Advantages of Type Casting: This is done to take advantage of certain
// features of type hierarchies or type representations.It helps to compute
// expressions containing variables of different data types.
#endif

/////////////////////////////////////////////////////////////////
//
// Conversion Basic <--> User-defined
//
// 1 Conversion between basic and user defined
//   a) Conversion from basic to user defined data type
//   b) Conversion from user-defined data type to basic data type
// 
// 2 Conversion between user defined data types
//   a) Conversion in destination object
//   b) Conversion in source object 
//
////////////////////////////////////////////////////////////////

#if CASE == 4
////////////////////////////////////////////////////////////////////////////////
// 
// 4. Conversion from basic to user defined data type
//
// Conversion from basic to user defined type is done by using the constructor
// function with one argument of basic type as follows.
/*
Syntax:
class class_name { 
   private: 
      //…. 
   public: 
      class_name ( data_type) { 
          // conversion code
          } 
};
*/
// example conversion from basic type to object
class celsius
{
  private:
    float temper;
  public:
    celsius(){temper=0;} 
    celsius(float ftmp){temper=(ftmp-32)* 5/9;}
    void showtemper(){cout<<"Temperature in Celsius: "<<temper<<endl;}
};
int main()
{
    celsius cel;                //cel is user defined
    float fer;                  //fer is basic type
    cout<<"\nEnter temperature in Fahrenheit measurement: ";
    cin>>fer;
    cel=fer;  // convert from basic to user-defined; eqvt to 
              //      cel = celsius(fer);
    cel.showtemper();
    return 0;
}
#endif

#if CASE == 5
////////////////////////////////////////////////////////////////////////////////
//
// 5. Conversion from user-defined type to basic data type
//
// Conversion from user-defined type of basic data type is done by overloading
// the cast operator of basic type as a member function. 
//
// Operator function is defined as an overloaded basic data type which takes no
// arguments.
//
// Return type of operator is not specified because the cast operator function
// itself specifies the return type.
/*
Syntax:
class class_name { 
       ... 
       public: 
             operator data_type() { 
                    //Conversion code 
             } 
};
*/
// Here is example program to illustrate conversion from user-defined type to
// basic data type.
class celsius
{
  private:
    float temper;
  public:
    celsius(){ temper=0; }
    operator float(){float fer;fer=temper *9/5 + 32;return (fer);}
          // operator is used to mean that the system type float is overloaded 
          // with user defined computation.
    void gettemper(){cout<<"\n Enter Temperature in Celsius:";cin>>temper;}
};
int main()
{
    celsius cel;            //cel is user defined
    float fer;              //fer is basic type
    cel.gettemper();
    fer=cel;     //convert from user-defined to basic;eqvt to  
                 //         fer= float(cel);
    cout<<"\nTemperature in Fahrenheit measurement: "<<fer\endl;
}
#endif

#if CASE == 6
////////////////////////////////////////////////////////////////////////////////
//
// 6. Conversion in Destination Object
//
// This conversion is exactly like conversion of basic to user defined data type
// i.e. one argument constructor is used.

// Conversion routine is defined as a one argument constructor in destination
// class and takes the argument of the source class type.
/*Eg.
classA objA;
classB objB;
objA=objB;
*/
// Here, objB is the source of the class classB and objA is the destination
// object of class classA.

// For this expression to work, the conversion routine should exist in classA
// (destination class type) as a one argument constructor as
/*
//source object class
class classB   
{
    //body of classB
}
//destination object class
class classA
{
   private:
    //….
   public:
    classA (classB objB) //object of source class
    {
        //code for conversion
        //from classB
        //to classA
    }
};
*/
#include<cmath>
class Cartesian
{
  private:
    float xco, yco;
  public:
    Cartesian(){xco=0;yco=0;}
    Cartesian(float x, float y){xco=x;yco=y;}
    Cartesian(Polar p){
        float xc0=static_cast<int>(p.radius * cos(p.angle));
        float yc0=static_cast<int>(p.radius * sin(p.angle));
        return Cartesian(x,y);
      }
    void display(){cout<<"("<<xco<<","<<yco<<")"<<endl;}
};
class Polar
{
private:
    float radius, angle;
public:
    Polar(){radius=0;angle =0;}
    Polar(float rad, float ang){radius =rad;angle=ang;}
    operator Cartesian()
    {
        float x=static_cast<int>(radius * cos(angle));
        float y=static_cast<int>(radius * sin(angle));
        return Cartesian(x,y);
    }
    void display(){cout<<"("<<radius<<","<<angle<<")"<<endl;}
};
int main()
{
    Polar pol(10.0, 0.78);
    cout<<"\nGiven Polar: ";
    pol.display();

    Cartesian cart(pol);
    //cart=pol;
    cart.display();
    cout<<"\nEquivalent cartesian: ";
    cart.display();
    return 0;
}
#endif

#if CASE == 7
////////////////////////////////////////////////////////////////////////////////
//
// 7. Conversion in source object
//
// This conversion is exactly like conversion of user-defined type to basic type
// i.e. overloading the cast operator is used.
/*Eg.
		classA objA; 
		classB objB; 
		objA=objB;*/
// Here, objB is the source of the class classB and objA is the destination
// object of class classA. Conversion routine is specified as conversion (cast)
// operator overloading for the type of destination class.
/*Syntax:
//destination object class
class classA   
{
    //body of classA
}
//source object class
class classB
{
private: 
    //….
public:
    operator classA () //cast operator destination types
    {
        //code for conversion from classB
        //to classA
    }
};*/
//conversion from user defined to user defined in source class
#include<cmath>
class Cartesian
{
  private:
    float xco, yco;
  public:
    Cartesian(){xco=0;yco=0;}
    Cartesian(float x, float y){xco=x;yco=y;}
    void display(){cout<<"("<<xco<<","<<yco<<")"<<endl;}
};
class Polar
{
private:
    float radius, angle;
public:
    Polar(){radius=0;angle =0;}
    Polar(float rad, float ang){radius =rad;angle=ang;}
    operator Cartesian()
    {
        float x=static_cast<int>(radius * cos(angle));
        float y=static_cast<int>(radius * sin(angle));
        return Cartesian(x,y);
    }
    void display(){cout<<"("<<radius<<","<<angle<<")"<<endl;}
};
int main()
{
    Polar pol(10.0, 0.78);
    cout<<"\nGiven Polar: ";
    pol.display();

    Cartesian cart;
    cart=pol;
    cout<<"\nEquivalent cartesian: ";
    cart.display();

    return 0;
}
#endif
  
////////////////////////////////////////////////////////////////////////////////
//
// TYPE CASTING
//
// 2 generic type-casting: functional and c-like:
// 		double x = 10.3; int y;
// 		y = int(x);    // functional notation
// 		y = (int)x;    // c-like cast notation 
// The functionality of these generic forms of type-casting is enough for most 
// needs with fundamental data types. However, these operators can be applied 
// indiscriminately on classes and pointers to classes, which can lead to code 
// that -while being syntactically correct- can cause runtime errors. For example, 
// the following code compiles without errors: 
//
// class Dummy {
//     double i,j;
// };
// class Addition {
//     int x,y;
//   public:
//     //Addition (int a, int b) { x=a; y=b; }
//     Addition (int a, int b) : x(a), y(b) {};
//     int result() { return x+y;}
// };
// int main () {
//   Dummy d;
//   Addition * padd;
//   padd = (Addition*) &d;
//   cout << padd->result();
//   return 0;
// }
// C++ uses four types of casting to solve the above difficulties:
//    Static Cast
//    Dynamic Cast
//    Const Cast
//    Reinterpret Cast
///////////////////////////////////////////////////////////////////////////////

#if CASE == 8
////////////////////////////////////////////////////////////////////////////////
// 
// 8. CONST_CAST
//
void print (char * str)
{
  cout << str << '\n';
}
int main () {
  const char * c = "sample text";
  // print(c); error
  print ( const_cast<char *> (c) );
  return 0;
}
// The example above is guaranteed to work because function print does not write to 
// the pointed object. Note though, that removing the constness of a pointed object
// to actually write to it causes undefined behavior.

// The program declares a pointer to Addition, but then it assigns to it a reference to 
// an object of another unrelated type using explicit type-casting:
// 		padd = (Addition*) &d;

// Unrestricted explicit type-casting allows to convert any pointer into any other 
// pointer type, independently of the types they point to. The subsequent call to 
// member result will produce either a run-time error or some other unexpected results.

// In order to control these types of conversions between classes, we have four specific 
// casting operators: dynamic_cast, reinterpret_cast, static_cast and const_cast. Their 
// format is to follow the new type enclosed between angle-brackets (<>) and immediately 
// after, the expression to be converted between parentheses.
// 		dynamic_cast <new_type> (expression)
// 		reinterpret_cast <new_type> (expression)
// 		static_cast <new_type> (expression)
// 		const_cast <new_type> (expression)

// The traditional type-casting equivalents to these expressions would be:
// 		(new_type) expression
// 		new_type (expression)
// but each one with its own special characteristics:
#endif

#if CASE == 9
/////////////////////////////////////////////////////////////////////////////////////////
//
// 9. Implicit conversions with classes
//
// In the world of classes, implicit conversions can be controlled by means of 
// three member functions:
// - Single-argument constructors: allow implicit conversion from a particular 
//   type to initialize an object.
// - Assignment operator: allow implicit conversion from a particular type on 
//   assignments.
// - Type-cast operator: allow implicit conversion to a particular type.
class A {};
class B 
{
public:
  B (const A& x) {} // conversion from A (constructor):
  B& operator= (const A& x) {return *this;} // conversion from A (assignment):
  operator A() {return A();} // conversion to A (type-cast operator)
};
int main ()
{
  A foo;
  B bar = foo;    // calls constructor
  bar = foo;      // calls assignment
  foo = bar;      // calls type-cast operator
  return 0;
}
// The type-cast operator uses a particular syntax: it uses the operator keyword 
// followed by the destination type and an empty set of parentheses. Notice that 
// the return type is the destination type and thus is not specified before the 
// operator keyword.
#endif

#if CASE == 10
///////////////////////////////////////////////////////////////////////////////
//
// 10. STATIC_CAST
//
// static_cast can perform conversions between pointers to related classes, not 
// only upcasts (from pointer-to-derived to pointer-to-base), but also downcasts 
// (from pointer-to-base to pointer-to-derived). No checks are performed during 
// runtime to guarantee that the object being converted is in fact a full object 
// of the destination type. Therefore, it is up to the programmer to ensure that 
// the conversion is safe. On the other side, it does not incur the overhead 
// of the type-safety checks of dynamic_cast.
/*
class Base {};
class Derived: public Base {};
Base * a = new Base;
Derived * b = static_cast<Derived*>(a);
*/
// This would be valid code, although b would point to an incomplete object of 
// the class and could lead to runtime errors if dereferenced.

// Therefore, static_cast is able to perform with pointers to classes not only 
// the conversions allowed implicitly, but also their opposite conversions.

// static_cast is also able to perform all conversions allowed implicitly (not 
// only those with pointers to classes), and is also able to perform the opposite 
// of these. It can:
// Convert from void* to any pointer type. In this case, it guarantees that if 
// the void* value was obtained by converting from that same pointer type, the 
// resulting pointer value is the same.
// Convert integers, floating-point values and enum types to enum types.

// Additionally, static_cast can also perform the following:
// Explicitly call a single-argument constructor or a conversion operator.
// Convert to rvalue references.
// Convert enum class values into integers or floating-point values.
// Convert any type to void, evaluating and discarding the value.
#endif

#if CASE == 11
////////////////////////////////////////////////////////////////////////////////
//
// 11. DYNAMIC_CAST
//
// dynamic_cast can only be used with pointers and references to classes (or with void*). 
// Its purpose is to ensure that the result of the type conversion points to a valid 
// complete object of the destination pointer type.

// This naturally includes pointer upcast (converting from pointer-to-derived to 
// pointer-to-base), in the same way as allowed as an implicit conversion.

// But dynamic_cast can also downcast (convert from pointer-to-base to 
// pointer-to-derived) polymorphic classes (those with virtual members) if -and 
// only if- the pointed object is a valid complete object of the target type. 
//
class Base { virtual void dummy() {} };
class Derived: public Base { int a; };
int main () {
  try {
    Base * pba = new Derived;
    Base * pbb = new Base;
    Derived * pd;

    pd = dynamic_cast<Derived*>(pba);
    if (pd==0) cout << "Null pointer on first type-cast.\n";

    pd = dynamic_cast<Derived*>(pbb);
    if (pd==0) cout << "Null pointer on second type-cast.\n";

  } catch (exception& e) {cout << "Exception: " << e.what();}
  return 0;
}
// Compatibility note: This type of dynamic_cast requires Run-Time Type Information (RTTI)
// to keep track of dynamic types. Some compilers support this feature as an option which 
// is disabled by default. This needs to be enabled for runtime type checking using 
// dynamic_cast to work properly with these types.

// The code above tries to perform two dynamic casts from pointer objects of type Base* 
// (pba and pbb) to a pointer object of type Derived*, but only the first one is 
// successful. Notice their respective initializations:
// 		Base * pba = new Derived;
// 		Base * pbb = new Base;

// Even though both are pointers of type Base*, pba actually points to an object of type 
// Derived, while pbb points to an object of type Base. Therefore, when their respective 
// type-casts are performed using dynamic_cast, pba is pointing to a full object of class
// Derived, whereas pbb is pointing to an object of class Base, which is an incomplete 
// object of class Derived.

// When dynamic_cast cannot cast a pointer because it is not a complete object of the 
// required class -as in the second conversion in the previous example- it returns a 
// null pointer to indicate the failure. If dynamic_cast is used to convert to a 
// reference type and the conversion is not possible, an exception of type bad_cast 
// is thrown instead.

// dynamic_cast can also perform the other implicit casts allowed on pointers: casting 
// null pointers between pointers types (even between unrelated classes), and casting 
// any pointer of any type to a void* pointer.
#endif

#if CASE == 12
///////////////////////////////////////////////////////////////////////////////
//
// 12. REINTERPRET_CAST
//
// reinterpret_cast converts any pointer type to any other pointer type, even of 
// unrelated classes. The operation result is a simple binary copy of the value 
// from one pointer to the other. All pointer conversions are allowed: neither 
// the content pointed nor the pointer type itself is checked.

// It can also cast pointers to or from integer types. The format in which this 
// integer value represents a pointer is platform-specific. The only guarantee 
// is that a pointer cast to an integer type large enough to fully contain it 
// (such as intptr_t), is guaranteed to be able to be cast back to a valid pointer.

// The conversions that can be performed by reinterpret_cast but not by static_cast 
// are low-level operations based on reinterpreting the binary representations of 
// the types, which on most cases results in code which is system-specific, and 
// thus non-portable. For example:
// 		class A { /* ... */ };
// 		class B { /* ... */ };
// 		A * a = new A;
// 		B * b = reinterpret_cast<B*>(a);
// This code compiles, although it does not make much sense, since now b points to 
// an object of a totally unrelated and likely incompatible class. Dereferencing b 
// is unsafe.
// const_cast
// This type of casting manipulates the constness of the object pointed by a pointer, 
// either to be set or to be removed. For example, in order to pass a const pointer 
// to a function that expects a non-const argument:
#endif

#if CASE == 13
///////////////////////////////////////////////////////////////////////////////
//
// 13. Implicit conversions with classes
//
// In the world of classes, implicit conversions can be controlled by means of 
// 3 member functions:
// - Single-argument constructors: allow implicit conversion from a particular 
//   type to initialize an object.
// - Assignment operator: allow implicit conversion from a particular type on 
//   assignments.
// - Type-cast operator: allow implicit conversion to a particular type.
//
class A {};
class B 
{
public:
  B (const A& x) {} // conversion from A (constructor):
  B& operator= (const A& x) {return *this;} // conversion from A (assignment):
  operator A() {return A();}  // conversion to A (type-cast operator)
};
int main ()
{
  A foo;
  B bar = foo;    // calls the 1st constructor, equivalent to B bar(foo)
  bar = foo;      // calls the 2nd assignment
  foo = bar;      // calls the 3rd type-cast operator
  return 0;
}
// The type-cast operator uses a particular syntax: it uses the operator keyword 
// followed by the destination type and an empty set of parentheses. Notice that 
// the return type is the destination type and thus is not specified before the 
// operator keyword.
#endif

#if CASE == 14
////////////////////////////////////////////////////////////////////////////////
//
// 14. KEYWORD_EXPLICIT
//
// On a function call, C++ allows one implicit conversion to happen for each argument. 
// This may be somewhat problematic for classes, because it is not always what is 
// intended. For example, if we add the following function to the last example:
// 		   void fn (B arg) {}
// This function takes an argument of type B, but it could as well be called with an 
// object of type A as argument:
// 		   fn (foo);
// This may or may not be what was intended. But, in any case, it can be prevented by 
// marking the affected constructor with the explicit keyword:
class A {};
class B 
{
public:
  explicit B (const A& x) {}
  B& operator= (const A& x) {return *this;}
  operator A() {return A();}
};
void fn (B x) {}
int main ()
{
  A foo;
  B bar (foo);
  bar = foo;
  foo = bar;
  //  fn (foo);  // not allowed for explicit ctor.
  fn (bar);  
  return 0;
}
// Additionally, constructors marked with explicit cannot be called with the 
// assignment-like syntax; In the above example, bar could not have been 
// constructed with:
// 		B bar = foo;
// Type-cast member functions (those described in the previous section) can 
// also be specified as explicit. This prevents implicit conversions in the 
// same way as explicit-specified constructors do for the destination type.
#endif

#if CASE == 15
////////////////////////////////////////////////////////////////////////////////
//
// 15. TYPEID
//
// typeid allows to check the type of an expression: 
//      typeid (expression)
// This operator returns a reference to a constant object of type type_info that is 
// defined in the standard header <typeinfo>. A value returned by typeid can be 
// compared with another value returned by typeid using operators == and != or can 
// serve to obtain a null-terminated character sequence representing the data type or 
// class name by using its name() member.
#include <typeinfo>
int main () {
  int * a=0;
  int b=0;
  if (typeid(a) != typeid(b))
  {
    cout << "a and b are of different types:\n";
    cout << "a is: " << typeid(a).name() << '\n';
    cout << "b is: " << typeid(b).name() << '\n';
  }
  return 0;
}
#endif

#if CASE == 16
////////////////////////////////////////////////////////////////////////////////
//
// 16. TYPEID: polymorphic class
//
// When typeid is applied to classes, typeid uses the RTTI to keep track of the type 
// of dynamic objects. When typeid is applied to an expression whose type is a 
// polymorphic class, the result is the type of the most derived complete object:
//    typeid, polymorphic class
#include <typeinfo>
#include <exception>
class Base { virtual void f(){} };
class Derived : public Base {};
int main () {
  try {
    Base* a = new Base;
    Base* b = new Derived;
    cout << "a is: " << typeid(a).name() << '\n';
    cout << "b is: " << typeid(b).name() << '\n';
    cout << "*a is: " << typeid(*a).name() << '\n';
    cout << "*b is: " << typeid(*b).name() << '\n';
  } catch (exception& e) { cout << "Exception: " << e.what() << '\n'; }
  return 0;
}
// Note: The string returned by member name of type_info depends on the specific 
// implementation of your compiler and library. It is not necessarily a simple string 
// with its typical type name, like in the compiler used to produce this output. 
//
// Notice how the type that typeid considers for pointers is the pointer type itself 
// (both a and b are of type class Base *). However, when typeid is applied to objects 
// (like *a and *b) typeid yields their dynamic type (i.e. the type of their most 
// derived complete object).
//
// If the type typeid evaluates is a pointer preceded by the dereference operator (*), 
// and this pointer has a null value, typeid throws a bad_typeid exception.
#endif