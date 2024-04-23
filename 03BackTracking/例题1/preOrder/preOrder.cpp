#include <vector>
#include "preOrder.h"

using namespace std;

TreeNode::TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right){
};

TreeNode::TreeNode(int val): val(val), left(nullptr), right(nullptr){};

void preOrder(TreeNode *root, int target, vector<TreeNode*> *result){
    if (root == nullptr) return;

    if (root->val == target){
        result -> push_back(root);
    }

    preOrder(root->left, target, result);
    preOrder(root->right, target, result);
    return;
}
