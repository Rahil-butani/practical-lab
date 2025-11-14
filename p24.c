#include <stdio.h>
#include <stdlib.h>

#define MAX_NOTES 50
#define MAX_LENGTH 1000

int stringLength(char str[])
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

void reverseString(char str[], char result[])
{
    int len = stringLength(str);
    int i;
    for (i = 0; i < len; i++) {
        result[i] = str[len - 1 - i];
    }
    result[len] = '\0';
}

int compareStrings(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    return str1[i] == str2[i];
}

void copyString(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void concatenateStrings(char str1[], char str2[], char result[])
{
    int i = 0, j = 0;

    while (str1[i] != '\0')
    {
        result[i] = str1[i];
        i++;
    }

    while (str2[j] != '\0')
    {
        result[i] = str2[j];
        i++;
        j++;
    }

    result[i] = '\0';
}


void toUpperCase(char str[], char result[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            result[i] = str[i] - 32;
        }
        else
        {
            result[i] = str[i];
        }
        i++;
    }
    result[i] = '\0';
}

void toLowerCase(char str[], char result[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            result[i] = str[i] + 32;
        }
        else
        {
            result[i] = str[i];
        }
        i++;
    }
    result[i] = '\0';
}


void capitalizeWords(char str[], char result[])
{
    int i = 0;
    int newWord = 1;

    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            result[i] = str[i];
            newWord = 1;
        }
        else if (newWord && str[i] >= 'a' && str[i] <= 'z')
        {
            result[i] = str[i] - 32;
            newWord = 0;
        }
        else if (newWord && str[i] >= 'A' && str[i] <= 'Z')
        {
            result[i] = str[i];
            newWord = 0;
        }
        else
        {
            result[i] = str[i];
            newWord = 0;
        }
        i++;
    }
    result[i] = '\0';
}

