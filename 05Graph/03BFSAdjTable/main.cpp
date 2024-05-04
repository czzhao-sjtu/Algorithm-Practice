#include "cls/adjTable.hpp"
#include "cls/bfsAdjTab.hpp"
#include "cls/utils.hpp"
#include <vector>
#include <iostream>

int main(){
    std::vector<int> V = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<std::vector<int>> E = {{0, 1}, 
                                       {0, 3}, 
                                       {1, 2}, 
                                       {1, 4}, 
                                       {3, 4}, 
                                       {3, 6},
                                       {2, 5}, 
                                       {4, 5}, 
                                       {4, 7},
                                       {6, 7}, 
                                       {5, 8},
                                       {7, 8}};
    
    GraphAdjTable G(V, E);
    G.print();
    std::cout << std::endl;

    std::vector<int> res = bfsAdjTable(G, 0);
    print_vector_int(res);

    // G.addEdge(1, 4);
    // G.print();
    // std::cout << std::endl;

    // G.deleteEdge(1, 4);
    // G.print();
    // std::cout << std::endl;

    // G.addVertex(6);
    // G.print();
    // std::cout << std::endl;

    // G.deleteVertex(5);
    // G.print();
    // std::cout << std::endl;

    // G.addEdge(1, 6);
    // G.print();
    // std::cout << std::endl;

    // G.addEdge(2, 6);
    // G.print();
    // std::cout << std::endl;
    // return 0;
}
