#pragma warning(disable : 4996) // Disable warning for unused function
#include <iostream>
#include <cstring>

using namespace std;
template <typename T>
T Max(T a, T b) {
	return (a > b) ? a : b; // return the maximum of a and b
}

//specilization for const char*
template <>
char* Max(char* a, char* b) {
	return (strcmp(a, b) > 0) ? a : b; // return the string that is lexicographically greater
}

const char* Max(const char* a, const char* b) {
	return (strcmp(a, b) > 0) ? a : b; 
}

int main() {
	cout << Max(1, 3) << endl;
	cout << Max(1.5, 2.5) << endl;
	cout << Max("apple", "banana") << endl; // uses const char* specialization

}