#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the lexicographically smallest rotation
char* orderlyQueue(char* s, int k) {
    int len = strlen(s);
    
    // If k == 1, we need to generate all rotations and find the smallest one
    if (k == 1) {
        char* result = strdup(s);  // Create a copy of the original string
        for (int i = 1; i < len; i++) {
            char* rotated = (char*)malloc(len + 1);  // Allocate memory for the rotated string
            // Create the rotated string by concatenating parts
            snprintf(rotated, len + 1, "%s", s + i);
            strncat(rotated, s, i);
            // Update the result if we found a lexicographically smaller rotation
            if (strcmp(rotated, result) < 0) {
                free(result);
                result = rotated;
            } else {
                free(rotated);
            }
        }
        return result;
    } else {
        // If k > 1, we can sort the string to get the lexicographically smallest arrangement
        char* result = strdup(s);  // Create a copy of the original string
        qsort(result, len, sizeof(char), (int (*)(const void*, const void*))strcmp);  // Sort the string
        return result;
    }
}
