#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {

    int n, k, val;
    struct Node *head=NULL, *temp=NULL, *newNode=NULL, *tail=NULL;

    scanf("%d",&n);

    // Creating linked list
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val);

        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=val;
        newNode->next=NULL;

        if(head==NULL)
        {
            head=newNode;
            temp=head;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
    }

    tail=temp;

    scanf("%d",&k);

    k = k % n;

    if(k>0)
    {
        // make circular
        tail->next=head;

        int steps = n-k;
        temp=head;

        for(int i=1;i<steps;i++)
            temp=temp->next;

        head=temp->next;
        temp->next=NULL;
    }

    // print list
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}