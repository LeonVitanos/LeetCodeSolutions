// Given a string s, return the longest palindromic substring in s.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string longest_palindrome;

class Solution {
public:
    string longestPalindrome(string s) {
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
                
                cout << temp;

                // Check if substring is palindromic
                bool flag=true;
                for(int j=0; j<temp_size/2; j++){
                    cout << "     " << temp[j] << " and " << temp[temp_size-j-1] << endl;
                    
                    if(temp[j]!=temp[temp_size-j-1]){ // Not palindromic
                        flag=false;
                        break;
                    }
                }

                cout << "   " << flag << endl;

                // If palindromic and bigger than already found, update
                if(flag && substring.length()-k>longest_palindrome.length()){
                    longest_palindrome.clear();
                    for (char c: s){
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
            for (int i=1; i<size; i++){
                temp.push_back(s[i]);
            }
            substring.clear();
            substring=temp;
        }


        // // Search by removing from left
        // string temp;
        // for (int i=1; i<size; i++){
        //     temp.push_back(s[i]);
        // }
        // longestPalindrome(temp);

        // // Search by removing from the right
        // temp.clear();
        // for (int i=0; i<size-1; i++){
        //     temp.push_back(s[i]);
        // }
        // longestPalindrome(temp);

        // Search by removing from both left and right

        // for (char c: s) {
        //     cur_palindrome.push_back(c);
        //             std::cout << "l = { ";
        //     for (char n : cur_palindrome) {
        //         std::cout << n << ", ";
        //     }
        //     std::cout << "};\n";

        //     // check if vector is palindrome
        //     bool pal = true;
        //     auto size = cur_palindrome.size();
        //     for(int i=0; i<cur_palindrome.size()/2; i++){
        //         cout << cur_palindrome[i] << " and " << cur_palindrome[size-i-1] << endl;
                
        //         if(cur_palindrome[i]!=cur_palindrome[size-i-1]){ // Not palindromic
        //             pal=false;
        //             break;
        //         }
        //     }

        //     if(pal && cur_palindrome.size()>longest_palindrome.length()){
        //         longest_palindrome.clear();
        //         for (char c: cur_palindrome){
        //             longest_palindrome.push_back(c);
        //         }
        //     }


            // bool pal = true;
            // while (pal){
            //     auto size = cur_palindrome.size();
            //     for(int i=0; i<cur_palindrome.size()/2; i++){
            //         cout << cur_palindrome[i] << " and " << cur_palindrome[size-i-1] << endl;
                    
            //         if(cur_palindrome[i]!=cur_palindrome[size-i-1]){ // Not palindromic
            //             pal = false;
            //             cur_palindrome.erase(cur_palindrome.begin());
            //             if(cur_palindrome.size()>longest_palindrome.length()){
            //                 longest_palindrome.clear();
            //                 for (char c: cur_palindrome){
            //                     longest_palindrome.push_back(c);
            //                 }
            //             }
            //             break;
            //         }
            //     }
            //     break;
            // }

            // if (itr != previous_chars.end()){
            //     std::vector<int> y(itr+1, previous_chars.end());
            //     previous_chars.clear();
            //     for (int i=0; i<y.size(); i++)
            //         previous_chars.push_back(y[i]);

            //     count = previous_chars.size();
            // }
            
            // count++;
            // if (count>max)
            //     max = count;

            // Print out the list
            // std::cout << "l = { ";
            // for (char n : cur_palindrome) {
            //     std::cout << n << ", ";
            // }
            // std::cout << "};\n";
       // }

    return longest_palindrome;
    } 
};

int main() {
    Solution myObj;
    cout << myObj.longestPalindrome("babad") << endl;
    //cout << myObj.longestPalindrome("cbbd") << endl;
}

