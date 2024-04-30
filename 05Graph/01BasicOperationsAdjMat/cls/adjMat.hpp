#include <vector>

#ifndef _ADJMAT_H
#define _ADJMAT_H

class GraphAdjMat{
    std::vector<int> vertices; 
    std::vector<std::vector<int>> adjMat;
    void printAdjMat();
    void printVertices();

    public: 
        GraphAdjMat(const std::vector<int> &vertices, const std::vector<std::vector<int>> &edges);

        int size() const; 
        void addVertex(int val);
        void addEdge(int val_i, int val_j);
        void deleteVertex(int val);
        void deleteEdge(int val_i, int val_j);
        void print();
};

#endif