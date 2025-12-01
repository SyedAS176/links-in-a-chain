#include <iostream>
#include "src/node.hpp"

int main() {
    // Create Link objects
    Link gold("Gold");
    Link silver("Silver");
    Link bronze("Bronze");

    // Create nodes, linking them as we go
    Node node_three(&bronze);            // tail
    Node node_two(&silver, &node_three); // silver -> bronze
    Node node_one(&gold, &node_two);     // gold -> silver; this is also the head of the list

    // Direct accessing the nodes using next()
    Node* retrieved_two = node_one.next();
    Node* retrieved_three = node_two.next();

    // Printing out the direct access
    std::cout << retrieved_two->get_data()->get_material() << "\n";
    std::cout << retrieved_three->get_data()->get_material() << "\n";

    return 0;
}