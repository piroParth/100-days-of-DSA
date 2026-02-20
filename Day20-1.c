#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 200003

typedef long long ll;

typedef struct Node {
    ll key;
    ll freq;
    struct Node* next;
} Node;

Node* hashTable[HASH_SIZE];

int hash(ll key) {
    if (key < 0) key = -key;
    return key % HASH_SIZE;
}

ll insert(ll key) {
    int idx = hash(key);
    Node* temp = hashTable[idx];

    while (temp != NULL) {
        if (temp->key == key) {
            temp->freq++;
            return temp->freq - 1;
        }
        temp = temp->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->freq = 1;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    ll arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    ll sum = 0;
    ll count = 0;

    insert(0);

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        count += insert(sum);
    }

    printf("%lld\n", count);

    return 0;
}