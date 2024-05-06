#include "AVL.hpp"
#include <algorithm>
TreeNode::TreeNode(int num):val(num){}

AVL::AVL():root(nullptr){}

int height(TreeNode *node){
    return (node == nullptr)? -1: node->height;
}

void updateHeight(TreeNode *node){
    node->height = std::max(height(node->left), height(node->right)) + 1;
}

int balanceFactor(TreeNode *node){
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

TreeNode *rightRotate(TreeNode *node){
    TreeNode *child = node->left;
    TreeNode *grandchild = child->right;

    node->left = grandchild;
    child->right = node;

    updateHeight(node);
    updateHeight(child);

    return child;
}

TreeNode *leftRotate(TreeNode *node){
    TreeNode *child = node->right;
    TreeNode *grandchild = child->left;

    node->right = grandchild;
    child->left = node;

    updateHeight(node);
    updateHeight(child);

    return child;
}

TreeNode *rotate(TreeNode *node){
    int _balanceFactor = balanceFactor(node);
    if (_balanceFactor > 1){
        // 左偏树 -> 执行右旋
        TreeNode *child = node->left;
        int _child_balanceFactor = balanceFactor(child);
        if (_child_balanceFactor >= 0){
            return rightRotate(node);
        }else if(_child_balanceFactor < 0){
            node->left = leftRotate(child);
            return rightRotate(node);
        }
    }else if(_balanceFactor < -1){
        TreeNode *child = node->right;
        int _child_balanceFactor = balanceFactor(child);
        if (_child_balanceFactor <= 0){
            return leftRotate(node);
        }else if (_child_balanceFactor > 0){
            node->right = rightRotate(child);
            return leftRotate(node);
        }
    }
    return node;
}

TreeNode *insertHelper(TreeNode *root, int num){
    // 在root中插入num并返回一棵平衡二叉树
    if (root == nullptr){
        return new TreeNode(num);
    }

    if (root->val > num){
        root->left = insertHelper(root->left, num);
    }else if (root->val < num){
        root->right = insertHelper(root->right, num);
    }else{
        return root;
    }

    updateHeight(root);
    root = rotate(root);
    return root;
}

void AVL::insert(int num){
    root = insertHelper(root, num);
}

TreeNode *removeHelper(TreeNode *root, int num){
    if (root == nullptr)
        return nullptr;

    if (root->val > num){
        root->left = removeHelper(root->left, num);
    }else if (root->val < num){
        root->right = removeHelper(root->right, num);
    }else if (root->val == num){
        if (root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }else if (root->right != nullptr){
            std::vector<TreeNode *> inorder_list;
            AVL::inorder(root->right, inorder_list);

            int temp = inorder_list[0]->val;
            root->left = removeHelper(root->left, temp);
            root->val = temp;
        }else if (root->left != nullptr && root->right == nullptr){
            TreeNode *child = root->left;
            delete root;
            return child;
        }
    }

    updateHeight(root);
    root = rotate(root);
    return root;
}

TreeNode *AVL::search(int num){
    TreeNode *cur = root;
    while (cur != nullptr){
        if (cur->val == num)
            return cur;
        else if (cur->val > num)
            cur = cur->left;
        else
            cur = cur->right;
    }
    return nullptr;
}


void AVL::remove(int num){
    root = removeHelper(root, num);
}

void AVL::inorder(TreeNode* node, std::vector<TreeNode*> &result){
    if (node == nullptr)
        return;
    
    inorder(node->left, result);
    result.push_back(node);
    inorder(node->right, result);
}