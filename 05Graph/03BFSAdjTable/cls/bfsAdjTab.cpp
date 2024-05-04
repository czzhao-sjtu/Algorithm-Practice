#include "bfsAdjTab.hpp"
#include <vector>
#include <queue>
#include <set>

std::vector<int> bfsAdjTable(GraphAdjTable &G, int startVetex){
    std::vector<int> res;
    std::queue<int> que;
    que.push(startVetex);
    std::set<int> visited = {startVetex};

    while (!que.empty()){
        int vet = que.front();
        que.pop();
        res.push_back(vet);
        for (const auto &sub_vet: G.adjtab[vet]){
            if (visited.count(sub_vet) != 1){
                que.push(sub_vet);
                visited.insert(sub_vet);
            }
        }
    }

    return res;
}