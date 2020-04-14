/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}; */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pHead = new ListNode(0);
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p3 = pHead;
        int sum = 0;
        int div = 0;
        while (p1 != NULL || p2 != NULL) {
            int x = (p1 != NULL) ? p1->val:0;
            int y = (p2 != NULL) ? p2->val:0;
            sum = x + y + div;
            div = sum / 10;
            //这行重点。应该重新new一个ListNode给它指向
            p3->next = new ListNode (sum % 10);
            p3 = p3->next;
            if (p1 != NULL) p1 = p1->next;
            if (p2 != NULL) p2 = p2->next;
        }
        //这个临届也要考虑
        if (div > 0) {
            p3->next = new ListNode(div);
        }
        return pHead->next;
    }
};
