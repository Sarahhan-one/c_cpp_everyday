#include "day06.h"

void exercise_pointer(void) {
    int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
    printf("%p\n", a);     // array type=> int [3][4], array pointer=> int(*)[4]
    printf("%p\n", *a);    // array type=> int [4], array pointer=> int *
    printf("%p\n", &a);    // pointer type => int(*)[3][4
    printf("%p\n", a[0]);  // array type=> int [4], array pointer=> int *
    printf("%d\n", *a[0]); // integer - a[0][0], **a, (*a)[0]
    printf("%d\n", *a[2]); // integer - a[2][0], **(a + 2), (*(a + 2))[0]
    printf("%d\n", *(*(a + 1) + 0));  // integer - a[1][0], *(*(a + 1))
    printf("%d\n", *(*(a + 0) + 2));  // integer - a[0][2]
    printf("%d\n", (*a + 2)[0]);      // integer - a[0][2]
    printf("%d\n", (*(a + 1))[0]);    // integer - a[1][0]
    printf('%d\n', (*(*a) + 1));      // integer - a[0][0] + 1 => 2

    //&(a + 1)[2]

}


void exercise_pointer2() {
    int* ptr; 
    int n[] = { 5, 10, 22, 34, 36, 44 };
    ptr = n; 

    printf("%d ", *ptr++);
    printf(" %d\n", *ptr);
    printf("%d ", *ptr+1);
    printf(" %d\n", *ptr);
    printf("%d ", ++*ptr);
    printf(" %d\n", *ptr);
    printf("%d ", *(ptr+1));
    printf(" %d\n", *ptr);
    printf("%d ", *ptr+=1);
    printf(" %d\n", *ptr);
    printf("%d ", *++ptr);
    printf(" %d\n", *ptr);
    printf("%d ", (*ptr)++);
    printf(" %d\n", *ptr);
}

void exercise_pointer3() {
    char* ptr[] = { "red", " orange", "pink", "white", "blue", "brown", "black", "gray" };
    printf("%c\n", **ptr);
    printf("%s\n", ptr[1]);
    printf("%s\n", ptr[1] + 3);
    printf("%c\n", *(*(ptr + 1) + 1));
    printf("%c\n", *(*(ptr + 2) + 1));
    printf("%s\n", ptr[3] + 2);
}





