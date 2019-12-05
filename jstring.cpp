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

#define CASE 4

#if CASE==1
////////////////////////////////////////////////////////////////////////////////

// 1. String applications
//
// In C++ we can store string by one of the two ways –

//    C style strings
//    string class (discussed here)

// string class is part of C++ library that supports a lot much functionality 
// over C style strings.
// C++ string class internally uses char array to store character but all 
// memory management, allocation, and null termination is handled by string 
// class itself that is why it is easy to use. The length of the C++ string 
// can be changed at runtime because of dynamic allocation of memory similar 
// to vectors. As string class is a container class, we can iterate over all 
// its characters using an iterator similar to other containers like vector, 
// set and maps, but generally, we use a simple for loop for iterating over 
// the characters and index them using [] operator.
// C++ string class has a lot of functions to handle string easily. Most 
// useful of them are demonstrated in below code.

// C++ program to demonstrate various function string class 
#include <bits/stdc++.h> 
using namespace std; 
  
int main() // various constructor of string class 
{ 
    // initialization by raw string 
    string str1("first string"); 
    cout << "str1 = "<< str1 << endl; 
  
    // initialization by another string 
    string str2(str1); 
    cout << "str2-copy of str1 = "<< str2 << endl; 
  
    // initialization by character with number of occurence 
    string str3(5, '#'); 
    cout << "str3(5,'#') = "<< str3 << endl; 

    // initialization by part of another string 
    string str4(str1, 6, 6); //from 6th (2nd par) 6 chars (3rd par) 
    cout << "str4(str1,6,6)-from 6th with 6 chars = "<< str4 << endl; 

    // initialization by part of another string : iteartor version 
    string str5(str2.begin(), str2.begin() + 5); 
    cout << "str5(str2.begin(),str2.begin()+5) = "<< str5 << endl; 

    //  assignment operator 
    string str6 = str4; 
    cout << "str6 = str4 = "<< str6 << endl; 

    // clear function deletes all character from string 
    str4.clear(); 
    cout << "str4-after str4.clear() = "<< str4 << endl; 

    //  both size() and length() return length of string and they work as synonyms 
    int len = str6.length(); // Same as "len = str6.size();" 
    cout << "Length of str6 is : " << len << endl; 
  
    // a particular character can be accessed using at [] operator 
    char ch = str6.at(2); //  Same as "ch = str6[2];" 
    cout << "str6.at(2)-3rd character of str6 = " << ch << endl; 
  
    // front return 1st and back returns last  of string 
    char ch_f = str6.front();  // Same as "ch_f = str6[0];" 
    char ch_b = str6.back();   // Same as "ch_b = str6[str6.length() - 1];" 
    cout << "1st of str6 = " << ch_f << ", last of str6 = "<< ch_b << endl; 
  
    // c_str returns null terminated char array version of string 
    const char* charstr = str6.c_str(); 
    printf("%s\n", charstr); 
  
    // append add the argument string at the end 
    str6.append(" extension"); //  same as str6 += " extension" 
    cout << "str6.append(\" extension\") = " << str6 << endl;

    // another version of append, which appends part of other string 
    str4.append(str6, 0, 6);  // at 0th position 6 character 
    cout << "str4.append(str6, 0, 6) = " << str4 << endl;

    // find returns index where pattern is found. If pattern is not there it 
    // returns predefined constant npos whose value is -1 
    if (str6.find(str4) != string::npos) 
        cout << "str4 found in str6 at " << str6.find(str4) << " pos" << endl; 
    else
        cout << "str4 not found in str6" << endl; 
  
    // substr(a, b) function returns a substring of b length starting from index a 
    cout << "str6.substr(7, 3) = " << str6.substr(7, 3) << endl; 
  
    // if 2nd argument is not passed, string till end is taken as substring 
    cout << "str6.substr(7) = " << str6.substr(7) << endl; 
  
    //  erase(a, b) deletes b characters at index a 
    str6.erase(7, 4); 
    cout << "str6.erase(7, 4) = "<< str6 << endl; 
  
    //  iterator version of erase 
    str6.erase(str6.begin() + 5, str6.end() - 3); 
    cout << "str6.erase(str6.begin()+5,str6.end()-3) = "<<str6 << endl; 
  
    str6 = "This is a examples"; 
  
    //  replace(a, b, str)  replaces b characters from a index by str 
    str6.replace(2, 7, "ese are test"); 
    cout << "str6.replace(2, 7, \"ese are test\") = "<<str6 << endl; 
  
    return 0; 
} 
/*
str1 = first string
str2-copy of str1 = first string
str3(5,'#') = #####
str4(str1,6,6)-from 6th with 6 chars = string
str5(str2.begin(),str2.begin()+5) = first
str6 = str4 = string
str4-after str4.clear() = 
Length of str6 is : 6
str6.at(2)-3rd character of str6 = r
1st of str6 = s, last of str6 = g
string
str6.append(" extension") = string extension
str4.append(str6, 0, 6) = string
str4 found in str6 at 0 pos
str6.substr(7, 3) = ext
str6.substr(7) = extension
str6.erase(7, 4) = string nsion
str6.erase(str6.begin()+5,str6.end()-3) = strinion
str6.replace(2, 7, "ese are test") = These are test examples
*/
// As seen in the above code, we can get the length of the string by 
// size() as well as length() but length() is preferred for strings. 
// We can concat a string to another string by += or by append(), 
// but += is slightly slower than append() because each time + is 
// called a new string (creation of new buffer) is made which is 
// returned that is a bit overhead in case of many append operation. 
#endif

