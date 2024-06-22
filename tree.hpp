#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "node.hpp"
#include "Complex.hpp"


//email: mamon8521@gmail.com
//ID: 322623323



template <typename T>
class PreOrderIterator {
private:
    std::stack<Node<T>*> stack;

public:
    PreOrderIterator(Node<T>* root) {
        if (root) {
            stack.push(root);
        }
    }

    bool operator!=(const PreOrderIterator& other) const {
        return !(*this == other);
    }

    bool operator==(const PreOrderIterator& other) const {
        if (stack.empty() && other.stack.empty()) {
            return true;
        }
        if (stack.empty() || other.stack.empty()) {
            return false;
        }
        return stack.top() == other.stack.top();
    }

    Node<T>* operator*() const {
        return stack.top();
    }

    PreOrderIterator& operator++() {
        Node<T>* node = stack.top();
        stack.pop();
        for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
            stack.push(*it);
        }
        return *this;
    }
};


template <typename T>
class PostOrderIterator {
private:
    std::stack<Node<T>*> stack1, stack2;

public:
    PostOrderIterator(Node<T>* root) {
        if (root) {
            stack1.push(root);
            while (!stack1.empty()) {
                Node<T>* node = stack1.top();
                stack1.pop();
                stack2.push(node);
                for (Node<T>* child : node->children) {
                    stack1.push(child);
                }
            }
        }
    }

    bool operator!=(const PostOrderIterator& other) const {
        return !(*this == other);
    }

    bool operator==(const PostOrderIterator& other) const {
        if (stack2.empty() && other.stack2.empty()) {
            return true;
        }
        if (stack2.empty() || other.stack2.empty()) {
            return false;
        }
        return stack2.top() == other.stack2.top();
    }

    Node<T>* operator*() const {
        return stack2.top();
    }

    PostOrderIterator& operator++() {
        stack2.pop();
        return *this;
    }
};


template <typename T>
class InOrderIterator {
private:
    std::stack<Node<T>*> stack;
    Node<T>* current;

    void pushLeft(Node<T>* node) {
        while (node) {
            stack.push(node);
            if (!node->children.empty()) {
                node = node->children.front();
            } else {
                node = nullptr;
            }
        }
    }

public:
    InOrderIterator(Node<T>* root) : current(root) {
        pushLeft(root);
    }

    bool operator!=(const InOrderIterator& other) const {
        return !(*this == other);
    }

    bool operator==(const InOrderIterator& other) const {
        if (stack.empty() && other.stack.empty()) {
            return true;
        }
        if (stack.empty() || other.stack.empty()) {
            return false;
        }
        return stack.top() == other.stack.top();
    }

    Node<T>* operator*() const {
        return stack.top();
    }

    InOrderIterator& operator++() {
        Node<T>* node = stack.top();
        stack.pop();
        if (!node->children.empty() && node->children.size() > 1) {
            pushLeft(node->children[1]);
        }
        return *this;
    }
};


template <typename T>
class BFSIterator {
private:
    std::queue<Node<T>*> queue;

public:
    BFSIterator(Node<T>* root) {
        if (root) {
            queue.push(root);
        }
    }

    bool operator!=(const BFSIterator& other) const {
        return !(*this == other);
    }

    bool operator==(const BFSIterator& other) const {
        if (queue.empty() && other.queue.empty()) {
            return true;
        }
        if (queue.empty() || other.queue.empty()) {
            return false;
        }
        return queue.front() == other.queue.front();
    }

    Node<T>* operator*() const {
        return queue.front();
    }

    BFSIterator& operator++() {
        Node<T>* node = queue.front();
        queue.pop();
        for (Node<T>* child : node->children) {
            queue.push(child);
        }
        return *this;
    }
};


template <typename T>
class DFSIterator {
private:
    std::stack<Node<T>*> stack;

public:
    DFSIterator(Node<T>* root) {
        if (root) {
            stack.push(root);
        }
    }

