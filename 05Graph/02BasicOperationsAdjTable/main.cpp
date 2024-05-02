#include "cls/adjTable.hpp"
#include <vector>
#include <iostream>

int main(){
    std::vector<int> V = {1, 3, 2, 5 ,4};
    std::vector<std::vector<int>> E = {{1, 3}, 
                                       {1, 5}, 
                                       {3, 2}, 
                                       {2, 5}, 
                                       {4, 5}, 
                                       {2, 4}};
    
    GraphAdjTable G(V, E);
    G.print();
    std::cout << std::endl;


    G.addEdge(1, 4);
    G.print();
    std::cout << std::endl;

    G.deleteEdge(1, 4);
    G.print();
    std::cout << std::endl;

    G.addVertex(6);
    G.print();
    std::cout << std::endl;

    G.deleteVertex(5);
    G.print();
    std::cout << std::endl;

    G.addEdge(1, 6);
    G.print();
    std::cout << std::endl;

    G.addEdge(2, 6);
    G.print();
    std::cout << std::endl;
    return 0;
}
