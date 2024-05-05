#include "heap.hpp"

void maxHeap::push(int val){
    max_heap.push_back(val);
    shift_up(max_heap.size() - 1);
}

int maxHeap::pop(){
    int return_value = max_heap[0];
    int temp = max_heap.back(); 
    max_heap[max_heap.size() - 1] = max_heap[0];
    max_heap[0] = temp;

    max_heap.pop_back();
    shift_down(0);
    return return_value;
}

int maxHeap::size(){
    return max_heap.size();
}

int maxHeap::peek(){
    return max_heap[0];
}

bool maxHeap::isEmpty(){
    return max_heap.empty();
}

void maxHeap::shift_up(int start_idx){
    int child_idx = start_idx;
    int parent_idx = (child_idx - 1) / 2;
    while (parent_idx >= 0 && max_heap[parent_idx] < max_heap[child_idx]){
        int temp = max_heap[child_idx];
        max_heap[child_idx] = max_heap[parent_idx];
        max_heap[parent_idx] = temp;

        child_idx = parent_idx;
        parent_idx = (child_idx - 1) / 2;
    }
    return;
}

void maxHeap::shift_down(int start_idx){
    int root_idx = start_idx;
    int left_idx = 2 * root_idx + 1;
    int right_idx = 2 * root_idx + 2;

    while (true){
        // root_idx在最底层
        if (left_idx >= max_heap.size() && right_idx >= max_heap.size())
            break;

        // 完全二叉树只可能是最底层的右子节点不存在
        // 此情况则只考虑父节点 和 左子节点
        if (right_idx >= max_heap.size()){
            if (max_heap[root_idx] >= max_heap[left_idx])
                break;
            else{
                int temp = max_heap[left_idx];
                max_heap[left_idx] = max_heap[root_idx];
                max_heap[root_idx] = temp;
                break;
            }
        }

        // 存在完整的父节点、左右子节点
        if (max_heap[root_idx] >= max_heap[left_idx] && max_heap[root_idx] >= max_heap[right_idx])
            break;

        // 选择较大的子节点与父节点交换
        if (max_heap[left_idx] > max_heap[right_idx]){
            int temp = max_heap[left_idx];
            max_heap[left_idx] = max_heap[root_idx];
            max_heap[root_idx] = temp;

            root_idx = left_idx;
            left_idx = root_idx * 2 + 1;
            right_idx = root_idx * 2 + 2;
        }else{
            int temp = max_heap[right_idx];
            max_heap[right_idx] = max_heap[root_idx];
            max_heap[root_idx] = temp;

            root_idx = right_idx;
            left_idx = root_idx * 2 + 1;
            right_idx = root_idx * 2 + 2;
        }
    }
}

void maxHeap::print(){
    print_vector_int(max_heap);
    return;
}

maxHeap::maxHeap(std::vector<int> &nums):max_heap(nums){
    for (int idx = (size() - 2) / 2; idx >= 0; idx--){
        shift_down(idx);
    }
}

maxHeap::maxHeap(){}