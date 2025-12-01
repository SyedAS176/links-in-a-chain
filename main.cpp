#include <iostream>
#include "src/link.hpp"
#include "src/node.hpp"

int main() {
    // Create Link objects
    Link gold("Gold");
    Link silver("Silver");
    Link bronze("Bronze");

    // Create nodes, linking them as we go
    Node<Link> node_one(&gold);                     // tail
    Node<Link> node_two(&silver, &node_one);        // silver -> bronze
    Node<Link> node_three(&bronze, &node_two);      // gold -> silver; this is also the head of the list

    // Direct accessing the nodes using next()
    Node<Link>* retrieved_two = node_one.next();
    Node<Link>* retrieved_three = node_two.next();

    // Printing out the direct access by traversing from head
    Node<Link>* current = &node_three;
    while (current != nullptr) {
        std::cout << current->get_data()->get_material() << "\n";
        current = current->next();
    }

    return 0;
}