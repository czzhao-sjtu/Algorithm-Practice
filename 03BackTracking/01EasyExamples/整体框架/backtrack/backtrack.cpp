#include "backtrack.hpp"
#include <vector>

using namespace std;

TreeNode::TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right){
};

TreeNode::TreeNode(int val): val(val), left(nullptr), right(nullptr){};

bool isSolution(std::vector<TreeNode*> &state){
    return (!state.empty()) && state.back()->val == 7;
}

void recordSolution(std::vector<TreeNode*> &state, std::vector<std::vector<TreeNode*>> &res){
    res.push_back(state);
    return;
}

bool isValid(std::vector<TreeNode*> &state, TreeNode *choice){
    return choice != nullptr;
    // return choice != nullptr && choice->val != 3;
}

void makeChoice(std::vector<TreeNode*> &state, TreeNode *choice){
    state.push_back(choice);
}
 
void undoChoice(std::vector<TreeNode*> &state, TreeNode *choice){
    state.pop_back();
    return;
}

std::vector<TreeNode*> nextChoice(std::vector<TreeNode*> &state){
    std::vector<TreeNode*> next_choice{state.back()->left, state.back()->right};
    return next_choice;
}

void backtrack(std::vector<TreeNode*> &state, const std::vector<TreeNode*> &choices, std::vector<std::vector<TreeNode*>> &res){
    if (isSolution(state)){
        recordSolution(state, res);
        return;
    }

    for (TreeNode *choice: choices){
        if (isValid(state, choice)){
            makeChoice(state, choice);
            backtrack(state, nextChoice(state), res);
            undoChoice(state, choice);
        }
    }
}