#include "trackback.hpp"
#include <vector>
#include <numeric>

using namespace std;

bool isSolution(std::vector<int> &state, int target);
void makeChoice(std::vector<int> &state, 
                int choice);
void undoChoice(std::vector<int> &state);
bool isValid(std::vector<int> &state, 
             int choice, 
             int target, 
             std::vector<int> &choices, 
             int idx);

void trackback(std::vector<int> &state, 
               std::vector<int> &choices, 
               int target, 
               int start,
               std::vector<std::vector<int>> &result){
    if (isSolution(state, target)){
        recordSolution(state, result);
        return;
    }

    for(int idx = start;idx < choices.size(); idx++){
        // 剪枝
        if (isValid(state, choices[idx], target, choices, idx)){
            // 尝试
            makeChoice(state, choices[idx]);
            trackback(state, choices, target, idx + 1, result);
            // 回退
            undoChoice(state);
        };
    }

    return;
}

bool isSolution(std::vector<int> &state, 
                int target){
    return !state.empty() && std::accumulate(state.begin(), state.end(), 0) == target;
}

void recordSolution(std::vector<int> &state,
                    std::vector<std::vector<int>> &result){
    result.push_back(state);
}
void makeChoice(std::vector<int> &state, 
                int choice){
    state.push_back(choice);
}

void undoChoice(std::vector<int> &state){
    state.pop_back();
}

bool isValid(std::vector<int> &state, 
             int choice, 
             int target, 
             std::vector<int> &choices, 
             int idx){
    return (std::accumulate(state.begin(), state.end(), 0) + choice <= target) && // 保证state中元素加上choice后小于等于target
           ((idx != 0 && choices[idx - 1] != choices[idx]) || idx == 0); // 保证在当前轮中元素不重复
}