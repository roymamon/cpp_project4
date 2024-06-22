#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include "Complex.hpp"
#include "node.hpp"
#include "tree.hpp"
#include <cstdlib>  


//email: mamon8521@gmail.com
//ID: 322623323


// helper method for test
template <typename T, typename Iterator>
std::vector<T> iteratorToVector(Iterator begin, Iterator end) {
    std::vector<T> result;
    while (begin != end) {
        result.push_back((*begin)->get_value());
        ++begin;
    }
    return result;
}


void testComplex() {
    Complex c1(1.0, 2.0);
    Complex c2(2.0, -1.0);

    Complex sum = c1 + c2;
    assert(sum.getReal() == 3.0);
    assert(sum.getImag() == 1.0);

    Complex diff = c1 - c2;
    assert(diff.getReal() == -1.0);
    assert(diff.getImag() == 3.0);

    Complex prod = c1 * c2;
    assert(prod.getReal() == 4.0);
    assert(prod.getImag() == 3.0);

    Complex quot = c1 / c2;
    assert(std::abs(quot.getReal() - 0.0) < 1e-9);
    assert(std::abs(quot.getImag() - 1.0) < 1e-9);

    std::cout << "Complex class tests passed!" << std::endl;
}


void testStringTree() {
    Node<std::string>* root_node = new Node<std::string>("root");
    Tree<std::string> tree;
    tree.add_root(*root_node);

    Node<std::string>* n1 = new Node<std::string>("child1");
    Node<std::string>* n2 = new Node<std::string>("child2");
    Node<std::string>* n3 = new Node<std::string>("child3");
    Node<std::string>* n4 = new Node<std::string>("child4");
    Node<std::string>* n5 = new Node<std::string>("child5");

    tree.add_sub_node(*root_node, *n1);
    tree.add_sub_node(*root_node, *n2);
    tree.add_sub_node(*n1, *n3);
    tree.add_sub_node(*n1, *n4);
    tree.add_sub_node(*n2, *n5);

    std::vector<std::string> expected_preorder = {"root", "child1", "child3", "child4", "child2", "child5"};
    std::vector<std::string> preorder = iteratorToVector<std::string>(tree.begin_pre_order(), tree.end_pre_order());
    assert(preorder == expected_preorder);

    std::vector<std::string> expected_postorder = {"child3", "child4", "child1", "child5", "child2", "root"};
    std::vector<std::string> postorder = iteratorToVector<std::string>(tree.begin_post_order(), tree.end_post_order());
    assert(postorder == expected_postorder);

    std::vector<std::string> expected_inorder = {"child3", "child1", "child4", "root", "child5", "child2"};
    std::vector<std::string> inorder = iteratorToVector<std::string>(tree.begin_in_order(), tree.end_in_order());
    assert(inorder == expected_inorder);

    std::vector<std::string> expected_bfs = {"root", "child1", "child2", "child3", "child4", "child5"};
    std::vector<std::string> bfs = iteratorToVector<std::string>(tree.begin_bfs_scan(), tree.end_bfs_scan());
    assert(bfs == expected_bfs);

    std::vector<std::string> expected_dfs = {"root", "child1", "child3", "child4", "child2", "child5"};
    std::vector<std::string> dfs = iteratorToVector<std::string>(tree.begin_dfs_scan(), tree.end_dfs_scan());
    assert(dfs == expected_dfs);

    std::cout << "String tree tests passed!" << std::endl;
    std::exit(EXIT_SUCCESS);

    
    
}


int main() {
   testComplex();
   testStringTree();


    return 0;
}
