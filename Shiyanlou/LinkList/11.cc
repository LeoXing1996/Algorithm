#include<iostream>
#include"LinkList.h"
using namespace std;

class Solution {
public:
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        ListNode * nhead = new ListNode(0);
        ListNode * p = nhead;
        ListNode * p1 = l1;
        ListNode * p2 = l2;
        while(p1 && p2){
            ListNode * temp;
            if(p1->val < p2->val) {
                temp = p1->next;
                p->next = p1;
                p1->next = NULL;
                p1 = temp;
            } else {
                temp = p2->next;
                p->next = p2;
                p2->next = NULL;
                p2 = temp;
            }
            p = p->next;
        }
        if(p1) p->next = p1;
        if(p2) p->next = p2;
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
    return 0;
}