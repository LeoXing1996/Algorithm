#include<iostream>
#include"LinkList.h"
using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head || !(head->next)) return head;
        
        int size = 1;
        ListNode * pt = head;
        for(; pt->next; pt = pt->next) ++size;
        if(k % size == 0) return head;
        int first = size - k % size;
        
        // find last kth node
        ListNode * rear = head;
        ListNode * nhead = new ListNode(0);
        for(int i=1; i<first; ++i) rear = rear->next;
        nhead->next = rear->next;
        rear->next = NULL;
        pt->next = head;
        return nhead->next;
    }
};

int main(){

    return 0;
}