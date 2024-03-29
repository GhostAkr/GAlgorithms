#ifndef INCLUDE_BSTSUCCESSORSEARCHER_HPP
#define INCLUDE_BSTSUCCESSORSEARCHER_HPP

#include <iostream>
#include <memory>
#include <limits>

class BSTNode
{
public:
    BSTNode();
    explicit BSTNode(int key, std::shared_ptr<BSTNode> parent = nullptr);
    int getKey() const;
    std::shared_ptr<BSTNode> getLeft() const;
    std::shared_ptr<BSTNode> getRight() const;
    std::shared_ptr<BSTNode> getParent() const;
    void setLeft(std::shared_ptr<BSTNode> left);
    void setRight(std::shared_ptr<BSTNode> right);

private:
    int _key;
    std::shared_ptr<BSTNode> _left;
    std::shared_ptr<BSTNode> _right;
    std::shared_ptr<BSTNode> _parent;
};

class BST
{
public:
    BST();
    explicit BST(int key);

    void insert(int key);
    void print() const;
    bool contains(int key) const;
    int findInorderSuccessor(int key) const;

private:
    std::shared_ptr<BSTNode> _root;

    static void insert(std::shared_ptr<BSTNode> after, int key);
    static void print(std::shared_ptr<BSTNode> after);
    static bool exists(std::shared_ptr<BSTNode> after, int key);
    static int findInorderSuccessor(std::shared_ptr<BSTNode> after, 
        int key, int minNode = std::numeric_limits<int>::max());
};

#endif  // INCLUDE_BSTSUCCESSORSEARCHER_HPP
