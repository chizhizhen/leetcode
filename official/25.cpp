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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int d = 0;
        auto node = head;
        while (node != NULL) {
            if (++d >= k) break;
            node = node->next;
        }
        if (d < k) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        for (int i = 0; i < k; ++i) {
            auto node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = node;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
