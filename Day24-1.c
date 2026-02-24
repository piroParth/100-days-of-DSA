#include <stdio.h>
#include <stdlib.h>

// Definition of node
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Delete first occurrence of key
void deleteFirstOccurrence(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }

    // Unlink the node
    prev->next = temp->next;
    free(temp);
}

// Display list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Create list: 10 -> 20 -> 30 -> 20 -> 40
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 20);
    insertEnd(&head, 40);

    printf("Original List:\n");
    display(head);

    int key = 20;
    deleteFirstOccurrence(&head, key);

    printf("List after deleting first occurrence of %d:\n", key);
    display(head);

    return 0;
}