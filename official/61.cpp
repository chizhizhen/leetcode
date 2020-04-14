#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 双指针，快慢指针法
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }
        int mod = k%n;
        if (mod == 0) return head;
        
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < mod; i++) {
            if (fast) {
                fast = fast->next;
            }
        }
        //这行很重要，可以取代mod==0那行
        if (!fast) return head;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        fast = slow->next;
        slow->next = NULL;
        return fast;
    }
    
    // 链表闭环，中间切开
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }
        cur->next = head;
        
        int mod = k%n;
        ListNode* p = head;
        for (int i = 0; i < n - mod - 1; i++) {
            p = p->next;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};
