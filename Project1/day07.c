#include "day07.h"

typedef void (*printFunc)(const void*);

void printArray(void* base, size_t num, size_t size, printFunc print) {
	char* arr = (char*)base;
	for (size_t i = 0; i < num; i++) {
		print(arr + i * size);
	}
	printf("\n");
}


void printInt(const void* elem) {
	printf("%d ", *(const int*)elem);
}

void printDouble(const void* elem) {
	printf("%.2f ", *(const double*)elem);
}

void printChar(const void* elem) {
	printf("%c ", *(const char*)elem);
}

void printStr(const void* elem) {
	printf("%s ", *(const char**)elem);
}

int compDouble(const void* a, const void* b) {
	double diff = *(double*)a - *(double*)b;
	return (diff > 0) - (diff < 0);
}

int compChar(const void* a, const void* b) {
	return (*(char*)a - *(char*)b);
}

int compInt(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int compStr(const void* a, const void* b) {
	return strcmp(*(char**)a, *(char**)b);
}

void f14_11() {
	double da[] = { 1.23, 9.11, 5.46, 7.2, 10.5, 2.7 };
	printArray(da, 6, sizeof(double), printDouble);
	qsort(da, 6, sizeof(double), compDouble);
	printArray(da, 6, sizeof(double), printDouble);

	char* str[] = { "dog", "elephant", "cat", "tiger", "lion" };
	printArray(str, 5, sizeof(char*), printStr);
	qsort(str, 5, sizeof(char*), compStr);
	printArray(str, 5, sizeof(char*), printStr);

	int ia[] = { 8, 7, 5, 2, 3 };
	printArray(ia, 5, sizeof(int), printInt);
	qsort(ia, 5, sizeof(int), compInt);
	printArray(ia, 5, sizeof(int), printInt);

	char ca[] = { 'A', 'Z', 'c', 'y', 'X' };
	printArray(ca, 5, sizeof(char), printChar);
	qsort(ca, 5, sizeof(char), compChar);
	printArray(ca, 5, sizeof(char), printChar);
}

int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
//int div(int a, int b) {
//	if (b == 0) {
//		printf("Division by zero is not allowed.\n");
//		return 0;
//	}
//	return a / b;
//}

int (*get_func(int num))(int, int) {
	if (num == 0) {
		return add;
	}
	return mul;
}

void f14_1b() {
	int (*func)(int, int);
	func = get_func(0);
	printf("%d\n", func(10, 20));
}

void f14_1() {
	struct operation {
		int (*func)(int, int); 
		char* name;
	};
	struct operation myop[] = {
		{add, "add"},
		{sub, "sub"},
		{mul, "mul"},
		{div, "div"}
	};

	int a = 10, b = 20;
	int res[4] = { 0 };
	int tot; 

	//const char* func_names[4] = { "add", "sub", "mul", "div" };
	//int(* func[4])(int, int) = {add, sub, mul, div};
	
	//use a loop to fill up res array, print out the result
	for (int i = 0; i < size_arr(myop); i++) {
		int temp = myop[i].func(a, b);
		printf("%s : %d\n", myop[i].name, temp);
	}
}
void print_arr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void sort_arr(int* arr, int size, int(* comp)(int, int)) {
	int temp;

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size - 1; j++) {
			if (comp(arr[i], arr[j])) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}


void sort_arr2(int* arr, int size, int comp) {
	int temp;

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) { 
			if (comp ? arr[i] < arr[j] : arr[i] > arr[j]) {//0 : ascending order 1 : descending order
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int comp_asc(int a, int b) {
	//arr[i] > arr[j]
	return a > b;
}

int comp_desc(int a, int b) {
	//arr[i] < arr[j]
	return a < b;
}

enum comp { DESC = 1, ASC = 0 };
void f14_5() {
	int arr[] = {8, 5, 2, 12, 7, 9, 4, 6, 10, 3};
	print_arr(arr, size_arr(arr)); 
	sort_arr2(arr, size_arr(arr), DESC);
	print_arr(arr, size_arr(arr));

}

//get the address of a function and call it to exchange two integers 
void exchange0(int* a, int* b) {
	int temp = *a; 
	*a = *b; 
	*b = temp; 
}

void exchange1(int** ap, int** bp) {
	int temp = **ap; 
	**ap = **bp;
	**bp = temp;
}

void exchange2(int*** app, int*** bpp) {
	int temp = ***app; 
	***app = ***bpp; 
	***bpp = temp;
}

void exchange3(int** ap, int** bp) {
	int* temp = *ap;
	*ap = *bp; 
	*bp = temp;
}

void exchange4(int*** app, int*** bpp) {
	int* temp = **app;
	**app = **bpp; 
	**bpp = temp;

}

void exchange5(int*** app, int*** bpp) {
	int** temp = *app;  
	*app = *bpp; 
	*bpp = temp;
}

void f13_3() {
	int a = 10, b = 5;
	int* ap = &a, * bp = &b;
	int** app = &ap, ** bpp = &bp;

	printf("%d %d\n", a, b);
	exchange0(&a, &b);
	printf("%d %d", a, b);

	return 0;
}
