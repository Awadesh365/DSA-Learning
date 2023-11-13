#include <iostream>
#include <memory>

using namespace std; 

struct Node
{
    int element;
    Node *next;
};

int main()
{
    // Part 1: Dynamic Memory Allocation with new for Raw Pointers
    Node *n = new Node;     // Allocate memory for a Node using new
    Node *ptr = new Node(); // Allocate memory and explicitly call the default constructor

    // Part 2: Smart Pointers
    auto first = unique_ptr<Node>();  // Create a unique_ptr with no managed object
    auto second = shared_ptr<Node>(); // Create a shared_ptr with no managed object

    // Part 3: Using std::make_unique for Creating and Initializing Objects
    auto third = make_unique<Node>(); // Create a unique_ptr and initialize the object

    // Access and modify the object through the smart pointer
    third->element = 42;

    // No need for explicit delete, memory is automatically released when smart pointers go out of scope

    // Display the modified element value
    cout << "Element: " << third->element << endl; 

    // Note: Displaying values of other pointers is omitted as they are not initialized

    return 0;
}
