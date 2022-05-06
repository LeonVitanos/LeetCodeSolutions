#include <iostream>
#include <vector>

using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
    int max = 0;
    for (auto &customer: accounts){
        int total=0;
        for (auto & bank: customer){
            total += bank;
        }
        if(total>max){
            max=total;
        }
    }
    return max; 
}