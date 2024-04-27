#include "solve/trackback.hpp"
#include <vector>
#include <iostream>

void print_result(std::vector<std::vector<int>> &result){
    for (auto &state: result){
        for (int idx = 0; idx < state.size(); idx++){
            using namespace std;
            if (idx == 0){
                cout << "[" << state[idx] << " ,";
            }else if(idx == state.size() - 1){
                cout << state[idx] << "]" << endl;
            }else{
                cout << state[idx] << ", ";
            }
        }
    }
}

int main(){
    std::vector<int> choices = {0, 1, 2, 3};
    std::vector<int> state;
    std::vector<std::vector<int>> result;

    std::vector<bool> selected_col(choices.size(), false);
    std::vector<bool> selected_principle(choices.size() - 1, false);
    std::vector<bool> selected_counter(choices.size() - 1, false);
    trackback(state, choices, 0, selected_col, selected_principle, selected_counter, result);
    print_result(result);
}