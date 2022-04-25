// Given a string s, find the length of the longest substring without repeating characters.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int count = 0;
        vector<char> previous_chars;
        for (char c: s) {
            auto itr = find(previous_chars.begin(), previous_chars.end(), c);
            std::vector<char> temp;

            if (itr != previous_chars.end()){
                std::vector<int> y(itr+1, previous_chars.end());
                previous_chars.clear();
                for (int i=0; i<y.size(); i++)
                    previous_chars.push_back(y[i]);

                count = previous_chars.size();
            }
            
            previous_chars.push_back(c);
            count++;
            if (count>max)
                max = count;

            // Print out the list
            // std::cout << "l = { ";
            // for (char n : previous_chars) {
            //     std::cout << n << ", ";
            // }
            // std::cout << "};\n";
        }

    return max;
    } 
};

int main() {
    Solution myObj;
    cout << myObj.lengthOfLongestSubstring("abcabefbcbb") << endl;
    cout << myObj.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << myObj.lengthOfLongestSubstring("bbbbb") << endl;
    cout << myObj.lengthOfLongestSubstring("pwwkew") << endl;
}