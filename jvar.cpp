////////////////////////////////////////////////////////////////////////////////
//
// VARIABLES 
//
// Including standard vector variable, pointer variables, array variables, etc.
//
// compiling:
// g++ -o jvar jvar.cpp
// ./jvar
//
// generate static library from the above compiled file:
// g++ -o jvar jvar.cpp
// ar rcs jvar.a jvar
// or
// g++ -o jvar.o jvar.cpp
// ./jvar.o
// ar rcs jvar.a jvar.o
//
// generate shared library from the complied objective file
// g++  -o jvar.o -fPIC jvar.cpp // position independent code
// g++ -shared jvar.o -o jvar.so 
// g++ -shared jvar -o jvar.so 
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

#define CASE 11

#if CASE==1
////////////////////////////////////////////////////////////////////////////////
//
// 1. ARRAY
//
// an array must be declared before it is used. A typical declaration for an array is:
//
// type name [elements];
//
// int v[5] is an array with 5 elements of type int. Array can initialized through, e.g.,:
//
// int v[5]= (0,1,2,3,4)
//
// if partial values are given to an array:
//
// int v[5]= (0,1,2) means int v[5]=(0,1,2,0,0)
// int v[5]=() means int v[5]=(0,0,0,0,0)
// int v[]=(1,2,3,4,5,6,7,8) means the array leangth matches the number of values assigned.
//
int a[] = {16, 2, 77, 40, 12071};
int b[5]={1,2,3};
int c[5]={};
int i, result=0;
char x[]="________";

int main ()
{
  cout<<"\n\n\n Print out arrays: "<<endl;
  for ( i=0 ; i<5 ; ++i )
  {
    result += a[i];
    cout << a[i] <<'\n';
    cout << b[i] <<'\n';
    cout << c[i] <<'\n';
    cout << result <<'\n';
    cout << x << i << x <<'\n';
  }
  cout<<"\n\n\n"<<endl;
}
#endif

#if CASE == 2
////////////////////////////////////////////////////////////////////////////////
// 
// 2. MULTIDIMENSIONAL ARRAY
//
// Multidimensional arrays are not limited to two indices (i.e., two dimensions). 
// They can contain as many indices as needed. Although be careful: the amount 
// of memory needed for an array increases exponentially with each dimension. 
//
// For example:
//
// char v[24][7][4][12]
//
#define WIDTH 5  // see jdefine for details on #define
#define HEIGHT 3 // see jdefine for details on #define
int M[HEIGHT][WIDTH];
int i,j;
int main ()
{

// display in a matrix format
  cout<<"\n\n\n Results: "<<endl;
  for (i=0; i<HEIGHT; i++)
  {
    cout<<endl;
    for (j=0; j<WIDTH; j++)
    {
      M[i][j]=(i+1)*(j+1);
      cout<<M[i][j]<<"\t";
    }

  }
  cout<<"\n\n\n"<<endl;
 
}
#endif

#if CASE==3
////////////////////////////////////////////////////////////////////////////////
//
// 3. ARRAYS AS PARAMETERS
//
// If you want to pass a single-dimension array as an argument in a function, 
// you would have to declare a formal parameter in one of following three ways 
// and all three declaration methods produce similar results because each tells
// the compiler that an integer pointer is going to be received. Similarly, you 
// can pass multi-dimensional arrays as formal parameters.
//
// Way-1: Formal parameters as a pointer −
//
// void myFunction(int *param) { ... }
//
// Way-2:Formal parameters as a sized array −
//
// void myFunction(int param[10]) {  }
//
// Way-3: Formal parameters as an unsized array −
//
// oid myFunction(int param[]) { ... }
//
// To pass an array as a parameter through Way-1 (pass it as a pointer)
// is prefered. For example, the following procedure sets the first n cells of 
// array A to 0.
 /* 
 void zero(int* A, int n)
  {
    for(int k = 0; k < n; k++)
    {
      A[k] = 0;
    }
  }
*/
// Now to use that procedure:
//
// int B[100];
// zero(B, 100);
//
// Notice that the argument, B, does not have any decoration. The array (or pointer) 
// B is being passed, so just call it B. 
//
// Way-2 and Way-3 are used to accommodate programmers who understand arrays 
// but do not understand Function heading
//
// void zero(int A[], int n)
//
// is equivalent to
//
// void zero(int* A, int n)
//
// The former form has the advantage that it clearly indicates that A is an array, not a 
// pointer to just one thing. For that reason, it is often preferred. But the two notations 
// mean the same thing. (Indicating that a parameter is an array might allow a compiler to
// warn you if you use the pointer in a way that is not appropriate for an array.) 
//
void printa (int arg[], int length) 
{
  for (int n=0; n<length; ++n)
    cout << arg[n] << ' ';
  cout << '\n';
}

void printa_p (int* arg, int length) 
{
  for (int n=0; n<length; ++n)
    cout << arg[n] << ' ';
  cout << '\n';
}

int main ()
{
  int firstarray[] = {5, 10, 15};
  int secondarray[] = {2, 4, 6, 8, 10};
  cout<<"\n Results via array passing as an array: "<<endl;
  printa (firstarray,3);
  printa (secondarray,5);
  cout<<"\n Results via pointer by passing as an array"<<endl;
  printa_p (firstarray,3);
  printa_p (secondarray,5);
  //cout<<"\n Resules vis pointer by passing as a pointer"<<endl;
  //printa_p (*firstarray,3);  // this is wrong!
  //printa_p (*secondarray,5); // this is wrong!
  cout<<"\n"<<endl;
}
#endif

#if CASE == 4
////////////////////////////////////////////////////////////////////////////////
//
// 4. VECTOR
//
// Vectors are sequence containers representing arrays that can change in size.
// Just like arrays, vectors use contiguous storage locations for their elements, 
// which means that their elements can also be accessed using offsets on regular 
// pointers to its elements, and just as efficiently as in arrays. But unlike arrays, 
// their size can change dynamically, with their storage being handled automatically 
// by the container.

// Internally, vectors use a dynamically allocated array to store their elements. 
// This array may need to be reallocated in order to grow in size when new elements 
// are inserted, which implies allocating a new array and moving all elements to it. 
// This is a relatively expensive task in terms of processing time, and thus, vectors 
// do not reallocate each time an element is added to the container.

