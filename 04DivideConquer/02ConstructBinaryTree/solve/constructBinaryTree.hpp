#include <vector>

#ifndef __BINARY_SEARCH_H
#define __BINARY_SEARCH_H

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right; 

    TreeNode(int value, TreeNode *left, TreeNode *right);

    static void preorder(TreeNode *root, std::vector<int> &result);
};

TreeNode *constrcutBinaryTree(std::vector<int> &preorder, int m, 
                              std::vector<int> &inorder, int l, int r);

void print_vector(std::vector<int> &vector);

#endif