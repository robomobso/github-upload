////////////////////////////////////////////////////////////////////////////////
//
// compiling:
//
// g++ -o jclass jclass.cpp
// ./jclass
//
// generate static library from the above compiled file:
// g++ -o jclass jclass.cpp
// ar rcs jclass.a jclass
// or
// g++ -o jclass.o jclass.cpp
// ./jlu10array.o
// ar rcs jclass.a jclass.o
//
// generate shared library from the complied objective file
// g++  -o jclass.o -fPIC jclass.cpp // position independent code
// g++ -shared jclass.o -o jclass.so 
// g++ -shared jclass -o jclass.so 
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

// 0. simply defined class
// 1. define class, then define members
// 2. constructor: a special function avoiding call the member function
// 3. automatic constructor
// 4. default constructor
// 5. copy constructor
// 6. constructor using member initilization
// 7. fried class
// 8. class inheritance
// 9. class Calling
// 10. Pointers to Class
// 11. Static Member
// 12. Constant Member
// 13. Class Template
// 14. Special Member
// 15. Class Member Calling Sequencs
// 16. Class Member Calling Sequence with Virtual Member
// 17. Class Member Calling Sequence with Different Calling Methods
// 18. Class Member Calling Sequence with Different Calling Methods
// 19. Class Member Calling Sequence with Different Calling Methods
// 20. Class Calling Sequence with Virtual Member
// 21. Calling Oder between Derived and Base Classes

// 26. CLASS MEMBER TYPE CASTIM EXAMPLE
// 27. CLASS INITIALIZATION EXAMPLE
// 28. CLASS CALL SEQUENCE EXAMPLE


#define CASE 26

#if CASE == 0
////////////////////////////////////////////////////////////////////////////////
// 
// 0. SIMPLY DEFINED CLASS
//
class R { 
    int w, h;                               // deafult, private access
  public:
    void init (int x,int y){w = x; h = y;}; // this returns nothing
    int area() {return w*h;}                // this returns, hence R can only return this
};
int main () {
  R rect; // rect has 2 private elements that cannot be accessed by the oursiders.
          // rect has 1 void function which does something.
          // rect has 1 function which can returns a value
  rect.init (11,22); // call the void function inside rect by passing values
  cout<<"R Results: "<<endl; 
  cout << "area: " << rect.area() << "\n" << endl; 
  return 0;
}
#endif

#if CASE == 1
////////////////////////////////////////////////////////////////////////////////
// 
// 1. DEFINE CLASS --> DEFINE MEMBERS
//
class R { 
    int w, h;  
  public:
    void init (int,int); // define the function profile, then define the details later on
    int area() {return w*h;}
};
void R::init (int x, int y) { w = x; h = y;}
int main () {
  R rect;
  rect.init (22,33);
  cout<<"R Results: "<<endl;
  cout << "area: " << rect.area() << "\n" << endl;
  return 0;
}
#endif

#if CASE == 2
////////////////////////////////////////////////////////////////////////////////
// 
// 2. CONSTRUCTOR
//
// A special function avoiding call the member function 
// when its members have not been assigne values.
// - Constructor has same name as the class itself
// - Constructors don’t have return type
// - A constructor is automatically called when an object is created. 
class R { 
    int w, h;  
  public:
    R (int,int); // parameterized constructor to initialize w and h
    int area() {return w*h;}
};
R::R (int a, int b) { w = a; h = b; };
int main () {
  R rect(33,44); // R rect; rect(33,44); is going to be wrong!!!
  cout<<"R Results: "<<endl;
  cout << "area: " << rect.area() << "\n" << endl;
  return 0;
}
#endif

#if CASE == 3
////////////////////////////////////////////////////////////////////////////////
// 
// 3. AUTOMATIC CONSTRUCTOR
//
// if we do not specify a constructor, C++ compiler generates a default constructor 
// for us (expects no parameters and has an empty body). hence the following is what 
// the compiler will do
//
class R { 
    int w, h;  
  public:
    R() {}; // constructor defined by the compiler 
    void init (int,int);
    int area() {return w*h;}
};
void R::init (int a, int b) {w = a; h = b;};
int main () {
  R rect;
  rect.init (44,55);
  cout<<"R Results: "<<endl;
  cout << "area: " << rect.area() << "\n" << endl;
  return 0;
}
#endif

#if CASE == 4
////////////////////////////////////////////////////////////////////////////////
// 
// 4. DEFAULT CONSTRUCTOR 
//
// The constructor which doesn’t take any argument. It has no parameters. 
//
class R { 
    int w, h;  
  public:
    R();   // default constructor to initialize w and h, defined later
           // R(){w=100; h=200;}; can be used
    int area() {return w*h;}
};
R::R () {w = 111; h = 222;};
int main () {
  R rect;       // R rect(); is wrong!!!
  cout<<"R Results: "<<endl;
  cout << "area: " << rect.area() << "\n" << endl;
  return 0;
}
#endif

#if CASE == 5
////////////////////////////////////////////////////////////////////////////////
//
// 5. COPY CONSTRUCTOR
//
class R { 
    int w, h;  
  public:
    R ();         // default constructor to initialize w and h
    R (int,int);  // copy constructor using the parameterized constructer
                  // define it directly R (int a, int b) {w = a;h = b;};
    int area() {return w*h;}
};
R::R () {w = 111;h = 222;};
R::R (int a, int b) {w = a;h = b;};
int main () {
  R rect(55,66);
  cout<<"R Results: "<<endl;
  cout << "area: " << rect.area() << "\n" << endl;
  R rect2;
  cout<<"R Results using default initilization: "<<endl;
  cout << "area: " << rect2.area() << "\n" << endl;
  return 0;
}
#endif

#if CASE == 6
////////////////////////////////////////////////////////////////////////////////
//
// 6. CONSTRUCTOR USING MEMBER INITILIZATION
//
class R { 
    int w, h;  
  public:
    R ();                       // default constructor to initialize w and h
    R (int x,int y):w(x),h(y){} //R(int x, int y){ w=x; h=y;}// R(int x, int y):w(x){h=y;}
    int area() {return w*h;}
};
R::R () {w = 111;h = 222;};
int main () {
  R rect (66,77);
  cout<<"R Results: "<<endl;
  cout << "area: " << rect.area() << "\n" << endl;
  R rect2;
  cout<<"R Results with default initilization: "<<endl;
  cout << "area: " << rect2.area() << "\n" << endl;
  return 0;
}
#endif

#if CASE == 7
////////////////////////////////////////////////////////////////////////////////
//
// 7. FRIED CLASS
//
// a friend class is a class whose members have access to the 
// private or protected members of another class
//
class Square;  // empty declaration of Square and it is necessary because 
               // in the following R uses Square. 
class R { 
    int w, h;  
  public:
    R ();        // default constructor to initialize w and h
    R (int,int); // copy constructor using the parameterized constructer
    int area() {return w*h;};
    void convert (Square a)
};
R::R () {w = 111;h = 222;};
R::R (int a, int b) {w = a;h = b;};
void R::convert (Square a) {
  w = a.side;
  h = a.side;
};

class Square { 
  friend class R;  // define R as a friend of class Square allowing R's member 
                    // functions to access private and protected members of Square. 
                    // More concretely, R accesses the member variable 
                    // Square::side, which describes the side of the square.
                    // R is considered a friend of Square. Square is not 
                    // considered a friend of R. Hence the member functions of 
                    // R can access the protected and private members of Square 
                    // but not the other way around. Of course, Square could also 
                    // be declared friend of R, if needed, granting such an access.
                    // Another property of friendships is that they are not 
                    // transitive: The friend of a friend is not considered a 
                    // friend unless explicitly specified.
  private:
    int side;
  public:
    Square (int a) : side(a) {}  // Square (int a) {side = a;}
};
int main () {
  R rect;
  Square sqr(4);
  rect.convert(sqr);
  cout << rect.area();
  R rect2(77,88);
  cout << rect2.area();
  return 0;
}
#endif

#if CASE == 8
////////////////////////////////////////////////////////////////////////////////
//
// 8. CLASS INHERITANCE
//
// Consider a group of vehicles. You need to create classes for Bus, Car and Truck. 
// The methods fuelAmount(), capacity(), applyBrakes() will be same for all of the 
// three classes. If we create these classes avoiding inheritance then we have to 
// write all of these functions in each of the three classes. 
//
// ou can clearly see that above process results in duplication of same code 3 
// times. This increases the chances of error and data redundancy. To avoid this 
// type of situation, inheritance is used. If we create a class Vehicle and write 
// these three functions in it and inherit the rest of the classes from the vehicle 
// class, then we can simply avoid the duplication of data and increase re-usability. 

// Using inheritance, we have to write the functions only one time instead of three
// times as we have inherited rest of the three classes from base class(Vehicle).