#if CASE == 2
////////////////////////////////////////////////////////////////////////////////
//
// 2. String functions 
//
#include <bits/stdc++.h> 
using namespace std; 
  
// this function returns floating point part of a number-string 
string returnFloatingPart(string str) 
{ 
    int pos = str.find("."); 
    if (pos == string::npos) // npos used as the value for a len (or sublen) 
                             // parameter in string's member functions, means 
                             // "until the end of the string".
        return ""; 
    else
        return str.substr(pos + 1); 
} 
  
// This function checks whether a string contains all digit or not 
bool containsOnlyDigit(string str) 
{ 
    int l = str.length(); 
    for (int i = 0; i < l; i++) 
    { 
        if (str.at(i) < '0' || str.at(i) > '9') 
            return false; 
    } 
    //  if we reach here all character are digits 
    return true; 
} 
  
// this function replaces all single space by %20 Used in URLS 
string replaceBlankWith20(string str) 
{ 
    string replaceby = "%20"; 
    int n = 0; 
  
    // loop till all space are replaced 
    while ((n = str.find(" ", n)) != string::npos ) 
    { 
        str.replace(n, 1, replaceby); 
        n += replaceby.length(); 
    } 
    return str; 
} 
  
// driver function to check above methods 
int main() 
{ 
    string fnum = "23.342"; 
    cout << "Floating part is : " << returnFloatingPart(fnum)  
         << endl; 
  
    string num = "3452"; 
    if (containsOnlyDigit(num)) 
        cout << "string contains only digit" << endl; 
  
    string urlex = "google com in"; 
    cout << replaceBlankWith20(urlex) << endl; 

    // compare: Comparing strings using compare() 
    string str("GeeksforGeeks"); 
    string str1("GeeksforGeeks"); 
    if ( str.compare(str1) == 0 ) 
        cout << "Strings are equal"<< endl; 
    else 
        cout << "Strings are unequal"<< endl; 

    // find()
    string str2("The Geeks for Geeks"); 
    // find() returns position to first occurrence of substring "Geeks" 
    cout << "First occurrence of \"Geeks\" starts from : "; 
    cout << str2.find("Geeks") << endl; 
      
    // Prints position of first occurrence of any character of "reef" (Prints 2) 
    cout << "First occurrence of character from \"reef\" is at : "; 
    cout << str2.find_first_of("reef") << endl; 
      
    // Prints position of last occurrence of any character of "reef" (Prints 16) 
    cout << "Last occurrence of character from \"reef\" is at : "; 
    cout << str2.find_last_of("reef") << endl; 
      
    // rfind() returns position to last occurrence of substring "Geeks" Prints 14 
    cout << "Last occurrence of \"Geeks\" starts from : "; 
    cout << str2.rfind("Geeks") << endl; 
  
	// find(“string”): Searches the string for the first occurrence of the substring 
	// specified in arguments. It returns the position of the first occurrence of substring.
	// find_first_of(“string”): Searches the string for the first character that matches any 
	// of the characters specified in its arguments. It returns the position of the first 
	// character that matches.
	// find_last_of(“string”): Searches the string for the last character that 
	// matches any of the characters specified in its arguments. It returns the 
	// position of the last character that matches.
	// rfind(“string”): Searches the string for the last occurrence of the substring 
	// specified in arguments. It returns the position of the last occurrence of substring

    // inserting
    string str3("Geeksfor"); 
      
    // Printing the original string 
    cout << str3 << endl; 
      
    // Inserting "Geeks" at 8th index position 
    str3.insert(8,"Geeks"); 
    cout << str3 << endl; 

    // insert(pos_to_begin,string_to_insert): This function inserts the given 
    // substring in the string. It takes two arguments, first the position 
    // from which you want to insert the substring and second the substring.

    // clearing
    string str4("GeeksforGeeks"); 
    str4.clear(); 
    (str4.empty()==1)? cout << "String is empty" << endl : cout << "String is not empty" << endl; 

    // clear(): This function clears all the characters from the string. 
    // The string becomes empty (length becomes 0) after this operation.
    // empty(): Tests whether the string is empty. This function return 
    // a Boolean value.

    return 0;       
} 
#endif

