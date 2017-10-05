#include "./binary_search_tree.h"
#include <iostream>

using namespace std;

int main() {
        // Generate a binary search tree for nodes of integer keys and values
        forest::binary_search_tree <int, int> binary_search_tree;

        // Insert 7 nodes in the form of a (key, value) pair
        binary_search_tree.insert(4,0);
        binary_search_tree.insert(2,0);
        binary_search_tree.insert(90,0);
        binary_search_tree.insert(3,100);
        binary_search_tree.insert(0,0);
        binary_search_tree.insert(14,0);
        binary_search_tree.insert(45,0);

        // Perform an in order traversal
        binary_search_tree.in_order_traversal();
        int key;
        while(cin >> key){
            binary_search_tree.delete_node(key);
            
            binary_search_tree.in_order_traversal();
        }

      

        return 0;
}