// Implementing inheritance in C++: For creating a sub-class which is inherited 
// from the base class we have to follow the below syntax.
/*
class subclass_name : access_mode base_class_name
{
  //body of subclass
};
*/
// Here, subclass_name is the name of the sub class, access_mode is the mode in 
// which you want to inherit this sub class for example: public, private etc. 
// and base_class_name is the name of the base class from which you want to 
// inherit the sub class.

// Note: A derived class doesn’t inherit access to private data members. However, 
// it does inherit a full parent object, which contains any private members which 
// that class declares.

/*//Base class 
class Parent 
{ 
      int ages;
    protected:
      int address;
    public: 
      int id_p = 1; 
      char code_p{'p'};
}; 
// Sub class inheriting from Base Class(Parent) 
class Child : public Parent 
{ 
    public: 
      int id_c = 2; 
      char code_c{'c'};
}; 
//main function 
int main()  
   { 
        Child c; 
        // An object of class child has all data members and 
        // member functions of class parent 
        cout << "Child id is " <<  c.id_c << endl; 
        cout << "Child code is " <<  c.code_c << endl;
        cout << "Parent id is " <<  c.id_p << endl; 
        cout << "Parent code is " <<  c.code_p << endl;
          
        return 0; 
   }  */

// In the above program the ‘Child’ class is publicly inherited from the 
// ‘Parent’ class so the public data members of the class ‘Parent’ will 
// also be inherited by the class ‘Child’.
//
///////////////////////
// Modes of Inheritance
///////////////////////
//
// - Public mode: If we derive a sub class from a public base class. Then the 
//   public member of the base class will become public in the derived class 
//   and protected members of the base class will become protected in derived class.
// - Protected mode: If we derive a sub class from a Protected base class. 
//   Then both public member and protected members of the base class will become 
//   protected in derived class.
// - Private mode: If we derive a sub class from a Private base class. 
//   Then both public member and protected members of the base class will 
//   become Private in derived class.

// Note : The private members in the base class cannot be directly accessed in 
// the derived class, while protected members can be directly accessed. For example,
// Classes B, C and D all contain the variables x, y and z in below example. 
// It is just question of access. 

/*class subclass_name : access_mode base_class
{
  //body of subclass
};*/

/*class A  
{ 
public: 
    int x; 
protected: 
    int y; 
private: 
    int z; 
}; 
class B : public A 
{ 
    // x is public 
    // y is protected 
    // z is not accessible from B 
}; 
class C : protected A 
{ 
    // x is protected 
    // y is protected 
    // z is not accessible from C 
}; 
class D : private A    // 'private' is default for classes 
{ 
    // x is private 
    // y is private 
    // z is not accessible from D 
}; 
*/
/*
// C++ program to explain Single inheritance 
// base class 
class Vehicle { 
  public: 
    Vehicle() { cout << "This is a Vehicle" << endl;} 
}; 

// sub class derived from two base classes 
class Car: public Vehicle{ }; 
  
// main function 
int main() 
{    
    // creating object of sub class will 
    // invoke the constructor of base classes 
    Car obj; 
    return 0; 
} 
This is a vehicle
*/

////////////////////////
// Multiple Inheritance
////////////////////////

// Multiple Inheritance is a feature of C++ where a class 
// can inherit from more than one classes. i.e one sub class is inherited from 
// more than one base classes.

// Syntax:
// class subclass_name : access_mode base_class1, access_mode base_class2, ....
// {
//   //body of subclass
// };

// Here, the number of base classes will be separated by a comma (‘, ‘) and 
// access mode for every base class must be specified.

/*
// C++ program to explain multiple inheritance 
// first base class 
class Vehicle { 
  public: 
    Vehicle() 
    { 
      cout << "This is a Vehicle" << endl; 
    } 
}; 
// second base class 
class FourWheeler { 
  public: 
    FourWheeler() { cout << "This is a 4 wheeler Vehicle" << endl; } 
}; 
// sub class derived from two base classes 
class Car: public Vehicle, public FourWheeler { 
  
}; 
int main() 
{    
    // creating object of sub class will 
    // invoke the constructor of base classes 
    Car obj; 
    return 0; 
} 
This is a Vehicle
This is a 4 wheeler Vehicle
*/

//////////////////////////
// Multilevel Inheritance
/////////////////////////
//
// In this type of inheritance, a derived class is created from another derived class. 
/*
// C++ program to implement Multilevel Inheritance 
// base class 
class Vehicle  
{ 
  public: 
    Vehicle(){ cout << "This is a Vehicle" << endl; } 
}; 
class fourWheeler: public Vehicle 
{  public: 
    fourWheeler(){ cout<<"Objects with 4 wheels are vehicles"<<endl; } 
}; 
// sub class derived from two base classes 
class Car: public fourWheeler{ 
   public: 
     car() { cout<<"Car has 4 Wheels"<<endl;} 
}; 
  
// main function 
int main() 
{    
    //creating object of sub class will 
    //invoke the constructor of base classes 
    Car obj; 
    return 0; 
} 
This is a Vehicle
Objects with 4 wheels are vehicles
Car has 4 Wheels
*/
////////////////////////////
// Hierarchical Inheritance
///////////////////////////
//
// In this type of inheritance, more than one sub class is inherited from a 
// single base class. i.e. more than one derived class is created from a 
// single base class
/*
// C++ program to implement Hierarchical Inheritance 
// base class 
class Vehicle  
{ 
  public: 
    Vehicle(){cout << "This is a Vehicle" << endl; } 
}; 
// first sub class  
class Car: public Vehicle { };
// second sub class 
class Bus: public Vehicle { }; 
// main function 
int main() 
{    
    // creating object of sub class will invoke the constructor of base class 
    Car obj1; 
    Bus obj2; 
    return 0; 
} 
This is a Vehicle
This is a Vehicle
*/
//
////////////////////////////////
// Hybrid (Virtual) Inheritance
////////////////////////////////
//
// Hybrid Inheritance is implemented by combining 
// more than one type of inheritance. For example: Combining Hierarchical inheritance 
// and Multiple Inheritance.
/*
// base class  
class Vehicle  
{ 
  public: 
    Vehicle() 
    { 
      cout << "This is a Vehicle" << endl; 
    } 
}; 
//base class 
class Fare 
{ 
    public: 
    Fare() 
    { 
        cout<<"Fare of Vehicle\n"; 
    } 
}; 
// first sub class  
class Car: public Vehicle 
{ 
  
}; 
// second sub class 
class Bus: public Vehicle, public Fare 
{ 
      
}; 
// main function  int main()  
{     
// creating object of sub class will  
// invoke the constructor of base class  Bus obj2;  return 0;  
}  
This is a Vehicle Fare of Vehicle */

//Base class Shape
class Shape {
   public:
      void set(int w, int h){width = w;height = h; }
   protected:
      int width;
      int height;
};
// Base class PaintCost
class PaintCost {
   public:
      int getCost(int area) {return area * 70; }
};
// Derived class
class Rectangle: public Shape, public PaintCost {
   public:
      int getArea() {return (width * height); }
};
int main(void) {
   Rectangle Rect;
   int area;
   Rect.set(5,7);
   area = Rect.getArea();
   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;
   // Print the total cost of painting
   cout << "Total paint cost: $" << Rect.getCost(area) << endl;

   return 0;
}

// We can summarize the different access types according to which functions can 
// access them in the following way: 

//Access	                public	protected  private
//members of the same class	yes		yes	   yes
//members of derived class	yes		yes	   no
//not members	              yes		no	   no

// The protected access specifier used in class P is similar to private. 
// Its only difference occurs in fact with inheritance: When a class inherits 
// another one, the members of the derived class can access the protected members 
// inherited from the base class, but not its private members.
#endif

#if CASE == 9
////////////////////////////////////////////////////////////////////////////////
//
// 9. class Calling
//
// Here is an example with four ways to construct objects of a class whose 
// constructor takes a single parameter:
//  C foo (10.0);   // functional form
//  C bar = 20.0;   // assignment init.
//  C baz {30.0};   // uniform init.
//  C qux = {40.0}; // POD-like''
//
// uniform initialization, which essentially is the same as the functional form, 
// but using braces ({}) instead of parentheses (()):
// 
// class_name object_name { value, value, value, ... }
// 
// An advantage of uniform initialization over functional form is that, 
// unlike parentheses, braces cannot be confused with function declarations, 
// and thus can be used to explicitly call default constructors:
//
// R rectb;   // default constructor called
// R rectc(); // function declaration (default constructor NOT called)
// R rectd{}; // default constructor called 
//
class C {
    double radius;
  public:
  	C(){}
    C(double r) { radius = r; }
    double length() {return 2*radius*3.14159265;}
};
class Arc {
    double radius,angle;
  public:
    Arc(double r, double a) { radius = r; angle = a;}
    double length() {return 2*radius*3.14159265*angle/360;}
};

