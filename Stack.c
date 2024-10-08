#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the stack

int stack[MAX]; // Array to store stack elements
int top = -1;   // Initialize top of the stack to -1 (empty stack)

// Function to push an element into the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop\n");
        return -1;
    } else {
        int poppedValue = stack[top];
        top--;
        printf("%d popped from stack\n", poppedValue);
        return poppedValue;
    }
}

// Function to peek the top element of the stack
int peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to display the stack elements
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Check if Empty\n5. Check if Full\n6. Display Stack\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            value = peek();
            if (value != -1)
                printf("Top element is %d\n", value);
            break;
        case 4:
            if (isEmpty()) {
                printf("Stack is empty\n");
            } else {
                printf("Stack is not empty\n");
            }
            break;
        case 5:
            if (isFull()) {
                printf("Stack is full\n");
            } else {
                printf("Stack is not full\n");
            }
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
