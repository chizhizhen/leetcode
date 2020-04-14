#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* root = NULL;
        ListNode* tmp;
        while (head) {
            tmp = head->next;
            head->next = root;
            root = head;
            head = tmp;
        }
        return root;
    }
};
