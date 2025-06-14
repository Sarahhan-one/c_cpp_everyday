#include "day03.h"

void printMenu(void) {
    printf("+-----------------+\n");
    printf("+ 0 : add      +\n");
    printf("+ 1 : subtract        +\n");
    printf("+ 2 : multiply      +\n");
    printf("+ 3 : divide      +\n");
    printf("+ 4 : terminate        +\n");
    printf("+-----------------+\n");
}
int add(int a, int b) {
    return a + b;
}
int minus(int a, int b) {
    return a - b;
}
int multi(int a, int b) {
    return a * b;
}
int divi(int a, int b) {
    return a / b;
}
void f_fp_exercise(void) {
    int a, b;
    int choice;
    int (*op[])(int, int) = { add, minus, multi, divi };
    (void)scanf("%d %d", &a, &b);
    printMenu();
    (void)scanf("%d", &choice);
    if ((choice >= 0) & (choice < 4)) {
        printf("%d\n", op[choice](a, b));
    }
}


void swap(int* pa, int* pb) {
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}
void f_05_8(void) {
    int a = 10, b = 20;
    swap(&a, &b);
    printf("swap : %d %d\n", a, b);
}

void f_04_05(void) {
    int score[5];
    int i;
    int count = sizeof(score) / sizeof(score[0]);
    int sum = 0;
    double avg = 0;

    printf("Enter the score: ");
    for (i = 0; i < count; i++)
    {
        (void)scanf("%d", &score[i]);
    }

    sum = 0;
    for (i = 0; i < count; i++)
    {
        sum += score[i];
    }
    avg = (double)sum / count;

    printf("Score: ");
    for (i = 0; i < count; i++)
    {
        printf("%d ", score[i]);
    }
    printf("\n");
    printf("Average: %.1lf", avg);
}


void f_04_01(void) {
    int arr[5] = { 1,2,3,4,5 };
    int i;
    int size = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void f_02_04i_a(void) {
    int pass_in;
    int max_in = 3;
    const int pass = 1357;

    while (max_in--) {
        (void)scanf("%d", &pass_in);
        if (pass_in == pass) {
            printf("Login Succeed!\n");
            break;
        }
    }
    if (max_in == -1) {
        printf("Ask supervisor.\n");
    }
}

void f_02_04i_b(void) {
    int in_data, pwd, i;
    int max_n = 3;
    pwd = 1357;
    for (i = 0; i < max_n; ++i) {
        printf("Enter the password : ");
        (void)scanf("%d", &in_data);
        if (in_data == pwd) {
            printf("Login Succeed!");
            return;
        }

    }
    printf("Ask supervisor.");
}

void f_02_4i_pwd_c(void) {
    int pwd = 0, count = 3;

    while (count--) {
        (void)scanf("%d", &pwd);
        if (pwd == 1357) {
            printf("Login Succeed!");
            return;
        }
    }
    printf("Ask supervisor.");
}