int main () 
{
  C C1,C2{},C3();

  C c1 (10.0);   // functional form
  cout << "c1's lengthference: " << c1.length() << '\n';

  C c2 = 20.0;   // assignment init.
  cout << "c2's lengthference: " << c2.length() << '\n';

  C c3 {30.0};   // uniform init.
  cout << "c3s lengthference: " << c3.length() << '\n';

  C c4 = {40.0}; // POD-like
  cout << "c4's lengthference: " << c4.length() << '\n';

  Arc a1 (10.0,90);   // functional form
  cout << "a1's arc length: " << c1.length() << '\n';

  Arc a3 {30.0,270};   // uniform init.
  cout << "a3's arc length: " << a3.length() << '\n';

  Arc a4 = {40.0,360}; // POD-like
  cout << "a4's arc length: " << a4.length() << '\n';

  return 0;
}
#endif 

#if CASE == 10
////////////////////////////////////////////////////////////////////////////////
//
// 10. Pointers to Class
//
// Objects can also be pointed to by pointers: Once declared, a class becomes a 
// valid type, so it can be used as the type pointed to by a pointer. For example:
// 		R * prect;
// is a pointer to an object of class R. Similarly as with plain data 
// structures, the members of an object can be accessed directly from a pointer 
// by using the arrow operator (->). Here is an example with some possible 
// combinations.
//
// This example makes use of several operators to operate on objects and pointers 
// (operators *, &, ., ->, []). They can be interpreted as:
//
// expression	can be read as
// *x	        pointed to by x
// &x	        address of x
// x.y	        member y of object x
// x->y	        member y of object pointed to by x
// (*x).y	    member y of object pointed to by x (equivalent to the previous one)
// x[0]	        first object pointed to by x
// x[1]	        second object pointed to by x
// x[n]	        (n+1)th object pointed to by x
//
// Most of these expressions have been introduced in earlier chapters. Most notably,
// the chapter about arrays introduced the offset operator ([]) and the chapter about 
// plain data structures introduced the arrow operator (->).
#include <math.h> 
class R {
  int w, h;
public:
  R(){}
  R(int x, int y) : w(x), h(y) {}
  R(const R &p) {w = p.w; h = p.h; } // user-defined copy constructor: a member function which 
                                     // initializes an object using another object of 
                                     // the same class. A copy constructor has the 
                                     // following general function prototype
                                     //
                                     // ClassName (const ClassName &old_obj); 
  int area(void) { return w * h; }
  int circum(void) {return 2*(w+h);}
  double diag(void) {return sqrt(w*w+h*h);}
};
int main() 
{
  R obj (3, 4);
  cout << "obj's area: " << obj.area() << '\n';
  cout << "obj's circum: " << obj.circum() << '\n';
  cout << "obj's diag: " << obj.diag() << '\n';

  R *foo;
  foo = &obj;
  cout << "*foo's area: " << foo->area() << '\n';
  cout << "*foo's circum: " << foo->circum() << '\n';
  cout << "*foo's diag: " << foo->diag() << '\n';

  R *bar;
  bar = new R (5, 6);
  cout << "*bar's area: " << bar->area() << '\n';
  cout << "*bar's circum: " << bar->circum() << '\n';
  cout << "*bar's diag: " << bar->diag() << '\n';

  R *baz;
  baz = new R[2] { {7,8}, {9,10} };
  cout << "baz[0]'s area:" << baz[0].area() << '\n';
  cout << "baz[1]'s area:" << baz[1].area() << '\n';   
  cout << "baz[0]'s circum:" << baz[0].circum() << '\n';
  cout << "baz[1]'s circum:" << baz[1].circum() << '\n';   
  cout << "baz[0]'s diag:" << baz[0].diag() << '\n';
  cout << "baz[1]'s diag:" << baz[1].diag() << '\n';  
/*  cout << "baz[0]'s area:" << baz[0]->area() << '\n';  // this is wrong, why?
  cout << "baz[1]'s area:" << baz[1]->area() << '\n';   
  cout << "baz[0]'s circum:" << baz[0]->circum() << '\n';
  cout << "baz[1]'s circum:" << baz[1]->circum() << '\n';   
  cout << "baz[0]'s diag:" << baz[0]->diag() << '\n';
  cout << "baz[1]'s diag:" << baz[1]->diag() << '\n';  */

  R alp=obj;  // This also calls copy constructor
  cout << "alp's area: " << alp.area() << '\n';
  cout << "alp's circum: " << alp.circum() << '\n';
  cout << "alp's diag: " << alp.diag() << '\n';

  R beta(alp);
  cout << "beta's area: " << beta.area() << '\n';
  cout << "beta's circum: " << beta.circum() << '\n';
  cout << "beta's diag: " << beta.diag() << '\n';

  R garmma; // default construct garmma 
  garmma = alp;
  cout << "garmma's area: " << garmma.area() << '\n';
  cout << "garmma's circum: " << garmma.circum() << '\n';
  cout << "garmma's diag: " << garmma.diag() << '\n';

  delete bar;
  delete[] baz; // baz is a aaray with elements in R

  return 0;
}	
#endif

#if CASE == 11
////////////////////////////////////////////////////////////////////////////////
//
// 11. Static Member
//
// A class can contain static members, either data or functions.
// A static data member of a class is also known as a "class variable", 
// because there is only one common variable for all the objects of that 
// same class, sharing the same value: i.e., its value is not different 
// from one object of this class to another.
//
// For example, it may be used for a variable within a class that can contain a 
// counter with the number of objects of that class that are currently allocated, 
// as in the following example:
class D {
  public:
    static int n;
    D () { n++; };
};
int D::n=0;
int main () 
{
  D a;
  cout << "a.n = "<<a.n << '\n';
  cout << "D::n  = "<<D::n << '\n';

  D b;
  cout << "b.n = "<<b.n << '\n';
  cout << "D::n  = "<<D::n << '\n';

  D c;
  cout << "c.n = "<<c.n << '\n';
  cout << "D::n  = "<<D::n << '\n';

  D d[10];
  cout <<"D::n = " << D::n << '\n';

  for (int i=0; i<10; i++)
  {
  	 D e[i];
     cout << "e["<<i<<"].n = "<<e[i].n << '\n';
     cout << i <<" D::n = " << D::n << '\n';
   };

  cout <<"D::n = " << D::n << '\n';

  D * f = new D;
  cout << f->n << '\n';
  cout <<"D::n = " << D::n << '\n';

  delete f;
  return 0;
}

// In fact, static members have the same properties as non-member variables but they
// enjoy class scope. For that reason, and to avoid them to be declared several times, 
// they cannot be initialized directly in the class, but need to be initialized somewhere 
// outside it. As in the previous example:
//
// int D::n=0;
// 
// Because it is a common variable value for all the objects of the same class, it can be 
// referred to as a member of any object of that class or even directly by the class name
// (of course this is only valid for static members):
//
// cout << a.n;
// cout << D::n;
// 
// These two calls above are referring to the same variable: the static variable n within 
// class D shared by all objects of this class. Again, it is just like a non-member 
// variable, but with a name that requires to be accessed like a member of a class (or an
// object). 
//
// Classes can also have static member functions. These represent the same: members of a
// class that are common to all object of that class, acting exactly as non-member 
// functions but being accessed like members of the class. Because they are like 
// non-member functions, they cannot access non-static members of the class (neither 
// member variables nor member functions). They neither can use the keyword this.
#endif

#if CASE == 12
////////////////////////////////////////////////////////////////////////////////
//
// 12. CONSTANT MEMBER
//
// Data members of a class may be declared as const. Such a data member must be
// initialized by the constructor using an initialization list. Once
// initialized, a const data member may never be modified, not even in the
// constructor or destructor. 

// Declaring a member function with the const keyword specifies that the
// function is a "read-only" function that does not modify the object for which
// it is called. Namely, The access to its data members from outside the class 
// is restricted to read-only, as if all its data members were const for those 
// accessing them from outside the class. 

// Data members that are both static and const have their own rules for
// initialization.

// An object of a class may be declared to be const, just like any other C++
// variable. For example:
//		const Date birthday(7, 3, 1969);
// declares a const object named birthday of the Date class.

// The const property of an object goes into effect after the constructor
// finishes executing and ends before the class's destructor executes. So the
// constructor and destructor can modify the object, but other methods of the
// class can't.

// You can declare a method of a class to be const. This must be done both in
// the method's prototype and in its definition by coding the keyword const
// after the method's parameter list. For example:
// 		int get_month() const;           // prototype in Date class definition
//		int Date::get_month() const      // method definition
//		{    return month;     }
//
// The this pointer passed to a const method is a pointer to a const object.
// That means the pointer can not be used to modify the object's data members.
// Any attempt to change a data member of the object that called a const method
// will result in a syntax error, as will attempting to call a non-const method
// for that object.

// const objects can only call const methods. Objects that are not const can
// call either const or non-const methods. A constant member function cannot 
// modify any non-static data members or call any member functions that aren't 
// constant.

// A const method can be overloaded with a non-const version. The choice of
// which version to use is made by the compiler based on the context in which
// the method is called.

