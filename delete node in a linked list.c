#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct Node {
    int val;
    struct ListNode *next;
};

// Function to delete a node in the linked list
void deleteNode(struct ListNode* node) {
    // Copy the value of the next node to the current node
    struct ListNode* temp = node->next;
    node->val = temp->val;
    
    // Skip the next node
    node->next = temp->next;
    
    // Free the memory of the next node (optional in some cases, but good practice)
    free(temp);
}

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
