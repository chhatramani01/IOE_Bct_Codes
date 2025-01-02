#include <iostream>
using namespace std;

#define MAX_SIZE 5 // Maximum size of the queue

int queue[MAX_SIZE]; // Array to store queue elements
int front = -1, rear = -1; // Pointers for the front and rear of the queue

// Function to check if the queue is empty
bool isEmpty() {
    return (front == -1 && rear == -1);
}

// Function to check if the queue is full
bool isFull() {
    return (rear == MAX_SIZE - 1);
}

// Enqueue operation (Add element to the queue)
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full!! You cannot add more items.\n";
    } else {
        if (isEmpty()) { // If queue is empty, initialize front and rear
            front = 0;
        }
        rear++;
        queue[rear] = value;
        cout << value << " added to the queue.\n";
    }
}

// Dequeue operation (Remove element from the queue)
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!! Nothing to remove.\n";
    } else {
        cout << queue[front] << " removed from the queue.\n";
        if (front == rear) { // Queue becomes empty
            front = rear = -1;
        } else {
            front++;
        }
    }
}

// Display the queue
void display() {
    if (isEmpty()) {
        cout << "Queue is empty!!\n";
    } else {
        cout << "Queue items: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    while (true) {
        cout << "\nWhat do you want to do?\n";
        cout << "1. Add item (Enqueue)\n";
        cout << "2. Remove item (Dequeue)\n";
        cout << "3. See all items (Display)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the number to add: ";
            cin >> value;
            enqueue(value);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
