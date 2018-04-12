#include<iostream>
#include"LinkList.h"

class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @return: nothing
     */
    void reorderList(ListNode * head) {
        if(!head || !(head->next) || !(head->next->next)) return ;
        int count = 0;
        ListNode * slow = head; //mid
        ListNode * quick = head;
        while(quick && quick->next){
            slow = slow->next;
            quick = quick->next->next;
        }
        // ListNode * rear = slow->next;
        ListNode * nhead = new ListNode(0);
        for(ListNode * pt = slow->next; pt; pt = slow->next){
            // ListNode * temp = pt->next;
            slow->next = pt->next;
            pt->next = nhead->next;
            nhead->next = pt;
        }
        for(ListNode * pt = nhead->next, * curr = head; pt; pt = nhead->next){
            nhead->next = pt->next;
            pt->next = curr->next;
            curr->next = pt;
            curr = pt->next;
        }
    }
};

int main(){
    ListNode node0(0);
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    // node3.next = &node4;
    Solution sol;
    sol.reorderList(&node0);
    return 0;
}