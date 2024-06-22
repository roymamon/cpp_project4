#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <iostream>

//email: mamon8521@gmail.com
//ID: 322623323


template <typename T>
class Node {
public:
    T key;
    std::vector<Node<T>*> children;

    Node(T k) : key(k) {}

    T get_value() const {
        return key;
    }

    friend std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
        os << node.key;
        return os;
    }
};

#endif 