// Constructors and destructors can never be declared as const. They are always
// allowed to modify an object even if the object is const.

// To declare a constant member function, place the const keyword after the closing
// parenthesis of the argument list. The const keyword is required in both the
// declaration and the definition.

// const Member Function Pledge
/*
I promise not to modify the object which calls me
(either directly or indirectly), and therefore
I may be called by const objects.

    "Directly" means changes a private data member in the body of the code.
    "Indirectly" means call a non-const member function or pass the const object
    "as a non-const parameter. 
*/
/*
// constant_member_function.cpp
class Date
{
public:
   Date( int mn, int dy, int yr );
   int getMonth() const;     // A read-only function
   void setMonth( int mn );   // A write function; can't be const
private:
   int month;
};
int Date::getMonth() const {return month;}   // Doesn't modify anything
void Date::setMonth( int mn ) {month = mn; } // Modifies data member
int main()
{
   Date MyDate( 7, 4, 1998 );
   MyDate.setMonth( 4 );    // Okay
   MyDate.getMonth();       // Okay

   const Date BirthDate( 1, 18, 1953 );
   BirthDate.getMonth();    // Okay cost member can access const member
   BirthDate.setMonth( 4 ); // C2662 Error, const member cannot access non-const member
}
*/
/*class M {
  public:
    int x;
    M(int val) : x(val) {}
    int get() {return x;}
};

int main() {
  const M foo(10);
  // foo.x = 20;  // not valid: x cannot be modified since foo is const.
  cout << foo.x << '\n';  // ok: data member x can be read
  return 0;
}*/

// The member functions of a const object can only be called if they are themselves 
// specified as const members; in the example above, member get (which is not specified 
// as const) cannot be called from foo. To specify that a member is a const member, the 
// const keyword shall follow the function prototype, after the closing parenthesis for 
// its parameters:
//
// int get() const {return x;}
//
// Note that const can be used to qualify the type returned by a member function. This 
// const is not the same as the one which specifies a member as const. Both are 
// independent and are located at different places in the function prototype:
//
// int get() const {return x;}        // const member function
// const int& get() {return x;}       // member function returning a const&
// const int& get() const {return x;} // const member function returning a const& 
//
// Member functions specified to be const cannot modify non-static data members nor call 
// other non-const member functions. In essence, const members shall not modify the state 
// of an object.
// 
// const objects are limited to access only member functions marked as const, but non-const 
// objects are not restricted and thus can access both const and non-const member functions 
// alike.
//
// You may think that anyway you are seldom going to declare const objects, and thus marking
// all members that don't modify the object as const is not worth the effort, but const 
// objects are actually very common. Most functions taking classes as parameters actually 
// take them by const reference, and thus, these functions can only access their const 
// members:
	
// const objects
/*class M {
    int x;
  public:
    M(int val) : x(val) {}
    const int& get() const {return x;}
};

void print (const M& arg) {cout << arg.get() << '\n';}

int main() {
  M foo (10);
  print(foo);

  return 0;
}*/

// If in this example, get was not specified as a const member, the call to arg.get() in 
// the print function would not be possible, because const objects only have access to 
// const member functions.
// 
// Member functions can be overloaded on their constness: i.e., a class may have two member
// unctions with identical signatures except that one is const and the other is not: in 
// this case, the const version is called only when the object is itself const, and the 
// non-const version is called when the object is itself non-const.

// overloading members on constness
class M {
    int x;
  public:
    M(int val) : x(val) {}                  //1.
    const int& get() const {return x;}      //2.
    int& get() {return x;}                  //3.
};

int main() {
  M foo (10);                // constructor in //1.
  cout << foo.get() << '\n'; // ok to access foo.get() in //3. or //2.
  foo.get() = 15;            // ok to modify since get() returns int& in //3.

  const M bar (20);
  cout << bar.get() << '\n'; // ok to access bar.get() in //2. - reading 
  //bar.get() = 25;          // not valid, since bar is constant, it can only access
                             // the constant member  get() in //.2., whihc returns 
                             // const int& and caanot be modified

  return 0;
}
#endif


#if CASE == 13
////////////////////////////////////////////////////////////////////////////////
//
// 13. CLASS TEMPLATE
//
// Just like we can create function templates, we can also create class templates, 
// allowing classes to have members that use template parameters as types. For example:

/*template <class T>
class mypair {
    T values [2];
  public:
    mypair (T first, T second)
    {
      values[0]=first; values[1]=second;
    }
};*/

// The class that we have just defined serves to store two elements of any valid type. 
// For example, if we wanted to declare an object of this class to store two integer 
// values of type int with the values 115 and 36 we would write:
//
// mypair<int> myobject (115, 36);
// 
// This same class could also be used to create an object to store any other type, such as:
//
// mypair<double> myfloats (3.0, 2.18); 
//
// The constructor is the only member function in the previous class template and it 
// has been defined inline within the class definition itself. In case that a member 
// function is defined outside the defintion of the class template, it shall be preceded 
// with the template <...> prefix:

// class templates
/*#include <iostream>
using namespace std;

template <class T>
class mypair {
    T a, b;
  public:
    mypair (T first, T second)
      {a=first; b=second;}
    T getmax ();
};

template <class T>
T mypair<T>::getmax ()
{
  T retval;
  retval = a>b? a : b;
  return retval;
}

int main () {
  mypair <int> myobject (100, 75);
  cout << myobject.getmax();
  return 0;
}*/
// 
// Notice the syntax of the definition of member function getmax:
//
// template <class T>
// T mypair<T>::getmax () 
//
// Confused by so many T's? There are three T's in this declaration: 
//  - The first one is the template parameter. Template parameter 
//    is also the class template parameter.
//  - The second T refers to the type returned by the function. 
//  - The third T (the one between angle brackets) is also a requirement: 
//    It specifies that this function's 
// 
// Template specialization
//
// It is possible to define a different implementation for a template when a 
// specific type is passed as template argument. This is called a template specialization.
// For example, let's suppose that we have a very simple class called mycontainer 
// that can store one element of any type and that has just one member function called 
// increase, which increases its value. But we find that when it stores an element of 
// type char it would be more convenient to have a completely different implementation 
// with a function member uppercase, so we decide to declare a class template specialization 
// for that type:

// class template:
/*template <class T>
class mycontainer {
    T element;
  public:
    mycontainer (T arg) {element=arg;}
    T increase () {return ++element;}
};

// class template specialization:
template <>
class mycontainer <char> {
    char element;
  public:
    mycontainer (char arg) {element=arg;}
    char uppercase ()
    {
      if ((element>='a')&&(element<='z'))
      element+='A'-'a';
      return element;
    }
};

int main () {
  mycontainer<int> myint (7);
  mycontainer<char> mychar ('j');
  cout << myint.increase() << endl;
  cout << mychar.uppercase() << endl;
  return 0;
}*/

// This is the syntax used for the class template specialization:
//
// template <> class mycontainer <char> { ... };
//
// First of all, notice that we precede the class name with template<> , 
// including an empty parameter list. This is because all types are known and no 
// template arguments are required for this specialization, but still, 
// it is the specialization of a class template, and thus it requires to be noted as such.
// But more important than this prefix, is the <char> specialization parameter 
// after the class template name. This specialization parameter itself identifies 
// the type for which the template class is being specialized (char). Notice the 
// differences between the generic class template and the specialization:
//
// template <class T> class mycontainer { ... };
// template <> class mycontainer <char> { ... };
//
// The first line is the generic template, and the second one is the specialization.
//
// When we declare specializations for a template class, we must also define 
// all its members, even those identical to the generic template class, because
// there is no "inheritance" of members from the generic template to the specialization.

template <class T>
class mypair {
    T a, b;
  public:
    mypair (T first, T second) {a=first; b=second;}
    T getmax ();
};
template <class T>
T mypair<T>::getmax ()
{
  T retval;
  retval = a>b? a : b;
  return retval;
}
template <class T>
class mycontainer {
    T element;
  public:
    mycontainer (T arg) {element=arg;}
    T increase () {return ++element;}
};
// class template specialization:
template <>
class mycontainer <char> {
    char element;
  public:
    mycontainer (char arg) {element=arg;}
    char uppercase ()
    {
      if ((element>='a')&&(element<='z'))
      element+='A'-'a';
      return element;
    }
};
int main () 
{
  mypair <int> myobject (100, 75);
  cout << "myobject.getmax() = "<<myobject.getmax()<<'\n';
  
  mycontainer<int> myint (7);
  mycontainer<char> mychar ('k');
  cout << "myint.increase() = "<<myint.increase() << endl;
  cout << "mychar.uppercase() = "<<mychar.uppercase() << endl;
  return 0;
}
#endif

#if CASE == 14
////////////////////////////////////////////////////////////////////////////////
//
// 14. SPECIAL MEMBER
//
////////////////////////////////////////////////////////////////////////////////
//
// Special member functions are member functions that are implicitly defined as 
// member of classes under certain circumstances. There are six:

