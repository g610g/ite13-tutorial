#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void print_array(int* arr, int len){
    for (int i = 0; i < len; i++){
        printf("%d\n", arr[i]);
    }
}
void input_dynamic(int n){

    int* dyn_array = (int*) malloc(sizeof(int) * n);
    int counter = 0;
    int buffer = 0;
    while(true){
        printf("enter element:");
        scanf("%d", &buffer);
        if (buffer == -1){
            print_array(dyn_array, counter);
            free(dyn_array);
            return;
        }
        if (counter >= n - 1){
            n *= 2;
            dyn_array = realloc(dyn_array, n * sizeof(int));
            dyn_array[counter] = buffer;
            counter += 1;
            continue;
        }
        dyn_array[counter] = buffer;
        counter += 1;
    }
}
int main(int argc, char *argv[])
{
    input_dynamic(4);
    return 0; 
}

