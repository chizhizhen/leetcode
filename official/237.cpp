#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
}

class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next) {
            ListNode* temp = node->next;
            int val = temp->val;
            if (val == ?) {
                node->next = temp->next;
            }
        }
    }
}
