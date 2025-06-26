#include <iostream>
using namespace std; 

int main() {
	cout << "Before exception" << endl;
	int num1 = 10, num2 = 0, num3; 
	try {
		cout << "Inside try block (before exception)" << endl;
		if (num2 == 0) {
			throw num2; 
		}
		num3 = num1 / num2; // This line will throw an exception
		cout << "num3 = " << num3 << endl;
	}
	catch (int e) { // Catch block for integer exception
		cout << "Exception caught: Division by zero" << endl;
		cout << "Caught exception value: " << e << endl; 
	}
	cout << "After exception" << endl;
}