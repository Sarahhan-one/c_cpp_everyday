#pragma once
#include <iostream>
#include <string.h>
using namespace std;
namespace Work {
	class Person
	{
	public: //it's accessible from outside of the class 
		//member var
		char name[20];
		int age;
		char tel[20];

		//method
		void inputInfo(const char* n, int a, const char* t) {
			strcpy_s(name, n);
			age = a;
			strcpy_s(tel, t);
		}
		void printInfo() {
			cout << "name: " << name << endl;
			cout << "age: " << age << endl;
			cout << "tel: " << tel << endl;
		}
	};
}