/*Member function	    typical form for class C:
Default constructor	C::C();
Destructor	        C::~C();
Copy constructor	C::C (const C&);
Copy assignment	    C& operator= (const C&);
Move constructor	C::C (C&&);
Move assignment	    C& operator= (C&&);*/

// Let's examine each of these:

//////////////////////////
// a. Default constructor
//////////////////////////
//
// The default constructor is the constructor called when objects of a class are declared,
// but are not initialized with any arguments. If a class definition has no constructors, 
// the compiler assumes the class to have an implicitly defined default constructor. 
// Therefore, after declaring a class like this:

/*class Example {
  public:
    int total;
    void accumulate (int x) { total += x; }
};*/
// 
// The compiler assumes that Example has a default constructor. Therefore, objects of 
// this class can be constructed by simply declaring them without any arguments:
// 
// Example ex;
//
// But as soon as a class has some constructor taking any number of parameters explicitly 
// declared, the compiler no longer provides an implicit default constructor, and no longer 
// allows the declaration of new objects of that class without arguments. For example, 
// the following class:
/*
class Example2 {
  public:
    int total;
    Example2 (int initial_value) : total(initial_value) { };
    void accumulate (int x) { total += x; };
};
*/
// Here, we have declared a constructor with a parameter of type int. Therefore the 
// following object declaration would be correct:
//
// Example2 ex (100);   // ok: calls constructor 
//
// But the following:
// 
// Example2 ex;         // not valid: no default constructor 
//
// Would not be valid, since the class has been declared with an explicit constructor 
// taking one argument and that replaces the implicit default constructor taking none.
// Therefore, if objects of this class need to be constructed without arguments, the
//  proper default constructor shall also be declared in the class. For example:

// classes and default constructors
/*#include <iostream>
#include <string>
using namespace std;

class Example3 {
    string data;
  public:
    Example3 (const string& str) : data(str) {}
    Example3() {}
    const string& content() const {return data;}
};

int main () {
  Example3 foo;
  Example3 bar ("Example");

  cout << "bar's content: " << bar.content() << '\n';
  return 0;
}
*/
// Here, Example3 has a default constructor (i.e., a constructor without parameters) 
// defined as an empty block:
//
// Example3() {}
//
// This allows objects of class Example3 to be constructed without arguments (like 
// foo was declared in this example). Normally, a default constructor like this is 
// implicitly defined for all classes that have no other constructors and thus no 
// explicit definition is required. But in this case, Example3 has another constructor:
//
// Example3 (const string& str);
//
// And when any constructor is explicitly declared in a class, no implicit default 
// constructors is automatically provided.
//
////////////////
// b. Destructor
////////////////
// 
// Destructors fulfill the opposite functionality of constructors: They are 
// responsible for the necessary cleanup needed by a class when its lifetime
// ends. The classes we have defined in previous chapters did not allocate any 
// resource and thus did not really require any clean up.
// 
// But now, let's imagine that the class in the last example allocates dynamic 
// memory to store the string it had as data member; in this case, it would be 
// very useful to have a function called automatically at the end of the object's
// life in charge of releasing this memory. To do this, we use a destructor. 
// A destructor is a member function very similar to a default constructor: 
// it takes no arguments and returns nothing, not even void. It also uses the 
// class name as its own name, but preceded with a tilde sign (~):

// destructors
/*#include <iostream>
#include <string>
using namespace std;

class Example4 {
    string* ptr;
  public:
    // constructors:
    Example4() : ptr(new string) {}
    Example4 (const string& str) : ptr(new string(str)) {}
    // destructor:
    ~Example4 () {delete ptr;}
    // access content:
    const string& content() const {return *ptr;}
};

int main () {
  Example4 foo;
  Example4 bar ("Example");

  cout << "bar's content: " << bar.content() << '\n';
  return 0;
}*/

//
// On construction, Example4 allocates storage for a string. Storage that is
//  later released by the destructor.
// The destructor for an object is called at the end of its lifetime; in the 
// case of foo and bar this happens at the end of function main.
//
//////////////////////
// c. Copy constructor
///////////////////////
//
// When an object is passed a named object of its own type as argument, its 
// copy constructor is invoked in order to construct a copy.
// 
// A copy constructor is a constructor whose first parameter is of type reference 
// to the class itself (possibly const qualified) and which can be invoked with a 
// single argument of this type. For example, for a class M, the copy 
// constructor may have the following signature:
//
// M::M (const M&);
//
// If a class has no custom copy nor move constructors (or assignments) defined, 
// an implicit copy constructor is provided. This copy constructor simply performs 
// a copy of its own members. For example, for a class such as:

/*class M {
  public:
    int a, b; string c;
};*/
//
// An implicit copy constructor is automatically defined. The definition assumed 
// for this function performs a shallow copy, roughly equivalent to:
//
// M::M(const M& x) : a(x.a), b(x.b), c(x.c) {}
//
// This default copy constructor may suit the needs of many classes. But shallow 
// copies only copy the members of the class themselves, and this is probably not 
// what we expect for classes like class Example4 we defined above, because it 
// contains pointers of which it handles its storage. For that class, performing 
// a shallow copy means that the pointer value is copied, but not the content itself; 
// This means that both objects (the copy and the original) would be sharing a single 
// string object (they would both be pointing to the same object), and at some point 
// (on destruction) both objects would try to delete the same block of memory, probably 
// causing the program to crash on runtime. This can be solved by defining the following 
// custom copy constructor that performs a deep copy:

// copy constructor: deep copy
/*class Example5 {
    string* ptr;
  public:
    Example5 (const string& str) : ptr(new string(str)) {}
    ~Example5 () {delete ptr;}
    // copy constructor:
    Example5 (const Example5& x) : ptr(new string(x.content())) {}
    // access content:
    const string& content() const {return *ptr;}
};

int main () {
  Example5 foo ("Example");
  Example5 bar = foo;

  cout << "bar's content: " << bar.content() << '\n';
  return 0;
}*/
//
// The deep copy performed by this copy constructor allocates storage 
// for a new string, which is initialized to contain a copy of the original 
// object. In this way, both objects (copy and original) have distinct copies 
// of the content stored in different locations.
//
/////////////////////
// d. Copy assignment
/////////////////////
//
// Objects are not only copied on construction, when they are initialized: 
// They can also be copied on any assignment operation. See the difference:

/*M foo;
M bar (foo);       // object initialization: copy constructor called
M baz = foo;       // object initialization: copy constructor called
foo = bar;               // object already initialized: copy assignment called */
//
// Note that baz is initialized on construction using an equal sign, but 
// this is not an assignment operation! (although it may look like one): 
// The declaration of an object is not an assignment operation, it is just 
// another of the syntaxes to call single-argument constructors.
// 
// The assignment on foo is an assignment operation. No object is being declared 
// here, but an operation is being performed on an existing object; foo.

// The copy assignment operator is an overload of operator= which takes a value 
// or reference of the class itself as parameter. The return value is generally 
// a reference to *this (although this is not required). For example, for a class 
// M, the copy assignment may have the following signature:
//
// M& operator= (const M&);
//
//The copy assignment operator is also a special function and is also defined implicitly 
// if a class has no custom copy nor move assignments (nor move constructor) defined.

// But again, the implicit version performs a shallow copy which is suitable for 
// many classes, but not for classes with pointers to objects they handle its storage, 
// as is the case in Example5. In this case, not only the class incurs the risk of 
// deleting the pointed object twice, but the assignment creates memory leaks by not 
// deleting the object pointed by the object before the assignment. These issues could
// be solved with a copy assignment that deletes the previous object and performs a deep copy:

/*Example5& operator= (const Example5& x) {
  delete ptr;                      // delete currently pointed string
  ptr = new string (x.content());  // allocate space for new string, and copy
  return *this;
}

// Or even better, since its string member is not constant, it could re-utilize the same string object:
//
Example5& operator= (const Example5& x) {
  *ptr = x.content();
  return *this;
}*/
//
/////////////////////////////////////
// e. Move constructor and assignment
/////////////////////////////////////
//
// Similar to copying, moving also uses the value of an object to set the value 
// to another object. But, unlike copying, the content is actually transferred 
// from one object (the source) to the other (the destination): the source loses 
// that content, which is taken over by the destination. This moving only happens
// when the source of the value is an unnamed object.

// Unnamed objects are objects that are temporary in nature, and thus haven't even
// been given a name. Typical examples of unnamed objects are return values of
// functions or type-casts.

// Using the value of a temporary object such as these to initialize another object 
// or to assign its value, does not really require a copy: the object is never going 
// to be used for anything else, and thus, its value can be moved into the destination  
// object. These cases trigger the move constructor and move assignments:

// The move constructor is called when an object is initialized on construction 
// using an unnamed temporary. Likewise, the move assignment is called when an
// object is assigned the value of an unnamed temporary:

