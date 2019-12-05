#define CASE 5

////////////////////////////////////////////////////////////

#if CASE == 1
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
bool isPalindrome(const string& word)
{
  // throw logic_error("Waiting to be implemented");
  bool flag{};
  int N = word.length()-1;
  for (int i=0; i<N; ++i)
  {
     if (word.at(i) != word.at(N-i))
     {
     	flag = 0;
     }
     else
     {
     	flag = 1;
     }
  }
  return flag;
}
int main()
{
    cout << isPalindrome("Deleveled");
    
    return 0;
}
#endif

/////////////////////////////////////////////////////////////

#if CASE == 2
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector
#include <string>

using namespace std;

vector<string> unique_names(const vector<string>& names1, const vector<string>& names2)
{
    //throw logic_error("Waiting to be implemented");
    vector<string> names{names2};
    int i;

    for(auto element1 : names1)
    {
    	i=0;
    	for(auto element2 : names2)
    	{
    		if (element2 != element1)
    		{
            	i++;
    		}   			
    	}
    	if (i==names2.size()){
    		names.push_back(element1);
    	}
    }
    return names;
}

int main()
{
    vector<string> names1 = {"Ava", "Emma", "Olivia"};
    vector<string> names2 = {"Olivia", "Sophia", "Emma"};
    
    vector<string> result = unique_names(names1, names2);
    for(auto element : result)
    {
        cout << element << ' '; // should print Ava Emma Olivia Sophia
    }
}
#endif

////////////////////////////////////////////////////////////////////

#if CASE == 3
// find example
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector

using namespace std;

int main () {
  // using std::find with array and pointer:
  int myints[] = { 10, 20, 30, 40 };
  int * p;

  //p = std::find (myints, myints+4, 30);
  p = find (myints, myints+4, 30);
  if (p != myints+4)
    cout << "Element found in myints: " << *p << '\n';
  else
    cout << "Element not found in myints\n";

  // using std::find with vector and iterator:
  vector<int> myvector (myints,myints+4);
  vector<int>::iterator it;

  it = find (myvector.begin(), myvector.end(), 30);
  if (it != myvector.end())
    cout << "Element found in myvector: " << *it << '\n';
  else
    cout << "Element not found in myvector\n";

  return 0;
}
#endif

//////////////////////////////////////////////////////

#if CASE == 4
#include <iostream>

class MathUtils
{
	int a,b;
public:
	MathUtils(int x, int y): a(x),b(y) {}
    static double average(int a, int b)
    {
        return (double(a + b) / 2.0);
    }
};

int main()
{
	MathUtils M(0,0);
    std::cout << M.average(2, 1);
}
#endif

//////////////////////////////////////////////////////

#if CASE == 5
#include <iostream>
#include <string>
#include <vector>       // std::vector
#include <bits/stdc++.h> 
#include<ctype.h>

using namespace std;

class TextInput
{
public:
  string a;
  TextInput(){}
	TextInput(string c){ a = c;}
  void add(string c) { 
    if (c >= '0' && c <= '9') 
      a+=c;
  }
  string getValue() { return a; }

};

class NumericInput : public TextInput { 
public:
	void add(string c) { if (isdigit(c)) { a+=c;} }
};

int main()
{
    TextInput* input = new NumericInput;
    input->add('1');
    input->add('a');
    input->add('0');
    cout << input->getValue();
}
#endif

//////////////////////////////////////////////////////

#if CASE == 6
#include <iostream>

class A {
  int a;
public:
  A(){std::cout << "A()"<<std::endl;}
  A(A& x){std::cout << "copy A()"<<std::endl;}
  ~A(){std::cout << "~A()"<<std::endl;}
  void init(int x){a=x;std::cout << "init" <<a<<std::endl;}
  void foo(int a) {std::cout << "foo_A" << a<<std::endl;}
  virtual void goo(int a) {std::cout << "goo_A" << a<<std::endl;}
};

class B : public A {
public:
  B(){std::cout << "B()"<<std::endl;}
  B(B& x){std::cout << "copy B()"<<std::endl;}
  ~B(){std::cout << "~B()"<<std::endl;}
  void foo(int a) {std::cout << "foo_B" << a<<std::endl;}
  void goo(int a) {std::cout << "goo_B" << a<<std::endl;}
};

int main () {
    A *b = new B;
    b->init(3);
    b->foo(2);
    b->goo(4);
    B c;
    B d=c;
    A e=d;
    c.goo(5);
}
/*
A()
B()
init3
foo_A2
goo_B4
A()
B()
A()
copy B()
copy A()
goo_B5
~A()
~B()
~A()
~B()
~A()
*/

#endif