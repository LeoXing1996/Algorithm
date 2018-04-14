#include<iostream>
#include"LinkList.h"
using namespace std;
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode * insertionSortList(ListNode * head) {
        // write your code here
        ListNode * nhead = new ListNode(0);
        nhead->next = head;
        ListNode * p1 = head;
        ListNode * p2 = head->next;
        while(p2){
            if(p2->val >= p1){
                p2 = p2->next;
                p1 = p1->next;
            } else {
                ListNode * temp = p2->next, * p = nhead;
                while(p->next->val < p2->val) p = p->next;
                p2->next = p->next;
                p->next = p2;
                p1->next = temp;
                p2 = temp;
            }
        }
        return nhead->next;
    }
};

int main(){
    return 0;
}