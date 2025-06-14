#include "day04.h"

char* my_gets(char* s)
{
	int c;
	char* cs; 

	cs = s;
	while ((c = getchar()) != '\n' && c != EOF)
		*cs++ = c;
	if (c == EOF && cs == s)
		return NULL;
	*cs++ = '\0';
	return s;
}

void my_gets_extra(void) {
	char str[30];
	printf("%s\n", my_gets(str));
}
void f08_2_extra1(void) {
	int ary[3][2] = { 0 };
	for (int i = 0; i < 3; ++i) {
		//(void)scanf("%d %d", &ary[i][0], &ary[i][1]);
		(void)scanf("%d %d", ary[i], ary[i]+1);
	}

	for (int i = 0; i < 3; ++i) {
		printf("%d %d\n", ary[i][0], ary[i][1]);
	}
}

void f08_2_extra2(void) {
	char ary[3] = { 0 };
	for (int i = 0; i < 3; ++i) {
		(void)scanf(" %c", ary + i);
	}

	for (int i = 0; i < 3; ++i) {
		printf("%c\n", ary[i]);
	}
}

static void my_func1(int* p, int n) {
	printf("%d\n", sizeof(p));
	for (int i = 0; i < n; ++i) {
		printf("%d ", *p++);
	}
	printf("\n");
}

static void my_func2(int p[], int n) {
	printf("%d\n", sizeof(p));
}

static void my_func3(int p[], int n) {
	printf("%d\n", sizeof(p));
}

void f07_3(void) {
	int ary[3] = { 10, 20, 30 };
	int a = 100;

	for (int i = 0; i < size(ary); ++i) {
		printf("%d ", ary[i]);
	}
	printf("\n");

	my_func1(ary, size(ary));
	my_func2(ary, size(ary));
}

void f07_extra1(void) {
	int ary[5] = { 10, 20, 30, 40, 50 };
	printf("sizeof(ary)   = %d\n", sizeof(ary));
	printf("sizeof(&ary)  = %d\n", sizeof(&ary));
	printf("sizeof(ary+1) = %d\n", sizeof(ary+1));
}

void f07_extra2(void) {
	int ary[3][5] = { 0 };
	int (*p)[5] = ary;
	printf("sizeof(ary)    = %d\n", sizeof(ary)); // 60
	printf("sizeof(ary[0]) = %d\n", sizeof(ary[0]));  // 20
	printf("sizeof(ary[0][0]) = %d\n", sizeof(ary[0][0]));  // 4
	printf("sizeof(*ary)    = %d\n", sizeof(*ary)); // 20  ary = &ary[0]  *ary = *&ary[0] = ary[0]
	printf("sizeof(p)  = %d\n", sizeof(p));    // p 
	printf("sizeof(*p) = %d\n", sizeof(*p));   // *p = ary[0]
}

void f07_extra3(void) {
	int ary[3] = { 10, 20, 30 };
	int (*p)[3] = &ary;
	
	printf("sizeof(p) = %d\n", sizeof(p));
	printf("sizeof(*p) = %d\n", sizeof(*p));
	// print 10 20 30 using pointer arithmetic
	int* p2 = (int*)p;
	for (int i = 0; i < 3; ++i) {
		printf("%d ", p2[i]);
	}
}