#if CASE ==3
////////////////////////////////////////////////////////////////////////////////
//
// 3. Reversing a String
//
// Given a string, write a C/C++ program to reverse it.
// string-reverse
// Write own reverse function by swapping characters: One simple 
// solution is two write our own reverse function to reverse a string in C++.
 
     // A Simple C++ program to reverse a string 
    #include <bits/stdc++.h> 
    using namespace std; 
      
    // revers(): default functiojn

    // reverse1(): user defined function 
    void reverse1(string& str) 
    { 
        int n = str.length(); 
      
        // Swap character starting from two corners 
        for (int i = 0; i < n / 2; i++) 
            swap(str[i], str[n - i - 1]); 
    } 
    
    // reverse2(): user defined function 
    void reverse2(string str) 
    { 
       for (int i=str.length()-1; i>=0; i--) 
          cout << str[i];  
    } 
      
    // revers3(): user defined function, reverse string pointer of that 
    char* reverse3(char const* str) 
    { 
        // find length of string 
        int n = strlen(str); 
      
        // create dynamic pointer char array 
        char *rev = new char[n+1]; 
      
        // copy of string to ptr array 
        strcpy(rev, str); 
      
        // Swap character starting from two 
        // corners 
        for (int i=0, j=n-1; i<j; i++,j--) 
            swap(rev[i], rev[j]);        
          
        // return pointer of reversed string 
        return rev; 
    } 

    // Driver program 
    int main() 
    { 
        string str = "geeksforgeeks"; 

        reverse(str.begin(), str.end()); 
        cout << str << endl; 
        reverse1(str); 
        cout << str << endl; 
        reverse2(str);
        cout << str << endl;

        printf("%s", reverse3(str)); 
        return 0; 
    } 
#endif


#if CASE == 4
////////////////////////////////////////////////////////////////////////////////
//
// 4. String vs Character Array
//
// In C++, in addition to character array, there exist a similar 
// kind of way to implement string, that is using string class 
// which is a part of C++ standard library. To implement string 
// using string class, we need to add header file . Basic difference
// between character array and a string is, in case of character array,
// the size has to be alloted at the time of declaration, i.e all 
// memory once allocated is fixed and cannot be altered at run time. 
// Whereas, for string, there is no need to specify the size and to 
// allocate fixed memory at the time of declaration.

// C++ program to demonstrate Character Array and String 
#include<iostream> 
#include<string>// for string class 
using namespace std; 
int main() 
{ 
    // Size has to be predefined in character array 
    char str[80] = "GeeksforGeeks"; 
  
    // Size not predefined in string 
    string s("GeeksforGeeks"); 
  
    // Printing character array and string 
    cout << str << endl; 
    cout << s << endl; 
  
    return 0; 
} 
#endif

#if CASE == 5
////////////////////////////////////////////////////////////////////////////////
//
// 5. Converting string to number and vice-versa
//
// In general or more specifically in competitive programming 
// there are many instances where we need to convert a number 
// to a string or string to a number. But lack of knowledge of
// certain essential tools bind us to do so. Some methods to 
// achieve this task are mentioned in this article.

// Converting string to number

// Method 1 : Using stringstream class or sscanf()
// Method 2 : String conversion using stoi() or atoi()
// Both these methods have been discussed in detail in the this article.
// Method 3 : Using boost lexical cast

// Boost library offers an inbuild function “lexical_cast(“string”)”, 
// which directly converts a string to number. It returns an 
// exception “bad_lexical_cast” in case of invalid input.