    bool operator!=(const DFSIterator& other) const {
        return !(*this == other);
    }

    bool operator==(const DFSIterator& other) const {
        if (stack.empty() && other.stack.empty()) {
            return true;
        }
        if (stack.empty() || other.stack.empty()) {
            return false;
        }
        return stack.top() == other.stack.top();
    }

    Node<T>* operator*() const {
        return stack.top();
    }

    DFSIterator& operator++() {
        Node<T>* node = stack.top();
        stack.pop();
        for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
            stack.push(*it);
        }
        return *this;
    }
};




template <typename T, int MaxChildren = 2>
class Tree {
private:
    Node<T>* root;

    void deleteNodes(Node<T>* node) {
        if (node == nullptr) {
            return;
        }

        for (Node<T>* child : node->children) {
            deleteNodes(child);
        }

        delete node;
    }

    void printNode(std::ostream& os, const Node<T>* node, int depth = 0) const {
        if (!node) return;

        os << std::string(depth * 2, ' ') << *node << "\n";
        for (const Node<T>* child : node->children) {
            printNode(os, child, depth + 1);
        }
    }

    void drawNode(sf::RenderWindow& window, Node<T>* node, float x, float y, float offset, sf::Font& font) const {
        if (!node) return;

     
        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(x, y);
        window.draw(circle);

        sf::Text text("", font, 15);
        text.setFillColor(sf::Color::Black);
        if constexpr (std::is_same<T, Complex>::value) {
            text.setString(node->key.toString());
        } else {
            text.setString(std::to_string(node->key));
        }
        text.setPosition(x + 10, y + 5);
        window.draw(text);

        float child_y = y + 100;
        float child_x = x - offset * (node->children.size() - 1) / 2;
        for (Node<T>* child : node->children) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x + 20, y + 20)),
                sf::Vertex(sf::Vector2f(child_x + 20, child_y + 20))
            };
            window.draw(line, 2, sf::Lines);
            drawNode(window, child, child_x, child_y, offset / 2, font);
            child_x += offset;
        }
    }

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        deleteNodes(root);
    }

    void add_root(Node<T>& node) {
        root = &node;
    }

    void add_sub_node(Node<T>& parent, Node<T>& child) {
        if (parent.children.size() < MaxChildren) {
            parent.children.push_back(&child);
        } else {
            throw std::runtime_error("Maximum children exceeded");
        }
    }

    void draw(sf::RenderWindow& window, sf::Font& font) const {
        drawNode(window, root, 400, 50, 300, font);
    }

    PreOrderIterator<T> begin_pre_order() { return PreOrderIterator<T>(root); }
    PreOrderIterator<T> end_pre_order() { return PreOrderIterator<T>(nullptr); }

    PostOrderIterator<T> begin_post_order() { return PostOrderIterator<T>(root); }
    PostOrderIterator<T> end_post_order() { return PostOrderIterator<T>(nullptr); }

    InOrderIterator<T> begin_in_order() { return InOrderIterator<T>(root); }
    InOrderIterator<T> end_in_order() { return InOrderIterator<T>(nullptr); }

    BFSIterator<T> begin_bfs_scan() { return BFSIterator<T>(root); }
    BFSIterator<T> end_bfs_scan() { return BFSIterator<T>(nullptr); }

    DFSIterator<T> begin_dfs_scan() { return DFSIterator<T>(root); }
    DFSIterator<T> end_dfs_scan() { return DFSIterator<T>(nullptr); }

    
    BFSIterator<T> begin() { return begin_bfs_scan(); }
    BFSIterator<T> end() { return end_bfs_scan(); }

    friend std::ostream& operator<<(std::ostream& os, const Tree<T, MaxChildren>& tree) {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");
        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Error loading font" << std::endl;
            return os;
        }

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::Black);
            tree.draw(window, font);
            window.display();
        }

        return os;
    }
};

#endif 
