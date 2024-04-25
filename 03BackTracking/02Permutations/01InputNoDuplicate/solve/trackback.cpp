#include "trackback.hpp"
#include <vector>

using namespace std;

void trackback(std::vector<int> &state, 
               std::vector<int> &choices, 
               std::vector<bool> &selected, 
               std::vector<std::vector<int>> &result){
    if (isSolution(state, choices)){
        recordSolution(state, result);
        return;
    }

    for(int idx = 0;idx < choices.size(); idx++){
        // 剪枝
        if (isValid(state, choices, selected, idx)){
            // 尝试
            makeChoice(state, choices[idx], selected, idx);
            trackback(state, choices, selected, result);
            // 回退
            undoChoice(state, choices[idx], selected, idx);
        }
    }
}

bool isSolution(std::vector<int> &state, 
                std::vector<int> &choices){
    return !choices.empty() && state.size() == choices.size(); 
}

void recordSolution(std::vector<int> &state,
                    std::vector<std::vector<int>> &result){
    result.push_back(state);
    return;
}

void makeChoice(std::vector<int> &state, 
                int choice, 
                std::vector<bool> &selected, 
                int idx){
    state.push_back(choice);
    selected[idx] = false;
    return;
}

void undoChoice(std::vector<int> &state, 
                int choice, 
                std::vector<bool> &selected, 
                int idx){
    state.pop_back();
    selected[idx] = true;
    return;
}

bool isValid(std::vector<int> &state, 
             std::vector<int> &choices, 
             std::vector<bool> &selected, 
             int idx){
    return selected[idx];
}