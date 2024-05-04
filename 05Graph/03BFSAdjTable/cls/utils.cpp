#include "utils.hpp"

void print_vector_int(std::vector<int> vec){
    std::vector<int>::iterator iter;
    int size = vec.size();
    int i;
    if (size == 0){
        std::cout << "()" << std::endl;
    }else if (size == 1){
        std::cout << "(" << *(vec.begin()) << ")" << std::endl;
    }else{
        for(i = 0, iter = vec.begin(); 
            iter != vec.end(); 
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