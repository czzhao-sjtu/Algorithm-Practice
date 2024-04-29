#include <iostream>
#include <vector>
#include <utility>
#include "hanota.hpp"

void f(int n, char src, char buffer, char tgt, std::vector<std::pair<char, char>> &path){
    if (n <= 0) return; // 无效的情况
    else if (n == 1) { // 最小问题
        path.push_back(std::pair<char, char>(src, tgt));
        return;
    }

    // n >= 2
    f(n-1, src, tgt, buffer, path);
    f(1, src, buffer, tgt, path);
    f(n-1, buffer, src, tgt, path);
}

void print_result(std::vector<std::pair<char, char>> &result){
    for (int idx = 0; idx < result.size(); idx++){
        std::cout << result[idx].first << " -> " << result[idx].second << std::endl;
    }
}