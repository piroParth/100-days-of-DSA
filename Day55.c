#include <stdio.h>
#include <stdlib.h>

// Tree Node
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

// Queue structure
struct Queue {
    struct TreeNode* arr[1000];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

// Push
void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
}

// Pop
struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Queue q;
    initQueue(&q);

    struct TreeNode* root = newNode(arr[0]);
    enqueue(&q, root);

    int i = 1;
    while (!isEmpty(&q) && i < n) {
        struct TreeNode* curr = dequeue(&q);

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

// Right View
void rightView(struct TreeNode* root) {
    if (!root) return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int size = q.rear - q.front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = dequeue(&q);

            // Print last node of level
            if (i == size - 1) {
                printf("%d ", curr->val);
            }

            if (curr->left) enqueue(&q, curr->left);
            if (curr->right) enqueue(&q, curr->right);
        }
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    rightView(root);

    return 0;
}