//C++ code to demonstrate working of lexical_cast() 
#include<iostream> 
#include <boost/lexical_cast.hpp>// for lexical_cast() 
#include <string> // for string 
using namespace std; 
int main() 
{ 
   string str = "5"; 
   string str1 = "6.5"; 
  
   // Initializing f_value with casted float f_value is 6.5 
   float f_value = boost::lexical_cast<float>(str1); 
  
   // Initializing i_value with casted int i_value is 5 
   int i_value = boost::lexical_cast<int>(str); 
  
   //Displaying casted values 
   cout << "The float value after casting is : "; 
   cout << f_value <<endl; 
   cout << "The int value after casting is : "; 
   cout << i_value <<endl; 
  
   return 0; 
} 

#endif

#if CASE == 6
////////////////////////////////////////////////////////////////////////////////
//
// 6. Converting number to string
//
// Method 1 : Using string streams
// In this method, string stream declares a stream object 
// which first inserts a number, as a stream into object
//  and then uses “str()” to follow internal conversion of number to string.

#include<iostream> 
#include <sstream>  // for string streams 
#include <string>  // for string 
using namespace std; 
int main() 
{ 
    int num = 2016; 
  
    // declaring output string stream 
    ostringstream str1; 
  
    // Sending a number as a stream into output string 
    str1 << num; 
  
    // the str() coverts number into string 
    string geek = str1.str(); 
  
    // Displaying the string 
    cout << "The newly formed string from number is : "; 
    cout << geek << endl; 
  
    return 0; 
} 
#endif

#if CASE == 7
////////////////////////////////////////////////////////////////////////////////
//
// Method 2 : Using to_string()
//
// This function accepts a number(can be any data type) and returns the 
// number in the desired string.
// C++ code to demonstrate "to_string()" method 
// to convert number to string. 
#include<iostream> 
#include<string> // for string and to_string() 
using namespace std; 
int main() 
{ 
    // Declaring integer 
    int i_val = 20; 
  
    // Declaring float 
    float f_val = 30.50; 
  
    // Conversion of int into string using to_string() 
    string stri = to_string(i_val); 
  
    // Conversion of float into string using to_string() 
    string strf = to_string(f_val); 
  
    // Displaying the converted strings 
    cout << "The integer in string is : "; 
    cout << stri << endl; 
    cout << "The float in string is : "; 
    cout << strf << endl; 
  
    return 0;     
} 
/*
The integer in string is : 20
The float in string is : 30.500000
*/
#endif

#if CASE == 8
////////////////////////////////////////////////////////////////////////////////
//
// Method 3 : Using boost lexical cast
// Similar to string conversion, the ” lexical_cast() ” function remains the 
// same, but this time argument list modifies to “lexical_cast(numeric_var).

// C++ code to demonstrate "lexical_cast()" method 
// to convert number to string. 
#include <boost/lexical_cast.hpp> // for lexical_cast() 
#include <string> // for string 
using namespace std; 
int main() 
{   
   // Declaring float 
   float f_val = 10.5; 
  
   // Declaring int 
   int i_val = 17; 
     
   // lexical_cast() converts a float into string 
   string strf = boost::lexical_cast<string>(f_val);  
     
   // lexical_cast() converts a int into string 
   string stri = boost::lexical_cast<string>(i_val);  
     
   // Displaying string converted numbers 
   cout << "The float value in string is : "; 
   cout << strf << endl; 
   cout << "The int value in string is : "; 
   cout << stri << endl; 
     
   return 0;    
} 
/*
The float value in string is : 10.5
The int value in string is : 17
*/
#endif

#if CASE == 9
////////////////////////////////////////////////////////////////////////////////
//
// std::string::append vs std::string::push_back() vs Operator += in C++

// To append characters, you can use operator +=, append(), and 
// push_back(). All of them helps to append character but with 
// a little difference in implementation and application.
/*
    Operator += : appends single-argument values.
    append() : lets you specify the appended value by using multiple arguments.
    push_back() : lets you to append single character at a time.
*/
// Here are few standards we can have for comparison among these three:


// 1)Full String:
/*
    += : We can append full string using +=.
    append() : We can also append full string using append().
    push_back : doesn’t allow appending of full string.
*/

// CPP code for comparison on the basis of appending Full String 
#include <iostream> 
#include <string> 
using namespace std; 
  