// Instead, vector containers may allocate some extra storage to accommodate for 
// possible growth, and thus the container may have an actual capacity greater 
// than the storage strictly needed to contain its elements (i.e., its size). 
// Libraries can implement different strategies for growth to balance between 
// memory usage and reallocations, but in any case, reallocations should only 
// happen at logarithmically growing intervals of size so that the insertion of 
// individual elements at the end of the vector can be provided with amortized 
// constant time complexity (see push_back).

// Therefore, compared to arrays, vectors consume more memory in exchange for 
// the ability to manage storage and grow dynamically in an efficient way.

// Compared to the other dynamic sequence containers (deques, lists and forward_lists), 
// vectors are very efficient accessing its elements (just like arrays) and relatively 
// efficient adding or removing elements from its end. For operations that involve 
// inserting or removing elements at positions other than the end, they perform worse 
// than the others, and have less consistent iterators and references than lists and 
// forward_lists.

// The declaration syntax of vector is the same as that of array, 
// with the difference that we don't need to specify the array length along with 
// the data type as shown below. 
//
// vector<datatype> array_name;
//

void printVector(const vector<int> &n)
{
    for (int j = 0; j < n.size(); j++ ) 
    {
        cout << "element[" << j << "] = " << n[j] << endl;
    }
}

int main()
{
    // define array without specifying its length
    vector<int> marks; // did not declare the array length
    cout << "length of marks if 'vector<int> marks': " << marks.size() << endl;
    // print element by element of an array by calling a function called printVector
    printVector(marks);

    marks = {50, 45, 47, 65, 80}; // make marks a vector of 5 values
    cout << "length of marks if 'marks = {50, 45, 47, 65, 80}': " << marks.size() << endl;
    // print element by element of an array by calling a function called printVector
    printVector(marks);
    
    marks = {50, 47, 60}; // adjust marks as a vector of 3 values
    cout << "length of marks if 'marks = {50, 47, 60}': " << marks.size() << endl;
    // print element by element of an array by calling a function called printVector
    printVector(marks);
    
    // Note that for bigger projects it can be tedious to repeatedly write out the explicit 
    // type of the vectors. You may use a typedef if you want:
    typedef vector<int> intvec_t;    // or whatever you want to name it
    intvec_t w;
    size_t size = 10; // is an allias of the fundamental unsigned type. 
                      // is the type returned by the sizeof operator.
    vector<int> x(size);        // make room for 10 integers, and initialize them to 0
    // do something with them:
    for(int i=0; i<size; ++i){ x[i] = i; }
    cout << "length of x if 'for(int i=0; i<size; ++i){ x[i] = i; }': " << x.size() << endl;
    printVector(x);
    
    // As you see, vector combines the advantages of both the static and the dynamic array 
    // because it takes a non-const size parameter such as the dynamic one and automatically 
    // deletes the used memory like the static one.

    vector<int> y;   // create an empty vector

    y.reserve(3);         // make room for 3 elements at this point, capacity() is 3 and size() is 0
    cout << "length of y if 'y.reserve(3)': " << y.size() << endl;
    printVector(y);
    
    y.push_back(999);     // append an element
    cout << "length of y if 'y.push_back(999)': " << y.size() << endl;
    printVector(y);
      
    y.resize(5);          // resize the vector at this point, the vector contains 999, 0, 0, 0, 0
    cout << "length of y if 'y.resize(5)': " << y.size() << endl;
    printVector(y);
      
    y.push_back(333);     // append another element into the vector at this point, the vector contains
                          // 999, 0, 0, 0, 0, 333
    cout << "length of y if 'y.push_back(333)': " << y.size() << endl; 
    printVector(y);
                         
    y.reserve(1);         // will do nothing, as capacity() > 1
    cout << "length of y if ' y.reserve(1)': " << y.size() << endl; 
    printVector(y);
    
    y.resize(3);          // at this point, the vector contains 999, 0, 0 capacity() remains 6 size() is 3
    cout << "length of y if 'y.resize(3)': " << y.size() << endl; 
    printVector(y);
    
    y.resize(6, 1);       // resize again, fill up with 1,  the vector contains 999, 0, 0, 1, 1, 1  
    cout << "length of y if 'y.resize(6, 1)': " << y.size() << endl; 
    printVector(y);


    return 0;
}
#endif

#if CASE == 5
////////////////////////////////////////////////////////////////////////////////
//
// 5. PASSING VECTOR AS A PARAMETER
//
// When we pass an array to a function, a pointer is actually passed.
// When a vector is passed to a function, a copy of the vector is created. 
// For example, we can see below program, changes made inside the function 
// are not reflected outside because function has a copy.

/*// C++ program to demonstrate that when vectors 
// are passed to functions without &, a copy is 
// created. 
#include<bits/stdc++.h> 
using namespace std; 
   
// The vect here is a copy of vect in main() 
void func(vector<int> vect) 
{ 
   vect.push_back(30); 
} 
   
int main() 
{ 
    vector<int> vect; 
    vect.push_back(10); 
    vect.push_back(20); 
   
    func(vect); 
   
    // vect remains unchanged after function 
    // call 
    for (int i=0; i<vect.size(); i++) 
       cout << vect[i] << " "; 
   
    return 0; 
} */

// The above style of passing might also take a lot of time in cases of 
// large vectors. So it is a good idea to pass by reference.
/*
// C++ program to demonstrate how vectors 
// can be passed by reference. 
#include<bits/stdc++.h> 
using namespace std; 
   
// The vect is passed by reference and changes 
// made here reflect in main() 
void func(vector<int> &vect) 
{ 
   vect.push_back(30); 
} 
   
int main() 
{ 
    vector<int> vect; 
    vect.push_back(10); 
    vect.push_back(20); 
   
    func(vect); 
  
    for (int i=0; i<vect.size(); i++) 
       cout << vect[i] << " "; 
   
    return 0; 
} */

// If we do not want a function to modify a vector, we can pass it as a const reference.
//
/*// C++ program to demonstrate how vectors 
// can be passed by reference with modifications 
// restricted. 
#include<bits/stdc++.h> 
using namespace std; 
   
// The vect is passed by constant reference 
// and cannot be changed by this function. 
void func(const vector<int> &vect) 
{ 
    // vect.push_back(30);  // Uncommenting this line would 
                             // below error 
    // "prog.cpp: In function 'void func(const std::vector<int>&)': 
    // prog.cpp:9:18: error: passing 'const std::vector<int>'  
    // as 'this' argument discards qualifiers [-fpermissive]"    
    
    for (int i=0; i<vect.size(); i++) 
       cout << vect[i] << " "; 
} 
   
int main() 
{ 
    vector<int> vect; 
    vect.push_back(10); 
    vect.push_back(20); 
   
    func(vect); 
    
    return 0; 
} 
*/

