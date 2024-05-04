#include <stdexcept>
#include <set>
#include <utility>
#include <iostream>
#include "adjTable.hpp"

void GraphAdjTable::addVertex(int val){
    if (adjtab.count(val) == 1)
        throw std::invalid_argument("顶点已存在");
    
    adjtab.insert(std::make_pair(val, std::set<int>()));
    return;
}

void GraphAdjTable::deleteVertex(int val){
    if (adjtab.count(val) == 1){
        std::vector<int> ele_to_delete;
        for (const auto &ele: adjtab[val]){
            ele_to_delete.push_back(ele);
        }

        for (const auto &ele: ele_to_delete){
            adjtab[ele].erase(val);
        }

        adjtab.erase(val);
        return;
    }else{
        throw std::invalid_argument("要删除的顶点不存在");
    }
}

void GraphAdjTable::addEdge(int val_i, int val_j){
    // 判断边的两个顶点是否存在
    if (adjtab.count(val_i) == 0 || adjtab.count(val_j) == 0){
        throw std::invalid_argument("边连接的顶点至少一个不存在");
    }

    // 在两个顶点各自的邻接表中添加彼此
    adjtab[val_i].insert(val_j);
    adjtab[val_j].insert(val_i);
    return;
}

void GraphAdjTable::deleteEdge(int val_i, int val_j){
    // 判断边的两个顶点是否存在
    if (adjtab.count(val_i) == 0 || adjtab.count(val_j) == 0){
        throw std::invalid_argument("边连接的顶点至少一个不存在");
    }

    // 判断两个顶点是否存在于彼此的邻接表中
    if (adjtab[val_i].count(val_j) == 0 || adjtab[val_j].count(val_i) == 0){
        throw std::invalid_argument("两个顶点至少一个存在于彼此的邻接表中");
    }

    // 删除
    adjtab[val_i].erase(val_j);
    adjtab[val_j].erase(val_i);
    return;
}

GraphAdjTable::GraphAdjTable(std::vector<int> &vertices, std::vector<std::vector<int>> &edges){
    for (const auto &vertex: vertices){
        addVertex(vertex);
    }

    for (const auto &edge: edges){
        addEdge(edge[0], edge[1]);
    }
    return;
}

void GraphAdjTable::print(){
    for (const auto &kv:adjtab){
        std::cout << kv.first;

        std::set<int>::iterator iter;
        int size = kv.second.size();
        int i;
        if (size == 0){
            std::cout << "()" << std::endl;
        }else if (size == 1){
            std::cout << "(" << *(kv.second.begin()) << ")" << std::endl;
        }else{
            for(i = 0, iter = kv.second.begin(); 
                iter != kv.second.end(); 
                iter++, i++){
                if (i == 0){
                    std::cout << "(" << *(iter)<< ",";
                }else if(i == size - 1){
                    std::cout << " " << *(iter) << ")"<< std::endl;
                }else{
                    std::cout << " " << *(iter) << ",";
                }
            }
        }
    }
    return;
}
