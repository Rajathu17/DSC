#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

// Structure to represent a circular queue element
struct CircularQueue {
    int data;
};

// Circular Queue variables
struct CircularQueue queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Function to check if the circular queue is empty
int isEmpty() {
    return front == -1 && rear == -1;
}
void enqueue(int value);
int dequeue();
void display();

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Dequeued element: %d\n", value);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to enqueue an element
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear].data = value;
    printf("%d enqueued successfully.\n", value);
}

// Function to dequeue an element
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = queue[front].data;
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return value;
}

// Function to check if the circular queue is full

// Function to display the elements of the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("front:%d",front);
    printf("Elements in the circular queue: ");
    for(int i = front;i!=rear;i = (i + 1) % MAX_SIZE)
  
        printf("%d ", queue[i].data);
        if (i == rear)
          printf("%d ", queue[i].data);
            
        
    }
    printf("\n");
}
