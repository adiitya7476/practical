#include <stdio.h>
#include <stdlib.h>
struct node
{
     int data;
     struct node *left;
     struct node *right;
};
struct node* createNode(int data)
{
     struct node *newNode;
     newNode = (struct node*)malloc(sizeof(struct node));
     newNode->data = data;
     newNode->left = NULL;
     newNode->right = NULL;
     return newNode;
}
int main()
{
     struct node *root;
     root = createNode(1);
     root->left = createNode(2);
     root->right = createNode(3);
     root->left->left = createNode(4);
     root->left->right = createNode(5);

    printf("Binary Tree:\n\n");
    printf("      %d\n", root->data);
    printf("     / \\\n");
    printf("    %d %d\n", root->left->data, root->right->data);
    printf("    / \\\n");
    printf(" %d %d\n",
         root->left->left->data,
         root->left->right->data);
    return 0;
}
