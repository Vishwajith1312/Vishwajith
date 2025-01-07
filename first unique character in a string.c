#include <stdio.h>
#include <string.h>

#define MAX_CHAR 26

int firstUniqChar(char* s) {
    int count[MAX_CHAR] = {0};  // Array to store the count of characters

    // Count the frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;  // 'a' maps to index 0, 'b' to index 1, and so on
    }

    // Find the first character with count 1
    for (int i = 0; s[i] != '\0'; i++) {
        if (count[s[i] - 'a'] == 1) {
            return i;  // Return the index of the first non-repeating character
        }
    }

    return -1;  // If no non-repeating character is found
}
