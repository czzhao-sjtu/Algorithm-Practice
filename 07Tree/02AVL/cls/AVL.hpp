#include <vector>

#ifndef _BST_H_
#define _BST_H_
struct TreeNode
{
    // data
    int val{};
    int height = 0;
    TreeNode *left{};
    TreeNode *right{};

    // methods
    TreeNode() = default;
    explicit TreeNode(int x);

    // friend funcs
    friend int height(TreeNode *);
    friend void updateHeight(TreeNode*);
    friend int balanceFactor(TreeNode*);
    friend TreeNode *rightRotate(TreeNode *node);
    friend TreeNode *leftRotate(TreeNode *node);
    friend TreeNode *rotate(TreeNode *node);
};

int height(TreeNode *);
void updateHeight(TreeNode*);
int balanceFactor(TreeNode*);
TreeNode *rightRotate(TreeNode *node);
TreeNode *leftRotate(TreeNode *node);
TreeNode *rotate(TreeNode *node);

class AVL
{
    public:
    //data
    TreeNode *root{};

    //method
    AVL();
    TreeNode *search(int num);
    void insert(int num);
    void remove(int num);
    static void inorder(TreeNode *node, std::vector<TreeNode*> &result);
};

TreeNode *insertHelper(TreeNode *root, int val);
TreeNode *removeHelper(TreeNode *root, int val);
#endif