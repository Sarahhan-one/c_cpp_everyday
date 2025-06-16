#include "day10.h"

//#define NDEBUG
#include <assert.h>

void f20_12(void) {
	int x;
	printf("\nEnter an integer value: ");
	(void)scanf("%d", &x);
	assert(x >= 0);
	printf("You entered %d.", x);
}

//------------------------------------------------------------------------------

// 구조체 멤버 접근
struct Point {
    int x, y;
};

#define GET_MEMBER(p, m) p##.##m
void f_pre01(void) {
    struct Point pt = { 1, 2 };
    printf("%d\n", GET_MEMBER(pt, y));  // → pt.y → 2
}


// 변수 추적 매크로
#define DEBUG_VAR(var) printf("[DEBUG] %s = %d (in %s:%d)\n", #var, var, __FILE__, __LINE__)
void f_pre02(void) {
    int score = 80;
    DEBUG_VAR(score);
}

// 자동 변수 이름 생성
#define DECLARE_INT(name) int var_##name
#define SET_VALUE(name, val) var_##name = val
#define PRINT_VALUE(name) printf(#name " = %d\n", var_##name)

void f_pre03(void) {
    DECLARE_INT(score);
    SET_VALUE(score, 90);
    PRINT_VALUE(score);
}

//---------------------------------------------------------------------------

//int (*SelectFunc(char ch)) (int, double);
typedef (*FP) (int, double);
FP SelectFunc(char ch);

double func_a(int a, double b) {
	return b * a;
}

double func_b(int a, double b) {
	return a / b;
}

FP SelectFunc(char ch) { // it will return different func depending on ch
	if (ch == 'a') return func_a;
	return func_b;
}

void typedef_ex01(void) {
	FP myfunc = SelectFunc('a');
	printf("%.1f\n", (double)myfunc(10, 2.5));
}

//----------------------------------------------------------------------------

typedef int (*AP)[4];
// return type : a pointer pointing to int [4] array 
//int (*SelectArray (int what))[4] { 
AP SelectArray(int what) {
	static int arr[3][4] = { 0 };
	return arr;
}

static void printArray(AP a) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void typedef_ex02() {
	int cnt = 0;
	AP a = SelectArray(0);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = cnt++;
		}
	}
}
