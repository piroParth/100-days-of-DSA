#include <stdio.h>

int main()
{
    int n, m;
    
    // Read number of elements
    scanf("%d", &n);
    
    int q[n];
    int front = -1, rear = -1;
    
    // Enqueue elements
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        
        if(front == -1) // first element
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % n;
        }
        
        q[rear] = x;
    }
    
    // Number of dequeue operations
    scanf("%d", &m);
    
    // Perform dequeue
    for(int i = 0; i < m; i++)
    {
        if(front == rear) // only one element
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % n;
        }
    }
    
    // Display queue
    int i = front;
    while(1)
    {
        printf("%d ", q[i]);
        
        if(i == rear)
            break;
            
        i = (i + 1) % n;
    }
    
    return 0;
}