int main()
{
    char notes[MAX_NOTES][MAX_LENGTH];
    int noteCount = 0;
    int choice;
    char tempNote[MAX_LENGTH];
    char tempNote2[MAX_LENGTH];
    char result[MAX_LENGTH * 2];
    int index, index2;
    printf("RAHIL-25CE011");

    printf("=========================================\n");
    printf("   Alex's Note-Taking Application\n");
    printf("=========================================\n\n");

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Add a new note\n");
        printf("2. Calculate length of a note\n");
        printf("3. Reverse a note\n");
        printf("4. Compare two notes\n");
        printf("5. Copy a note\n");
        printf("6. Concatenate two notes\n");
        printf("7. Convert note to uppercase\n");
        printf("8. Convert note to lowercase\n");
        printf("9. Capitalize each word in note\n");
        printf("10. Display all notes\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                if (noteCount >= MAX_NOTES) {
                    printf("Maximum notes limit reached!\n");
                    break;
                }
                printf("Enter your note (max %d characters):\n", MAX_LENGTH - 1);
                fgets(notes[noteCount], MAX_LENGTH, stdin);
                int len = stringLength(notes[noteCount]);
                if (len > 0 && notes[noteCount][len - 1] == '\n')
                {
                    notes[noteCount][len - 1] = '\0';
                }
                noteCount++;
                printf("Note added successfully! (Total notes: %d)\n", noteCount);
                break;

            case 2:
                if (noteCount == 0)
                {
                    printf("No notes available!\n");
                    break;
                }
                printf("Enter note index (1-%d): ", noteCount);
                scanf("%d", &index);
                getchar();
                if (index < 1 || index > noteCount)
                {
                    printf("Invalid index!\n");
                    break;
                }
                printf("Length of note %d: %d characters\n", index, stringLength(notes[index - 1]));
                break;

            case 3:
                if (noteCount == 0)
                {
                    printf("No notes available!\n");
                    break;
                }
                printf("Enter note index to reverse (1-%d): ", noteCount);
                scanf("%d", &index);
                getchar();
                if (index < 1 || index > noteCount)
                {
                    printf("Invalid index!\n");
                    break;
                }
                reverseString(notes[index - 1], result);
                printf("Original: %s\n", notes[index - 1]);
                printf("Reversed: %s\n", result);
                break;

            case 4:
                if (noteCount < 2)
                {
                    printf("Need at least 2 notes to compare!\n");
                    break;
                }
                printf("Enter first note index (1-%d): ", noteCount);
                scanf("%d", &index);
                printf("Enter second note index (1-%d): ", noteCount);
                scanf("%d", &index2);
                getchar();
                if (index < 1 || index > noteCount || index2 < 1 || index2 > noteCount)
                {
                    printf("Invalid index!\n");
                    break;
                }
                if (compareStrings(notes[index - 1], notes[index2 - 1]))
                {
                    printf("The notes are IDENTICAL.\n");
                }
                else
                {
                    printf("The notes are DIFFERENT.\n");
                }
                break;

            case 5:
                if (noteCount == 0)
                {
                    printf("No notes available!\n");
                    break;
                }
                printf("Enter note index to copy (1-%d): ", noteCount);
                scanf("%d", &index);
                getchar();
                if (index < 1 || index > noteCount)
                {
                    printf("Invalid index!\n");
                    break;
                }
                if (noteCount >= MAX_NOTES)
                {
                    printf("Maximum notes limit reached!\n");
                    break;
                }
                copyString(notes[noteCount], notes[index - 1]);
                noteCount++;
                printf("Note copied successfully! New note index: %d\n", noteCount);
                break;

            case 6:
                if (noteCount < 2)
                {
                    printf("Need at least 2 notes to concatenate!\n");
                    break;
                }
                printf("Enter first note index (1-%d): ", noteCount);
                scanf("%d", &index);
                printf("Enter second note index (1-%d): ", noteCount);
                scanf("%d", &index2);
                getchar();
                if (index < 1 || index > noteCount || index2 < 1 || index2 > noteCount) {
                    printf("Invalid index!\n");
                    break;
                }
                if (noteCount >= MAX_NOTES)
                {
                    printf("Maximum notes limit reached!\n");
                    break;
                }
                concatenateStrings(notes[index - 1], notes[index2 - 1], notes[noteCount]);
                noteCount++;
                printf("Notes concatenated successfully! New note index: %d\n", noteCount);
                printf("Result: %s\n", notes[noteCount - 1]);
                break;

            case 7:
                if (noteCount == 0)
                {
                    printf("No notes available!\n");
                    break;
                }
                printf("Enter note index to convert to uppercase (1-%d): ", noteCount);
                scanf("%d", &index);
                getchar();
                if (index < 1 || index > noteCount)
                {
                    printf("Invalid index!\n");
                    break;
                }
                toUpperCase(notes[index - 1], result);
                printf("Original: %s\n", notes[index - 1]);
                printf("Uppercase: %s\n", result);
                break;

            case 8:
                if (noteCount == 0)
                {
                    printf("No notes available!\n");
                    break;
                }
                printf("Enter note index to convert to lowercase (1-%d): ", noteCount);
                scanf("%d", &index);
                getchar();
                if (index < 1 || index > noteCount)
                {
                    printf("Invalid index!\n");
                    break;
                }
                toLowerCase(notes[index - 1], result);
                printf("Original: %s\n", notes[index - 1]);
                printf("Lowercase: %s\n", result);
                break;

            case 9:
                if (noteCount == 0)
                {
                    printf("No notes available!\n");
                    break;
                }
                printf("Enter note index to capitalize words (1-%d): ", noteCount);
                scanf("%d", &index);
                getchar();
                if (index < 1 || index > noteCount)
                {
                    printf("Invalid index!\n");
                    break;
                }
                capitalizeWords(notes[index - 1], result);
                printf("Original: %s\n", notes[index - 1]);
                printf("Capitalized: %s\n", result);
                break;

            case 10:
                if (noteCount == 0)
                {
                    printf("No notes available!\n");
                    break;
                }
                printf("\n--- ALL NOTES ---\n");
                for (int i = 0; i < noteCount; i++)
                {
                    printf("%d. %s\n", i + 1, notes[i]);
                }
                printf("Total: %d notes\n", noteCount);
                break;

            case 11:
                printf("Thank you for using Alex's Note-Taking App!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}