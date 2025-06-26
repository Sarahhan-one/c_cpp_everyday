#include <iostream>
using namespace std; 

class Point {
public:
	int x; 
	int y; 

	Point() : x(0), y(0) {} // default constructor
	Point(int x, int y) : x(x), y(y) {
		cout << "Parameterized constructor called" << endl;
	} // parameterized constructor
	void print() {
		cout << "Point(" << x << ", " << y << ")" << endl;
	}
};

int main() {
	Point p1(1, 2);
	cout << "p1: ";
	p1.print();
}