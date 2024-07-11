#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
private:
    T* elements;
    size_t capacity;
    size_t size;

public:
    // Constructor
    Vector() : capacity(10), size(0) {
        elements = new T[capacity];
    }

    // Destructor
    ~Vector() {
        delete[] elements;
    }

    // Copy constructor
    Vector(const Vector& other) : capacity(other.capacity), size(other.size) {
        elements = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            elements[i] = other.elements[i];
        }
    }

    // Assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] elements;

            capacity = other.capacity;
            size = other.size;
            elements = new T[capacity];

            for (size_t i = 0; i < size; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    // Push element to the back of the vector
    void push_back(const T& value) {
        if (size == capacity) {
            resize();
        }
        elements[size++] = value;
    }

    
    T& at(size_t index) {
        if (index < size) {
            return elements[index];
        } else {
            std::cerr << "Error: Index out of bounds." << std::endl;
            throw std::out_of_range("Index out of bounds");
        }
    }

    
    size_t getSize() const {
        return size;
    }

private:
    
    void resize() {
        capacity *= 2;
        T* newElements = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }
};

#endif // VECTOR_H