/*M fn();            // function returning a M object
M foo;             // default constructor
M bar = foo;       // copy constructor
M baz = fn();      // move constructor
foo = bar;         // copy assignment
baz = M();         // move assignment */
//
// Both the value returned by fn and the value constructed with M are unnamed temporaries.
// In these cases, there is no need to make a copy, because the unnamed object is 
// very short-lived and can be acquired by the other object when this is a more efficient operation.
//
// The move constructor and move assignment are members that take a parameter of 
// type rvalue reference to the class itself:

/*M (M&&);             // move-constructor
M& operator= (M&&);  // move-assignment */

// An rvalue reference is specified by following the type with two ampersands (&&). 
// As a parameter, an rvalue reference matches arguments of temporaries of this type.

// The concept of moving is most useful for objects that manage the storage they use, 
// such as objects that allocate storage with new and delete. In such objects, copying 
// and moving are really different operations:
// - Copying from A to B means that new memory is allocated to B and then the 
//   entire content of A is copied to this new memory allocated for B.
// - Moving from A to B means that the memory already allocated to A is 
//   transferred to B without allocating any new storage. It involves simply copying the pointer.

/*For example: move constructor/assignment
class Example6 {
    string* ptr;
  public:
    Example6 (const string& str) : ptr(new string(str)) {}
    ~Example6 () {delete ptr;}
    // move constructor
    Example6 (Example6&& x) : ptr(x.ptr) {x.ptr=nullptr;}
    // move assignment
    Example6& operator= (Example6&& x) {
      delete ptr; 
      ptr = x.ptr;
      x.ptr=nullptr;
      return *this;
    }
    // access content:
    const string& content() const {return *ptr;}
    // addition:
    Example6 operator+(const Example6& rhs) {
      return Example6(content()+rhs.content());
    }
};
int main () {
  Example6 foo ("Exam");
  Example6 bar = Example6("ple");   // move-construction
  foo = foo + bar;                  // move-assignment
  cout << "foo's content: " << foo.content() << '\n';
  return 0;
}*/

// Compilers already optimize many cases that formally require a 
// move-construction call in what is known as Return Value Optimization. 
// Most notably, when the value returned by a function is used to initialize
// an object. In these cases, the move constructor may actually never get called.

// Note that even though rvalue references can be used for the type of any
// function parameter, it is seldom useful for uses other than the move constructor. 
// Rvalue references are tricky, and unnecessary uses may be the source of errors quite difficult to track.
//
//////////////////////
// f. Implicit members
//////////////////////
//
// The six special members functions described above are members 
// implicitly declared on classes under certain circumstances:

/*Member function	implicitly defined:	default definition:
Default constructor	if no other constructors	does nothing
Destructor	if no destructor	does nothing
Copy constructor	if no move constructor and no move assignment	copies all members
Copy assignment	if no move constructor and no move assignment	copies all members
Move constructor	if no destructor, no copy constructor and no copy nor move assignment	moves all members
Move assignment	if no destructor, no copy constructor and no copy nor move assignment	moves all members
*/
// Notice how not all special member functions are implicitly defined in the 
// same cases. This is mostly due to backwards compatibility with C structures 
// and earlier C++ versions, and in fact some include deprecated cases. Fortunately,
// each class can select explicitly which of these members exist with their default 
// definition or which are deleted by using the keywords default and delete, 
// respectively. The syntax is either one of:

/*function_declaration = default;
function_declaration = delete;

For example:

// default and delete implicit members
#include <iostream>
using namespace std;

class R {
    int w, h;
  public:
    R (int x, int y) : w(x), h(y) {}
    R() = default;
    R (const R& other) = delete;
    int area() {return w*h;}
};

int main () {
  R foo;
  R bar (10,20);

  cout << "bar's area: " << bar.area() << '\n';
  return 0;
}*/

// Here, R can be constructed either with two int arguments 
// or be default-constructed (with no arguments). It cannot however 
// be copy-constructed from another R object, because this 
// function has been deleted. Therefore, assuming the objects of the 
// last example, the following statement would not be valid:

// R baz (foo);
//
// It could, however, be made explicitly valid by defining its copy constructor as:
//
// R::R (const R& other) = default;
// Which would be essentially equivalent to:

// R::R (const R& other) : w(other.w), h(other.h) {}
//
// Note that, the keyword default does not define a member function equal to
//  the default constructor (i.e., where default constructor means constructor
//  with no parameters), but equal to the constructor that would be 
// implicitly defined if not deleted.

// In general, and for future compatibility, classes that explicitly
// define one copy/move constructor or one copy/move assignment but 
// not both, are encouraged to specify either delete or default on 
// the other special member functions they don't explicitly define.
#endif
    
#if CASE == 15
//////////////////////////////////////////////////////////////////////////
//
// 15. CLASS MEMBER CALLING SEQUENCS
//
class A {
public:
  A() { cout << "a"; }
  ~A() { cout << "A"; }
};
class B {
public:
  B() { cout << "b"; }
  ~B() { cout << "B"; }
};
class C {
public:
  C() { cout << "c"; }
  ~C() { cout << "C"; }
};
A a;
int main() {
  C c;
  B b;
}
// Answer - The program is guaranteed to output: acbBCA
// Explanation
//
// [basic.start.dynamic]§6.6.3¶5 in the standard:
// It is implementation-defined whether the dynamic initialization of a non-local 
// inline variable with static storage duration is sequenced before the first 
// statement of main or is deferred. If it is deferred, it strongly happens before 
// any non-initialization odr-use of that variable."

// Since A() is not constexpr, the initialization of a is dynamic. There are two 
// possibilities:
// - a is initialized before main() is called, i.e. before b or c are initialized.
// - a is not initialized before main(). It is however guaranteed to be initialized 
// before the the use of any function defined in the same translation unit, i.e. 
// before the constructors of b and c are called.

// Then, b and c are initialized in order.
//
// Before main() exits, b and c are destructed in the reverse order of their 
// construction. Then, when main() returns, a is destructed as per §6.6.4 in 
// the standard:
// "Destructors for initialized objects (...) with static storage duration 
// are called as a result of returning from main."
#endif

#if CASE == 16
///////////////////////////////////////////////////////////////////////////////////////
//
// 16. CLASS MEMBER CALLING SEQUENCE WITH VIRTUAL MEMBER
//
struct A {
  A() { foo(); }
  virtual ~A() { foo(); }
  virtual void foo() { cout << "1"; }
  void bar() { foo(); }
};
struct B : public A {
  virtual void foo() { cout << "2"; }
};
int main() {
  B b;
  b.bar();
}
// Answer - The program is guaranteed to output: 121
// Even though foo() is virtual, it is not considered to be so during the execution of 
// constructors and destructors.

// If an object of type B is being constructed, 
// - first the constructor of A is called, 
// - then the constructor of B. 
// Thus, during A's constructor, the "B part" of the object has not been constructed yet, 
// and should not be used. One could easily imagine that B::foo() would use the "B part" 
// of the object, so it would be dangerous for A's constructor to call it.

// When the object is destroyed, B's destructor is called first, then A's destructor, 
// leading to the same problem.
#endif 


#if CASE == 17
///////////////////////////////////////////////////////////////////////////////////////
//
// 17. CLASS MEMBER CALLING SEQUENCE WITH DIFFERENT CALLING METHODS
//
#include <utility>
struct X {
    X() { cout << "1"; }
    X(X &) { cout << "2"; }
    X(const X &) { cout << "3"; }
    X(X &&) { cout << "4"; }
    ~X() { cout << "5"; }
};
struct Y {
    mutable X x;
    Y() = default;
    Y(const Y &) = default;
};
int main() {
    Y y1;
    Y y2 = move(y1);
}
// Answer - The program is guaranteed to output: 1255

// Explanation

// First, the line Y y1; creates an instance of Y. Y has an X data member, 
// which is default constructed, printing 1.

// Then, Y y2 = move(y1);

// copy-initializes another Y. The move turns y1 into an rvalue, but since 
// Y has no move constructor, its copy constructor is called. The implicitly-defined 
// copy-constructor performs a copy of x, as specified in [class.copy.ctor]§15.8.1¶14:

// The implicitly-defined copy/move constructor for a non-union class X performs 
// a memberwise copy/move of its bases and members.

// Now the question is which copy constructor is used to initialize the copy of x. 
// Will it pick X(X &) or X(const X &)? The Y inside the Y(const Y &) copy constructor
// is const, but x is marked mutable, and [dcl.stc]§10.1.1¶9 says:

// The mutable specifier on a class data member nullifies a const specifier applied 
// to the containing class object and permits modification of the mutable class member 
// even though the rest of the object is const

// So x is considered non-const, and X(X &) is a better match to overload resolution 
// than X(const X &), because in the latter case, a const conversion has to happen.
// So X(X &) is called, printing 2.

// Finally, both y1 and y2 are destroyed at the end of main, printing 55.
#endif

