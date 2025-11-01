#include <iostream>
using namespace std;

#define SIZE 5  // maximum size of circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if queue is full
bool isFull() {
    return ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front);
}

// Function to check if queue is empty
bool isEmpty() {
    return (front == -1);
}

// Function to insert an element (enqueue)
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is FULL! Cannot enqueue " << value << endl;
        return;
    }

    if (front == -1)  // first insertion
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    cout << value << " enqueued successfully!" << endl;
}

// Function to remove an element (dequeue)
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! Cannot dequeue." << endl;
        return;
    }

    cout << queue[front] << " dequeued successfully!" << endl;

    if (front == rear) {
        // queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Function to see the front element (peek)
void peek() {
    if (isEmpty()) {
        cout << "Queue is EMPTY! Nothing to peek." << endl;
    } else {
        cout << "Front element is: " << queue[front] << endl;
    }
}

// Function to display all elements
void display() {
    if (isEmpty()) {
        cout << "Queue is EMPTY!" << endl;
        return;
    }

    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

// Main menu-driven function
int main() {
    int choice, value;

    do {
        cout << "\n--- CIRCULAR QUEUE MENU ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty())
                    cout << "Queue is EMPTY.\n";
                else
                    cout << "Queue is NOT empty.\n";
                break;
            case 6:
                if (isFull())
                    cout << "Queue is FULL.\n";
                else
                    cout << "Queue is NOT full.\n";
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