// Passing a vector to constructor in C++. When class member is a vector object (not a reference).

// We can simply assign in constructor.
/*
// Passing vector object to a constructor. 
#include <iostream> 
#include <vector> 
using namespace std; 
  
class MyClass { 
    vector<int> vec; 
  
public: 
    MyClass(vector<int> v)  
    { 
       vec = v; 
    } 
    void print() 
    { 
        /// print the value of vector 
        for (int i = 0; i < vec.size(); i++) 
            cout << vec[i] << " "; 
    } 
}; 
  
int main() 
{ 
    vector<int> vec; 
    for (int i = 1; i <= 5; i++) 
        vec.push_back(i); 
    MyClass obj(vec); 
    obj.print(); 
    return 0; 
} */

// We can also initialize using initialer list.
/*
// Initializing vector object using initializer 
// list. 
#include <iostream> 
#include <vector> 
using namespace std; 
  
class MyClass { 
    vector<int> vec; 
  
public: 
    MyClass(vector<int> v) : vec(v) 
    { 
    } 
    void print() 
    { 
        /// print the value of vector 
        for (int i = 0; i < vec.size(); i++) 
            cout << vec[i] << " "; 
    } 
}; 
  
int main() 
{ 
    vector<int> vec; 
    for (int i = 1; i <= 5; i++) 
        vec.push_back(i); 
    MyClass obj(vec); 
    obj.print(); 
    return 0; 
*/
// When class member is a vector a reference. 
// In C++, references must be initialized using initializer list.

/*
// CPP program to initialize a vector reference. 
#include <iostream> 
#include <vector> 
using namespace std; 
  
class MyClass { 
    vector<int>& vec; 
  
public: 
    // this is the right way to assign 
    // the reference of stl container 
    MyClass(vector<int>& arr) 
        : vec(arr) 
    { 
    } 
    void print() 
    { 
        /// print the value of vector 
        for (int i = 0; i < vec.size(); i++) 
            cout << vec[i] << " "; 
    } 
}; 
  
int main() 
{ 
    vector<int> vec; 
    for (int i = 1; i <= 5; i++) 
        vec.push_back(i); 
    MyClass obj(vec); 
    obj.print(); 
    return 0; 
} */


#endif

#if CASE == 6
////////////////////////////////////////////////////////////////////////////////
//
// 6. MEMBER SELECTION
//
// dot (.) operator vs. arrow (->) operator
//
// The . (dot) operator and the -> (arrow) operator are used to reference individual
// members of classes, structures, and unions.

// The dot operator is applied to the actual object. The arrow operator is used with 
// a pointer to an object. For example, consider the following structure −
/*
struct Employee {
   char first_name[16];
   int  age;
}  emp;
*/

// The (.) dot operator
//
// To assign the value "zara" to the first_name member of object emp, you would write
// something as follows −
//
// strcpy(emp.first_name, "zara");
//

// The (->) arrow operator
//
// If p_emp is a pointer to an object of type Employee, then to assign the value "zara"
// to the first_name member of object emp, you would write something as follows −
//
// strcpy(p_emp->first_name, "zara");
//
// The -> is called the arrow operator. It is formed by using the minus sign followed 
// by a greater than sign.

// Simply saying: To access members of a structure, use the dot operator. 
// To access members of a structure through a pointer, use the arrow operator.

struct Person
{
    int age;
    double weight;
};

int main()
{
	// Member selection using actual struct variable
	Person person;
	person.age = 5;
	cout << "Person person, person.age = " << person.age << endl;

	// Member selection using reference to struct
	Person &ref = person;
	ref.age = 6;
	cout << "Person &ref = person, ref.age = 6, person.age = " << person.age << endl;

	// Member selection using pointer to struct
	Person *ptr = &person;
	(*ptr).age= 7;
	cout << "Person *ptr = &person, (*ptr).age = 7, person.age = " << person.age << endl;

	// 2nd member selection using pointer to struct (->)
	Person *ptr2 = &person;
	ptr2->age = 8;
	cout << "Person *ptr2 = &person, ptr2->age = 8, person.age = " << person.age << endl;
}
#endif

#if CASE == 7
////////////////////////////////////////////////////////////////////////////////
//
// 7. VARIABLE VISIBILITY
//
//
int foo;        // global variable

int some_function ()
{
  int bar;      // local variable
  bar = 0;
}

int other_function ()
{
  foo = 1;  // ok: foo is a global variable
  //bar = 2;  // wrong: bar is not visible from this function
}

int main () 
{
  int x = 10;
  int y = 20;
  {
    int x;   // ok, inner scope.
    x = 50;  // sets value to inner x
    y = 50;  // sets value to (outer) y
    cout << "inner block:\n";
    cout << "x: " << x << '\n';
    cout << "y: " << y << '\n';
  }
  cout << "outer block:\n";
  cout << "x: " << x << '\n';
  cout << "y: " << y << '\n';
  return 0;
}
#endif

#if CASE == 8
////////////////////////////////////////////////////////////////////////////////
//
// 8. POINTER VARIABLE
//
using namespace std;

