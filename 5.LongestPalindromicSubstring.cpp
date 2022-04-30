// Given a string s, return the longest palindromic substring in s.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string longest_palindrome;
        auto size = s.size();     

        string substring = s;
        for (int i=0; i<size; i++){
            for(int k=0; k<substring.size(); k++){
                
                // We remove from right
                string temp;
                for(int l=0; l<substring.size()-k; l++){
                    temp.push_back(substring[l]);
                }
                auto temp_size = temp.size();
                
                // Check if substring is palindromic
                bool flag=true;
                for(int j=0; j<temp_size/2; j++){                    
                    if(temp[j]!=temp[temp_size-j-1]){ // Not palindromic
                        flag=false;
                        break;
                    }
                }

                // If palindromic and bigger than already found, update
                if(flag && substring.length()-k>longest_palindrome.length()){
                    longest_palindrome.clear();
                    for (char c: temp){
                        longest_palindrome.push_back(c);
                    }
                }
            }

            // Terminate if only one char
            if(substring.size()==1){
                if(longest_palindrome.empty())
                    longest_palindrome=substring;
                break;
            }

            // Remove most left character
            string temp;
            for (int i=1; i<substring.size(); i++){
                temp.push_back(substring[i]);
            }
            substring.clear();
            substring=temp;
        }
    return longest_palindrome;
    } 
};

int main() {
    Solution myObj;
    cout << myObj.longestPalindrome("babad") << endl;
    cout << myObj.longestPalindrome("cbbd") << endl;
}

