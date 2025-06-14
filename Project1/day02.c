#include "day02.h"

void f_01_11c(void) {
	int a = 20, b = 5;
	a %= b -= 1;     //  a = a % ( b = b - 1 )  a = 20 % 4
	printf("a = %d, b = %d\n", a, b);  
}

// number reversal 
static int reverse(int num) {
	int reversed = 0;
	while (num > 0) {
		reversed = reversed * 10 + (num % 10);
		num /= 10;
	}
	return reversed;
}

void f_01_11b(void) {
	int num = 0;
	int reversed_num = 0;

	(void)scanf("%d", &num);
	reversed_num = reverse(num);
	printf("%d\n", reversed_num);
}

/*
x = 127 x + 1 = 128 y = -128
x = 7F  x + 1 = 80  y = FFFFFF80
x = -128     x - 1 = -129     y = 127
x = FFFFFF80 x - 1 = FFFFFF7F y = 7F
*/

// char == signed char 
// signed char -> int : then parity bit is used for padding value
void f_01_11a(void) {
	char x = 127;
	char y = x + 1;
	printf("x = %d x+1 = %d y = %d\n", x, x + 1, y);
	printf("x = %X x+1 = %X y = %X\n", x, x + 1, y);

	x = -128;
	y = x - 1;
	printf("x = %d x-1 = %d y = %d\n", x, x - 1, y);
	printf("x = %X x-1 = %X y = %X\n", x, x - 1, y);
}


static unsigned int isBitSet(unsigned int num, int bitPosition) {
	return 1 & (num >> bitPosition);
}

void f_01_10q(void) {
	unsigned int num;
	int bitPosition;

	printf("Enter a number: ");
	(void)scanf("%d", &num);

	printf("Enter bit position to check (0-31): ");
	(void)scanf("%d", &bitPosition);

	unsigned int res = isBitSet(num, bitPosition);
	printf("Bit %d of number %u is %u.\n", bitPosition, num, res);
}

void f_01_10o(void) {
	unsigned int num = 0b10101010;
	printf("Inital Value           : %X\n", num);
	printf("After setBits(2, 3)    : %X\n", setBits(num, 2, 3));
	printf("After clearBits(4, 2)  : %X\n", clearBits(num, 4, 2));
	printf("After toggleBits(1, 5) : %X\n", toggleBits(num, 1, 5));
}

unsigned int setBits(unsigned int num, int start, int count) {
	return num | (((1 << count) - 1) << start);
}

unsigned int clearBits(unsigned int num, int start, int count) {
	return num & ~(((1 << count) - 1) << start);
}

unsigned int toggleBits(unsigned int num, int start, int count) {
	return num ^ (((1 << count) - 1) << start);
}


void f_01_10n(void) {
	unsigned int num = 0b1010;
	printf("Inital Value    : %X\n", num);
	printf("After setBit(2)    : %X\n", setBit(num, 2));
	printf("After clearBit(1)  : %X\n", clearBit(num, 1));
	printf("After toggleBit(3) : %X\n", toggleBit(num, 3));
}

unsigned int setBit(unsigned int num, int bitPosition) {
	return num | (1 << bitPosition);
}

unsigned int clearBit(unsigned int num, int bitPosition) {
	return num & ~(1 << bitPosition);
}

unsigned int toggleBit(unsigned int num, int bitPosition) {
	return num ^ (1 << bitPosition);
}

void f_01_10j(void) {
	int a = 10, b = 20, res;

	res = (a > b) ? a : b;

	if (a > b) {
		res = a;
	}
	else {
		res = b;
	}

	printf("Bigger value : %d\n", res);
}