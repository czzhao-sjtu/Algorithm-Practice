#include <vector>
#include <utility>

#ifndef __BINARY_SEARCH_H
#define __BINARY_SEARCH_H

void f(int n, char src, char buffer, char tgt, std::vector<std::pair<char, char>> &path);

void print_result(std::vector<std::pair<char, char>> &path);
#endif