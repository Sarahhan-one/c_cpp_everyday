#include "day08.h"

typedef struct _profile {
    int age;
    double height;
    char* name;
} profile_t;

static void init_struct(profile_t* pf) {
    pf->age = 21; 
    pf->height = 160.5;;
    pf->name = "윤소영";
}

static void print_struct(profile_t pf) {
	printf("Age: %d\n", pf.age);
	printf("Height: %.1f\n", pf.height);
    printf("Name: %s\n", pf.name);
}
void f16_8() {
    profile_t pf = { 0 }; 
    init_struct(&pf);
    print_struct(pf);
}

int* func1(void) {
	static int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    return a; // not using Static causes ERROR : returning address of local variable or temporary : a
}

void f15_9() {
    int* pi = func1();
    for (int i = 0; i < 10; i++) {
        printf("%d ", pi[i]);
    }
	printf("\n");
}

char** str_gets(char** str, int N, char* temp, int temp_size) {
    for (int i = 0; i < N; i++) {
        fgets(temp, temp_size, stdin);
        str[i] = (char*)calloc(strlen(temp) + 1, sizeof(char));
        if (str[i] == NULL) {
            printf("We have no more memory!\n");
            exit(1);
        }
        strcpy(str[i], temp);
    }
    return str;
}

void str_free(char** str, int N) {
    for (int i = 0; i < N; i++) {
        free(str[i]);
    }
    free(str);
}

void f15_7b() {
    char temp[80];
    char** str = NULL;
    int N;

    (void)freopen("data.txt", "rt", stdin);
    (void)scanf("%d", &N); //left the newline character in the buffer
    fgets(temp, sizeof(temp), stdin); //consume the newline character after the number


    str = (char**)calloc(N, sizeof(char*));
    if (str == NULL) {
        printf("We have no more memory!\n");
        str_free(str, N);
        return;
    }

    str = str_gets(str, N, temp, sizeof(temp));

    //do the task - ex. printing
    for (int i = 0; i < N; i++) {
        printf("%s\n", str[i]);
    }

	str_free(str, N);

    fclose(stdin);
}


void f15_7() {
    char temp[80];
    char** str = NULL; 
    int N; 

    (void)freopen("data.txt", "rt", stdin);
	(void)scanf("%d", &N); //left the newline character in the buffer
	fgets(temp, sizeof(temp), stdin); //consume the newline character after the number

    str = (char**)calloc(N, sizeof(char*));
    if (str == NULL) {
        printf("We have no more memory!\n");
        exit(1);
        return;
    }

    for (int i = 0; i < N; i++) {
        fgets(temp, sizeof(temp), stdin);
        str[i] = (char*)calloc(strlen(temp) + 1, sizeof(char));
        if (str[i] == NULL) {
            printf("We have no more memory!\n");
            for (int i = 0; i < N; i++) {
                free(str[i]);
            }
            free(str);
            exit(1); 
            return;
        }
        strcpy(str[i], temp);
    }

    //do the task - ex. printing
    for (int i = 0; i < N; i++) {
        printf("%s\n", str[i]);
    }
    //free
    for (int i = 0; i < N; i++) {
        free(str[i]);
    }
    free(str);
}

static void realloc_test(int** pi, int N, int n) {
    int* tmp = NULL;
    int total = n + N;
    tmp = (int*)realloc(*pi, sizeof(int) * total);

    if (tmp == NULL) {
        printf("메모리가 부족합니다");
        exit(1);
    }

    //it has the same disassembly code &(*pi)[i] -> compiler does it for you
    //*pi = tmp;
    //for (int i = n; i < total; i++) {
    //    (void)scanf("%d", (*pi + i));
    //}

    //this is more efficient code
    for (int i = n; i < total; i++) {
        (void)scanf("%d", (tmp + i));
    }
     *pi = tmp;
}

void f15_2b() {
    int T;
    int N = 0;
    int* pi = NULL;
    (void)freopen("numbers.txt", "rt", stdin);
    (void)scanf("%d", &T);
    
    while (T--) {
        int n;
        (void)scanf("%d", &n);
        realloc_test(&pi, N, n);
        N += n;
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += pi[i];
    }
    printf("%d people's average age  : %.1lf \n", N, (double)sum / N);
    free(pi);
    pi = NULL;
}


void f15_2() {
    int T;
    (void)freopen("numbers.txt", "rt", stdin);
    (void)scanf("%d", &T);

    int n = 0;
    int sum = 0;
    int* pi = NULL;
    while (T--) {
        int temp_n; 
        (void)scanf("%d", &temp_n);

		n += temp_n;
        int* temp_pi = (int*)realloc(pi, n * sizeof(int));

        if (temp_pi == NULL) {
            printf("Memory allocation failed");
            free(pi);
            return;
        }
        
        pi = temp_pi;

        for (int i = n - temp_n; i < n; i++) {
            (void)scanf("%d", &pi[i]);
            sum += pi[i];
        }
    }
    free(pi);
    pi = NULL;
	printf("Total Average for %d of data : %.1lf \n", n, (sum / (double)n));
}
 