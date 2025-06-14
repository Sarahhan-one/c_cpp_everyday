#include "day09.h"

typedef struct rgb {
	unsigned short blue : 5;
	unsigned short green : 6;
	unsigned short red : 5;
} RGB_t;

typedef union pixelcolor {
	unsigned short color;
	RGB_t rgb;
} PColor_t;

void f17_03() {
	PColor_t dot1 = { 0 }, dot2 = { 0 };
	dot1.color = 0x1234;
	printf("%d %d\n", sizeof(RGB_t), sizeof(PColor_t)); // 2 bytes
	printf("%#x\n", dot1.color);
	printf("%d %d %d\n", dot1.rgb.red, dot1.rgb.green, dot1.rgb.blue);
	dot1.rgb.red = 5;
	printf("%#x\n", dot1.color);

}

typedef struct _student {
	int id;
	int* scores;
	char* name;
}student_t; 

student_t* input_line(student_t* stu, int M) {
	student_t temp = { 0 }; 
	char temp_name[20] = { 0 }; 

	(void)scanf("%d", &temp.id); 
	temp.scores = (int*)calloc(M, sizeof(int));
	if (temp.scores == NULL) {
		perror("Failed to allocate memory(1)");
		exit(1);
		return;
	}

	for (int i = 0; i < M; i++) {
		(void)scanf("%d", temp.scores + i);
	}
	
	(void)scanf("%s", temp_name);
	temp.name = (char*)calloc(1, strlen(temp_name) + 1);
	if (temp.name == NULL) {
		perror("Failed to allocate memory(2)");
		exit(1);
		return;
	}
	strcpy(temp.name, temp_name);

	*stu = temp;
	return stu;
}

student_t* input_data(int N, int M) {
	student_t* temp = NULL;
	student_t* stu = (student_t*)calloc(N, sizeof(student_t));
	if (stu == NULL) {
		perror("Failed to allocate memory(3)");
		exit(1);
		return;
	}
	
	for (int i = 0; i < N; i++) {
		temp = input_line(stu + i, M);
		if (temp == NULL) {
			perror("Failed to allocate memory(4)");
			exit(1);
			return;
		}
	}
	return stu;
}

void print_data(student_t* stu, int N, int M) {
	student_t temp = { 0 };
	for (int i = 0; i < N; i++) {
		temp = stu[i];
		printf("%d ", temp.id);
		for (int j = 0; j < M; j++) {
			printf("%d ", temp.scores[j]);
		}
		printf("%s\n", temp.name);
	}
}

void free_data(student_t** stu, int N) {
	student_t* temp = *stu; 
	if (stu == NULL) return;

	for (int i = 0; i < N; i++) {
		if (temp[i].scores != NULL) {
			free(temp[i].scores);
			temp[i].scores = NULL;
		}
	}
	free(temp); 
	*stu = NULL;
}

void f16_9() {
	//creates a structure
	//read the data, save it onto the structure, and print them
	(void)freopen("students.txt", "rt", stdin);
	
	int N, M;
	(void)scanf("%d %d", &N, &M); 
	(void)getchar();
	printf("N = %d, M = %d\n", N, M);

	student_t* stu = { 0 };
	stu = input_data(N, M); 
	if (stu != NULL) {
		print_data(stu, N, M);
		free_data(&stu, N);
	}
}

void f15_9e() {
	//varing N x M 2D array
	int N = 2;
	int M = 3;
	
	//allocate the memory for 2D array NxM
	int** rows = (int**)calloc(N, sizeof(int*));
	int* cols = (int*)calloc(N*M, sizeof(int));
	if (rows == NULL) {
		perror("Failed to allocate memory");
		exit(1);
		return;
	}
	if (cols == NULL) {
		perror("Failed to allocate memory");
		exit(1);
		return;
	}

	for (int i = 0; i < N; i++) {
		*(rows + i) = cols + M*i;
	}

	//do the task
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			rows[i][j] = cnt++;
		}
	}
	//printing
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", rows[i][j]);
		}
		printf("\n");
	}

	//free 
	free(rows);
	free(cols);
	rows = NULL;
	cols = NULL;

}

void f15_9d() {
	int N;
	(void)freopen("alloc.txt", "rt", stdin);
	(void)scanf("%d", &N); //left the newline character in the buffer
	(void)getchar(); //consume the newline character after the number

	//pointer array 
	int** rows = (int **)calloc(N, sizeof(int*));
	int* sizes = (int*)calloc(N, sizeof(int));

	for (int i = 0; i < N; i++) {
		int M;
		(void)scanf("%d", &M);
		sizes[i] = M;
		rows[i] = (int*)calloc(M, sizeof(int));
		for (int j = 0; j < M; j++) {
			(void)scanf("%d", &rows[i][j]);
		}
	}

	//do the task
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < sizes[i]; j++) {
			printf("%d ", rows[i][j]);
		}
		printf("\n");
	}

	//free
	for (int i = 0; i < N; i++) {
		free(rows[i]);
	}
	free(rows);
	rows = NULL;
}

void f15_9c() {
	//3d array of integers 
	//first dimension vary in size, other two dimensions are fixed 
	int n = 4; 
	int (*p)[3][5] = (int (*)[3][5])calloc(n, sizeof(int[3][5])); 

	if (p == NULL) {
		perror("Failed to allocate memory");
		exit(1);
		return;
	}

	//use the array
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 5; k++) {
				p[i][j][k] = i*15 + j*5 + k;
				printf("%d ", p[i][j][k]);
			}
		}
		printf("\n");
	}


	//free 
	free(p);
	p = NULL;
} 

void f15_9b() {
	// 2d array of integers
	// rows vary in size 
	// cols are fixed at 100

	int n = 10; //number of rows
	int (*p)[100] = (int (*)[100])calloc(n, sizeof(int[100])); // pointer to an array of 100 integers

	if (p == NULL) {
		perror("Failed to allocate memory");
		exit(1);
		return;
	}

	//use the array - fill the array from 0 to n * 100 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 100; j++) {
			p[i][j] = i * 100 + j;
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	//free
	free(p);
	p = NULL;

}