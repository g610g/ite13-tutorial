

#include <stdio.h>
#include <stdlib.h>
typedef struct Sudent {
  char *name;
  int age;
} Student;

int dynamic_allocation(int n){
    int* dyn_array = (int*) malloc(sizeof(int) * n);
    if (dyn_array == NULL){
        return -1;
    }
    int sum = 0;
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

void create_student() {
    Student s1;
    s1.name = "Gio";
    s1.age = 22;
    printf("%s\n", s1.name);
    printf("%d\n", s1.age);
}

int main(int argc, char *argv[]) {
    FILE *fp = fopen("data.txt", "r");

    char buffer[10];
    while (fscanf(fp, "%s", buffer) == 1) {
        printf("Read: %s\n", buffer);
    }
    fclose(fp);
    create_student(); 
    printf("%d", factorial(1));
    exit(0);
}

