#include <unordered_map>
#include <set>

#ifndef _ADJ_TABLE_H
#define _ADJ_TABLE_H
class GraphAdjTable
{
private:
    std::unordered_map<int, std::set<int>> adjtab;
    /* data */
public:
    GraphAdjTable(std::vector<int> &vertices, std::vector<std::vector<int>> &edges);
    void addVertex(int val);
    void deleteVertex(int val);
    void addEdge(int val_i, int val_j);
    void deleteEdge(int val_i, int val_j);
    void print();
};

#endif