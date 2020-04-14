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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (size == 0) return NULL;
        if (size == 1) return lists[0];
        vector<ListNode*>& lists;
        ListNode* tmp = lists[0];
        for (int i = 1; i < size; i++) {
            tmp = merge2Lists(tmp, lists[i]);
        }
        return tmp;
    }
private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* root = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                root->next = l1;
                l1 = l1->next;
            } else {
                root->next = l2;
                l2 = l2->next;
            }
            root = root->next;
        }
        if (l1 == NULL) root->next = l2;
        else root->next = l1;
        return head->next; //这里很关键，不能直接return root，因为root已经指到最后了，这就是定义head的原因。
    }
};
