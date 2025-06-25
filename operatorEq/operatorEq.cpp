#include <iostream>
#include <cstring>
using namespace std; 
class Person {
public:
	char* name; 
	int age;

	Person() {}
	Person(const char* name, int age) {
		size_t len = strnlen_s(name, 20) + 1; 
		this->name = new char[len];
		strcpy_s(this->name, len, name);
		this->age = age; 
	}

	//copy constructor
	Person(const Person& p) {
		size_t len = strnlen_s(p.name, 20) + 1; 
		name = new char[len];
		strcpy_s(this->name, len, p.name);
		age = p.age; 
	}

	//= operator overload
	Person operator= (const Person& p) {
		delete[] name; //free old memory
		size_t len = strnlen_s(p.name, 20) + 1;
		name = new char[len];
		strcpy_s(name, len, p.name);
		age = p.age;
		return *this; //return the current object
	}

	//Destructor
	~Person() {
		delete[] name; //free dynamically allocated memory
	}

	void print() const {
		cout << "Name: " << name << ", Age: " << age << endl;
	}
};

int main() {
	Person p1("Alice", 30);
	Person p2("Bob", 25);
	Person p3 = p2; // Calls copy constructor
	p1.print(); // Output: Name: Alice, Age: 30
	p2.print(); // Output: Name: Bob, Age: 25
	p3.print(); // Output: Name: Bob, Age: 25
	p3 = p1; // Calls assignment operator
	p1.print(); // Output: Name: Alice, Age: 30
	p2.print(); // Output: Name: Bob, Age: 25
	p3.print(); // Output: Name: Alice, Age: 30
}