#pragma once

template <typename T>
class Node {
private:
    T* data;
    Node<T>* nextNode;

public:
    Node(T* data) : data(data), nextNode(nullptr) {}                        // Node constructor with no child

    Node(T* data, Node<T>* nextNode) : data(data), nextNode(nextNode) {}    // Node constructor with child

    Node<T>* next() {                                                       // Return next node in the chain
        return nextNode;
    }

    T* get_data() {  // Returns the stored data inside (you can have Links or any other data type stored)
        return data;
    }
};