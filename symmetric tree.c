#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct Node {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to check if two trees are mirrors of each other
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) {
        return true; // Both are NULL, so they are mirrors
    }
    if (t1 == NULL || t2 == NULL) {
        return false; // One is NULL and the other is not, so they are not mirrors
    }
    return (t1->val == t2->val) && // The values must be equal
           isMirror(t1->left, t2->right) && // Left child of t1 with right child of t2
           isMirror(t1->right, t2->left);   // Right child of t1 with left child of t2
}

// Main function to check if a binary tree is symmetric
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true; // An empty tree is symmetric
    }
    return isMirror(root->left, root->right); // Check if left and right subtrees are mirrors
}

// Function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
