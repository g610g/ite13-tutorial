

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct Student {
  char* name;
  int age;
} Student;
void prime_numbers(int n){
    if (n <= 1){
        printf("Cant generate prime numbers for this range");
    }
}
void count_file_line(char * filename){
    FILE * fp = fopen(filename, "r");
    char buffer[250];
    int line_count = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        line_count += 1; 
    }
    printf("number of lines for file %s is %d", filename, line_count);
    return;
}
int dynamic_allocation(int n){
    int* dyn_array = (int*) malloc(sizeof(int) * n);
    if (dyn_array == NULL){
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++){
        dyn_array[i] = i + 1;
    }

    for (int i = 0; i < n; i++){
        sum+= dyn_array[i];
    }
    return sum;
    
}
int factorial(int n){
    if (n == 1){
       return n;
    }
    return n * factorial(n - 1);
}
void allocate_calloc(){
    int* conti = (int*) calloc(10, sizeof(int));

    for (int i = 0; i < 10; i++){
        printf("%p\n", conti + i);
    }
}
void reallocate(int n){
    int* dyn_array = (int*) malloc(sizeof(int) * n);
    int sum = 0;
    for (int i = 0; i < n; i++){
        dyn_array[i] = i + 1;
    }

    dyn_array = realloc(dyn_array, n * 2);
    for (int i = 0; i < ( n * 2 ); i++){
        printf("%d\n", dyn_array[i]); 
    }
}
void create_student() {
    Student s1;
    s1.name = "Gio Gonzales";
    s1.age = 22;
    printf("%s\n", s1.name);
    printf("%d\n", s1.age);
}
void print_array(int* arr, int len){
    for (int i = 0; i < len; i++){
        printf("%d\n", arr[i]);
    }
}

void write_struct(Student* student){

    FILE *file = fopen("test.dat", "wb");
    if (file == NULL){
        printf("Something went wrong");
        exit(1);
    }

    fwrite(student, sizeof(Student), 1, file);
    fclose(file);
}
void read_struct(char* name){
    Student s1;
    FILE *file = fopen(name, "rb");

    if (file == NULL){
        printf("Something went wrong");
        exit(1);
    }
    fread(&s1, sizeof(s1), 1, file);
    printf("Name of student: %s \n", s1.name);
    printf("Age of student: %d \n", s1.age);
    fclose(file);
}
int main(int argc, char *argv[]) {
    FILE *fp = fopen("test.dat", "wb");
    Student s1 = {"Gio", 2};
    Student student_buffer;
    int num = 1;
    int* numptr = &num;
    char buffer[50];
    int int_buffer[10];
    write_struct(&s1);
    read_struct("test.dat");
    /*for (int i = 0; i < 10; i++){*/
    /*    printf("%p\n", int_buffer + i);*/
    /*}*/
    /**/
    /*while (fgets(buffer, sizeof(buffer), fp)) {*/
    /*    printf("Read: %s\n", buffer);*/
    /*}*/
    fclose(fp);
    /*create_student(); */
    /*printf("%d\n", factorial(5));*/
    /*printf("%d\n", dynamic_allocation(5));*/
    /*count_file_line("data.txt");*/
    exit(0);
}

