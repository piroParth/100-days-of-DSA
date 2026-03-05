#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

int main() {

    int n, c, e;
    struct Node *head=NULL, *temp=NULL, *newNode=NULL;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&c,&e);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coef = c;
        newNode->exp = e;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Print Polynomial
    temp = head;
    while(temp != NULL)
    {
        if(temp->exp == 0)
            printf("%d", temp->coef);
        else if(temp->exp == 1)
            printf("%dx", temp->coef);
        else
            printf("%dx^%d", temp->coef, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}