#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};



struct node *create()
{
    struct node *newnode;
    int data;
    printf("Enter node value (-1 to stop): ");
    scanf("%d", &data);
    
    if (data == -1) {
        return NULL;
    }

    
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;


    printf("Enter left child of %d:\n", data);
    newNode->left = createTree();
    printf("Enter right child of %d:\n", data);
    newNode->right = createTree();

    return newNode;
}

void pre_order(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        printf("%d\t",root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void post_order (struct node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d\t",root->data);
    }
}

void in_order (struct node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        in_order(root->left);
        printf("%d\t",root->data);
        in_order(root->right);
    }
    
}

void main()
{
    struct node *root=0;
    int ch;
    while (1)
    {
    printf("\nEnter choice\n1. To create a tree\n2. To Pre-Order Traversal\n3. To Post-order Traversal\n4. To In-order Traversal\n5. To exit\n");
    scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        {
            root=create();
            break;
        }
        case 2:
        {
            printf("Pre-Order traversal is=\t");
            pre_order(root);
            break;
        }
        case 3:
        {
            printf("Post-Order traversal is=\t");
            post_order(root);
            break;
        }
        case 4:
        {
            printf("In-Order traversal is=\t");
            in_order(root);
            break;
        }
        case 5:
        {
            exit(0);
            break;
        }
        
        }
    }
    
    
}
