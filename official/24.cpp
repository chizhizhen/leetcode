#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {};
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {    
        ListNode* pre = new ListNode(0);
        ListNode* root = pre;
        root->next = head;
        while (root->next != NULL && root->next->next != NULL) {
            ListNode* l1 = root->next;
            ListNode* l2 = l1->next;
            ListNode* l3 = l2->next;
            
            root->next = l2;
            l2->next = l1;
            l1->next = l3;
            root = l1;
        }
        return pre->next;
    }
};
