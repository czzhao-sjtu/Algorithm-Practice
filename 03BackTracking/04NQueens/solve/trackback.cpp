#include "trackback.hpp"
#include <vector>
#include <numeric>

using namespace std;

void trackback(std::vector<int> &state, 
               std::vector<int> &choices, 
               int row,
               std::vector<bool> &selected_col, 
               std::vector<bool> &selected_principle, 
               std::vector<bool> &selected_counter, 
               std::vector<std::vector<int>> &result){
    if (isSolution(state, choices)){
        recordSolution(state, result);
        return;
    }

    for (int choice: choices){
        if (isValid(choice, row, selected_col, selected_principle, selected_counter)){
            makeChoice(state, row, choice, selected_col, selected_principle, selected_counter);
            trackback(state, choices, row + 1, selected_col, selected_principle, selected_counter, result);
            undoChoice(state, row, choice, selected_col, selected_principle, selected_counter);
        }
    }

    return;
}

bool isSolution(std::vector<int> &state, 
                std::vector<int> &choices){
    return state.size() == choices.size();
}

void recordSolution(std::vector<int> &state,
                    std::vector<std::vector<int>> &result){
    result.push_back(state);
}

bool isValid(int choice, int row, 
             std::vector<bool> &selected_col, 
             std::vector<bool> &selected_principle, 
             std::vector<bool> &selected_counter){
    int col = choice; 
    const int num_ele = selected_col.size();
    const int principle_idx = col - row + (num_ele - 1);
    const int counter_idx = col + row;
    return !(selected_col[col] || selected_principle[principle_idx] || selected_counter[counter_idx]);
}

void makeChoice(std::vector<int> &state, 
                int row, 
                int choice, 
                std::vector<bool> &selected_col, 
                std::vector<bool> &selected_principle, 
                std::vector<bool> &selected_counter 
){
    state.push_back(choice);

    int col = choice; 
    const int num_ele = selected_col.size();
    const int principle_idx = col - row + (num_ele - 1);
    const int counter_idx = col + row;
    selected_col[col] = true;
    selected_principle[principle_idx] = true; 
    selected_counter[counter_idx] = true;
}

void undoChoice(std::vector<int> &state, 
                int row, 
                int choice, 
                std::vector<bool> &selected_col, 
                std::vector<bool> &selected_principle, 
                std::vector<bool> &selected_counter 
){
    state.pop_back();

    int col = choice; 
    const int num_ele = selected_col.size();
    const int principle_idx = col - row + (num_ele - 1);
    const int counter_idx = col + row;
    selected_col[col] = false;
    selected_principle[principle_idx] = false; 
    selected_counter[counter_idx] = false;
}