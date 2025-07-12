// 622. Design Circular Queue
// ---------------------------------------------------------
// Problem:
// Design a circular queue with fixed capacity, supporting typical queue operations
// including enqueue, dequeue, and access to front and rear, with wrap-around behavior.
//
// ---------------------------------------------------------
// ✅ Approach: Circular Linked List
// ---------------------------------------------------------
// - Maintain a circular singly-linked list by connecting the `rear` node back to `front`.
// - Track current queue `size` and `capacity` to enforce bounds.
// - Use `front` and `rear` pointers to access ends efficiently.
//
// 🔁 enQueue(value):
//   - Add new node at rear and link it back to front.
//   - Special handling for first element (front == rear).
//
// 🔁 deQueue():
//   - Remove node at front.
//   - Update rear->next to point to new front.
//
// 🟢 Time Complexity: O(1) for all operations (insertion, deletion, access)
// 🟢 Space Complexity: O(k) for storing k elements
//
// Runtime     : 4 ms     (Beats 45.85%)
// Memory Usage: 23.35 MB (Beats 92.49%)
// ---------------------------------------------------------

//Soluttion:
class MyCircularQueue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val): data(val), next(nullptr) {}
    };

    int size;        // current number of elements
    int capacity;    // max capacity of the queue
    Node* front;     // pointer to front node
    Node* rear;      // pointer to rear node

public:
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
        front = rear = nullptr;
    }

    bool enQueue(int value) {
        if (size == capacity) return false;  // queue full

        if (size == 0) {
            front = new Node(value);
            rear = front;
            rear->next = front;              // circular link
        } else {
            Node* temp = new Node(value);
            rear->next = temp;
            rear = temp;
            rear->next = front;              // complete the loop
        }

        size++;
        return true;
    }

    bool deQueue() {
        if (size == 0) return false;         // queue empty

        if (size == 1) {
            delete front;
            front = rear = nullptr;
            size = 0;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;              // reconnect rear to new front
            delete temp;
            size--;
        }

        return true;
    }

    int Front() {
        if (size == 0) return -1;
        return front->data;
    }

    int Rear() {
        if (size == 0) return -1;
        return rear->data;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