int main()
{
	int i;
	i = 500;
        cout<<"'int i; i=500': i = "<<i<<'\n';
        cout<<"'int i; i=500': &i = "<<&i<<'\n';
        cout<<"'int i; i=500': *(&i) =  "<<*(&i)<<'\n';
        cout<<"'int i; i=500': &(*(&i)) =  "<<&(*(&i))<<'\n';
        cout<<"T-------------------------------------"<<'\n';
        
	int *ptr_k;
	// The address of a variable can be obtained by preceding the name of a 
	// variable with an ampersand sign (&), known as address-of operator: 
	ptr_k = &i;
	// The actual address of a variable in memory cannot be known before runtime.
	// This would assign the address of variable i to ptr_k; by preceding the 
	// name of the variable i with the address-of operator (&), we are no 
	// longer assigning the content of the variable itself to ptr_k, but its address.
        cout<<"'int *ptr_k; ptr_k=&i': ptr_k = "<<ptr_k<<'\n';
        cout<<"'int *ptr_k; ptr_k=&i': &ptr_k = "<<&ptr_k<<'\n';
        cout<<"'int *ptr_k; ptr_k=&i': *ptr_k = "<<*ptr_k<<'\n';
        cout<<"T-------------------------------------"<<'\n';
        
        int j;
	// As just seen, a variable which stores the address of another variable 
	// is called a pointer. Pointers are said to
	// "point to" the variable whose address they store.
	j = *ptr_k;
	// This could be read as: "j equal to value pointed to by ptr_k"
	// & is the address-of operator, and can be read simply as "address of"
	// * is the dereference operator, and can be read as "value pointed to by"
        cout<<"'int j; j=*ptr_k': j = "<<j<<'\n';
        cout<<"'int j; j=*ptr_k': &j = "<<&j<<'\n';
        cout<<"'int j; j=*ptr_k': *(&j) = "<<*(&j)<<'\n';
        cout<<"T-------------------------------------"<<'\n';
        
	// As just seen, a variable which stores the address of another variable 
	// is called a pointer. Pointers are said to "point to" the variable whose 
	// address they store. An interesting property of pointers is that they can 
	// be used to access the variable they point to directly. This is done by 
	// preceding the pointer name with the dereference operator(*). The operator 
	// itself can be read as "value pointed to by".
	// Therefore, following with the previous example, the following statement: 

        int l;
	l=j;
        cout<<"'int l; i=j': l = "<<l<<'\n';
        cout<<"'int l; i=j': &l = "<<&l<<'\n';
        cout<<"T-------------------------------------"<<'\n';
        
        int m;
	m=j*2;
        cout<<"'int m; m=j*2': m = "<<m<<'\n';
        cout<<"'int m; m=j*2': m = "<<&m<<'\n';
        cout<<"T-------------------------------------"<<'\n';
        
        int array[5];
	// the variable array is a pointer to the beginning of the 5 integers. 
	// It is convenient to think of array and array[0] as pointing to the same 
	// location, which is a good reason for arrays in C to be numbered starting at 0.
	// We don't ever want to change where array points. We want to make sure we can 
	// always find the start of the array. So let's declare another pointer:
 	//int *array_q;
	// and set it to point to the same place;
	// THIS IS WRONG AND CANNOT COMPILE:
	// array_q=&array;
        // cout<<"'int *array_q; array_q=&array': array_q = "<<'\n';
        // printVector(array_q);
        //cout<<"T-------------------------------------"<<'\n';
        int *array_p;
	array_p=array;
	// array_p=&aaray does not work, but array_p=array works because pointers 
	// are simply integers referring to locations in memory. The variable array 
	// is a pointer pointing to the beggining of the 5 integers. Think of 
	// memory as a set of numbered slots. The array we just declared 
	// takes up 5 slots; if an integer takes up four bytes, the slots might 
	// be numbered 50, 54, 58... and the array variable points to 50. 
	// Don't confuse these numbers with the values in the elements of the array, 
	// which you can think of as pieces of paper inserted into the slots.
	// Using this pointer now, we can step through the array and initialize 
	// each element:      
  	for (i=0; i<5; i++)
    	{
      		*array_p = i*i;
                cout<<"i = "<<i<<'\n';
                cout<<"array[i] = "<<array[i]<<'\n';
                cout<<"&array[0] = "<<&array[0]<<'\n';
                cout<<"&array = "<<&array<<'\n';
                cout<<"&array[i] = "<<&array[i]<<'\n';
                cout<<"array_p = "<<array_p<<'\n';
                cout<<"*array_p = "<<*array_p<<'\n';
      		array_p++;
                cout<<"array_p = "<<array_p<<'\n';
                cout<<"*array_p = "<<*array_p<<'\n';
    	}
	// The two statements within the loop treat the pointer very differently. 
	// The first statement has an asterisk, so it looks at the value that 
	// the pointer is pointing to. This is called dereferencing the pointer. 
	// The statement changes the value, not the pointer itself. Thus, the 
	// first element of the array is set to 0*0, the second element to 1*1, 
	// and so on. The second statement changes the pointer itself, because 
	// there is no asterisk on it. The values within the array do not change.
        // Before going on (because the next example can be confusing), make 
	// sure you understand when code looks at the pointer itself (when 
	// there's no asterisk) versus when code looks at the memory to which 
	// the pointer is pointing (when there is an asterisk). Here's an analogy: 
	// imagine you are walking next to a set of 5 mailboxes, which collectively 
	// represent the array. The statement *array_p = i*i puts a slip of paper 
	// holding a number into the mailbox. The statement array_p++ walks to 
	// the next mailbox. 
	cout<<"T-------------------------------------"<<'\n';
	
        // Most programmers, secure in their understanding of
	// pointers, would combine the two statements within the loop:
	array_p=array; //initialize the pointer array_p or you can use a different
	               // pointer
  	for (i=0; i<5; i++)
    	{
      		*array_p++ = i*i;
                cout<<"array_p = "<<array_p<<'\n';
		cout<<"*array_p = "<<*array_p<<'\n';
    	}
    	// The construct *array_p++ looks confusing at first. Rest assured that 
    	// C is guaranteed to dereference the pointer first (*array_p) and set 
    	// the element of the array, then to increment the pointer itself. The 
    	// loop is exactly equivalent to the previous one, once it is compiled.
	// Suppose you didn't want to increment the pointer; you wanted to increment 
	// the element of the array. You can put parentheses around the asterisk 
	// and pointer, so the deferencing occurs first:
	//  (*array_p)++;
	cout<<"T-------------------------------------"<<'\n';
	
	//array_p=array; // initialize the pointer
  	//for (i=0; i<5; i++)
    	//{
      	//	(*array_p)++ = i*i;
      	//	cout<<"array_p = "<<array_p<<'\n';
	//	cout<<"*array_p = "<<*array_p<<'\n';
    	//}
	// Back to our program: having set the values within the array, we can 
	// reuse the pointer to print them. The following line of code is 
	// extremely important, because the program has left array_p pointing to
	// a location past the end of the array. You must not deference array_p 
	// now, because you'll access memory you're not supposed to access. 
	// That's a buffer overflow, and it could terminate the program or 
	// overwrite critical memory (which could produce wrong results or be 
	// used by exploiters to compromise the system). Therefore, reset 
	// array_p before using it:
  	// array_p=array;
        //cout<<"T-------------------------------------"<<'\n';
	       
	// Regarding the increment (++) and decrement (--) operators, they both 
	// can be used as either prefix or suffix of an expression, with a slight 
	// difference in behavior:  as a prefix, the increment happens before 
	// the expression is evaluated, and as a suffix, the increment happens 
	// after the expression is evaluated. This also applies to expressions 
	// incrementing and decrementing pointers, which can become part of more 
	// complicated expressions that also include dereference operators (*). 
	// Remembering operator precedence rules, we can recall that postfix 
	// operators, such as increment and decrement, have higher precedence 
	// than prefix operators, such as the dereference operator (*). 
	// Therefore, the following expression:
	//
        // 	*p++
	//
	// is equivalent to *(p++). And what it does is to increase the value of 
	// p (so it now points to the next element), but because ++ is used as 
	// postfix, the whole expression is evaluated as the value pointed 
	// originally by the pointer (the address it pointed to before being incremented).

	// Essentially, these are the four possible combinations of the 
	// dereference operator with both the prefix and suffix
	// versions of the increment operator (the same being applicable also to 
	// the decrement operator):
	//
	// *p++   - same as *(p++): increment pointer, and dereference 
	//          unincremented address
	// *++p   - same as *(++p): increment pointer, and dereference 
	//          incremented address
	// ++*p   - same as ++(*p): dereference pointer, and increment the 
	//          value it points to
	// (*p)++ - dereference pointer, and post-increment the value it 
	//          points to 

	// A typical -but not so simple- statement involving these operators is:
	// 	
	//	*p++ = *q++;
	//
	// Because ++ has a higher precedence than *, both p and q are incremented, 
	// but because both increment operators (++) are used as postfix and not 
	// prefix, the value assigned to *p is *q before both p and q are 
	// incremented. And then 
	// both are incremented. It would be roughly equivalent to:
	//
	//	*p = *q;
	//	++p;
	//	++q;
	
	// Pointers and const
	//
	// Pointers can be used to access a variable by its address, and this 
	// access may include modifying the value pointed. But it is also 
	// possible to declare pointers that can access the pointed value to 
	// read it, but not to modify it. For this, it is enough with qualifying 
	// the type pointed to by the pointer as const. For example:
	//	int x;
	//	int y = 5;
	//	const int * p = &y;
	//	x = *p;          // ok: reading p
	//	*p = x;          // error: modifying p, which is const-qualified 
	// Here p points to a variable, but points to it in a const-qualified 
	// manner, meaning that it can read the value pointed, but it cannot 
	// modify it. Note also, that the expression &y is of type int*, but 
	// this is assigned to a pointer of type const int*. This is allowed: a 
	// pointer to non-const can be implicitly converted to a pointer to
	// const. But not the other way around! As a safety feature, pointers to 
	// const are not implicitly convertible to pointers to non-const. One of 
	// the use cases of pointers to const elements is as function parameters: 
	// a function that takes a pointer to non-const as parameter can modify 
	// the value passed as argument, while a function that takes a pointer to 
	// const as parameter cannot.
	
	// Pointers to functions
	// C++ allows operations with pointers to functions. The typical use of 
	// this is for passing a function as an argument to another function. 
	// Pointers to functions are declared with the same syntax as a regular 
	// function declaration, except that the name of the function is enclosed 
	// between parentheses () and an asterisk (*) is inserted before the name:
	/*
	// pointer to functions
#include <iostream>
using namespace std;

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
  n = operation (5, m, minus);
  cout <<n;
  return 0;
}
	*/

	// In the example above, minus is a pointer to a function that has two 
	// parameters of type int. It is directly 	
	// initialized to point to the function subtraction:
	// int (* minus)(int,int) = subtraction;

	// Pointers to pointers
	// C++ allows the use of pointers that point to pointers, that these, 
	// in its turn, point to data (or even to other

/*	// pointers). The syntax simply requires an asterisk (*) for each level 
        // of indirection in the declaration of the pointer:
char a;
char * b;
char ** c;
a = 'z';
b = &a;
c = &b;
*/
//	return 0;
}
#endif

