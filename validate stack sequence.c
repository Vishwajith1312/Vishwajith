#include <stdio.h>
#include <stdbool.h>

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    int stack[pushedSize];  // Stack to simulate push and pop operations
    int top = -1;  // Points to the top of the stack
    int j = 0;  // Pointer to traverse the popped array

    for (int i = 0; i < pushedSize; i++) {
        stack[++top] = pushed[i];  // Push the current element from pushed
        
        // Check if the top of the stack matches the next popped value
        while (top >= 0 && stack[top] == popped[j]) {
            top--;  // Pop the stack
            j++;    // Move to the next element in popped
        }
    }

    // If we've processed all elements in popped, return true
    return j == poppedSize;
}
