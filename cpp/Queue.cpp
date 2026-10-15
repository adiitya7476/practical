#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        if (front == -1)
           front = 0;
        rear++;
        queue[rear] = value;
        printf("%d inserted\n", value);
    }
}
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty\n");

    }
    else
    {
        printf("%d deleted\n", queue[front]);
        front++;
    }
}
void display()
{
    int i;


    if (front == -1 || front > rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue: ");


        for (i = front; i <= rear; i++)
        {
             printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();


    dequeue();


    display();


    return 0;
}
