# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};


list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}


list_node * merge_list(list_node * head1, list_node * head2)
{
    //////在下面完成代码
    list_node* root = new list_node();
    list_node* dumm = root;
    while(head1->next != NULL && head2->next != NULL) {
        if (head1->val < head2->val) {
            dumm->next = head1;
            head1 = head1->next;
        } else {
            dumm->next = head2;
            head2 = head2->next;
        }
        dumm = dumm->next;
    }
    if (head1->next != NULL) dumm->next = head1;
    else if (head2->next != NULL) dumm->next = head2;
    return root->next;
}


void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}


int main ()
{
    list_node * head1 = input_list();
    list_node * head2 = input_list();
    list_node * new_head = merge_list(head1, head2);
    print_list(new_head);
    return 0;
}
