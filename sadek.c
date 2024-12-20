#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void listFiles(const char *path);
void changePermissions(const char *path, const char *permissions);
void createDeleteFiles(const char *path, int create);
void createSymbolicLink(const char *target, const char *link);
void copyFiles(const char *source, const char *destination);
void moveFiles(const char *source, const char *destination);
void addNotesToFile(const char *path, const char *note, int append);
void setAlias(const char *aliasName, const char *command);
void viewFileContent(const char *path, const char *mode);
void findFiles(const char *directory, const char *pattern);

int main() {
    int choice;
    char path[256], permissions[10], target[256], link[256];
    char source[256], destination[256], note[256], aliasName[50], command[256], pattern[256];
    int append, create;

    printf("Welcome to Logistics and Supply Chain System\n");

    // Define current_user using getenv
    char *current_user = getenv("USER");

    while (1) {
        if (current_user && strcmp(current_user, "sadek") == 0) {
            printf("You are currently logged in as 'sadek'\n");
            printf("\nChoose a task:\n");
            printf("1. List files/directories\n");
            printf("2. Change permissions of files/directories\n");
            printf("3. Make/delete files/directories\n");
            printf("4. Create symbolic link files\n");
            printf("5. Copy files/directories\n");
            printf("6. Move files/directories\n");
            printf("7. Add notes to a file\n");
            printf("8. Set alias for a command\n");
            printf("9. View file content\n");
            printf("10. Find files/directories\n");
            printf("0. Exit\n");
        } else {
            printf("You are not 'sadek'. Certain features may be restricted.\n");
            printf("\nChoose a task:\n");
            printf("1. List files/directories\n");
            printf("2. Change permissions of files/directories\n");
            printf("3. Make/delete files/directories\n");
            printf("4. Create symbolic link files\n");
            printf("5. Copy files/directories\n");
            printf("6. Move files/directories\n");
            printf("0. Exit\n");
        }
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter path to list files/directories: ");
                scanf("%s", path);
                listFiles(path);
                break;

            case 2:
                printf("Enter path to file/directory: ");
                scanf("%s", path);
                printf("Enter new permissions (e.g., 755): ");
                scanf("%s", permissions);
                changePermissions(path, permissions);
                break;

            case 3:
                printf("Enter path to file/directory: ");
                scanf("%s", path);
                printf("Enter 1 to create or 0 to delete: ");
                if (scanf("%d", &create) != 1) {
                    printf("Invalid input. Please enter 1 or 0.\n");
                    break;
                }
                createDeleteFiles(path, create);
                break;

            case 4:
                printf("Enter target file for symbolic link: ");
                scanf("%s", target);
                printf("Enter symbolic link name: ");
                scanf("%s", link);
                createSymbolicLink(target, link);
                break;

            case 5:
                printf("Enter source file/directory: ");
                scanf("%s", source);
                printf("Enter destination: ");
                scanf("%s", destination);
                copyFiles(source, destination);
                break;

            case 6:
                printf("Enter source file/directory: ");
                scanf("%s", source);
                printf("Enter destination: ");
                scanf("%s", destination);
                moveFiles(source, destination);
                break;

            case 7:
                if (!current_user || strcmp(current_user, "sadek") != 0) {
                    printf("This feature is restricted.\n");
                    break;
                }
                printf("Enter file path to add notes: ");
                scanf("%s", path);
                printf("Enter note: ");
                getchar(); // Consume newline
                fgets(note, sizeof(note), stdin);
                note[strcspn(note, "\n")] = 0; // Remove newline
                printf("Enter 1 to append or 0 to overwrite: ");
                if (scanf("%d", &append) != 1) {
                    printf("Invalid input. Please enter 1 or 0.\n");
                    break;
                }
                addNotesToFile(path, note, append);
                break;

            case 8:
                if (!current_user || strcmp(current_user, "sadek") != 0) {
                    printf("This feature is restricted.\n");
                    break;
                }
                printf("Enter alias name: ");
                scanf("%s", aliasName);
                printf("Enter command: ");
                getchar(); // Consume newline
                fgets(command, sizeof(command), stdin);
                command[strcspn(command, "\n")] = 0; // Remove newline
                setAlias(aliasName, command);
                break;

            case 9:
                if (!current_user || strcmp(current_user, "sadek") != 0) {
                    printf("This feature is restricted.\n");
                    break;
                }
                printf("Enter file path to view content: ");
                scanf("%s", path);
                printf("Enter view mode (cat, head, tail): ");
                scanf("%s", permissions); // Reusing permissions variable
                viewFileContent(path, permissions);
                break;

            case 10:
                if (!current_user || strcmp(current_user, "sadek") != 0) {
                    printf("This feature is restricted.\n");
                    break;
                }
                printf("Enter directory to search: ");
                scanf("%s", path);
                printf("Enter search pattern: ");
                scanf("%s", pattern);
                findFiles(path, pattern);
                break;

            case 0:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
