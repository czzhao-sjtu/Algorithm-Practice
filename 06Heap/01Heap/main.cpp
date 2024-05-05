#include "cls/heap.hpp"
#include <iostream>
#include <vector>

int main(){
    maxHeap heap;

    heap.push(1);
    heap.push(3);
    heap.push(2);
    heap.push(5);
    heap.push(4);
    heap.push(100);

    heap.print();

    std::cout << "Pop all of the elements." << std::endl;
    while(heap.size() != 0){
        std::cout << heap.pop() << std::endl;
    }

    heap.push(1);
    std::cout << "Pop all of the elements." << std::endl;
    while(heap.size() != 0){
        std::cout << heap.pop() << std::endl;
    }

    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    maxHeap heap2(nums);
    std::cout << "Heap2:" << std::endl;
    heap2.print();
    while(heap2.size() != 0){
        std::cout << heap2.pop() << std::endl;
    }

    std::vector<int> nums3;
    for (int i = 0; i <= 100; i++){
        nums3.push_back(i);
    }
    maxHeap heap3(nums3);
    std::cout << "Heap3:" << std::endl;
    while(heap3.size() != 0){
        std::cout << heap3.pop() << std::endl;
    }
    return 0;
}