#include <iostream>
#include "Person.h"
using namespace std;

void swap1(int a, int b) { //call by value : copy the value
	int tmp;
	tmp = a; 
	a = b; 
	b = tmp; 
}

void swap2(int* a, int* b) { //call by value : copy the address 
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap3(int& a, int& b) { //call by reference
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {

	int a = 10, b = 20;
	swap1(a, b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	int a = 10, b = 20;
	swap2(&a, &b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	int a = 10, b = 20;
	swap3(a, b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

#if 0
	cout << "Hello world\n";

	Work::Person p1; //Person object is generated in stack
	p1.inputInfo("aaa", 12, "111");
	p1.printInfo();

	int a = 10;
	int& b = a; 

	a = 20;
	b = 30; 

	int* p = &a;
	int& c = *p; 


	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;

	cout << "&a: " << &a << endl;
	cout << "&b: " << &b << endl;
	cout << "&c: " << &c << endl;
#endif
}