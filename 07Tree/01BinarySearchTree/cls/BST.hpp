#include <vector>

#ifndef _BST_H_
#define _BST_H_
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    int degree();
    TreeNode(int num);
};

class BST
{
    public:
    //data
    TreeNode *root;

    //method
    BST();
    TreeNode *search(int num);
    void insert(int num);
    void remove(int num);
    static void inorder(TreeNode *node, std::vector<TreeNode*> &result);
};

#endif