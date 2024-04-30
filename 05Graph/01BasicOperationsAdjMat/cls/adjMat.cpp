#include "adjMat.hpp"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

void GraphAdjMat::addVertex(int val){
    if (std::find(vertices.begin(), vertices.end(), val) != vertices.end())
        return;
    
    vertices.push_back(val);

    for (auto &row: adjMat){
        row.push_back(0);
    }
    adjMat.push_back(std::vector<int>(vertices.size(), 0));
    return;
}

void GraphAdjMat::deleteVertex(int val){
    // 找到val在vertices中的下标
    int idx;
    auto iter = std::find(vertices.begin(), vertices.end(), val);
    if (iter == vertices.end()) return;
    else{
        idx = iter - vertices.begin();
    }
    // 将val从vertices中删除
    vertices.erase(vertices.begin() + idx);

    // 将val从adjmat中删除
    adjMat.erase(adjMat.begin() + idx);
    for (auto &row: adjMat){
        row.erase(row.begin() + idx);
    }

    return;
}

void GraphAdjMat::addEdge(int val_i, int val_j){
    // 找到两个边的下标
    int i, j;
    auto iter = std::find(this->vertices.begin(), this->vertices.end(), val_i);
    if (iter == this->vertices.end())
        throw std::out_of_range("节点不存在");
    else
        i = iter - this->vertices.begin();

    iter = std::find(this->vertices.begin(), this->vertices.end(), val_j);
    if (iter == this->vertices.end())
        throw std::out_of_range("节点不存在");
    else
        j = iter - this->vertices.begin();
    
    adjMat[i][j] = 1;
    adjMat[j][i] = 1;
}

void GraphAdjMat::deleteEdge(int val_i, int val_j){
    // 找到两个边的下标
    int i, j;
    auto iter = std::find(this->vertices.begin(), this->vertices.end(), val_i);
    if (iter == this->vertices.end())
        throw std::out_of_range("节点不存在");
    else
        i = iter - this->vertices.begin();

    iter = std::find(this->vertices.begin(), this->vertices.end(), val_j);
    if (iter == this->vertices.end())
        throw std::out_of_range("节点不存在");
    else
        j = iter - this->vertices.begin();

    adjMat[i][j] = 0;
    adjMat[j][i] = 0;
}

GraphAdjMat::GraphAdjMat(const std::vector<int> &vertices, 
                         const std::vector<std::vector<int>> &edges){
    for (auto vertex: vertices){
        addVertex(vertex);
    }

    for (const auto &edge: edges){
        addEdge(edge[0], edge[1]);
    }
}

void GraphAdjMat::printAdjMat(){
    // range-based loop
    for (int idx = 0; idx < adjMat.size(); idx++){
        auto &row = adjMat[idx];
        std::cout << vertices[idx] << ": ";
        for (auto& el : row) {
            std::cout << el << " ";}
        std::cout << "; " << std::endl;
    }
}

void GraphAdjMat::printVertices(){
    std::cout << "   ";
    for (auto &ele: vertices){
        std::cout << ele << " ";
    }
    std::cout << ";" << std::endl;
}

void GraphAdjMat::print(){
    std::cout << "Vertices:" << std::endl;
    printVertices();

    std::cout << "Adjacency Matrix:" << std::endl;
    printAdjMat();
}

int GraphAdjMat::size() const{
    return vertices.size();
}