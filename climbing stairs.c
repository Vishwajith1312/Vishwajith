#include <stdio.h>

int climbStairs(int n) {
    if (n == 1) return 1;  // Base case: Only 1 way to reach the first step
    int prev1 = 1, prev2 = 2;  // prev1 = ways(1), prev2 = ways(2)
    
    // Iterate from 3 to n and calculate the number of ways
    for (int i = 3; i <= n; i++) {
        int current = prev1 + prev2;
        prev1 = prev2;  // Update prev1 to previous step
        prev2 = current;  // Update prev2 to current step
    }
    
    return prev2;  // Return the number of ways to reach the nth step
}
