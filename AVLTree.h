#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <cstddef>
#include <string>
#include <vector>

class AVLTree {
    struct Node {
        std::string word;
        Node* left = nullptr;
        Node* right = nullptr;
        int height = 1;
        std::size_t repetitions = 1;
        explicit Node(const std::string& value);
    };

    Node* root = nullptr;
    std::size_t nodeCount = 0;
    std::size_t elementCount = 0;

    static int getHeight(Node* node);
    static int getBalance(Node* node);
    static void updateHeight(Node* node);
    static Node* rotateRight(Node* node);
    static Node* rotateLeft(Node* node);
    Node* insertNode(Node* node, const std::string& word);
    static void inorder(Node* node, std::vector<std::string>& result);
    static void destroy(Node* node);

public:
    AVLTree() = default;
    ~AVLTree();
    AVLTree(const AVLTree&) = delete;
    AVLTree& operator=(const AVLTree&) = delete;

    void insert(const std::string& word);
    std::vector<std::string> getSorted() const;
    std::size_t estimatedMemoryBytes() const;
};

#endif
