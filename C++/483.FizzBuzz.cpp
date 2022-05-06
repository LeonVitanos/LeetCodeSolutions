// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;

        for(int i=1; i<=n; i++){
            if(i%5 == 0 && i%3 == 0)
                answer.push_back("FizzBuzz");
            else if (i%3 == 0)
                answer.push_back("Fizz");
            else if (i%5 == 0)
                answer.push_back("Buzz");
            else
                answer.push_back(to_string(i));
        }

        return answer;
    }
};

int main() {
    Solution myObj;
    vector<string> output = myObj.fizzBuzz(15);
    for (auto c: output)
        cout << c << " ";
}