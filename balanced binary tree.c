int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0; // Height of an empty tree is 0
    }

    // Recursively calculate the height of left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // If any subtree is unbalanced, propagate the unbalanced state
    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
        return -1; // Tree is unbalanced
    }

    // Return the height of the current subtree
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to determine if the tree is height-balanced
bool isBalanced(struct TreeNode* root) {
    return height(root) != -1;
}
