#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to represent a student
struct Student {
    int rollNumber;
    char name[50];
    int age;
    float marks;
};

// Array to store all the students
struct Student students[MAX_STUDENTS];
int numStudents = 0;

// Function to add a new student to the database
void addStudent() {
    struct Student newStudent;
    
    printf("Enter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);
    printf("Enter Name: ");
    scanf("%s", newStudent.name);
    printf("Enter Age: ");
    scanf("%d", &newStudent.age);
    printf("Enter Marks: ");
    scanf("%f", &newStudent.marks);
    
    students[numStudents++] = newStudent;
    printf("Student added successfully.\n");
}

// Function to view details of all students
void viewStudents() {
    if (numStudents == 0) {
        printf("No students in the database.\n");
        return;
    }
    
    printf("Student Database:\n");
    printf("Roll Number\tName\tAge\tMarks\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t\t%s\t%d\t%.2f\n", students[i].rollNumber, students[i].name, students[i].age, students[i].marks);
    }
}

// Function to update information of a student
void updateStudent() {
    int rollNumber;
    int found = 0;
    
    printf("Enter Roll Number of student to update: ");
    scanf("%d", &rollNumber);
    
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Enter new Name: ");
            scanf("%s", students[i].name);
            printf("Enter new Age: ");
            scanf("%d", &students[i].age);
            printf("Enter new Marks: ");
            scanf("%f", &students[i].marks);
            printf("Student information updated successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
}

// Function to delete a student from the database
void deleteStudent() {
    int rollNumber;
    int found = 0;
    
    printf("Enter Roll Number of student to delete: ");
    scanf("%d", &rollNumber);
    
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            for (int j = i; j < numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            numStudents--;
            printf("Student deleted successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found.\n");
    }
}

int main() {
    int choice;
    
    while(1) {
        printf("\nStudent Database Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Update Student Information\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
