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

    char pwd[256];
    FILE *fp = popen("pwd", "r");
    if (fp == NULL) {
        printf("Failed to get current directory.\n");
        return 1;
    }
    fgets(pwd, sizeof(pwd), fp);
    pclose(fp);
    pwd[strcspn(pwd, "\n")] = 0; // Remove newline

    if (strcmp(pwd, "/home/sadek") == 0) {
        printf("\nAdmin Dashboard\n");
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
        printf("0. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    } else if (strcmp(pwd, "/home/warehouse") == 0) {
        printf("\nWarehouse Staff Dashboard\n");
        printf("1. List files/directories\n");
        printf("2. Make/delete files/directories\n");
        printf("3. Move files/directories\n");
        printf("4. View file content\n");
        printf("0. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    } else if (strcmp(pwd, "/home/customer") == 0) {
        printf("\nCustomer Dashboard\n");
        printf("1. List files/directories\n");
        printf("2. Copy files/directories\n");
        printf("3. View file content\n");
        printf("4. Add notes to a file\n");
        printf("0. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    } else {
        printf("Unauthorized access. Exiting...\n");
        return 1;
    }

    switch (choice) {
        case 1:
            printf("Enter path to list files/directories: ");
            scanf("%s", path);
            listFiles(path);
            break;

        case 2:
            if (strcmp(pwd, "/home/warehouse") == 0 || strcmp(pwd, "/home/sadek") == 0) {
                printf("Enter path to file/directory: ");
                scanf("%s", path);
                printf("Enter new permissions (e.g., 755): ");
                scanf("%s", permissions);
                changePermissions(path, permissions);
            } else {
                printf("Access denied for this action.\n");
            }
            break;

        case 3:
            if (strcmp(pwd, "/home/warehouse") == 0 || strcmp(pwd, "/home/sadek") == 0) {
                printf("Enter path to file/directory: ");
                scanf("%s", path);
                printf("Enter 1 to create or 0 to delete: ");
                scanf("%d", &create);
                createDeleteFiles(path, create);
            } else {
                printf("Access denied for this action.\n");
            }
            break;

        case 4:
            if (strcmp(pwd, "/home/sadek") == 0) {
                printf("Enter target file for symbolic link: ");
                scanf("%s", target);
                printf("Enter symbolic link name: ");
                scanf("%s", link);
                createSymbolicLink(target, link);
            } else {
                printf("Access denied for this action.\n");
            }
            break;

        case 5:
            if (strcmp(pwd, "/home/sadek") == 0 || strcmp(pwd, "/home/customer") == 0) {
                printf("Enter source file/directory: ");
                scanf("%s", source);
                printf("Enter destination: ");
                scanf("%s", destination);
                copyFiles(source, destination);
            } else {
                printf("Access denied for this action.\n");
            }
            break;

        case 6:
            if (strcmp(pwd, "/home/sadek") == 0 || strcmp(pwd, "/home/warehouse") == 0) {
                printf("Enter source file/directory: ");
                scanf("%s", source);
                printf("Enter destination: ");
                scanf("%s", destination);
                moveFiles(source, destination);
            } else {
                printf("Access denied for this action.\n");
            }
            break;

        case 7:
            if (strcmp(pwd, "/home/sadek") == 0 || strcmp(pwd, "/home/customer") == 0) {
                printf("Enter file path to add notes: ");
                scanf("%s", path);
                printf("Enter note: ");
                getchar(); // Consume newline
                fgets(note, sizeof(note), stdin);
                note[strcspn(note, "\n")] = 0; // Remove newline
                printf("Enter 1 to append or 0 to overwrite: ");
                scanf("%d", &append);
                addNotesToFile(path, note, append);
            } else {
                printf("Access denied for this action.\n");
            }
            break;

        case 8:
            if (strcmp(pwd, "/home/sadek") == 0) {
                printf("Enter alias name: ");
                scanf("%s", aliasName);
                printf("Enter command: ");
                getchar(); // Consume newline
                fgets(command, sizeof(command), stdin);
                command[strcspn(command, "\n")] = 0; // Remove newline
                setAlias(aliasName, command);
            } else {
                printf("Access denied for this action.\n");
            }
            break;

        case 9:
            printf("Enter file path to view content: ");
            scanf("%s", path);
            printf("Enter view mode (cat, head, tail): ");
            scanf("%s", permissions); // Reusing permissions variable
            viewFileContent(path, permissions);
            break;

        case 10:
            if (strcmp(pwd, "/home/sadek") == 0) {
                printf("Enter directory to search: ");
                scanf("%s", path);
                printf("Enter search pattern: ");
                scanf("%s", pattern);
                findFiles(path, pattern);
            } else {
                printf("Access denied for this action.\n");
            }
            break;

        case 0:
            printf("Logging out...\n");
            return 0;

        default:
            printf("Invalid choice. Try again.\n");
    }

    return 0;
}

// Function implementations
void listFiles(const char *path) {
    char command[512] = "ls -l ";
    strcat(command, path);
    system(command);
}

void changePermissions(const char *path, const char *permissions) {
    char command[512] = "chmod ";
    strcat(command, permissions);
    strcat(command, " ");
    strcat(command, path);
    system(command);
}

void createDeleteFiles(const char *path, int create) {
    char command[512];
    if (create) {
        strcpy(command, "mkdir -p ");
        strcat(command, path);
    } else {
        strcpy(command, "rm -rf ");
        strcat(command, path);
    }
    system(command);
}

void createSymbolicLink(const char *target, const char *link) {
    char command[512] = "ln -s ";
    strcat(command, target);
    strcat(command, " ");
    strcat(command, link);
    system(command);
}

void copyFiles(const char *source, const char *destination) {
    char command[512] = "cp -r ";
    strcat(command, source);
    strcat(command, " ");
    strcat(command, destination);
    system(command);
}

void moveFiles(const char *source, const char *destination) {
    char command[512] = "mv ";
    strcat(command, source);
    strcat(command, " ");
    strcat(command, destination);
    system(command);
}

void addNotesToFile(const char *path, const char *note, int append) {
    char command[512] = "echo \"";
    strcat(command, note);
    strcat(command, append ? "\" >> " : "\" > ");
    strcat(command, path);
    system(command);
}

void setAlias(const char *aliasName, const char *command) {
    printf("alias %s='%s'\n", aliasName, command);
}

void viewFileContent(const char *path, const char *mode) {
    char command[512];
    strcpy(command, mode);
    strcat(command, " ");
    strcat(command, path);
    system(command);
}

void findFiles(const char *directory, const char *pattern) {
    char command[512] = "find ";
    strcat(command, directory);
    strcat(command, " -name \"");
    strcat(command, pattern);
    strcat(command, "\"");
    system(command);
}
