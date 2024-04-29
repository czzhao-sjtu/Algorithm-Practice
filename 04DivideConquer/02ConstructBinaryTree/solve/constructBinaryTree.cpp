#include <vector>
#include <iostream>
#include <algorithm>
#include "constructBinaryTree.hpp"

TreeNode::TreeNode(int value, TreeNode *left, TreeNode *right): value(value), left(left), right(right){
}

void TreeNode::preorder(TreeNode *root, std::vector<int> &result){
    if (root == nullptr){
        return;
    }
    // root 非空
    result.push_back(root->value);
    preorder(root->left, result);
    preorder(root->right, result);
}

TreeNode *constrcutBinaryTree(std::vector<int> &preorder, int m, 
                              std::vector<int> &inorder, int l, int r){
    TreeNode *root = new TreeNode(preorder[m], nullptr, nullptr);

    //查找root->value在inorder数组中的下标
    auto iter = std::find(inorder.begin() + l, inorder.begin() + r + 1, root->value);
    int i = iter - inorder.begin();
    if (i - 1 < l)
        root->left = nullptr;
    else
        root->left = constrcutBinaryTree(preorder, m+1,
                                         inorder, l, i-1);
    
    if (i + 1 > r)
        root->right = nullptr;
    else
        root->right = constrcutBinaryTree(preorder, m + (i - l) + 1, 
                                          inorder, i+1, r);

    return root;
}

void print_vector(std::vector<int> &vector){
    if (vector.size() == 0){
        std::cout << "()" << std::endl;
        return;
    }

    for (int i = 0; i < vector.size(); i++){
        if (i == 0) std::cout << "(" << vector[i];
        else if(i == vector.size() - 1) std::cout << ", " << vector[i] << ")"<<std::endl;
        else std::cout << ", " << vector[i];
    }

    return;
}