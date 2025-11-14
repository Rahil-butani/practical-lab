#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 20
#define MAX_SEATS 20

void displaySeatingChart(char seats[][MAX_SEATS], int rows, int seatsPerRow)
{
    int i, j;
    printf("\n========== Seating Chart ==========\n");
    printf("    ");
    for (j = 1; j <= seatsPerRow; j++)
    {
        printf("%2d ", j);
    }
    printf("\n");

    for (i = 0; i < rows; i++)
    {
        printf("Row %d: ", i + 1);
        for (j = 0; j < seatsPerRow; j++) {
            printf("%2c ", seats[i][j]);
        }
        printf("\n");
    }
    printf("===================================\n");
    printf("Legend: O = Available, X = Reserved\n\n");
}

int main()
{
    printf("RAHIL-25CE011");

    char seats[MAX_ROWS][MAX_SEATS];
    int rows, seatsPerRow;
    int numReserved;
    int row, seat;
    int i, j;
    int choice;

    printf("Theatre Seating Reservation System\n");
    printf("===================================\n\n");

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of seats per row: ");
    scanf("%d", &seatsPerRow);

    if (rows <= 0 || rows > MAX_ROWS || seatsPerRow <= 0 || seatsPerRow > MAX_SEATS) {
        printf("Invalid input! Rows and seats must be between 1 and %d.\n", MAX_ROWS);
        return 1;
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < seatsPerRow; j++) {
            seats[i][j] = 'O';
        }
    }

    printf("\nEnter the number of reserved seats: ");
    scanf("%d", &numReserved);

    for (i = 0; i < numReserved; i++) {
        printf("Enter row and seat number for reserved seat %d (e.g., 2 5): ", i + 1);
        scanf("%d %d", &row, &seat);
        if (row < 1 || row > rows || seat < 1 || seat > seatsPerRow) {
            printf("Invalid seat position! Try again.\n");
            i--;
            continue;
        }
        seats[row - 1][seat - 1] = 'X';
    }

    displaySeatingChart(seats, rows, seatsPerRow);

    while (1) {
        printf("\nOptions:\n");
        printf("1. Reserve a seat\n");
        printf("2. Cancel a reservation\n");
        printf("3. Display seating chart\n");
        printf("4. Display statistics\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter row and seat number to reserve (e.g., 2 5): ");
                scanf("%d %d", &row, &seat);

                if (row < 1 || row > rows || seat < 1 || seat > seatsPerRow) {
                    printf("Invalid seat position!\n");
                } else if (seats[row - 1][seat - 1] == 'X') {
                    printf("Seat is already reserved!\n");
                } else {
                    seats[row - 1][seat - 1] = 'X';
                    printf("Seat reserved successfully!\n");
                    displaySeatingChart(seats, rows, seatsPerRow);
                }
                break;

            case 2:
                printf("Enter row and seat number to cancel (e.g., 2 5): ");
                scanf("%d %d", &row, &seat);

                if (row < 1 || row > rows || seat < 1 || seat > seatsPerRow) {
                    printf("Invalid seat position!\n");
                } else if (seats[row - 1][seat - 1] == 'O') {
                    printf("Seat is already available!\n");
                } else {
                    seats[row - 1][seat - 1] = 'O';
                    printf("Reservation cancelled successfully!\n");
                    displaySeatingChart(seats, rows, seatsPerRow);
                }
                break;

            case 3:
                displaySeatingChart(seats, rows, seatsPerRow);
                break;

            case 4: {
                int reserved = 0, available = 0;
                for (i = 0; i < rows; i++) {
                    for (j = 0; j < seatsPerRow; j++) {
                        if (seats[i][j] == 'X') {
                            reserved++;
                        } else {
                            available++;
                        }
                    }
                }
                printf("\n========== Statistics ==========\n");
                printf("Total seats: %d\n", rows * seatsPerRow);
                printf("Reserved seats: %d\n", reserved);
                printf("Available seats: %d\n", available);
                printf("================================\n");
                break;
            }

            case 5:
                printf("Thank you for using the Theatre Seating System!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}