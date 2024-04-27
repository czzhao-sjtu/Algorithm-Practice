#include <vector>
#ifndef _TRACKBACK_H
#define _TRACKBACK_H
void trackback(std::vector<int> &state, 
               std::vector<int> &choices, 
               int row,
               std::vector<bool> &selected_col, 
               std::vector<bool> &selected_principle, 
               std::vector<bool> &selected_counter, 
               std::vector<std::vector<int>> &result);

bool isSolution(std::vector<int> &state, 
                std::vector<int> &choices);

bool isValid(int choice, int row, 
             std::vector<bool> &selected_col, 
             std::vector<bool> &selected_principle, 
             std::vector<bool> &selected_counter);

void undoChoice(std::vector<int> &state, 
                int row, 
                int choice, 
                std::vector<bool> &selected_col, 
                std::vector<bool> &selected_principle, 
                std::vector<bool> &selected_counter 
);
void makeChoice(std::vector<int> &state, 
                int row, 
                int choice, 
                std::vector<bool> &selected_col, 
                std::vector<bool> &selected_principle, 
                std::vector<bool> &selected_counter 
);

void recordSolution(std::vector<int> &state,
                    std::vector<std::vector<int>> &result
);

#endif