#if CASE == 18
///////////////////////////////////////////////////////////////////////////////////////
//
// 18. CLASS MEMBER CALLING SEQUENCE WITH DIFFERENT CALLING METHODS
//
class A
{
  public:
    A(int n = 0): m(n) { cout << 'd'<< "\n" << endl; }
    A(const A& a): m(a.m) { cout << 'c'<< "\n" << endl;}
  private:
    int m;
};
void f(const A &a1, const A &a2 = A()) { }
int main()
{
	cout << "----A a(2);----" << "\n" << endl;
    A a(2);  // d
    cout << "----A b;----" << "\n" << endl;
    A b;  // d
    cout << "-----const A c(a);----" << "\n" << endl;
    const A c(a);  // c
    cout << "-----const A &d = c;----" << "\n" << endl;
    const A &d = c;  // 
    cout << "-----const A e = b;----" << "\n" << endl;
    const A e = b;  // c
    cout << "----b = d;----" << "\n" << endl;
    b = d;  // 
    cout << "----A *p = new A(c);----" << "\n" << endl;
    A *p = new A(c);  // c
    cout << "----A *q = &a;---" << "\n" << endl;
    A *q = &a;  // d
    cout << "----static_cast<void>(q);----" << "\n" << endl;
    static_cast<void>(q);  // d
    cout << "----delete p;----" << "\n" << endl;
    delete p;
    cout << "----f(3,4);----" << "\n" << endl;
    f(3,4);  // d d
    return 0;
}
#endif

#if CASE == 19
//////////////////////////////////////////////////////////////////////////////////////
//
// 19. CALLING EXAMPLE
//
struct X {
    X() { cout << "1"; }
    X(const X &) { cout << "3"; }
    ~X() { cout << "2"; }
    void f() { cout << "4"; }
} object;

int main() {
    X(object);
    object.f();
}
// Answer: The program is guaranteed to output: 11422

// Explanation
//
// - First, a global X object is created, printing 1.
//
// - Then main is called, and we get to the line X(object);. 
//    This can be interpreted in two ways:
//    1. As creating a temporary unnamed copy of object.
//    2. As creating a new variable of type X named object. 
//      This is easier to see if you remove the parentheses, 
//      and it becomes just X object.
//    in the C++ standard says:
//    "An expression-statement with a function-style explicit type 
//     conversion (§8.2.3) as its leftmost subexpression can be 
//     indistinguishable from a declaration where the first 
//     declarator starts with a (." In those cases the statement 
//     is a declaration. So X(object) is in fact a declaration of a 
//     new variable object (which shadows the global object). 
//     The constructor is called, and 1 is printed again.
//
// - We then call f(), and 4 is printed.
//
// - Next, main exits, and the local object is destroyed, printing 2.
//
// - Finally, the global object is destroyed, again printing 2.
#endif

#if CASE == 20
//////////////////////////////////////////////////////////////////////////////////////
//
// 20. CLASS CALLING SEQUENCE WITH VIRTUAL MEMBER
//
// A virtual function is a member function which is declared within a base class
// and is re-defined(Overriden) by a derived class. When you refer to a derived 
// class object using a pointer or a reference to the base class, you can call a 
// virtual function for that object and execute the derived class’s version of 
// the function.

// Virtual functions ensure that the correct function is called for an object, 
// regardless of the type of reference (or pointer) used for function call.
// They are mainly used to achieve Runtime polymorphism
// Functions are declared with a virtual keyword in base class.
// The resolving of function call is done at Run-time.

// Rules for Virtual Functions

// - Virtual functions cannot be static and also cannot be a friend function of 
//   another class.
// - Virtual functions should be accessed using pointer or reference of base 
//   class type to achieve run time polymorphism.
// - The prototype of virtual functions should be same in base as well as 
//   derived class.
// - They are always defined in base class and overridden in derived class. 
//   It is not mandatory for derived class to override (or re-define the 
//   virtual function), in that case base class version of function is used.
// - A class may have virtual destructor but it cannot have a virtual constructor.
//
///////////////////////////////////////
// Statc Function vs. Virtual Functions
///////////////////////////////////////
//
// Virtual and static functions are not related to each other in anyway.
// Virtaul functions is how run time polymorphism is implemented. You define 
// a virtual class and then derived your own class from it. There you overide 
// the virtual function and put some functionallity that is maybe specific 
// to objects of the derived class only....in short for a virtual function
// to use you must have a parent class and atleast two differnet types of 
// derived classes from it, in which the virtual function is overloaded. If 
// you are not intersted in working with derived classes, you don't need to 
// use a virtual function

// static functions are a different story. If a function is defined static in 
// a class and you made two objects of that class. So when you call the static 
// memeber function, it will use the same instatance for both the objects.
class A
{
  public:
    A(int n = 0) : m(n) { }
  public:
    virtual int f() const { return m; }
    virtual ~A() { }
  protected:
    int m;
};
class B: public A
{
  public:
    B(int n = 0) : A(n) { }
  public:
    virtual int f() const { return m + 1; }
};
int main()
{
    const A a(1);  // 
    const B b(3);
    const A *x[2] = { &a, &b };
    typedef vector<A> V;
    V y({ a, b });
    V::const_iterator i = y.begin();

    cout << x[0]->f() << x[1]->f()
              << i->f() << (i + 1)->f() << endl;
    return 0;
}
#endif

#if CASE == 21
//////////////////////////////////////////////////////////////////////////////////////
//
// 21. CALLING ODER BETWEEN DERIVED AND BASE CLASSES
//
struct Base {
  void f(int) { cout << "i"; }
};
struct Derived : Base {
  void f(double) { cout << "d"; }
};
int main() {
  Derived d;
  int i = 0;
  d.f(i);
}
// answer is d
//
// Why does overload resolution not pick the obviously better void f(int), 
// but instead void f(double) which requires a floating-integral conversion 
// from int to double?

// It turns out that void f(int) isn't even in scope, and is not considered
// for overload resolution at all. When the name f is introduced in Derived, 
// it hides the name f that was introduced in Base.

// [basic.scope]§6.3 in the C++ standard is dedicated to scope. 
// [basic.scope.hiding]§6.3.10¶1 and ¶3 has some hints about what's
// going on in our case:

// ¶1: "A name can be hidden by an explicit declaration of that same name in 
// a nested declarative region or derived class (§13.2)"
//¶3: "The declaration of a member in a derived class (Clause 13) hides the 
// declaration of a member of a base class of the same name; see §13.2"

// Both of these refer to [class.member.lookup]§13.2, so let's explore the 
// details about how the name f is looked up in a class scope C:

// [class.member.lookup]§13.2¶4:
//"If C contains a declaration of the name f, the declaration set contains
// every declaration of f declared in C that satisfies the requirements of 
// the language construct in which the lookup occurs.(...) If the resulting 
// declaration set is not empty, the subobject set contains C itself, and 
// calculation is complete."

// So when looking for a declaration of f and finding Derived::f, the 
// calculation is complete, and Base is not examined at all. If no f was 
// found in Derived, we would continue with [class.member.lookup]§13.2¶5:

// "Otherwise (i.e., C does not contain a declaration of f or the resulting 
// declaration set is empty), S(f,C) is initially empty. If C has base 
// classes, calculate the lookup set for f in each direct base class subobject 
// Bi, and merge each such lookup set S(f, Bi) in turn into S(f, C).

//But since Derived does indeed contain a declaration of f, we never get
// around to looking at Base.
#endif

#if CASE == 22
////////////////////////////////////////////////////////////////////////////////////
//
// 22. WHEN TO DESTROY
//
class C {
public:
  C(int i) : i(i) { cout << i; }
  ~C() { cout << i + 5; }

private:
  int i;
};
int main() {
  const C &c = C(1);
  C(2);
  C(3);
}
// Answer - The program is guaranteed to output: 127386
//
// [class.temporary]§15.2¶4 in the standard: "Temporary objects are destroyed 
// as the last step in evaluating the full-expression (...) that (lexically) 
// contains the point where they were created." This means that normally the 
// temporaries returned from C(1), C(2), and C(3) should be destroyed at the 
// end of the line.

// However: [class.temporary]§15.2¶6 states: "(...)when a reference is bound 
// to a temporary. The temporary to which the reference is bound (...) persists 
// for the lifetime of the reference", so the lifetime of the temporary returned 
// by C(1) is extended for the lifetime of c, to the end of main(). The 
// temporaries returned by C(2) and C(3) are still destroyed at the end of 
// their lines of creation, so they get destroyed before the one returned by C(1)

#endif

