#include "cls/AVL.hpp"
#include "cls/utils.hpp"
#include <iostream>
#include <vector>

int main(){
    AVL tree = AVL();

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

    AVL tree2 = AVL();
    for (int idx = 0; idx < 100; idx++){
        tree2.insert(idx);
    }

    inorder_list = std::vector<TreeNode*>();
    tree2.inorder(tree2.root, inorder_list);
    print_vector_TreeNode(inorder_list);
}