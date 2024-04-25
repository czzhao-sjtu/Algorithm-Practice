#include "preOrder/preOrder.h"
#include <vector>
#include <iostream>

using namespace std;

void print_path(vector<TreeNode*> &path){
    for (int idx = 0; idx < path.size(); idx++){
        if (idx == 0) 
            cout << path[idx]->val;
        else 
            cout << " -> " << path[idx]->val;
    }
    cout << endl;
}

int main(){
    // 构建测试用例
    TreeNode root(1);
    TreeNode left1(7);
    TreeNode right1(3);
    TreeNode left11(4);
    TreeNode left12(5);
    TreeNode right11(6);
    TreeNode right12(7);
    root.left = &left1;
    root.right = &right1;
    left1.left = &left11;
    left1.right = &left12;
    right1.left = &right11;
    right1.right = &right12;

    vector<vector<TreeNode*>> result;
    vector<TreeNode*> path;
    int target = 7;
    preOrder(&root, target, path, result);

    for (int idx=0; idx < result.size(); idx++){
        path = result[idx];
        print_path(path);
    }
    return 0;
}