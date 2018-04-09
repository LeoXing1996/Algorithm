#include<iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

class Solution{
public:
    ListNode * addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode * newhead = new ListNode(0);
        ListNode * rear = newhead;
        ListNode * p1 = l1;
        ListNode * p2 = l2;
        bool high = false;
        bool curr = false;
        while(p1 && p2){
            int S = p1->val + p2->val;
            if(curr) S+=1;
            if(S>=10) high = true;   //进位
            else high = false;  //不进位

            ListNode * temp = new ListNode(S%10);
            temp->next = rear->next;
            rear->next = temp;
            rear = rear->next;
            curr = high;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1){
            int S = p1->val;
            if(curr) S+=1;  //进位
            if(S>=10) high = true;
            else high = false;

            ListNode * temp = new ListNode(S%10);
            temp->next = rear->next;
            rear->next = temp;
            rear = rear->next;
            curr = high;
            p1 = p1->next;
        }
        while(p2){
            int S = p2->val;
            if(curr) S+=1;  //进位
            if(S>=10) high = true;
            else high = false;

            ListNode * temp = new ListNode(S%10);
            temp->next = rear->next;
            rear->next = temp;
            rear = rear->next;
            curr = high;
            p2 = p2->next;
        }
        if(curr) {
            ListNode *temp = new ListNode(1);
            temp->next = rear->next;
            rear->next = temp;
            rear = rear->next;
        }
        return newhead->next;
    }
};

int main(){
    ListNode head1(9);
    ListNode frist1(9);
    ListNode second1(9);
    ListNode head2(1);
    // ListNode frist2(9);
    // ListNode second2(2);
    head1.next = &frist1;
    frist1.next = &second1;
    // head2.next = &frist2;
    // frist2.next = &second2;
    Solution sol;
    ListNode* new_head;
    new_head = sol.addTwoNumbers(&head1, &head2);
    return 0;
}