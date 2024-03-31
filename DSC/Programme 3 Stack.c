#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int element) {
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else
        stack[++top] = element;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

bool isPalindrome() {
    if (top == -1)
        return false;
    
    int i = 0, j = top;
    while (i <= j) {
        if (stack[i] != stack[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void displayStack() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack contents: ");
        for (int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice, element;
    while (1) {
        printf("\nSTACK Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if stack contents form a palindrome\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                printf("Popped element: %d\n", pop());
                break;
            case 3:
                if (isPalindrome())
                    printf("Stack contents form a palindrome.\n");
                else
                    printf("Stack contents do not form a palindrome.\n");
                break;
            case 4:
                displayStack();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
