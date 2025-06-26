#include <iostream>
using namespace std; 

class Point {
public:
	int x, y;
};

int main() {
	Point* p = NULL; 
	int arr[] = { 1, 2, 3 };
	try {
		for (int i = 0; i < 4; i++) {
			if (i >= 3) {
				throw i; 
			}
			cout << "arr[" << i << "] = " << arr[i] << endl; // Accessing array elements
		}
		if (p == NULL) {
			throw "Null pointer exception"; // Throw an exception if pointer is null
		}
	}
	catch (int e) { // Catch block for integer exception
		cout << "Index out of bounds" << endl;
	}

	catch (const char* e) { //catch block for string exception
		cout << "null pointer exception" << endl;
		p = new Point;
		p->x = 1;
		p->y = 2;
		cout << p->x << endl; // Attempt to access member of null pointer
		cout << p->y << endl;
	}

	catch(...) { // Catch-all block for any other exceptions
		cout << "An unexpected error occurred" << endl;
	}
}