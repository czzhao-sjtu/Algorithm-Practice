#include "BST.hpp"
TreeNode::TreeNode(int num){
    val = num;
    left = nullptr;
    right = nullptr;
}

int TreeNode::degree(){
    if (left == nullptr && right == nullptr)
        return 0;
    else if (left != nullptr && right !=nullptr)
        return 2;
    else
        return 1;
}

BST::BST():root(nullptr){}

TreeNode *BST::search(int num){
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

void BST::insert(int num){
    if (root == nullptr){
        root = new TreeNode(num);
        return;
    }

    TreeNode *pre = nullptr;
    TreeNode *cur = root;

    while(cur != nullptr){
        if (cur->val == num)
            return;
        else if (cur->val > num){
            pre = cur;
            cur = cur->left;
        }else{
            pre = cur;
            cur = cur->right;
        }
    }

    cur = new TreeNode(num);
    if (num > pre->val)
        pre->right = cur;
    else
        pre->left = cur;
    return;
}

void BST::remove(int num){
    if (root == nullptr)
        return;

    TreeNode *pre = nullptr;
    TreeNode *cur = root;
    while (cur != nullptr){
        if (cur->val == num){
            break;
        }else if (cur->val > num){
            pre = cur;
            cur = cur->left;
        }else{
            pre = cur;
            cur = cur->right;
        }
    }

    if (cur == nullptr)
    // 如果二叉搜索树中不存在相应节点
    // 直接返回
        return;

    if (pre == nullptr){
        // 目标节点是根节点
        if (root->degree() == 0){
            root = nullptr;
            delete cur;
        }
        else if (root->degree() == 1){
            if (root->left == nullptr){
                root = root->right;
            }else if(root->right == nullptr){
                root = root->left;
            }
            delete cur;
        }else if (root->degree() == 2){
            std::vector<TreeNode*> inorder_list;
            inorder(root->right, inorder_list);
            TreeNode *nex = inorder_list[0];

            int temp = nex->val;
            remove(temp); // temp对应的一定是一个叶节点, 度为0；

            root->val = temp;
        }
        return;
    }else{
        // 目标节点非根节点
        if (cur->degree() == 0){
            if (pre->left->val == num)
                pre->left = nullptr;
            else
                pre->right = nullptr;
            delete cur;
        }else if (cur->degree() == 1){
            if (pre->left->val == num)
                pre->left = (cur->left != nullptr) ? cur->left : cur->right;
            else
                pre->right = (cur->left != nullptr) ? cur->left : cur->right;
            delete cur;
        }else if (cur->degree() == 2){
            std::vector<TreeNode *> inorder_list;
            inorder(cur->right, inorder_list);
            TreeNode *nex = inorder_list[0];

            int temp = nex->val;
            remove(temp);

            cur->val = temp;
        }
        return;
    }
}

void BST::inorder(TreeNode* node, std::vector<TreeNode*> &result){
    if (node == nullptr)
        return;
    
    inorder(node->left, result);
    result.push_back(node);
    inorder(node->right, result);
}