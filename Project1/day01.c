#include <stdio.h>
void f_01_7(void);
void f_01_7f(void);

void f_01_7f(void) {
	int num = 10;
	int* p = &num;

	printf("%zu %zu\n", sizeof(num), sizeof(p));
	printf("%p %p\n", p, &num);
	printf("%d %d\n", *p, num);
	printf("%p %d\n", &p, **&p);
	return;
}

void f_01_7(void) {
	unsigned char uch1 = -1;
	unsigned char uch2 = 128;
	signed char ch1 = -1;
	signed char ch2 = 128;
	printf("unsigned char(%%u) : %u %u\n", uch1, uch2);
	printf("signed char(%%d) : %d %d\n", ch1, ch2);

	printf("signed char(%%d) : %d %d\n", uch1, uch2);
	printf("unsigned char(%%u) : %u %u\n", ch1, ch2);
	return;
}
