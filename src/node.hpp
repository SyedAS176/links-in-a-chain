#pragma once

#include "link.hpp"

class Node {
private:
    Link* link;
    Node* nextNode;

public:
    Node(Link* link);                   // Node constructor for no child

    Node(Link* link, Node* nextNode);   // Node constructor for child

    Node* next();                       // Return next node

    Link* get_data();                   // Returns the Link stored inside
};