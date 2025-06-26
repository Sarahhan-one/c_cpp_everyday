#include <iostream> 
using namespace std; 

class MyException {
	string msg; //exception message
public:
	MyException(string msg) : msg(msg) {}
	//print the exception message
	void printMsg() {
		cout << msg << endl;
	}
};

int main() {
	int arr[] = { 1, 2 }; 
	int n1 = 1, n2 = 0, n3 = 0; 
	try {
		for (int i = 0; i < 3; i++) {
			if (i >= 2) {
				throw MyException("Index out of bounds");
			}
			cout << arr[i] << endl;
		}
		if (n2 == 0) {
			throw MyException("Division by zero");
		}
		cout << "n1/ n2 = " << n1 / n2 << endl; 
	} 
	catch (MyException& e) { // Catch block for MyException
		e.printMsg(); // Print the exception message
	} 
	cout << "End of program" << endl;
}