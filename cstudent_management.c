#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

struct Student s[100];
int count = 0;

void addStudent() {
    printf("\nEnter ID: ");
    scanf("%d", &s[count].id);

    printf("Enter Name: ");
    scanf("%s", s[count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);

    count++;
    printf("\n✅ Student Added Successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("\n⚠️ No records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nID: %d", s[i].id);
        printf("\nName: %s", s[i].name);
        printf("\nMarks: %.2f\n", s[i].marks);
    }
}

void searchStudent() {
    int id, found = 0;
    printf("\nEnter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            printf("\n✅ Student Found!");
            printf("\nName: %s", s[i].name);
            printf("\nMarks: %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n❌ Student not found!\n");
    }
}

void deleteStudent() {
    int id, found = 0;
    printf("\nEnter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }
            count--;
            printf("\n🗑️ Student Deleted Successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n❌ Student not found!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n\n===== Student Management System =====");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Delete Student");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("\n👋 Exiting... Thank you!\n");
                exit(0);
            default:
                printf("\n⚠️ Invalid choice! Try again.\n");
        }
    }

    return 0;
}