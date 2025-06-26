#include <iostream>
using namespace std;

class Point {
	int x; 
	int y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	void print() {
		cout << "Point(" << x << ", " << y << ")" << endl;
	}
	//friend : allows the function to access private members of the class
	friend Point operator+(const Point& p1, const Point& p2); 
};

Point operator+(const Point& p1, const Point& p2) { // overload + operator
	Point res(p1.x + p2.x, p1.y + p2.y);
	return res;
}


int main() {
	Point p1(1, 2);
	Point p2(3, 4);
	Point p3 = p1 + p2; //output is Point(4, 6)
	p3.print();
}