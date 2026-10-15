#include <stdio.h>
#include <stdlib.h>
struct node
{
     int data;
     struct node *next;
};
int main()
{
     struct node *head, *newNode, *temp;
     int n, i;
     head = NULL;
     printf("Enter number of nodes: ");
    scanf("%d", &n);
     for (i = 1; i <= n; i++)
     {      newNode = (struct node*)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d", &newNode->data);
            newNode->next = NULL;
            if (head == NULL)
            {
                    head = newNode;
            }
            else
            {
                    temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    printf("\nSingly Linked List:\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
printf("NULL");
    return 0;
}
