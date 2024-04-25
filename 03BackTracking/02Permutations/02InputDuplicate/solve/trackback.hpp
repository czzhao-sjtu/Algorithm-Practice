#include <vector>
#include <set>
#ifndef _TRACKBACK_H
#define _TRACKBACK_H

void trackback(std::vector<int> &state, 
               std::vector<int> &choices, 
               std::vector<bool> &selected, 
               std::vector<std::vector<int>> &result);

bool isSolution(std::vector<int> &state, 
                std::vector<int> &choices);
    
void recordSolution(std::vector<int> &state,
                    std::vector<std::vector<int>> &result);

void makeChoice(std::vector<int> &state, 
                int choice, 
                std::vector<bool> &selected, 
                int idx,
                std::set<int> &duplicated);

void undoChoice(std::vector<int> &state, 
                int choice, 
                std::vector<bool> &selected, 
                int idx);

bool isValid(std::vector<int> &state, 
             std::vector<int> &choices, 
             std::vector<bool> &selected, 
             int idx,
             std::set<int> &duplicated);
#endif