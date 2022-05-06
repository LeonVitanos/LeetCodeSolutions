// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute force
        vector<int>::iterator iter, iter2;
        int i = 1;

        for (iter = nums.begin(); iter != nums.end(); ++iter) {
            for (iter2 = nums.begin() + i; iter2 != nums.end(); ++iter2) {
                cout << *iter << *iter2 << "  ";
                if (*iter+*iter2==target)
                    return {(int) (&*iter - &nums[0]), (int) (&*iter2 - &nums[0])};
            }
            i++;
        }

        return {0,0};
    }
};

int main() {
    Solution myObj;
    vector<int> vec = {2,7,11,15};
    vector<int> output = myObj.twoSum(vec, 9);
    cout << '[' << output[0] << ',' << output[1] << ']' << endl;

    vec = {3, 2, 4};
    output = myObj.twoSum(vec, 6);
    cout << '[' << output[0] << ',' << output[1] << ']' << endl;

    vec = {3,3};
    output = myObj.twoSum(vec, 6);
    cout << '[' << output[0] << ',' << output[1] << ']' << endl;
}