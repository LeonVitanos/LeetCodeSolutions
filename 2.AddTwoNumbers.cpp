#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode temp{0};       
        auto curr = &temp;
        
        while (l1 || l2 || carry){
            int val = carry + (l1? l1->val : 0) + (l2? l2->val : 0);
            curr->next = new ListNode(val % 10);
            carry = val/10;
            
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            curr = curr->next;
        }
        
        return temp.next;
    }
};

int main() {
}