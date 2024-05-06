#include "cls/BST.hpp"
#include "cls/utils.hpp"
#include <iostream>
#include <vector>

int main(){
    BST tree = BST();

    tree.insert(5);
    tree.insert(8);
    tree.insert(7);
    tree.insert(3);
    tree.insert(1);

    std::vector<TreeNode*> inorder_list = std::vector<TreeNode*>();
    tree.inorder(tree.root, inorder_list);
    print_vector_TreeNode(inorder_list);
     
    tree.remove(5);
    inorder_list = std::vector<TreeNode*>();
    tree.inorder(tree.root, inorder_list);
    print_vector_TreeNode(inorder_list);

    tree.remove(3);
    inorder_list = std::vector<TreeNode*>();
    tree.inorder(tree.root, inorder_list);
    print_vector_TreeNode(inorder_list);

    tree.remove(1);
    inorder_list = std::vector<TreeNode*>();
    tree.inorder(tree.root, inorder_list);
    print_vector_TreeNode(inorder_list);

}