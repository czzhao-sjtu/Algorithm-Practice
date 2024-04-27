#include <vector>
#ifndef _TRACKBACK_H
#define _TRACKBACK_H

bool isSolution(std::vector<int> &state, int target);
void recordSolution(std::vector<int> &state,
                    std::vector<std::vector<int>> &result);
bool isValid(std::vector<int> &state, 
             int choice, 
             int target);
void makeChoice(std::vector<int> &state, 
                int choice);
void undoChoice(std::vector<int> &state);

void trackback(std::vector<int> &state, 
               std::vector<int> &choices, 
               int target, 
               int start,
               std::vector<std::vector<int>> &result);
 
#endif