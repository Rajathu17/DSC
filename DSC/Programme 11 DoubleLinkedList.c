#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Global declaration of the head pointer
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node to the left of the node with a given key value
void insertLeft(int key, int newData) {
    struct Node* newNode = createNode(newData);
    struct Node* current = head;

    // Traverse the list to find the node with the given key value
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    // If key is not found
    if (current == NULL) {
        printf("Key not found in the list. Cannot insert.\n");
        free(newNode);
        return;
    }

    // Insert the new node to the left of the node with the given key
    newNode->next = current;
    newNode->prev = current->prev;
    if (current->prev != NULL) {
        current->prev->next = newNode;
    } else {
        head = newNode;
    }
    current->prev = newNode;

    printf("%d inserted to the left of %d\n", newData, key);
}

// Function to delete a node with given data from the list
void deleteNode(int key) {
    struct Node* current = head;

    // Traverse the list to find the node with the given data
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    // If node with given data is not found
    if (current == NULL) {
        printf("%d not found in the list. Cannot delete.\n", key);
        return;
    }

    // Adjust pointers to delete the node
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    printf("%d deleted from the list\n", key);
    free(current);
}

// Function to display the doubly linked list
void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, key, newData;

    do {
        printf("\nMenu:\n");
        printf("1. Insert a new node to the left of a node\n");
        printf("2. Delete a node\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key value of the node: ");
                scanf("%d", &key);
                printf("Enter the data to be inserted: ");
                scanf("%d", &newData);
                insertLeft(key, newData);
                break;
            case 2:
                printf("Enter the data of the node to be deleted: ");
                scanf("%d", &key);
                deleteNode(key);
                break;
            case 3:
                displayList();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    // Free memory allocated for the list
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
