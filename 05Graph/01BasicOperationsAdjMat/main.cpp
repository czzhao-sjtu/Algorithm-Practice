#include "cls/adjMat.hpp"
#include <vector>

int main(){
    std::vector<int> V = {1, 3, 2, 5 ,4};
    std::vector<std::vector<int>> E = {{1, 3}, 
                                       {1, 5}, 
                                       {3, 2}, 
                                       {2, 5}, 
                                       {4, 5}, 
                                       {2, 4}};
    
    GraphAdjMat G(V, E);
    G.print();

    G.addEdge(1, 4);
    G.print();

    G.deleteEdge(1, 4);
    G.print();

    G.addVertex(6);
    G.print();

    G.deleteVertex(5);
    G.print();

    G.addEdge(1, 6);
    G.print();

    G.addEdge(2, 6);
    G.print();
    return 0;
}