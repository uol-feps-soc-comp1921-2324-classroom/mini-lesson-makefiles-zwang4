#include "file_io.h"

void createFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "This is a sample file.\n");
        fclose(file);
        printf("File created successfully.\n");
    } else {
        printf("Error creating the file.\n");
    }
}

void readFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file != NULL) {
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }
        fclose(file);
    } else {
        printf("Error reading the file.\n");
    }
}

void updateFile(const char* filename) {
    FILE* file = fopen(filename, "a");
    if (file != NULL) {
        fprintf(file, "This line is added for an update.\n");
        fclose(file);
        printf("File updated successfully.\n");
    } else {
        printf("Error updating the file.\n");
    }
}

void deleteFile(const char* filename) {
    if (remove(filename) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Error deleting the file.\n");
    }
}
