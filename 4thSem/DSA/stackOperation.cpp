#include <iostream>
using namespace std;

#define MAX_SIZE 5 // Maximum size of the stack

int stack[MAX_SIZE]; // Array to hold stack elements
int top = -1;        // Variable to track the top of the stack

// Push operation
void push(int value) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack is full!! Cannot push " << value << " into the stack.\n";
        return;
    }
    stack[++top] = value;
    cout << value << " pushed into the stack.\n";
}

// Pop operation
void pop() {
    if (top == -1) {
        cout << "Stack is empty!! Cannot pop from an empty stack.\n";
        return;
    }
    cout << stack[top--] << " popped from the stack.\n";
}

// Display the stack
void display() {
    if (top == -1) {
        cout << "Stack is empty!!\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\nStack Operations:\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
}
