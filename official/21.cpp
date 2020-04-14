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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;
        else {
            if (l1->val <= l2->val) {
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            }
            else {
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
    }

    ListNode* mergeTwoLists2(ListNode* p1, ListNode* p2) {
        ListNode dummy(-1),*root=&dummy;
        while(p1!=NULL&&p2!=NULL){
            if(p1->val<p2->val){
                root->next=p1;
                p1=p1->next;
            }
            else{
                root->next=p2;
                p2=p2->next;
            }
            root=root->next;
        }
        if(p1==NULL) root->next=p2;
        else root->next=p1;
        return dummy.next;
    }
};

int main(int argc, char* argv[]) {
    string s = "()[]{}";
    
    Solution solution;
    bool out = solution.isValid(s);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
