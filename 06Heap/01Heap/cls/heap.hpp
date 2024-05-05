#include <vector>
#include "utils.hpp"

#ifndef _HEAP_H
#define _HEAP_H
class maxHeap{
    private:
        std::vector<int> max_heap;
        void shift_up(int start_idx);
        void shift_down(int start_idx);
    public:
        maxHeap(std::vector<int> &nums);
        maxHeap();
        void push(int val);
        int pop();
        int peek();
        int size();
        bool isEmpty();
        void print();
};

#endif