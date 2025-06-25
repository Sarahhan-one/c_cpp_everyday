#include <iostream>
#include <cstring>
using namespace std;

//clss myString act like a string class 
class myString {

public:
	char* str;
	int len;
	myString() : str(nullptr), len(0) {} //default constructor
	myString(const char* s) { //constructor to initialize string
		len = strnlen_s(s, 100);
		this->str = new char[len + 1]; //allocate memory for string
		strcpy_s(this->str, len, s); //copy string
	}

	myString(char* s) { 
		len = strnlen_s(s, 100);
		this->str = new char[len + 1];
		strcpy_s(this->str, len, s); 
	}

	myString(const myString& p) { //copy constructor
		len = p.len; //copy length
		this->str = new char[len + 1]; //allocate memory for string
		strcpy_s(this->str, len, p.str); //copy string
	}
	
	~myString() { //destructor
		delete[] str; //free allocated memory
	}

	int getLen() const { //get length of string
		return len;
	}

	myString operator+(const myString& p) { //assignment operator overload
		int newLen = this->len + p.len;
		char* dest = new char[newLen + 1];
		strcpy_s(dest, this->len + 1, this->str);
		strcat_s(dest, newLen + 1, p.str);
		myString res(dest);
		delete[] dest;
		return res;
	}

	myString& operator=(const myString& p) { //assignment operator overload
		if (this != &p) { //check for self-assignment
			delete[] str; //free old memory
			len = p.len; //copy length
			str = new char[len + 1]; //allocate memory for new string
			strcpy_s(str, len + 1, p.str); //copy string
		}
		return *this; //return the current object
	}

	bool operator==(const myString& p) const { //equality operator overload
		return strcmp(this->str, p.str) ? false : true; //compare strings
	}


};

ostream& operator<<(ostream& os, const myString& s) { //output stream operator overload
	os << s.str; //output string to stream
	return os; //return output stream
}

int main() {
	//test myString
	myString s1("Hello");
	cout << "s1: " << s1.str << endl; //print myString
	char str[] = "World";
	myString s2(str); //convert char array to myString
	cout << "s2: " << s2.str << endl;
	myString s3(s1); //copy myString
	cout << "s3: " << s3.str << endl;
	myString s4 = s1 + s2; //concatenate myStrings
	cout << "s4: " << s4.str << endl;


#if 0 
	char str[] = "qwer"; 
	string s1 = "aaa";
	cout << "s1: " << s1 << endl; 

	string s2(str); //convert char array to string
	cout << "s2: " << s2 << endl;

	string s3(s1); //copy string
	cout << "s3: " << s3 << endl;

	string s4 = s1 + s2; //concatenate strings
	cout << "s4: " << s4 << endl;

	s4 = s3;
	cout << "s4: " << s4 << endl;
#endif
}