class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* psrc = head;
        ListNode* pdst = head;
        for (int i = 0; i < n; i++) {
            pdst = pdst->next;
        }
        if (pdst == NULL) return head->next;//删除第一个节点
        while (pdst->next) {
            pdst = pdst->next;
            psrc = psrc->next;
        }
        psrc->next = psrc->next->next;
        return head;
    }
};
