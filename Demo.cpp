/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "node.hpp"
#include "tree.hpp"
#include "Complex.hpp"


//email: mamon8521@gmail.com
//ID: 322623323


using namespace std;

int main() {
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree; 
    tree.add_root(root_node);
    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */


    

    cout << "Preorder traversal:" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        cout << (*node)->get_value() << ", ";
    }        
    cout << endl;
     // should print: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6


    cout << "Postorder traversal:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        cout << (*node)->get_value() << ", ";
    }
    cout << endl;
     // should print: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1


    cout << "Inorder traversal:" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        cout << (*node)->get_value() << ", ";
    }
    cout << endl;
     // should print: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3





    cout << "BFS traversal:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        cout << (*node)->get_value() << ", ";
    }
    cout << endl;
    // should print: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    cout << "Range-based for loop (BFS):" << endl;
    for (auto node : tree) {
        cout << node->get_value() << ", ";
    }
    cout << endl;
    // should print: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    cout << "DFS traversal:" << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        cout << (*node)->get_value() << ", ";
    }
    cout << endl;
    // should print: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6



    Node<double> root_node_3ary = Node<double>(1.1);
    Tree<double, 3> three_ary_tree; 
    three_ary_tree.add_root(root_node_3ary);
    Node<double> n1_3ary = Node<double>(1.2);
    Node<double> n2_3ary = Node<double>(1.3);
    Node<double> n3_3ary = Node<double>(1.4);
    Node<double> n4_3ary = Node<double>(1.5);
    Node<double> n5_3ary = Node<double>(1.6);

    three_ary_tree.add_sub_node(root_node_3ary, n1_3ary);
    three_ary_tree.add_sub_node(root_node_3ary, n2_3ary);
    three_ary_tree.add_sub_node(root_node_3ary, n3_3ary);
    three_ary_tree.add_sub_node(n1_3ary, n4_3ary);
    three_ary_tree.add_sub_node(n2_3ary, n5_3ary);

    


     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */

    // Complex number example
    Node<Complex> root_complex = Node<Complex>(Complex(1.0, 1.0));
    Tree<Complex> complex_tree; // Binary tree that contains complex numbers.
    complex_tree.add_root(root_complex);
    Node<Complex> c1 = Node<Complex>(Complex(1.0, 2.0));
    Node<Complex> c2 = Node<Complex>(Complex(2.0, 1.0));
    Node<Complex> c3 = Node<Complex>(Complex(1.0, -1.0));
    Node<Complex> c4 = Node<Complex>(Complex(-1.0, 1.0));
    Node<Complex> c5 = Node<Complex>(Complex(-1.0, -1.0));

    complex_tree.add_sub_node(root_complex, c1);
    complex_tree.add_sub_node(root_complex, c2);
    complex_tree.add_sub_node(c1, c3);
    complex_tree.add_sub_node(c1, c4);
    complex_tree.add_sub_node(c2, c5);

    
    // Preorder traversal for complex tree
    cout << "Complex tree Preorder traversal:" << endl;
    for (auto node = complex_tree.begin_pre_order(); node != complex_tree.end_pre_order(); ++node) {
        cout << (*node)->get_value() << ", ";
    }
    cout << endl;
    // should print: 1+1i, 1+2i, 1-1i, -1+1i, 2+1i, -1-1i

    cout << "Complex tree BFS traversal:" << endl;
    for (auto node = complex_tree.begin_bfs_scan(); node != complex_tree.end_bfs_scan(); ++node) {
        cout << (*node)->get_value() << ", ";
    }
    cout << endl;
    // should print: 1+1i, 1+2i, 2+1i, 1-1i, -1+1i, -1-1i

    cout << "Complex tree DFS traversal:" << endl;
    for (auto node = complex_tree.begin_dfs_scan(); node != complex_tree.end_dfs_scan(); ++node) {
        cout << (*node)->get_value() << ", ";
    }
    cout << endl;
    // should print: 1+1i, 1+2i, 1-1i, -1+1i, 2+1i, -1-1i

    
    cout << tree; // Should print the graph using GUI.
    cout << three_ary_tree;
    cout << complex_tree;


}
