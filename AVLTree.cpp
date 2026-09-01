#include "AVLTree.h"

#include <algorithm>

AVLTree::Node::Node(const std::string& value) : word(value) {}
AVLTree::~AVLTree() { destroy(root); }

int AVLTree::getHeight(Node* node) { return node ? node->height : 0; }
int AVLTree::getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}
void AVLTree::updateHeight(Node* node) {
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
}

AVLTree::Node* AVLTree::rotateRight(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

AVLTree::Node* AVLTree::rotateLeft(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

AVLTree::Node* AVLTree::insertNode(Node* node, const std::string& word) {
    if (!node) {
        ++nodeCount;
        return new Node(word);
    }
    if (word < node->word) node->left = insertNode(node->left, word);
    else if (word > node->word) node->right = insertNode(node->right, word);
    else {
        ++node->repetitions;
        return node;
    }

    updateHeight(node);
    const int balance = getBalance(node);
    if (balance > 1 && word < node->left->word) return rotateRight(node);
    if (balance < -1 && word > node->right->word) return rotateLeft(node);
    if (balance > 1 && word > node->left->word) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && word < node->right->word) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

void AVLTree::insert(const std::string& word) {
    ++elementCount;
    root = insertNode(root, word);
}

void AVLTree::inorder(Node* node, std::vector<std::string>& result) {
    if (!node) return;
    inorder(node->left, result);
    for (std::size_t i = 0; i < node->repetitions; ++i) result.push_back(node->word);
    inorder(node->right, result);
}

std::vector<std::string> AVLTree::getSorted() const {
    std::vector<std::string> result;
    result.reserve(elementCount);
    inorder(root, result);
    return result;
}

void AVLTree::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

std::size_t AVLTree::estimatedMemoryBytes() const {
    return nodeCount * sizeof(Node);
}
