#include <vector>

#ifndef _PREORDER_H
#define _PREORDER_H
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int, TreeNode *, TreeNode*);
    TreeNode(int);
};

void preOrder(TreeNode *, int, int, vector<TreeNode*> &, vector<vector<TreeNode*>> &);
#endif