#if CASE == 9
////////////////////////////////////////////////////////////////////////////////
//
// 9. SCOPE RESOLUTION
//
// :: is the scope resolution operator - used to qualify names. 
//

namespace foo {
  class bar;
}

class bar;
using namespace foo;

// Now you have to use the scope resolution operator to refer to a specific bar.
// ::foo::bar is a fully qualified name.
// ::bar is another fully qualified name. (:: first means "global namespace")

struct Base 
{
    void foo();
};

struct Derived : Base 
{
    void foo();
    void bar() 
    {
       Derived::foo();
       Base::foo();
    }
};

// This uses scope resolution to select specific versions of foo.
#endif

#if CASE == 10
////////////////////////////////////////////////////////////////////////////////
//
// 10. REFERENCE VARIABLES
//
// reference variables: references allow us to define aliases to other objects or values
//
// There are three sets of variables:
// - Normal variables, which hold values directly.
// - Pointers, which hold the address of another value (or null) and can be 
//   dereferenced to retrieve the value at the address they point to.
// - References variable is a type of C++ variable that acts as an alias to 
//   another object or value

// C++ supports three kinds of references:
// - References to non-const values (typically just called “references”, or 
//   “non-const references”).
// - References to const values (often called “const references”)
// - r-value references

// A reference (to a non-const value) is declared by using an ampersand (&) 
// between the reference type and the variable name:

int value = 5; // normal integer
int &ref = value; // reference to variable value

// References generally act identically to the values they’re referencing. 
// In this sense, a reference acts as an alias for the object being referenced. For example:
int x = 5; // normal integer
int &y = x; // y is a reference to x
int &z = y; // z is also a reference to x

