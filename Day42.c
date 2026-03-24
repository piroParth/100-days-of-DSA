#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Queue {
    int arr[MAX];
    int front, rear;
};

struct Stack {
    int arr[MAX];
    int top;
};

void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(struct Queue* q, int x) {
    q->arr[++q->rear] = x;
}

int dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmptyQueue(struct Queue* q) {
    return q->front > q->rear;
}

void initStack(struct Stack* s) {
    s->top = -1;
}

void push(struct Stack* s, int x) {
    s->arr[++s->top] = x;
}

int pop(struct Stack* s) {
    return s->arr[s->top--];
}

int isEmptyStack(struct Stack* s) {
    return s->top == -1;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Queue q;
    struct Stack s;

    initQueue(&q);
    initStack(&s);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    while (!isEmptyQueue(&q)) {
        push(&s, dequeue(&q));
    }

    while (!isEmptyStack(&s)) {
        enqueue(&q, pop(&s));
    }

    while (!isEmptyQueue(&q)) {
        printf("%d ", dequeue(&q));
    }

    return 0;
}