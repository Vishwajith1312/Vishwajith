#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct Node {
    int val;
    struct ListNode *next;
};

// Function to detect cycle in the linked list using Floyd’s Tortoise and Hare algorithm
bool hasCycle(struct ListNode* head) {
    if (head == NULL) {
        return false; // Empty list cannot have a cycle
    }

    struct ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move slow pointer by 1 step
        fast = fast->next->next;    // Move fast pointer by 2 steps
        
        if (slow == fast) {
            return true;  // Cycle detected
        }
    }

    return false;  // No cycle found
}

// Helper function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}
