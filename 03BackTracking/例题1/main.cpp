#include "preOrder/preOrder.h"
#include <vector>
#include <iostream>

using namespace std;

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

    vector<TreeNode*> result;
    int target = 7;
    preOrder(&root, target, &result);

    for (int idx=0; idx < result.size(); idx++){
        cout << "Addr: " << result[idx] << "  Value: " << result[idx]->val << endl;
    }
    return 0;
}