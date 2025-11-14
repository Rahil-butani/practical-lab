#include <stdio.h>
int main() {
    int choice;
    int total = 0;
    printf("RAHIL-25CE011");

    printf("Welcome to the Menu\n");
    printf("1. Burger - 150\n");
    printf("2. Pizza - 200\n");
    printf("3. Pasta - 120\n");
    printf("4. Sandwich - 100\n");
    printf("5. French Fries - 80\n");
    printf("Enter the number of the item you want to order (Enter 0 to finish):\n");
while (1) {
        printf("Your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        if (choice == 0) {
            break;
        }
        switch (choice) {
            case 1:
                total += 150;
                printf("Burger added. Current total: %d\n", total);
                break;
            case 2:
                total += 200;
                printf("Pizza added. Current total: %d\n", total);
                break;
            case 3:
                total += 120;
                printf("Pasta added. Current total: %d\n", total);
                break;
            case 4:
                total += 100;
                printf("Sandwich added. Current total: %d\n", total);
                break;
            case 5:
                total += 80;
                printf("French Fries added. Current total: %d\n", total);
                break;
            default:
                printf("Invalid choice. Please select a valid item number.\n");
        }
    }
    printf("\nThank you for your order! Your total bill is: %d\n", total);
    return 0;
}