#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
    vector<T> elements;

public:
    
    void push(const T& value) {
        elements.push_back(value);
    }

  
    void pop() {
        if (!empty()) {
            elements.pop_back();
        } else {
            cerr << "Error: Stack is empty. Cannot pop." << endl;
        }
    }

 
    void print() const {
    if (empty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements: ";
        for (const T& element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }
}

    T& top() {
        if (!empty()) {
            return elements.back();
        } else {
            cerr << "Error: Stack is empty. Cannot retrieve top element." << endl;
            throw out_of_range("Stack is empty");
        }
    }

   
    bool empty() const {
        return elements.empty();
    }

    
    size_t size() const {
        return elements.size();
    }

    void print(){

    }
};

#endif // STACK_H