// Function to demonstrate comparison among 
// +=, append(), push_back() 
void appendDemo(string str1, string str2) 
{ 
    string str = str1; 
  
    // Appending using += 
    str1 += str2; 
    cout << "Using += : "; 
    cout << str1 << endl; 
  
    // Appending using append() 
    str.append(str2); 
    cout << "Using append() : "; 
    cout << str << endl; 
} 
  
// Driver code 
int main() 
{ 
    string str1("Hello World! "); 
    string str2("GeeksforGeeks"); 
  
    cout << "Original String : " << str1 << endl; 
    appendDemo(str1, str2); 
  
    return 0; 
} 

/*
Original String : Hello World! 
Using += : Hello World! GeeksforGeeks
Using append() : Hello World! GeeksforGeeks
*/
#endif

#if CASE == 10
////////////////////////////////////////////////////////////////////////////////
//
// 2) Appending part of String
/*
    += : Doesn’t allow appending part of string.
    append() : Allows appending part of string.
    push_back : We can’t append part of string using push_back.*/

// CPP code for comparison on the basis of 
// Appending part of string 
  
#include <iostream> 
#include <string> 
using namespace std; 
  
// Function to demonstrate comparison among 
// +=, append(), push_back() 
void appendDemo(string str1, string str2) 
{ 
    // Appends 5 characters from 0th index of 
    // str2 to str1 
    str1.append(str2, 0, 5); 
    cout << "Using append() : "; 
    cout << str1; 
} 
  
// Driver code 
int main() 
{ 
    string str1("GeeksforGeeks "); 
    string str2("Hello World! "); 
  
    cout << "Original String : " << str1 << endl; 
    appendDemo(str1, str2); 
  
    return 0; 
} 

/*
Original String : GeeksforGeeks 
Using append() : GeeksforGeeks Hello
*/
#endif

#if CASE == 11
////////////////////////////////////////////////////////////////////////////////
//
// 3)Appending C-string (char*):
/*
    += : Allows appending C-string
    append() : It also allows appending C-string
    push_back : We cannot append C-string using push_back().*/

// CPP code for comparison on the basis of 
// Appending C-string 
  
#include <iostream> 
#include <string> 
using namespace std; 
  
// Function to demonstrate comparison among 
// +=, append(), push_back() 
void appendDemo(string str) 
{ 
    string str1 = str; 
  
    // Appending using += 
    str += "GeeksforGeeks"; 
    cout << "Using += : "; 
    cout << str << endl; 
  
    // Appending using append() 
    str1.append("GeeksforGeeks"); 
    cout << "Using append() : "; 
    cout << str1 << endl; 
} 
  
// Driver code 
int main() 
{ 
    string str("World of "); 
  
    cout << "Original String : " << str << endl; 
    appendDemo(str); 
  
    return 0; 
} 
/*
Original String : World of 
Using += : World of GeeksforGeeks
Using append() : World of GeeksforGeeks
*/
#endif

#if CASE == 12
////////////////////////////////////////////////////////////////////////////////
//
// 4)Appending character array:
/*
    += : Allows appending of character array
    append() : Allows appending of character array.
    push_back : Does not allow char array appending.
*/

// CPP code for comparison on the basis of 
// Appending character array 
  
#include <iostream> 
#include <string> 
using namespace std; 
  
// Function to demonstrate comparison among 
// +=, append(), push_back() 
void appendDemo(string str) 
{ 
    char ch[6] = {'G', 'e', 'e', 'k', 's', '\0'};  
    string str1 = str; 
  
    // Appending using += 
    str += ch; 
    cout << "Using += : " << str << endl; 
  
    // Appending using append() 
    str1.append(ch); 
    cout << "Using append() : "; 
    cout << str1 << endl; 
} 
  
// Driver code 
int main() 
{ 
    string str("World of "); 
    cout << "Original String : " << str << endl; 
    appendDemo(str); 
  
    return 0; 
} 
/*
Original String : World of 
Using += : World of Geeks
Using append() : World of Geeks
*/
#endif

#if CASE == 13
////////////////////////////////////////////////////////////////////////////////
//
// 5)Appending single character:

/*    += : We can append single character using += operator.
    append() : Doesn’t allow appending single character.
    push_back : Allows appending single character.*/

// CPP code for comparison on the basis of 
// Appending single character 
  
#include <iostream> 
#include <string> 
using namespace std; 
  
