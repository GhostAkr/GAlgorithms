#include <iostream>
#include "../include/BSTSuccessorSearcher.hpp"

int main(int argc, char** argv)
{
    BST tree(20);
    tree.insert(9);
    tree.insert(25);
    tree.insert(5);
    tree.insert(12);
    tree.insert(11);
    tree.insert(14);

    tree.print();
    std::cout << "Inorder successor of " << 9 << " is " << tree.findInorderSuccessor(9)
        << std::endl;  // should return 11
    std::cout << "Inorder successor of " << 14 << " is " << tree.findInorderSuccessor(14)
        << std::endl;  // should return 20
    return 0;
}
