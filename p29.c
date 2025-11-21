#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEAMS 100
#define MAX_NAME_LEN 50
#define MAX_SPORT_LEN 50

struct Coach {
    char name[MAX_NAME_LEN];
    int age;
    int years_of_experience;
};

struct Team {
    char team_name[MAX_NAME_LEN];
    char sport_type[MAX_SPORT_LEN];
    struct Coach coach;
};

struct Team teams[MAX_TEAMS];
int team_count = 0;

void add_team();
void search_team();
void display_all_teams();
int find_team_index(const char *name);

int main() {
    int choice;

    do {
        printf("\n\n=== Sports Team Management System ===\n");
        printf("1. Add New Team\n");
        printf("2. Search for a Team\n");
        printf("3. Display All Teams\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                add_team();
                break;
            case 2:
                search_team();
                break;
            case 3:
                display_all_teams();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

int find_team_index(const char *name) {
    for (int i = 0; i < team_count; i++) {
        if (strcasecmp(teams[i].team_name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_team() {
    if (team_count >= MAX_TEAMS) {
        printf("\nError: Maximum number of teams reached (%d).\n", MAX_TEAMS);
        return;
    }

    struct Team new_team;

    printf("\n--- Add New Team ---\n");
    printf("Enter Team Name: ");
    if (fgets(new_team.team_name, MAX_NAME_LEN, stdin) == NULL) return;
    new_team.team_name[strcspn(new_team.team_name, "\n")] = 0;

    if (find_team_index(new_team.team_name) != -1) {
        printf("Error: A team with the name '%s' already exists. Aborting.\n", new_team.team_name);
        return;
    }

    printf("Enter Sport Type (e.g., Basketball, Football): ");
    if (fgets(new_team.sport_type, MAX_SPORT_LEN, stdin) == NULL) return;
    new_team.sport_type[strcspn(new_team.sport_type, "\n")] = 0;

    printf("\n--- Coach Details ---\n");
    printf("Enter Coach's Name: ");
    if (fgets(new_team.coach.name, MAX_NAME_LEN, stdin) == NULL) return;
    new_team.coach.name[strcspn(new_team.coach.name, "\n")] = 0;

    printf("Enter Coach's Age: ");
    scanf("%d", &new_team.coach.age);
    printf("Enter Coach's Years of Experience: ");
    scanf("%d", &new_team.coach.years_of_experience);
    while (getchar() != '\n');

    teams[team_count] = new_team;
    team_count++;

    printf("\nSuccess: Team '%s' added successfully!\n", new_team.team_name);
}

void search_team() {
    if (team_count == 0) {
        printf("\nNo teams have been added yet to search.\n");
        return;
    }

    int search_choice;
    printf("\n--- Search Team ---\n");
    printf("Search by:\n");
    printf("1. Team Name\n");
    printf("2. Sport Type\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &search_choice);
    while (getchar() != '\n');

    char search_term[MAX_NAME_LEN];
    int found_count = 0;

    switch (search_choice) {
        case 1:
            printf("Enter the Team Name to search: ");
            if (fgets(search_term, MAX_NAME_LEN, stdin) == NULL) return;
            search_term[strcspn(search_term, "\n")] = 0;

            int index = find_team_index(search_term);
            if (index != -1) {
                printf("\nTeam Found!\n");
                printf("----------------------------------------\n");
                printf("Team Name: %s\n", teams[index].team_name);
                printf("Sport Type: %s\n", teams[index].sport_type);
                printf("Coach: %s (Age: %d, Exp: %d years)\n",
                       teams[index].coach.name,
                       teams[index].coach.age,
                       teams[index].coach.years_of_experience);
                printf("----------------------------------------\n");
                found_count = 1;
            }
            break;

        case 2:
            printf("Enter the Sport Type to search: ");
            if (fgets(search_term, MAX_NAME_LEN, stdin) == NULL) return;
            search_term[strcspn(search_term, "\n")] = 0;

            printf("\nTeams Found for Sport: %s\n", search_term);
            printf("----------------------------------------\n");
            for (int i = 0; i < team_count; i++) {
                if (strcasecmp(teams[i].sport_type, search_term) == 0) {
                    printf("Team: %s | Coach: %s | Experience: %d years\n",
                           teams[i].team_name,
                           teams[i].coach.name,
                           teams[i].coach.years_of_experience);
                    found_count++;
                }
            }
            printf("----------------------------------------\n");
            break;

        default:
            printf("\nInvalid search choice.\n");
            return;
    }

    if (found_count == 0) {
        printf("\nNo teams found matching the criteria.\n");
    }
}

void display_all_teams() {
    if (team_count == 0) {
        printf("\nNo teams have been added yet.\n");
        return;
    }

    printf("\n=== All Stored Teams and Coach Details (%d Teams) ===\n", team_count);
    printf("------------------------------------------------------------------------\n");
    printf("| Team Name     | Sport Type     | Coach Name     | Age     | Exp. (Yrs)     |\n");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < team_count; i++) {
        printf("| %-13s | %-14s | %-14s | %-7d | %-14d |\n",
               teams[i].team_name,
               teams[i].sport_type,
               teams[i].coach.name,
               teams[i].coach.age,
               teams[i].coach.years_of_experience);
    }
    printf("------------------------------------------------------------------------\n");
}
