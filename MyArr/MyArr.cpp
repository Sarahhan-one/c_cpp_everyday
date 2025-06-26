#include <iostream>
using namespace std; 

//Arbitrary type array class
template<typename T>
class MyArr {
	T* arr;  //address of the array
	int len; //length of the array
public:
    MyArr() {
        arr = new T[6];
        len = 6;
    }
    MyArr(int len) {
        arr = new T[len];
        this->len = len;
    }

	// overload [] operator for array access - for read-only access
    const T& operator[](int idx) const { 
        if (idx < 0 || idx >= len) {
            cout << "Index out of bounds!" << endl;
            exit(-1); // exit if index is out of bounds
        }
        return arr[idx];
	}   

	// overload [] operator for array access - for write access
    T& operator[](int idx) {
        if (idx < 0 || idx >= len) {
            cout << "Index out of bounds!" << endl;
            exit(-1); // exit if index is out of bounds
        }
        return arr[idx];
    }

    ~MyArr() { // destructor to free allocated memory
		delete[] arr; 
	}

    int getLen() const { //get length of string
        return len;
    }

    void print() { // print function to display array elements
        for (int i = 0; i < len; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
	}
};

class Point {
public:
    int x;
    int y;
    Point(int x = 0, int y = 0) : x(x), y(y) {} // constructor
    friend ostream& operator<<(ostream& os, const Point& p);
};

ostream& operator<<(ostream& os, const Point& p) {
    os << "Point(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    MyArr<Point> a;
    cout << a.getLen() << endl;
    a[0] = Point(1, 2);
    a[1] = Point(3, 4);
    
    for (int i = 0; i < 2; ++i) {
        cout << a[i] << " "; 
	}

    MyArr<int> b(3);
    for (int i = 0; i < b.getLen(); ++i) {
        b[i] = i + 1; // initialize array with values 1, 2, 3
	}
    for (int i = 0; i < b.getLen(); ++i) {
        cout << b[i] << " ";
    }
    return 0;
}