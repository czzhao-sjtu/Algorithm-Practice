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
    std::vector<int> choices = {1, 1, 3};
    std::vector<bool> selected(choices.size(), true);
    std::vector<std::vector<int>> result;
    std::vector<int> state;

    trackback(state, choices, selected, result);
    print_result(result);
}