#include <stdio.h>
#include <stdlib.h>

int main() {
    // Open the file in read mode
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Define a buffer to store the contents of the file
    char buffer[100];

    // Read the contents of the file into the buffer
    size_t bytesRead = fread(buffer, sizeof(char), sizeof(buffer) - 1, file);
    if (bytesRead == 0 && ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return 1;
    }

    // Null-terminate the buffer to make it a valid string
    buffer[bytesRead] = '\0';

    // Print the contents of the buffer to the console
    printf("File contents:\n%s\n", buffer);

    // Close the file
    fclose(file);
    return 0;
}