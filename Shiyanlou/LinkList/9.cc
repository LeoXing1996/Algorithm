#include<iostream>
#include"LinkList.h"

using namespace std;

class Solution{
public:
    ListNode * reverse(ListNode * head) {
        if(!head || !(head->next)) return head;
        ListNode * p = head->next;
        ListNode * q;
        head->next = NULL;
        while(p){
            q = p->next;
            p->next = head;
            head = p;
            p = q;
        }
        return head;
    }
};

int main(){
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    node1.next = &node2;
    node2.next = &node3;
    
    Solution sol;
    ListNode * n = sol.reverse(&node1);
    return 0;
}