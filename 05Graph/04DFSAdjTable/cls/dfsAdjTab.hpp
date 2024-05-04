#include "adjTable.hpp"
#include <vector>

#ifndef _BFS_ADJ_TABLE_H
#define _BFS_ADJ_TABLE_H

void dfsAdjTable(GraphAdjTable &G, std::set<int> &visited, std::vector<int> &result, int startVetex);
#endif