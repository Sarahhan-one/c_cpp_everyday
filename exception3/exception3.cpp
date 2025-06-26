#include <iostream>
using namespace std; 

static void f1() {
	cout << "f1 called" << endl;
	throw - 1; //throw an exception
}
static void f2() {
	cout << "f2 called" << endl;
	f1();
}
static void f3() {
	cout << "f3 called" << endl;
	f2();
}

int main() {
	try {
		f3();
	}
	catch (int e) {
		cout << "Exception caught: " << e << endl; 
	}
}