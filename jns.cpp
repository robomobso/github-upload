// namespaces
#include <iostream>
using namespace std;

// namespace identifier
// {
//   named_entities
// }

namespace myNamespace
{
  int a=1, b=2;
}

namespace foo
{
  int value() { return 5; }
}

namespace bar
{
  const double pi = 3.1416;
  double value() { return 2*pi; }
}

int main () {
  cout << foo::value() << '\n';
  cout << bar::value() << '\n';
  cout << bar::pi << '\n';
  cout << myNamespace::a << '\n';
  cout << myNamespace::b << '\n';
  return 0;
}

// using
#include <iostream>
using namespace std;

namespace first
{
  int x = 5;
  int y = 10;
}

namespace second
{
  double x = 3.1416;
  double y = 2.7183;
}

int main () 
{
  using namespace first;
  cout << x << '\n';
  cout << y << '\n';
  cout << second::x << '\n';
  cout << second::y << '\n';

  {
    using namespace second;
    cout << x << '\n';
  }

  return 0;
}

////////////////////////////////////////////////////////////////////////////////
// g++ -o msup msup_jlu10.cpp

#include <iostream>
#include <cstring>
//using namespace std;

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
	std::cout << "Person person, person.age = " << person.age << std::endl;

	// Member selection using reference to struct
	Person &ref = person;
	ref.age = 6;
	std::cout << "Person &ref = person, ref.age = 6, person.age = " << person.age << std::endl;

	// Member selection using pointer to struct
	Person *ptr = &person;
	(*ptr).age= 7;
	std::cout << "Person *ptr = &person, (*ptr).age = 7, person.age = " << person.age << std::endl;

	// 2nd member selection using pointer to struct (->)
	Person *ptr2 = &person;
	ptr2->age = 8;
	std::cout << "Person *ptr2 = &person, ptr2->age = 8, person.age = " << person.age << std::endl;
}