#if CASE == 23
////////////////////////////////////////////////////////////////////////////////////
//
// 23. EXAMPLE
//
int x = 0;
class A {
public:
  A() { cout << 'a';
    if (x++ == 0) {throw exception();}
  }
  ~A() { cout << 'A'; }
};
class B {
public:
  B() { cout << 'b'; }
  ~B() { cout << 'B'; }
  A a;
};
void foo() { static B b; }
int main() {
  try {
    foo();
  }
  catch (exception &) {
    cout << 'c';
    foo();
  }
}
// Answer - The program is guaranteed to output: acabBA
// Static local variables are initialized the first time control passes 
// through their declaration. 
// - The first time foo() is called, b is attempted initialized. 
// Its constructor is called, which first constructs 
// all member variables. This means A::A() is called, printing a. 
// - A::A() then throws an exception, the constructor is aborted, and neither b or 
// B::a are actually considered constructed. 
// - In the catch-block, c is printed, and then foo() is called again.
// Since b was never initialized the first time, it tries again, 
// this time succeeding, printing ab. 
// - When main() exits, the static variable b is destroyed, first calling
// the destructor printing B, and then destroying member variables, 
// printing A. 
#endif 

#if CASE == 24
////////////////////////////////////////////////////////////////////////////////////
//
// 24. EXAMPLE
//
class A {
  public:
    A(int n = 2) : m(n) { }
    ~A() { cout << m; }
  protected:
    int m;
};
class B : public A {
  public:
    B(int n) : m_a1(m + 1), m_a2(n) { }
    ~B(){ cout << m; --m;}
  private:
    A m_a1;
    A m_a2;
};
int main()
{
    { B b(5); }
    cout << endl;
    return 0;
}
#endif

#if CASE == 25
//////////////////////////////////////////////////////////////////////////////////////
//
// 25. EXAMPLE
//
class A
{
  public:
    A() : m(0) { }
  protected:
    int m;
};
class B
{
  public:
    B() : m_d(0.0) { }

  protected:
    double m_d;
};
class C : public A, public B
{
  public:
    C() : m_c('a') { }
  private:
    char m_c;
};
int main()
{
    C c; // call A --> call B --> call C
    A *pa = &c;
    B *pb = &c;
    const int x = (pa == &c) ? 1 : 2;
    const int y = (pb == &c) ? 3 : 4;
    const int z = (reinterpret_cast<char*>(pa) == reinterpret_cast<char*>(pb)) ? 5 : 6;
    cout << x << y << z << endl;
    return 0;
}
#endif

#if CASE == 26
///////////////////////////////////////////////////////////////////////////////////////
//
// 26. CLASS MEMBER TYPE CASTIM EXAMPLE
//
#include <cstddef>
#include <iostream>

class A {
  public:  A() : m_x(0) { }
  public:
    static ptrdiff_t offset(const A &a) { const char *p = reinterpret_cast<const char*>(&a);
                                          const char *q = reinterpret_cast<const char*>(&a.m_x); return q - p;}
  private: int m_x;
};
class B : public A {
  public: B() : m_x('a') { }
  public: static int m_n;
  public: static ptrdiff_t offset(const B &b){ const char *p = reinterpret_cast<const char*>(&b);
                                               const char *q = reinterpret_cast<const char*>(&b.m_x); return q - p;}
private: char m_x;
};
int B::m_n = 1;
class C
{
  public: C() : m_x(0) { }
          virtual ~C() { }
  public: static ptrdiff_t offset(const C &c) { const char *p = reinterpret_cast<const char*>(&c);
                                                const char *q = reinterpret_cast<const char*>(&c.m_x); return q - p;}
  private: int m_x;
};
int main()
{
    A a; // A()
    B b; // A(), B()
    C c; // C()
    std::cout << ((A::offset(a) == 0) ? 0 : 1);
    std::cout << ((B::offset(b) == 0) ? 0 : 2);
    std::cout << ((A::offset(b) == 0) ? 0 : 3);
    std::cout << ((C::offset(c) == 0) ? 0 : 4);
    std::cout << std::endl;

    return 0;
}
#endif

#if CASE == 27
///////////////////////////////////////////////////////////////////////////////////////
//
// 27. CLASS INITIALIZATION EXAMPLE
// 
// A class object with a constructor must be 
// - explicitly initialized
// - initialized through a default constructor. 
// Except for aggregate initialization, 
// 
// explicit initialization using a constructor is the only way to 
// initialize non-static constant and reference class members.

// A class object that has only implicitly declared C++11 begins or 
// explicitly defaulted C++11 ends constructors, and has no virtual 
// functions, no private or protected non-static data members, and 
// no base classes is called an aggregate. Examples of aggregates 
// are C-style structures and unions.

// You explicitly initialize a class object when you create that 
// object. There are two ways to initialize a class object:
// - Using a parenthesized expression list. 
//   The compiler calls the constructor of the class using this 
//   list as the constructor's argument list.
// - Using a single initialization value and the = operator. 
//   Because this type of expression is an initialization, 
//   not an assignment, the assignment operator function, if one 
//   exists, is not called. The type of the single argument
//   must match the type of the first argument to the constructor. 
//   If the constructor has remaining arguments, these arguments 
//   must have default values.

// The following example shows the declaration and use of several 
// constructors that explicitly initialize class objects: 

// This example illustrates explicit initialization
// by constructor.
class complx {
  double re, im;
public:
  complx():re(0), im(0) { cout << " - default constructor" << endl;}   // 1. default constructor
  complx(const complx& c) { re = c.re; im = c.im; cout << " - copy constructor" << endl;}   
                                                                    // 2. copy constructor
  complx( double r, double i = 0.0) { re = r; im = i; cout << " - constructor with arg; init with defaul trailing arg." << endl;}  
                                                                    // 3. constructor with default trailing argument
  void display() {cout << " - call display: " << "re = "<< re << " im = " << im << endl; }   
                                                                    // 4. member function:
};
int main() 
{

  cout << "complx one(0): " << endl;
  complx one(0);// initialize with complx(double, double) using 3, the 2nd argument is default
  one.display();

  cout << "complx two = one: " << endl;
  complx two = one;   // initialize with a copy of one using 2 complx::complx(const complx&)
  two.display();

  cout << "complx three = complx(3,4): " << endl;
  complx three = complx(3,4);   // construct complx(3,4) directly into three
  three.display();

  cout << "complx four: " << endl;
  complx four;   // initialize with default constructor 1.
  four.display();

  cout << "complx five = 5: " << endl;
  complx five = 5;   // complx(double, double) and construct directly into five
  five.display();

}
/*
complx one(0): 
 - constructor with arg; init with defaul trailing arg.
 - call display: re = 0 im = 0
complx two = one: 
 - copy constructor
 - call display: re = 0 im = 0
complx three = complx(3,4): 
 - constructor with arg; init with defaul trailing arg.
 - call display: re = 3 im = 4
complx four: 
 - default constructor
 - call display: re = 0 im = 0
complx five = 5: 
 - constructor with arg; init with defaul trailing arg.
 - call display: re = 5 im = 0
*/
#endif

#if CASE == 28
///////////////////////////////////////////////////////////////////////////////////////
//
// 28. CLASS CALL SEQUENCE EXAMPLE
//
#include <iostream>
class A {
  int a;
public:
  A(){cout << "A() - Defaule constructor"<<endl;} // default constructor for base class A
  A(A& x){cout << "copy A() - Copy constructor"<<endl;} // copy constructor
  ~A(){cout << "~A() - Destructor"<<endl;} // destructor
  void init(int x){a=x;cout << "init_A - call init" <<a<<endl;} // member function 
  void foo(int a) {cout << "foo_A - call foo" << a<<endl;}   // member function
  virtual void goo(int a) {cout << "goo_A - call goo" << a<<endl;} // member functuion which can be 
                                                                  // replaced by the derived class
};
class B : public A {
public:
  B(){cout << "B() - Defaule constructor" << endl;}  // default constructor
  B(B& x){cout << "copy B() - Copy constructor" << endl;} // compy constructor
  ~B(){cout << "~B() - Destructor" << endl;} // destructor
  void foo(int a) {cout << "foo_B - call foo" << endl;} // member function
  void goo(int a) {cout << "goo_B - call goo" << endl;} // member function, which can only 
                                                          // overload the virtual function
                                                          // of the same name in the base class
};
int main () 
{

    cout << "A *b = new B: " << endl;
    A *b = new B;

    cout << "b->init(3): " << endl;
    b->init(3);

    cout << "b->foo(2): " << endl;
    b->foo(2);

    cout << "b->goo(4): " << endl;
    b->goo(4);

    cout << "B c: " << endl;
    B c;

    cout << "B d=c: " << endl;
    B d=c;
    
    cout << "A e=d: " << endl;
    A e=d;
       
    cout << "c.goo(5): " << endl;
    c.goo(5);

}
/*
A *b = new B: 
A() - Defaule constructor
B() - Defaule constructor
b->init(3): 
init_A - call init3
b->foo(2): 
foo_A - call foo2
b->goo(4): 
goo_B - call goo
B c: 
A() - Defaule constructor
B() - Defaule constructor
B d=c: 
A() - Defaule constructor
copy B() - Copy constructor
A e=d: 
copy A() - Copy constructor
c.goo(5): 
goo_B - call goo
~A() - Destructor
~B() - Destructor
~A() - Destructor
~B() - Destructor
~A() - Destructor
*/

#endif