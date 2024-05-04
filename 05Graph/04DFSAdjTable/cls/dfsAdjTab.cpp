#include "dfsAdjTab.hpp"
#include "adjTable.hpp"
#include <vector>
#include <queue>
#include <set>

void dfsAdjTable(GraphAdjTable &G, std::set<int> &visited, std::vector<int> &result, int startVetex){
    result.push_back(startVetex);

    for (const auto &sub_vet: G.adjtab[startVetex]){
        if (visited.count(sub_vet) != 1){
            visited.insert(sub_vet);
            dfsAdjTable(G, visited, result, sub_vet);
        }
    }
    return;
}