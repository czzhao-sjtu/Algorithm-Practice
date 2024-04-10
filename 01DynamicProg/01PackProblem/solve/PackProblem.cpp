#include "PackProblem.h"

tuple<vector<int>, int> maxValues(vector<int> values, vector<int> weights, int maxCapacity){
    const int W = maxCapacity + 1;
    const int N = values.size();
    vector<vector<int>> matrix(W, vector<int>(N, 0));
    vector<vector<bool>> ifReserved(W, vector<bool>(N, false));

    //initialization
    for (int i = 1; i <= maxCapacity; i++){
        int current_capacity = i; 
        if (current_capacity >= weights[0]) {
            matrix[i][0] = values[0];
            ifReserved[i][0] = true;
        }else {
            matrix[i][0] = 0;}
    }

    //计算最大值
    for (int i = 1; i < W; i++){
        for (int j = 1; j < values.size() + 1; j++){
            int value_wo_j = matrix[i][j - 1];
            int value_w_j = (i - weights[j] < 0) ? 0 : matrix[i - weights[j]][j-1] + values[j];

            if (value_wo_j > value_w_j)
                matrix[i][j] = value_wo_j;
            else{
                matrix[i][j] = value_w_j;
                ifReserved[i][j] = true;
            }
        }
    }

    //TraceBack
    vector<int> reservedItems;
    int i = maxCapacity;
    int j = values.size() - 1;
    while ( i > 0 && j >= 0 ){
        if (ifReserved[i][j]) {
            reservedItems.push_back(j);
            i = i - weights[j];
            j = j - 1;
        }else{
            j = j - 1;
        }
    }
    return make_tuple(reservedItems, matrix[W-1][N-1]);
}