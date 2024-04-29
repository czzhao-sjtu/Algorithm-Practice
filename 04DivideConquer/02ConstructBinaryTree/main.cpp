#include "solve/constructBinaryTree.hpp"
#include <vector>
#include <iostream>

int main(){
    // Test1
    std::vector<int> preorder = {3, 9, 2, 1, 7};
    std::vector<int> inorder = {9, 3, 1, 2, 7};

    TreeNode *root = constrcutBinaryTree(preorder, 0, inorder, 0, inorder.size() - 1);
    std::vector<int> preorder_vector;
    root->preorder(root, preorder_vector);
    print_vector(preorder_vector);

}