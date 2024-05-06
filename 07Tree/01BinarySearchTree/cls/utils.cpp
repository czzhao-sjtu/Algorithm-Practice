#include "utils.hpp"
#include "BST.hpp"
#include <vector>

void print_vector_TreeNode(std::vector<TreeNode*> vec){
    std::vector<TreeNode*>::iterator iter;
    int size = vec.size();
    int i;
    if (size == 0){
        std::cout << "()" << std::endl;
    }else if (size == 1){
        std::cout << "(" << (*(vec.begin()))->val << ")" << std::endl;
    }else{
        for(i = 0, iter = vec.begin(); 
            iter != vec.end(); 
            iter++, i++){
            if (i == 0){
                std::cout << "(" << (*(iter))->val << ",";
            }else if(i == size - 1){
                std::cout << " " << (*(iter))->val << ")"<< std::endl;
            }else{
                std::cout << " " << (*(iter))->val << ",";
            }
        }
    }
}