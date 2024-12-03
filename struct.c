
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct Rectangle{
    int width;
    int length;
}Rectangle;
typedef struct Animal{
    char name[50];
    int age;
}Animal;
typedef struct User{
    char* fullname;
    char* email;
    char* password;
    int id;

}User;

//when passing struct in a function, best practice to pass it by reference
int find_area_rectangle(Rectangle* rectangle){
   return rectangle->width * rectangle->length; 
}

//allocate this struct user in the heap
User* create_user(int id, char* fullname, char* password, char* email){
    User* user = (User*)malloc(sizeof(User));

    user->id = id;
    user->email = email;
    user->password= password;
    user->fullname = fullname;
    return user;
}
int main(int argc, char *argv[])
{
    Animal animal;
    strcpy(animal.name, "Gio");
    Rectangle rectangle = {10, 2};
    Rectangle* rectptr = &rectangle;
    printf("%s\n", animal.name);
    printf("Mutate width");
    scanf("%d", &rectptr->width);
    printf("%d\n", rectangle.length);
    printf("%d\n", rectangle.width);
    printf("%d\n", find_area_rectangle(&rectangle));
    return EXIT_SUCCESS;
}
