#include "../include/BSTSuccessorSearcher.hpp"

/* ====================================
    BSTNode implementation
==================================== */

BSTNode::BSTNode()
: _key(0)
, _left(nullptr)
, _right(nullptr)
, _parent(nullptr)
{}

BSTNode::BSTNode(int key, std::shared_ptr<BSTNode> parent)
: _key(key)
, _left(nullptr)
, _right(nullptr)
, _parent(parent)
{}

int BSTNode::getKey() const
{
    return _key;
}

std::shared_ptr<BSTNode> BSTNode::getLeft() const
{
    return _left;
}

std::shared_ptr<BSTNode> BSTNode::getRight() const
{
    return _right;
}

std::shared_ptr<BSTNode> BSTNode::getParent() const
{
    return _parent;
}

void BSTNode::setLeft(std::shared_ptr<BSTNode> left)
{
    _left = left;
}

void BSTNode::setRight(std::shared_ptr<BSTNode> right)
{
    _right = right;
}

/* ====================================
    BST implementation
==================================== */

BST::BST()
: _root(nullptr)
{}

BST::BST(int key)
: _root(std::make_shared<BSTNode>(key))
{}

void BST::insert(std::shared_ptr<BSTNode> after, int key)  // static
{
    if (key < after->getKey())
    {
        if (after->getLeft())
        {
            BST::insert(after->getLeft(), key);
        }
        else
        {
            BSTNode newNode(key, after);
            after->setLeft(std::make_shared<BSTNode>(newNode));
        }
    }
    else if (key > after->getKey())
    {
        if (after->getRight())
        {
            BST::insert(after->getRight(), key);
        }
        else
        {
            BSTNode newNode(key, after);
            after->setRight(std::make_shared<BSTNode>(newNode));
        }
    }
}

void BST::insert(int key)
{
    BST::insert(_root, key);
}

void BST::print(std::shared_ptr<BSTNode> after)  // static
{
    std::cout << "{" << after->getKey() << ": ";

    std::cout << "p = ";
    
    if (after->getParent())
    {
        std::cout << after->getParent()->getKey();
    }
    else
    {
        std::cout << "null";
    }
    std::cout << "; ";
    
    std::cout << "l = ";
    if (after->getLeft())
    {
        std::cout << after->getLeft()->getKey();
    }
    else
    {
        std::cout << "null";
    }
    std::cout << "; ";

    std::cout << "r = ";
    if (after->getRight())
    {
        std::cout << after->getRight()->getKey();
    }
    else
    {
        std::cout << "null";
    }
    std::cout << "}" << std::endl;

    if (after->getLeft())
    {
        print(after->getLeft());
    }
    if (after->getRight())
    {
        print(after->getRight());
    }
}

void BST::print() const
{
    BST::print(_root);
}

bool BST::exists(std::shared_ptr<BSTNode> after, int key)  // static
{
    if (after->getKey() == key)
    {
        return true;
    }
    else if (key < after->getKey())
    {
        if (!after->getLeft())
        {
            return false;
        }
        else
        {
            return BST::exists(after->getLeft(), key);
        }
    }
    else  // key > after->getKey()
    {
        if (!after->getRight())
        {
            return false;
        }
        else
        {
            return BST::exists(after->getRight(), key);
        }
    }
}

bool BST::contains(int key) const
{
    return BST::exists(_root, key);
}

int BST::findInorderSuccessor(  // static
    std::shared_ptr<BSTNode> after, 
    int key,
    int minNode
){
    int currKey = after->getKey();
    if (currKey <= key)
    {
        if (!after->getRight())
        {
            return minNode;
        }
        return BST::findInorderSuccessor(after->getRight(), key, minNode);
    }
    else
    {
        minNode = currKey < minNode ? currKey : minNode;
        if (!after->getLeft())
        {
            return minNode;
        }
        return BST::findInorderSuccessor(after->getLeft(), key, minNode);
    }
}

int BST::findInorderSuccessor(int key) const
{
    return BST::findInorderSuccessor(_root, key);
}
