#include <vector>
#include "preOrder.h"

using namespace std;

TreeNode::TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right){
};

TreeNode::TreeNode(int val): val(val), left(nullptr), right(nullptr){};

void preOrder(TreeNode *root, int target, vector<TreeNode*> &path, vector<vector<TreeNode*>> &result){
    if (root == nullptr) return;

    // 1. 尝试: 探索以本节点为基础的两种可能性
    path.push_back(root);
    if (root->val == target){
        result.push_back(path);
    }

    preOrder(root->left, target, path, result);
    preOrder(root->right, target, path, result);

    // 2. 回退: 消除以本节点为基础的影响
    path.pop_back();
    return;
}
