#include "day05.h"

void array_pointer_ex2(void) {
    int a[3][4] = { 0 };
    int* temp = *a;  // temp = a[0]
    (void)freopen("day05.txt", "rt", stdin);
    for (int i = 0; i < size_ary(a); ++i) {
        for (int j = 0; j < size_ary(a[0]); ++j) {
            //(void)scanf("%d", &a[i][j]);
            //(void)scanf("%d", a[i]+j);
            //(void)scanf("%d", a[0] + (i * size_ary(a[0]) + j));
            (void)scanf("%d", temp++);
        }
    }
    temp = a[0];
    for (int i = 0; i < size_ary(a) * size_ary(a[0]); ++i) {
        (void)scanf("%d", temp+i);
    }

    for (int i = 0; i < size_ary(a); ++i) {
        for (int j = 0; j < size_ary(a[0]); ++j) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
}

void array_pointer_ex(void) {
    int arr[3][4][5] = { 0 };
    int (*p)[4][5] = arr;
}


void Increment();
extern int GetNum();
void print_num(void);
extern int num;

void f10_10(void) {
    print_num();
    printf("num : %d\n", GetNum());  // 0
    Increment();
    printf("num : %d\n", GetNum());  // 1
    Increment();
    printf("num : %d\n", GetNum());  // 2
    printf("main-num : %d\n", num);  // ?    
    return;
}


char* my_strcpy(char* to, const char* from) {
    char* save = to;

    for (; (*to = *from); ++from, ++to);
    return save;
}

unsigned int my_strlen(const char* str) {
    const char* s;

    if (str == 0) return 0;
    for (s = str; *s; ++s);
    return s - str;
}


int my_strcmp(const char* s1, const char* s2) {
    while (*s1 == *s2) {
        if (*s1 == 0) return 0;
        s1++;
        s2++;
    }
    return *(unsigned const char*)s1 - *(unsigned const char*)s2;
}

char* my_strcat(char* s, const char* append) {
    char* save = s;

    for (; *s; s++);
    while ((*s++ = *append++));

    return save;
}

// *s++ = *p++;
static int a = 100;
void f09_8(void) {
    static int a = 200;
    //printf("%d\n", a);
    char name[20] = "apple";
    char str[5] = "jam";

    char temp[10] = "";
    char* temp2 = 0;
    //my_strcpy();
    printf("%d\n", my_strlen(temp));
    //my_strcmp();
    //my_strcat(name, str);
}

void f01_8b(void) {
    int x = 10;
    int const* a = &x;
    int* p = a;

    //*a = 20;
    *p = 30;
    printf("%d %d %d\n", x, *a, *p);
}
void f09_2(void) {
    char* dessert1 = "apple";
    const char* dessert2 = "apple";
    char const* dessert3 = "apple";

    dessert1[0] = 'A';  // run-time error  - rodata
    dessert1 = "Banana";

    //dessert1 = 'A';  // run-time error
    //dessert2[0] = 'A';  // compile-time error
    //dessert3[0] = 'A';  // compile-time error
    dessert2 = "Banana";
    dessert3 = "Banana";
    //dessert3 = 'A';  // run-time error
    printf("%s %s %s\n", dessert1, dessert2, dessert3);
}

/*
char *strcpy(char *dest, const char *src);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *ptr, int value, size_t num);
*/


// literal calulation happen at compile time -> ('a' - 'A')
char* to_upper01(char* name, int size) {
    for (int i = 0; i < size; i++) {
        if ('a' <= name[i] && name[i] <= 'z') {
            name[i] -= ('a' - 'A');  
        }
    }
    return name;
}

char* to_upper02(char* name, int size) {
    for (int i = 0; i < size; i++) {
        if ((name[i] >= 97) && (name[i] <= 122)) {
            name[i] -= 32;
        }
    }
    return name;
}

char* to_upper03(char* str, int size) {
    for (int i = 0; i < size && str[i] != '\0'; i++) {
        if ('a' <= str[i] && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    return str;
}

char* to_upper04(char* name, int size) {
    char* str = name;
    int count = 0;
    while (count < size && *str != '\0') {
        char ch = *str;
        if (ch >= 'a' && ch <= 'z') {
            *str = ch - ('a' - 'A');  //  -= 32;
        }
        str++;
        count++;
    }

    return name;
}



void f08_6(void) {
    char name[40] = "Tom & Jerry!";
    printf("%s\n", to_upper01(name, size_ary(name)));
    printf("%s\n", to_upper03(name, size_ary(name)));
}
