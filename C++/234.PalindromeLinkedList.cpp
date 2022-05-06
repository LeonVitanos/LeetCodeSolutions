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

bool isPalindrome(ListNode* head)
    {
        //Find middle node
        ListNode *p1=head, *p2=head;
        
        while (p2 && p2->next){
            p1 = p1->next;
            p2 = p2->next->next;
        }

        ListNode* pMid = p1;

        //Reverse List starting from middle node
        ListNode *prev = NULL;
        
        while(p1) {
            ListNode* temp = p1->next;
            p1->next = prev;
            prev = p1;
            p1 = temp;
        }

        //Check if two linked lists are the same, thus palindrome
            //Infinite foor loop, similar to while
        for(;head!=pMid; head=head->next, prev=prev->next) {
            if (head->val != prev->val) {
                return false;
            }
        }
        return true;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    cout << (isPalindrome(head) ? "true\n" : "false\n");
    return 0;
}