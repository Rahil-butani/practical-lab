#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a word in place
void reverseWord(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++) {
        char temp = word[i];
        word[i] = word[len - i - 1];
        word[len - i - 1] = temp;
    }
}

// Function to reverse the entire sentence
void reverseSentence(char *sentence) {
    int len = strlen(sentence);
    for (int i = 0; i < len / 2; i++) {
        char temp = sentence[i];
        sentence[i] = sentence[len - i - 1];
        sentence[len - i - 1] = temp;
    }
}

int main() {
    FILE *fp_in, *fp_out;
    char filename[] = "Demo.txt";
    char outputFile[] = "Output.txt";
    char line[1000];
    int wordCount = 0;
    int choice;

    printf("1. Reverse each word\n");
    printf("2. Reverse the entire sentence\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // consume newline

    fp_in = fopen(filename, "w+");
    if (fp_in == NULL) {
        printf("Error: File '%s' not found.\n", filename);
        return 1;
    }

    fp_out = fopen(outputFile, "w");
    if (fp_out == NULL) {
        printf("Error: Unable to create output file.\n");
        fclose(fp_in);
        return 1;
    }

    printf("\n--- Reversed Content ---\n");

    while (fgets(line, sizeof(line), fp_in)) {
        // Process line based on user choice
        if (choice == 1) {
            char word[100];
            int i = 0, j = 0;

            while (line[i] != '\0') {
                if (isalnum(line[i])) {
                    word[j++] = line[i];
                } else {
                    if (j > 0) {
                        word[j] = '\0';
                        reverseWord(word);
                        fprintf(fp_out, "%s", word);
                        printf("%s", word);
                        wordCount++;
                        j = 0;
                    }
                    fputc(line[i], fp_out);
                    printf("%c", line[i]);
                }
                i++;
            }
        } else if (choice == 2) {
            reverseSentence(line);
            fprintf(fp_out, "%s", line);
            printf("%s", line);
        }
    }

    fclose(fp_in);
    fclose(fp_out);

    printf("\n\nReversed content saved to '%s'.\n", outputFile);
    if (choice == 1)
        printf("Total words reversed: %d\n", wordCount);

    return 0;
}