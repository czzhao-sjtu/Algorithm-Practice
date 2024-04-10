#include <iostream>
#include <vector>
#include <tuple>
#include <string.h>
#include <functional>
#include "solve/PackProblem.h"

using namespace std;

int main(){
    const int maxCapacity = 8;
    vector<int> values = {3, 4, 5, 6};
    vector<int> weights = {1, 2, 3, 4};

    vector<int> reservedItems; 
    int maxTotal;
    make_tuple(ref(reservedItems), ref(maxTotal))= maxValues(values, weights, maxCapacity);
    
    cout << "max total:" << maxTotal << endl;

    for (int i = 0; i < reservedItems.size(); i++){
        int idx = reservedItems[i];
        cout << idx << " value:" << values[idx] << " weight:" << weights[idx] << endl;
    }

    return 0;
}