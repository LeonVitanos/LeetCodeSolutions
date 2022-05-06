#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        char previous;
        for (char c: s) {
            switch (c) {
                case 'I':
                    total += 1;
                    break;
                case 'V':
                    if(previous=='I')
                        total += 3; // Not 4, because we also want to remove the I that was added. Same for the others.
                    else
                        total += 5;
                    break;
                case 'X':
                    if(previous=='I')
                        total += 8;
                    else
                        total += 10;
                    break;
                case 'L':
                    if(previous=='X')
                        total += 30;
                    else
                        total += 50;
                    break;
                case 'C':
                    if(previous=='X')
                        total += 80;
                    else
                        total += 100;
                    break;
                case 'D':
                    if(previous=='C')
                        total += 300;
                    else
                        total += 500;
                    break;
                case 'M':
                    if(previous=='C')
                        total += 800;
                    else
                        total += 1000;
                    break;
                }
            
            previous = c;
        }

        return total;
    }
};

int main() {
    Solution myObj;
    cout << myObj.romanToInt("III") << endl;
    cout << myObj.romanToInt("LVIII") << endl;
    cout << myObj.romanToInt("MCMXCIV") << endl;
}