// Function to demonstrate comparison among 
// +=, append(), push_back() 
void appendDemo(string str) 
{ 
    string str1 = str; 
  
    // Appending using += 
    str += 'C'; cout << "Using += : " << str << endl; 
  
    // Appending using push_back() 
    str1.push_back('C'); 
    cout << "Using push_back : "; 
    cout << str1; 
} 
  
// Driver code 
int main() 
{ 
    string str("AB"); 
  
    cout << "Original String : " << str << endl; 
    appendDemo(str); 
  
    return 0; 
} 
/*
Original String : AB
Using += : ABC
Using push_back : ABC
*/
#endif

#if CASE == 14
////////////////////////////////////////////////////////////////////////////////
//
// 6)Iterator range:
/*
    += : Doesn’t provide iterator range.
    append() : Provides iterator range.
    push_back : Doesn’t provide iterator range.*/

// CPP code for comparison on the basis of 
// Appending using iterator range 
  
#include <iostream> 
#include <string> 
using namespace std; 
  
// Function to demonstrate comparison among 
// +=, append(), push_back() 
void appendDemo(string str1, string str2) 
{ 
  
    // Appends all characters from 
    // str2.begin()+5, str2.end() to str1 
    str1.append(str2.begin() + 5, str2.end()); 
    cout << "Using append : "; 
    cout << str1; 
} 
// Driver code 
int main() 
{ 
    string str1("Hello World! "); 
    string str2("GeeksforGeeks"); 
  
    cout << "Original String : " << str1 << endl; 
    appendDemo(str1, str2); 
  
    return 0; 
} 
/*
Original String : Hello World! 
Using append : Hello World! forGeeks*/
#endif

#if CASE == 15
////////////////////////////////////////////////////////////////////////////////
//
// 7)Return Value:
//
/*    += : Return *this.
    append() : Returns *this
    push_back : Doesn’t return anything.*/

// CPP code for comparison on the basis of 
// Return value 
  
#include <iostream> 
#include <string> 
using namespace std; 
  
// Function to demonstrate comparison among 
// +=, append(), push_back() 
string appendDemo(string str1, string str2) 
{ 
    // Appends str2 in str1 
    str1.append(str2); // Similarly with str1 += str2 
    cout << "Using append : "; 
  
    // Returns *this 
    return str1; 
} 
  
// Driver code 
int main() 
{ 
    string str1("Hello World! "); 
    string str2("GeeksforGeeks"); 
    string str; 
    cout << "Original String : " << str1 << endl; 
    str = appendDemo(str1, str2); 
    cout << str; 
    return 0; 
} 
/*
Original String : Hello World! 
Using append : Hello World! GeeksforGeeks
*/

#endif

#if CASE == 16
////////////////////////////////////////////////////////////////////////////////
//
// Print substring of a given string without using any string 
// function and loop in C

// Write a function mysubstr() in C that doesn’t use any string 
// function, doesn’t use any loop and prints substring of a 
// string. The function should not modify contents of string 
// and should not use a temporary char array or string.

// For example mysubstr(“geeksforgeeks”, 1, 3) should print 
// “eek” i.e., the substring between indexes 1 and 3.
// Recommended: Please try your approach on {IDE} first,
// before moving on to the solution.

// One solution is to use recursion. Thanks to Gopi and 
// oggy for suggesting this solution.
#include<stdio.h> 
// This function prints substring of str[] between low and 
// high indexes (both inclusive).   
void mysubstr(char str[], int low, int high) 
{ 
    if (low<=high) 
    { 
        printf("%c", str[low]); 
        mysubstr(str, low+1, high); 
    } 
} 
int main () 
{ 
    char str[] = "geeksforgeeks"; 
    mysubstr(str, 1, 3); 
    return 0; 
}
/*
Output: eek*/
#endif

#if CASE == 17
////////////////////////////////////////////////////////////////////////////////
//
// How to do it if recursions is also not allowed?
//
// We can always use pointer arithmetic to change the beginning part. For 
// example (str + i) gives us address of i’th character. To limit the ending, 
// we can use width specifier in printf which can be passed as an argument
// when * is used in format string.

#include <stdio.h> 
  
// This function prints substring of str[] between low and 
// high indexes (both inclusive).   
void mysubstr(char str[], int low, int high) 
{ 
    printf("%.*s", high-low+1, (str+low)); 
} 
  
int main () 
{ 
    char str[] = "geeksforgeeks"; 
    mysubstr(str, 1, 3); 
    return 0; 
} 
// Output: eek
#endif