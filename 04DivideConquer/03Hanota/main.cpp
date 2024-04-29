#include "solve/hanota.hpp"
#include <vector>
#include <utility>
#include <iostream>

int main(){
    std::vector<std::pair<char, char>> path;
    f(4, 'A', 'B', 'C', path);
    print_result(path);
}