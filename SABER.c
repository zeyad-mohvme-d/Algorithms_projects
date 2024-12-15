#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void listFiles();
void changePermissions();
void createDirectory();
void deleteDirectory();
void createSymbolicLink();
void copyFile();
void moveFile();
void appendToFile();
void viewFileContent();
void findFiles();

int main() {
    int choice;

    while (1) {
        printf("\n--- Logistics System Menu ---\n");
        printf("1. List files/directories\n");
        printf("2. Change permissions of files/directories\n");
        printf("3. Create directory\n");
        printf("4. Delete directory\n");
        printf("5. Create symbolic link\n");
        printf("6. Copy file\n");
        printf("7. Move file\n");
        printf("8. Append to file\n");
        printf("9. View file content\n");
        printf("10. Find files/directories\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                listFiles();
                break;
            case 2:
                changePermissions();
                break;
            case 3:
                createDirectory();
                break;
            case 4:
                deleteDirectory();
                break;
            case 5:
                createSymbolicLink();
                break;
            case 6:
                copyFile();
                break;
            case 7:
                moveFile();
                break;
            case 8:
                appendToFile();
                break;
            case 9:
                viewFileContent();
                break;
            case 10:
                findFiles();
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Function implementations

void listFiles() {
    char path[256];
    printf("Enter directory path: ");
    scanf("%s", path);
    char command[512];
    snprintf(command, sizeof(command), "ls -l %s", path);
    system(command);
}

void changePermissions() {
    char path[256];
    char permissions[8];
    printf("Enter file/directory path: ");
    scanf("%s", path);
    printf("Enter permissions (e.g., 755): ");
    scanf("%s", permissions);
    char command[512];
    snprintf(command, sizeof(command), "chmod %s %s", permissions, path);
    system(command);
}

void createDirectory() {
    char path[256];
    printf("Enter directory path to create: ");
    scanf("%s", path);
    char command[512];
    snprintf(command, sizeof(command), "mkdir -p %s", path);
    system(command);
}

void deleteDirectory() {
    char path[256];
    printf("Enter directory path to delete: ");
    scanf("%s", path);
    char command[512];
    snprintf(command, sizeof(command), "rmdir %s", path);
    system(command);
}

void createSymbolicLink() {
    char target[256], linkPath[256];
    printf("Enter target file path: ");
    scanf("%s", target);
    printf("Enter symbolic link path: ");
    scanf("%s", linkPath);
    char command[512];
    snprintf(command, sizeof(command), "ln -s %s %s", target, linkPath);
    system(command);
}

void copyFile() {
    char source[256], destination[256];
    printf("Enter source file path: ");
    scanf("%s", source);
    printf("Enter destination file path: ");
    scanf("%s", destination);
    char command[512];
    snprintf(command, sizeof(command), "cp %s %s", source, destination);
    system(command);
}

void moveFile() {
    char source[256], destination[256];
    printf("Enter source file path: ");
    scanf("%s", source);
    printf("Enter destination file path: ");
    scanf("%s", destination);
    char command[512];
    snprintf(command, sizeof(command), "mv %s %s", source, destination);
    system(command);
}

void appendToFile() {
    char filePath[256], content[256];
    printf("Enter file path: ");
    scanf("%s", filePath);
    printf("Enter content to append: ");
    scanf(" %[^\n]", content); // Read multi-word input
    char command[512];
    snprintf(command, sizeof(command), "echo \"%s\" >> %s", content, filePath);
    system(command);
}

void viewFileContent() {
    char filePath[256], mode[10];
    printf("Enter file path: ");
    scanf("%s", filePath);
    printf("View mode (cat, head, tail): ");
    scanf("%s", mode);

    char command[512];
    if (strcmp(mode, "cat") == 0 || strcmp(mode, "head") == 0 || strcmp(mode, "tail") == 0) {
        snprintf(command, sizeof(command), "%s %s", mode, filePath);
        system(command);
    } else {
        printf("Invalid mode! Use 'cat', 'head', or 'tail'.\n");
    }
}

void findFiles() {
    char path[256], searchTerm[256];
    printf("Enter directory path: ");
    scanf("%s", path);
    printf("Enter search term: ");
    scanf("%s", searchTerm);
    char command[512];
    snprintf(command, sizeof(command), "find %s -name '*%s*'", path, searchTerm);
    system(command);
}

