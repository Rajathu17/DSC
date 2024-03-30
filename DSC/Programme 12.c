#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct node* insert(struct node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d \n", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d \n", root->data);
    }
}

int main() {
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("\nPreorder traversal of the given tree \n");
    preorder(root);

    printf("\nPostorder traversal of the given tree \n");
    postorder(root);

    return 0;
}