int main()
{
    int value = 5; // normal integer
    int &ref = value; // reference to variable value --> ref 
                      // and value are treated synonymously.
                      // reference must be initialized
    //int &ref = 5; // this is wrong
    cout << "value = 5, value = " << value << '\n';
    cout << "&ref = value, ref = "<< ref << '\n';
    cout << "value = 5, &value = " << &value << '\n'; // Using the address-of operator on a 
                                                           // reference returns the address of the 
                                                           // value being referenced
    cout << "&ref = value, &ref = "<< &ref << '\n';

    value = 6; // value is now 6
    ref = 7;   // value is now 7
    cout << "value = 6: "<< value << '\n';
    cout << "ref = 7: "<< ref << '\n';
    cout << "ref = 7, value = "<< value << '\n';
    cout << "&ref = value, ref = "<< ref << '\n';
    cout << "value = 5, &value = " << &value << '\n'; // Using the address-of operator on a 
                                                           // reference returns the address of the 
                                                           // value being referenced
    cout << "&ref = value, &ref = "<< &ref << '\n';

    ++ref;
    cout <<"++ref, value = "<< value << '\n';
    cout << "++ref, ref = " << ref <<'\n';
    cout << "&ref = value, ref = "<< ref << '\n';
    cout << "value = 5, &value = " << &value << '\n'; // Using the address-of operator on a 
                                                           // reference returns the address of the 
                                                           // value being referenced
    cout << "&ref = value, &ref = "<< &ref << '\n';

    // References and pointers have an interesting relationship -- a reference acts like a pointer 
    // that is implicitly dereferenced when accessed (references are usually implemented internally 
    // by the compiler using pointers). Thus given the following:
    value = 5;
    int *const ptr = &value;
    //int &ref = value; // *ptr and ref evaluate identically. As a result, the following 
                      // two statements produce the same effect:
    cout << "value = 5, value = " << value << '\n';
    cout << "value = 5, *const ptr = &value, *ptr = " << *ptr << '\n';
    cout << "&ref = value, ref = "<< ref << '\n';
    cout << "value = 5, &value = " << &value << '\n'; // Using the address-of operator on a 
                                                           // reference returns the address of the 
                                                           // value being referenced
    cout << "value = 5, *const ptr = &value, ptr = " << ptr << '\n';
    cout << "&ref = value, &ref = "<< &ref << '\n';

    return 0;
}
#endif


#if CASE == 11
////////////////////////////////////////////////////////////////////////////////
//
// 11. SIZE OF ARRAY
//

size_t get_size_1(int* arr)
{
  return sizeof(arr);
}

size_t get_size_2(int arr[])
{
  return sizeof(arr);
}

size_t get_size_3(int (&arr)[10])
{
  return sizeof(arr);
}

int main()
{
  int array[10];
  //Assume sizeof(int*) != sizeof(int[10])
  cout << (sizeof(array) == get_size_1(array));
  cout << (sizeof(array) == get_size_2(array));
  cout << (sizeof(array) == get_size_3(array));
}
#endif


#if CASE == 12
////////////////////////////////////////////////////////////////////////////////
//
// 12. FUNCTION RETURN A STRCT
//
// A function can also return a struct, which is one of the few ways to have 
// a function return multiple variables.
struct Point3d
{
    double x;
    double y;
    double z;
};
 
Point3d getZeroPoint()
{
    Point3d temp = { 0.0, 0.0, 0.0 };
    return temp;
}
 
int main()
{
    Point3d zero = getZeroPoint();
 
    if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
        std::cout << "The point is zero\n";
    else
        std::cout << "The point is not zero\n";
 
    return 0;
}


#if CASE == 13
////////////////////////////////////////////////////////////////////////////////
//
// 12. INITIALIZING VARIABLE
//
// C++ supports three basic ways to initialize a variable. 
// - First, we can do copy initialization by using an equals sign:
//       int width = 5; // copy initialization of value 5 into variable width
//
// - Second, we can do a direct initialization by using parenthesis:
//       int width( 5 ); // direct initialization of value 5 into variable width
// 
// - Third, brace initialization (also called uniform initialization) 
//   that uses curly braces:
//       int width{ 5 }; // uniform initialization of value 5 into variable width
//   Initializing a variable with empty braces indicates zero initialization. 
//   Zero initialization generally initializes the variable to zero (or empty, 
//   if that’s more appropriate for a given type).
//
// For simple data types (like integers), copy and direct initialization are 
// essentially the same. But for some advanced types, direct initialization 
// can perform better than copy initialization. Prior to C++11, direct 
// initialization was recommended over copy initialization in most cases 
// because of the performance boost.
//
// Uniform initialization has the added benefit of disallowing “narrowing” 
// conversions. This means that if you try to use uniform initialization 
// to initialize a variable with a value it can not safely hold, the compiler
// will throw an warning or error. For example:
//
//     int width{ 4.5 }; // error: an integer variable can not 
//                       // hold a non-integer value
//
// In the above snippet, we’re trying to assign a number (4.5) that has a 
// fractional part (the .5 part) to an integer variable (which can only 
// hold numbers without fractional parts). Copy and direct initialization 
// would drop the fractional part, resulting in initialization of value 4 
// into variable width. However, with uniform initialization, this will 
// cause the compiler to issue an error (which is generally a good thing, 
// because losing data is rarely desired).
//
//////////////
// { 0 } vs {}
//////////////
// Use an explicit initialization value if you’re actually using that value.
//     int x { 0 }; // explicit initialization to value 0
//     std::cout << x; // we're using that zero value
// Use zero initialization if the value is temporary and will be replaced:
//     int x{}; // zero initialization
//     std::cin >> x; // we're immediately replacing that value
// 
//////////////////////////
// Multiple initialization
//////////////////////////
// You can initialize multiple variables defined on the same line:
//
//     int a = 5, b = 6; // copy initialization
//     int c( 7 ), d( 8 ); // direct initialization
//     int e{ 9 }, f{ 10 }; // uniform initialization (preferred)
//
////////////////////////////////
// Initialization vs. Assignment
////////////////////////////////
// Initialization gives a variable a value at the point when it is created. 
// Assignment gives a variable a value at some point after it is created.
//
////////////////////////////////////////////////////////
// Implicity Initialization vs. Explicity Initialization
////////////////////////////////////////////////////////
//     int i{ 0 }; // Explicitly initialized to 0
//     int i{};    // Implicitly initialized to 0
//
///////////////////////
// Array Initialization
///////////////////////
//     int arr[](1, 2, 3); // Nope
//     int arr[]{ 1, 2, 3 }; // Ok
//
////////////////////////////////////////
// When Does Direct Initilization Fails?
////////////////////////////////////////
//      std::vector<int> v{10}; // The vector has 1 element, a 10.
//      std::vector<int> v(10); // The vector has 10 elements, all 0.
//
///////////////////////////////////
// Rule of Thumb in Initialization:
///////////////////////////////////
// Always use uniform initialization (brace initialization). 
// If that's not possible, then use direct initialization.
//
//////////////////////////
// Function Initialization
//////////////////////////
//      void foo(int x = 0);
// we gnerally would not call this foo(0); 
// we'd use foo() instead
//
/////////////////////////
// Pointer Initialization
/////////////////////////
// 0 is no longer used as a pointer value.
//     int *pOld{ 0 };
//     int *pNow{ nullptr }; // using nullptr instead of zero to 
//                           // initialize a pointer
//
///////////////////////////////////////
// Static Local Variable Initialization
///////////////////////////////////////
//
/*
int main() {
  static int a;
  std::cout << a;
}
*/
// Since a is a static local variable, it is automatically 
// zero-initialized. This would not have happened if we 
// removed the keyword static, making it a non-static local 
// variable.

