#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;

public:
    // Constructor
    Queue() : frontNode(nullptr), rearNode(nullptr) {}

    // Destructor
    ~Queue() {
        clear();
    }

    
    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (Empty()) {
            frontNode = newNode;
            rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

void print() {
    Node* current = frontNode;
    while (current != nullptr) {
        
        current->data.displayDetails();
        cout << " ";
        current = current->next;
    }
    cout << endl;
}

   
    void dequeue() {
        if (!Empty()) {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            delete temp;

            if (frontNode == nullptr) {
                rearNode = nullptr; 
            }
        } else {
                cerr << "Error: Queue is empty. Cannot dequeue." << endl;
        }
    }
     
    bool Empty() const {
        return frontNode == nullptr;
    }



  
    T& front() {
        if (!Empty()) {
            return frontNode->data;
        } else {
            cerr << "Error: Queue is empty. Cannot retrieve front element." << endl;
            throw out_of_range("Queue is empty");
        }
    }

    
    bool isEmpty() const {
        return frontNode == nullptr;
    }

    size_t size() const {
        size_t count = 0;
        Node* current = frontNode;
        while (current != nullptr) {
            ++count;
            current = current->next;
        }
        return count;
    }

  
    void clear() {
        while (!Empty()) {
            dequeue();
        }
    }
};

#endif // QUEUE_H
