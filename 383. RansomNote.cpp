// Given a string s, return the longest palindromic substring in s.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (char c: magazine){
            int n = ransomNote.size();
            for (int i=0; i<n; i++){
                if (ransomNote[i]==c){
                    ransomNote.erase(i, 1);
                    break;
                }
            }
        }
        return ransomNote.empty();
    }
};

int main() {
    Solution myObj;
    cout << myObj.canConstruct("a", "b") << endl;
    cout << myObj.canConstruct("aa", "ab") << endl;
    cout << myObj.canConstruct("aa", "aab") << endl;
}