// [basic.start.static]§6.6.2¶2 in the standard:
//
// If constant initialization is not performed, a variable with static 
// storage duration (6.7.1) or thread storage duration (6.7.2) is 
// zero-initialized (11.6)

// a has static storage duration and is not constant initialized, 
// so it gets zero-initialized.
#endif


#if CASE == 14
////////////////////////////////////////////////////////////////////////////////
//
// 14. INITILIZING STRUCT
//
// Initializing structs by assigning values member by member is a little 
// cumbersome, so C++ supports a faster way to initialize structs using 
// an initializer list. This allows you to initialize some or all the 
// members of a struct at declaration time.
/*
struct Employee
{
    short id;
    int age;
    double wage;
};
 
Employee joe = { 1, 32, 60000.0 }; // joe.id = 1, joe.age = 32, joe.wage = 60000.0
Employee frank = { 2, 28 }; // frank.id = 2, frank.age = 28, frank.wage = 0.0 (default initialization)
*/
// In C++11, we can also use uniform initialization:
/*
Employee joe { 1, 32, 60000.0 }; // joe.id = 1, joe.age = 32, 
                                 //joe.wage = 60000.0
Employee frank { 2, 28 }; // frank.id = 2, frank.age = 28, 
//                        // frank.wage = 0.0 (default initialization)
*/
// If the initializer list does not contain an initializer for some elements,
// those elements are initialized to a default value (that generally 
// corresponds to the zero state for that type). In the above example, 
// we see that frank.wage gets default initialized to 0.0 because we did 
// not specify an explicit initialization value for it.
#endif


#if CASE == 15
////////////////////////////////////////////////////////////////////////////////
//
// 15. INITILIZING CLASS
//
// In the previous lesson, for simplicity, we initialized our class member 
// data in the constructor using the assignment operator. For example:
/*
class Something
{
private:
    int m_value1;
    double m_value2;
    char m_value3;
public:
    Something()
    {
        // These are all assignments, not initializations
        m_value1 = 1;
        m_value2 = 2.2;
        m_value3 = 'c';
    }
};
*/
// When the class’s constructor is executed, m_value1, m_value2, and 
// m_value3 are created. Then the body of the constructor is run, where 
// the member data variables are assigned values. This is similar to 
// the flow of the following code in non-object-oriented C++:
/*  
int m_value1;
double m_value2;
char m_value3;
 
m_value1 = 1;
m_value2 = 2.2;
m_value3 = 'c';
*/
// While this is valid within the syntax of the C++ language, it does 
// not exhibit good style (and may be less efficient than initialization).

// However, as you have learned in previous lessons, some types of data
// (e.g. const and reference variables) must be initialized on the line 
// they are declared. Consider the following example:
/*
class Something
{
private:
    const int m_value;
public:
    Something(){ m_value = 1;} // error: const vars can not be assigned
};
*/
// This produces code similar to the following:
/*
const int m_value; // error: const vars must be initialized with a value during its creation
m_value = 5;       // error: const vars can not be assigned to
*/
// Assigning values to const or reference member variables in the body 
// of the constructor is clearly not sufficient in some cases.
//
// Member initializer lists
//
// To solve this problem, C++ provides a method for initializing class 
// member variables (rather than assigning values to them after they 
// are created) via a member initializer list (often called a “member 
// initialization list”). Do not confuse these with the similarly named
// initializer list that we can use to assign values to arrays.

// We know that you could initialize variables in three ways: 
// copy, direct, and via uniform initialization (C++11 only).
//    int value1 = 1; // copy initialization
//    double value2(2.2); // direct initialization
//    char value3 {'c'}; // uniform initialization
//
// Using an initialization list is almost identical to doing direct 
// initialization (or uniform initialization in C++11).
//
// This is something that is best learned by example. Revisiting our
// code that does assignments in the constructor body:
/* 
class Something
{
private:
    int m_value1;
    double m_value2;
    char m_value3;
public:
    Something()
    {
        // These are all assignments, not initializations
        m_value1 = 1;
        m_value2 = 2.2;
        m_value3 = 'c';
    }
};
*/
//
////////////////////////
// Direct Inilialization
////////////////////////
//
// Now let’s write the same code using an initialization list:
/*
class Something
{
private:
    int m_value1;
    double m_value2;
    char m_value3;
public:
    Something() : m_value1(1), m_value2(2.2), m_value3('c') // directly initialize our member variables
    {
    // No need for assignment here
    }
    void print()
    { std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n"; }
};
int main()
{
    Something something;
    something.print();
    return 0;
}
*/
// This prints: Something(1, 2.2, c)

// The member initializer list is inserted after the constructor parameters.
// It begins with a colon (:), and then lists each variable to initialize 
// along with the value for that variable separated by a comma.

// Note that we no longer need to do the assignments in the constructor body,
// since the initializer list replaces that functionality. Also note that the
// initializer list does not end in a semicolon.

// Of course, constructors are more useful when we allow the caller to pass
// in the initialization values:
/*
class Something
{
private:
    int m_value1;
    double m_value2;
    char m_value3;
public:
    Something(int value1, double value2, char value3='c')
        : m_value1(value1), m_value2(value2), m_value3(value3) // directly initialize our member variables
    {
    // No need for assignment here
    }
    void print()
    { std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n"; }
};
int main()
{
    Something something(1, 2.2); // value1 = 1, value2=2.2, value3 gets default value 'c'
    something.print();
    return 0;
}
*/
// This prints: Something(1, 2.2, c)

// Note that you can use default parameters to provide a default value in 
// case the user didn’t pass one in.

// Here’s an example of a class that has a const member variable:
/*
class Something
{
private:
    const int m_value;
public:
    Something(): m_value(5) // directly initialize our const member variable
    {} 
};
*/
// This works because we’re allowed to initialize const variables 
// (but not assign to them!).

