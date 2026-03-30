#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree
struct TreeNode* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    // Pick current root from preorder
    int curr = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* node = newNode(curr);

    // If no children
    if (start == end)
        return node;

    // Find root in inorder
    int inIndex = search(inorder, start, end, curr);

    // Build left and right
    node->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    node->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return node;
}

// Postorder traversal
void postorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct TreeNode* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}