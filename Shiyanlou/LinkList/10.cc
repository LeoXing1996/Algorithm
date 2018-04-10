#include<iostream>
#include"LinkList.h"
using namespace std;

class Solution{
public:
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        ListNode * nhead = new ListNode(0);
        nhead->next = head;
        ListNode * r = nhead;
        ListNode * p;
        ListNode * q;
        for(int i=0; i<m-1; ++i) r = r->next;
        p = r->next;
        q = p->next;
        for(int i=m; i<n; ++i) {
            p->next = q->next;
            q->next = r->next;
            r->next = q;
            q = p->next;
        }
        return nhead->next;
    }
};

int main (){
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    node1.next = &node2;
    node2.next = &node3;
    
    Solution sol;
    ListNode * n = sol.reverseBetween(&node1,1,1);
    return 0;
}