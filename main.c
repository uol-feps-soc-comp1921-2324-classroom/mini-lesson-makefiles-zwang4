#include <stdio.h>
#include "file_io.h"

int main() {
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);

    // Create a new file
    createFile(filename);

    // Read and display content of the file
    printf("File Content:\n");
    readFile(filename);

    // Update the file
    updateFile(filename);

    // Read and display updated content
    printf("Updated File Content:\n");
    readFile(filename);

    // Delete the file
    deleteFile(filename);

    return 0;
}
