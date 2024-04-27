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
    std::vector<int> choices = {3, 4, 5};
    std::vector<int> state;
    int target = 9;
    std::vector<std::vector<int>> result;

    trackback(state, choices, target, 0, result);
    print_result(result);
}