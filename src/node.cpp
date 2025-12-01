#include "node.hpp"

Node::Node(Link* link) {
    this->link = link;
    this->nextNode = nullptr;
}

Node::Node(Link* link, Node* nextNode) {
    this->link = link;
    this->nextNode = nextNode;
}

Node* Node::next() {
    return this->nextNode;
}

Link* Node::get_data() {
    return this->link;
}