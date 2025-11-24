#include <stdio.h>
#include <stdlib.h>

#define FILENAME "student_marks.bin"

void input_marks() {
    FILE *file;
    int mark;
    int student_count = 0;

    file = fopen(FILENAME, "wb");

    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", FILENAME);
        return;
    }

    printf("\n--- Input Student Marks ---\n");
    printf("Enter marks for students (Enter -1 to stop):\n");

    while (1) {
        printf("Mark for Student %d: ", student_count + 1);
        if (scanf("%d", &mark) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n');
            continue;
        }

        if (mark == -1) {
            break;
        }

        fwrite(&mark, sizeof(int), 1, file);
        student_count++;
    }

    fclose(file);
    printf("Successfully wrote %d marks to %s.\n", student_count, FILENAME);
}

void retrieve_marks() {
    FILE *file;
    int mark;
    int student_number = 1;

    file = fopen(FILENAME, "rb");

    if (file == NULL) {
        printf("Error: Could not open file %s for reading.\n", FILENAME);
        printf("Please ensure marks have been input first.\n");
        return;
    }

    printf("\n--- Retrieved Student Marks ---\n");

    while (fread(&mark, sizeof(int), 1, file) == 1) {
        printf("Student %d: %d\n", student_number, mark);
        student_number++;
    }

    fclose(file);
    printf("Successfully retrieved and displayed %d marks.\n", student_number - 1);
}

int main() {
    int choice;

    do {
        printf("\n\n=== CHARUSAT Examination Mark System ===\n");
        printf("1. Input and Store Marks\n");
        printf("2. Retrieve and Display Marks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            while (getchar() != '\n');
            choice = 0; 
        }

        switch (choice) {
            case 1:
                input_marks();
                break;
            case 2:
                retrieve_marks();
                break;
            case 3:
                printf("Exiting system. Goodbye.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}