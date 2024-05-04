#include "cls/adjTable.hpp"
#include "cls/dfsAdjTab.hpp"
#include "cls/utils.hpp"
#include <vector>
#include <iostream>
#include <set>

int main(){
    std::vector<int> V = {0, 1, 2, 3, 4, 5, 6};
    std::vector<std::vector<int>> E = {{0, 1}, 
                                       {0, 3}, 
                                       {1, 2}, 
                                       {2, 5}, 
                                       {4, 5},
                                       {5, 6}
                                       };
    
    GraphAdjTable G(V, E);
    G.print();
    std::cout << std::endl;

    std::vector<int> result;
    int startVetex = 0;
    std::set<int> visited = {0};

    dfsAdjTable(G, visited, result, startVetex);
    print_vector_int(result);
}
