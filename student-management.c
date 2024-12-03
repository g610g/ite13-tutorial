
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

void add_student(Student **students, int *count) {
    (*count)++;
    *students = realloc(*students, (*count) * sizeof(Student));
    if (*students == NULL) {
        perror("Error reallocating memory");
        exit(1);
    }

    Student *new_student = &(*students)[*count - 1];
    printf("Enter student ID: ");
    scanf("%d", &new_student->id);
    printf("Enter student name: ");
    scanf(" %[^\n]s", new_student->name);
    printf("Enter student grade: ");
    scanf("%f", &new_student->grade);
}

void display_students(Student *students, int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nStudent Records:\n");
    printf("ID\tName\t\tGrade\n");
    printf("------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

void save_to_file(const char *filename, Student *students, int count) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }

    fwrite(&count, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), count, file);

    fclose(file);
    printf("Students saved to file '%s'.\n", filename);
}

void load_from_file(const char *filename, Student **students, int *count) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file for reading");
        return;
    }

    fread(count, sizeof(int), 1, file);
    *students = realloc(*students, (*count) * sizeof(Student));
    if (*students == NULL) {
        perror("Error reallocating memory");
        fclose(file);
        exit(1);
    }

    fread(*students, sizeof(Student), *count, file);

    fclose(file);
    printf("Students loaded from file '%s'.\n", filename);
}

int main() {
    Student *students = NULL;
    int count = 0;
    int choice;

    const char *filename = "students.dat";

    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Save to File\n");
        printf("4. Load from File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student(&students, &count);
                break;
            case 2:
                display_students(students, count);
                break;
            case 3:
                save_to_file(filename, students, count);
                break;
            case 4:
                load_from_file(filename, &students, &count);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    free(students);
    return 0;
}
