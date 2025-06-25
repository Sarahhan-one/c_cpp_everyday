#include <iostream>
using namespace std; 

class Point {
public:
	int x; 
	int y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}//constructor
	friend ostream& operator<<(ostream& os, const Point& p);
};

ostream& operator<<(ostream& os, const Point& p) {
	os << "Point(" << p.x << ", " << p.y << ")";
	return os;
}

template<typename T> 
class TempTest {
public:
	T a; 
	T b; 
	TempTest(T a, T b) : a(a), b(b) {}
	void print() {
		cout << "a: " << a << ", b: " << b << endl;
	} 
};

int main() {
	TempTest<int> t1(10, 20);
	TempTest<double> t2(10.5, 20.5);
	TempTest<Point> t3(Point{ 1, 2 }, Point{ 3, 4 });

	t1.print();
	t2.print();
	t3.print();
}