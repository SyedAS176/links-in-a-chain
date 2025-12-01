#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/node.hpp"

TEST_CASE("Node basic constructor works") {
    Link gold("Gold");
    Node node_one(&gold);

    REQUIRE(node_one.get_data()->get_material() == "Gold");
    REQUIRE(node_one.next() == nullptr);
}

TEST_CASE("Node constructor with next pointer") {
    Link gold("Gold");
    Node node_one(&gold);

    Link silver("Silver");
    Node node_two(&silver, &node_one);

    REQUIRE(node_two.get_data()->get_material() == "Silver");
    REQUIRE(node_two.next() == &node_one);
}

TEST_CASE("Three-node chain behaves correctly") {
    Link gold("Gold");
    Node node_one(&gold);

    Link silver("Silver");
    Node node_two(&silver, &node_one);

    Link bronze("Bronze");
    Node node_three(&bronze, &node_two);

    SECTION("Correct data stored") {
        REQUIRE(node_three.get_data()->get_material() == "Bronze");
        REQUIRE(node_two.get_data()->get_material() == "Silver");
        REQUIRE(node_one.get_data()->get_material() == "Gold");
    }

    SECTION("Correct next links") {
        REQUIRE(node_three.next() == &node_two);
        REQUIRE(node_three.next()->next() == &node_one);
        REQUIRE(node_three.next()->next()->next() == nullptr);
    }
}

TEST_CASE("Traversal order is correct") {
    Link gold("Gold");
    Node node_one(&gold);

    Link silver("Silver");
    Node node_two(&silver, &node_one);

    Link bronze("Bronze");
    Node node_three(&bronze, &node_two);

    Node* curr = &node_three;
    std::vector<std::string> expected = {"Bronze", "Silver", "Gold"};

    int idx = 0;
    while (curr != nullptr) {
        REQUIRE(curr->get_data()->get_material() == expected[idx]);
        curr = curr->next();
        idx++;
    }
}