#include "reculsive.h"
const int N = 3;
const int M = 5;
int arr[10]; 
bool vis[5] = { false };


void printArr(int L) {
	for (int i = 1; i < L; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test_14(int L) {
	if (L > N) {
		printArr(L);
		return;
	}
	
	int start = (L == 1) ? 0 : arr[L - 1]; //start from the previous element
	for (int i = start; i < M; i++) {
		if (vis[i]) continue;
		arr[L] = i + 1;
		vis[i] = true; 
		test_14(L + 1);
		vis[i] = false;

	}
}

void test_13(int L) {// L : current digit , N : max digit
	if (L > N) {
		printArr(L);
		return;
	}

	//for (int i = 0; i < N; i++) { // it goes over all the possibilities in a graph
	//	arr[L] = i + 1; 
	//	test_13(L + 1);
	//}
	
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			arr[L] = i + 1;
			vis[i] = true;
			test_13(L + 1);
			vis[i] = false;
		}
	}
}
 
void test_12(int L) {
	if (L > N) return;
	bool vis[4] = { false };
	for (int i = 1; i < 4; i++) {
		vis[i] = true; 
		for (int j = 1; j < 4; j++) {
			if (vis[j]) continue;
			vis[j] = true; 
			for (int k = 1; k < 4; k++) {
				if (vis[k]) continue; 
				vis[j] = true;
				printf("%d%d%d\n", i, j, k);
				vis[k] = false;
			}
			vis[j] = false;
		}
		vis[i] = false;
	}
}

void test_11(int L) { // N: digits L: current digit
	if (L > N) {
		printArr(L);
		return;
	}
	arr[L] = 1; 
	test_11(L + 1);
	arr[L] = 0; 
	test_11(L + 1);
}

void test_10(int L) {
	if (L > N) return; 
	for (int i = 0; i < N - L; i++) {
		printf(" ");
	}
	for (int i = 0; i < 2*L-1; i++) {
		printf("*");
	}
	printf("\n");
	test_10(L + 1);
	for (int i = 0; i < N - L + 1; i++) {
		printf(" ");
	}
	for (int i = 0; i < 2 * L - 3; i++) {
		printf("*");
	}
	printf("\n");
}

void test_09(int L) {
	if (L > 5) return;
	for (int i = 0; i < L; i++) {
		printf("*");
	}
	printf("\n");
	test_09(L + 1);
}

void test_08(int i) {//1 2 3 4 5 1 2 3 4 5
	if (i > N) return;
	printf("%d ", i); 
	test_08(i + 1); 
	printf("%d ", N - i + 1);
}

void test_07(int i) { //1 2 3 3 2 3 3 - binary tree - dfs
	if (i > 3) return; 
	printf("%d ", i); 
	test_07(i + 1);
	test_07(i + 1);
	test_07(i + 1); 
}

void test_06(int i) {
	if (i > 5) return;
	printf("%d ", i);
	test_06(i + 1);
	if (i < 5) printf("%d ", i);
}

void test_05(int i) {
	if (i > 5) return;
	printf("%d ", i);
	test_05(i + 1);
	printf("%d ", i);
}

void test_04(int i) {
	if (i < 0) return;
	printf("%d ", i);
	test_04(i - 1);
}

void test_03(int i) {
	if (i > 5) return;
	printf("%d ", i);
	test_03(i + 1);
}

void test_02(int L) {//will not print anything
	test_02(L + 1);
	printf("%d ", L);
}

void test_01(int L) { //limits in stack memory 
	//a and L are local variables - use the same stack memory
	int a[100] = { 0 };
	printf("%d ", L);
	test_01(L + 1);
} 