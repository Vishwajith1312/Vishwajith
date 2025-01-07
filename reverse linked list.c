#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct Node {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) {
            printf("->");
        }
        head = head->next;
    }
    printf("\n");
}

// Function to reverse the linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *current = head, *next = NULL;
    
    while (current != NULL) {
        // Store the next node
        next = current->next;
        
        // Reverse the 'next' pointer of the current node
        current->next = prev;
        
        // Move the 'prev' and 'current' pointers one step forward
        prev = current;
        current = next;
    }
    
    // At the end, 'prev' will point to the new head of the reversed list
    return prev;
}
