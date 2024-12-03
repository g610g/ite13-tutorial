

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int first_num = 5;
    int second_num = 10;

    int* ptr_one = &first_num;
    int* ptr_two = &second_num;

    ptr_two = ptr_one;
    printf("%d\n", *ptr_two);

    *ptr_one = second_num;
    printf("%d\n", *ptr_two);


    int** ptr_three = &ptr_two;
    *ptr_one = 20;
    printf("%d\n", **ptr_three);
}