// Rule: Use member initializer lists to initialize your class member 
// variables instead of assignment.

/////////////////////////
// Uniform initialization
/////////////////////////
//
// Instead of direct initialization, uniform initialization can be used:
/*
class Something
{
private:
    const int m_value;
public:
    Something(): m_value { 5 } // Uniformly initialize our member variables
    {} 
};
*/
// We strongly encourage you to begin using this new syntax (even if you 
// aren’t using const or reference member variables) as initialization 
// lists are required when doing composition and inheritance (subjects 
// we will be covering shortly).

// Rule: Favor uniform initialization over direct initialization if your 
// compiler is C++11 compatible

///////////////////////////////////////////////////////////
// Initializing array members with member initializer lists
///////////////////////////////////////////////////////////
//
// Consider a class with an array member:
/* 
class Something
{
private:
    const int m_array[5];
};*/
// Prior to C++11, you can only zero an array member via a member
// initialization list:
/*
class Something
{
private:
    const int m_array[5];
public:
    Something(): m_array {} // zero the member array
    {}
};*/
//
// However, in C++11, you can fully initialize a member array using 
// uniform initialization:
/*
class Something
{
private:
    const int m_array[5];
 
public:
    Something(): m_array { 1, 2, 3, 4, 5 } // use uniform initialization to initialize our member array
    {}
};*/

/////////////////////////////////////////////////
// Initializing member variables that are classes
/////////////////////////////////////////////////
//
// A member initialization list can also be used to initialize members that 
// are classes.
/*
class A
{
public:
    A(int x) { std::cout << "A " << x << "\n"; }
};
class B
{
private:
    A m_a;
public:
    B(int y) : m_a(y-1) // call A(int) constructor to initialize member m_a
    { std::cout << "B " << y << "\n";}
};
int main()
{
    B b(5);
    return 0;
}
*/
// This prints:
// A 4
// B 5

// - When variable b is constructed, the B(int) constructor is called with value 5. 
// - Before the body of the constructor executes, m_a is initialized, 
//   calling the A(int) constructor with value 4. This prints “A 4”. 
// - Then control returns back to the B constructor, and the body of the B 
//   constructor executes, printing “B 5”.

////////////////////////////////////
// Formatting your initializer lists
////////////////////////////////////
//
// C++ gives you a lot of flexibility in how to format your initializer 
// lists, and it’s really up to you how you’d like to proceed. But here
// are some recommendations:

// If the initializer list fits on the same line as the function name, 
// then it’s fine to put everything on one line:
/*
class Something
{
private:
    int m_value1;
    double m_value2;
    char m_value3;
public:
    Something() : m_value1(1), m_value2(2.2), m_value3('c') // everything on one line
    {}
};
*/
// If the initializer list doesn’t fit on the same line as the function name,
// then it should go indented on the next line.
/*
class Something
{
private:
    int m_value1;
    double m_value2;
    char m_value3;
public:
    Something(int value1, double value2, char value3='c') // this line already has a lot of stuff on it
        : m_value1(value1), m_value2(value2), m_value3(value3) // so we can put everything indented on next line
    {}
};
*/

// If all of the initializers don’t fit on a single line (or the initializers 
// are non-trivial), then you can space them out, one per line:
/*
class Something
{
private:
    int m_value1;
    double m_value2;
    char m_value3;
    float m_value4;
public:
    Something(int value1, double value2, char value3='c', float value4=34.6) // this line already has a lot of stuff on it
        : m_value1(value1), // one per line, commas at end of each line
          m_value2(value2),
          m_value3(value3),
          m_value4(value4) 
    {}
};
*/
//
/////////////////////////
// Initializer list order
/////////////////////////
//
// Perhaps surprisingly, variables in the initializer list are not initialized 
// in the order that they are specified in the initializer list. Instead, they 
// are initialized in the order in which they are declared in the class.

// For best results, the following recommendations should be observed:
// 1) Don’t initialize member variables in such a way that they are dependent 
// upon other member variables being initialized first (in other words, ensure
// your member variables will properly initialize even if the initialization 
// ordering is different).
// 2) Initialize variables in the initializer list in the same order in which 
// they are declared in your class. This isn’t strictly required so long as 
// the prior recommendation has been followed, but your compiler may give you 
// a warning if you don’t do so and you have all warnings turned on.

// Summary

// Member initializer lists allow us to initialize our members rather than 
// assign values to them. This is the only way to initialize members that 
// require values upon initialization, such as const or reference members, 
// and it can be more performant than assigning values in the body of the 
// constructor. Member initializer lists work both with fundamental types 
// and members that are classes themselves.

#if CASE == 16
////////////////////////////////////////////////////////////////////////////////
//
// 15. Example
// 
#include <utility>
struct X {
    X() { std::cout << "1"; }
    X(X &) { std::cout << "2"; }
    X(const X &) { std::cout << "3"; }
    X(X &&) { std::cout << "4"; }
    ~X() { std::cout << "5"; }
};
struct Y {
    mutable X x;
    Y() = default;
    Y(const Y &) = default;
};

int main() {
    Y y1;
    Y y2 = std::move(y1);
}

// Answer-The program is guaranteed to output: 1255

// Explanation

// First, the line

//    Y y1;

// creates an instance of Y. Y has an X data member, which is default 
// constructed, printing 1.

// Then,

//    Y y2 = std::move(y1);

// copy-initializes another Y. The std::move turns y1 into an rvalue, 
// but since Y has no move constructor, its copy constructor is called. 
// The implicitly-defined (default) copy-constructor performs a copy of 
// x, as  specified in [class.copy.ctor]§15.8.1¶14:
//
// The implicitly-defined copy/move constructor for a non-union class X 
// performs a memberwise copy/move of its bases and members.

// ow the question is which copy constructor is used to initialize the 
// copy of x. Will it pick X(X &) or X(const X &)? The Y inside the 
// Y(const Y &) copy constructor is const, but x is marked mutable, and 
// [dcl.stc]§10.1.1¶9 says:

// The mutable specifier on a class data member nullifies a const specifier 
// applied to the containing class object and permits modification of the 
// mutable class member even though the rest of the object is const

// So x is considered non-const, and X(X &) is a better match to overload 
// resolution than X(const X &), because in the latter case, a const
// conversion has to happen. So X(X &) is called, printing 2.

// Finally, both y1 and y2 are destroyed at the end of main, printing 55.