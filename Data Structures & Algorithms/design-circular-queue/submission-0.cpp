class Node {
public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

class MyCircularQueue {
private:
    Node* front;
    Node* rear;
    int size;
    int capacity;

public:
    MyCircularQueue(int k) {
        front = rear = NULL;
        size = 0;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) 
            return false;

        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front;  
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;  
        }

        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) 
            return false;

        if (front == rear) {  
            delete front;
            front = rear = NULL;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;  
            delete temp;
        }

        size--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) 
            return -1;
        return front->val;
    }
    
    int Rear() {
        if (isEmpty()) 
            return -1;
        return rear->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};