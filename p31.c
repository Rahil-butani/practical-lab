#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *summary;
    int initial_size, new_size;

    printf("Enter initial size of the article summary: ");
    scanf("%d", &initial_size);
    getchar();

initial_size++;
    summary = (char *)calloc(initial_size, sizeof(char));
    if (summary == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the initial article summary:\n");
    fgets(summary, initial_size, stdin);

    printf("\nInitial Summary:\n%s\n", summary);


    printf("\nEnter new size for expanded summary: ");
    scanf("%d", &new_size);
    getchar();

new_size++;
    summary = (char *)realloc(summary, new_size * sizeof(char));
    if (summary == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    printf("Enter the updated (longer) article summary:\n");
    fgets(summary, new_size, stdin);


    printf("\nUpdated Summary:\n%s\n", summary);

    free(summary);
    return 0;
}
