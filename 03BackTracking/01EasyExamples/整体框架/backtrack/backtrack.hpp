#include <vector>

#ifndef _BACKTRACK_H
#define _BACKTRACK_H

struct TreeNode
{
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int, TreeNode *, TreeNode*);
    TreeNode(int);
};

bool isSolution(std::vector<TreeNode*> &);

void recordSolution(std::vector<TreeNode*> &state, std::vector<std::vector<TreeNode*>> &res);

bool isValid(std::vector<TreeNode*> &state, TreeNode *choice);

void makeChoice(std::vector<TreeNode*> &state, TreeNode *choice);

void undoChoice(std::vector<TreeNode*> &state, TreeNode *choice);

std::vector<TreeNode*> nextChoice(std::vector<TreeNode*> &state);

void backtrack(std::vector<TreeNode*> &state, const std::vector<TreeNode*> &choices, std::vector<std::vector<TreeNode*>> &res);

#endif