#include<iostream>

using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->next = NULL;
        this->val = val;
    }
};
class Solution{
public:
    ListNode* partition(ListNode* head, int x){
        ListNode Head(0);
        
        ListNode* new_head = &Head;
        new_head->next = head;
        
        ListNode* piv = head;
        ListNode* low = head;
        ListNode* high;
        // 找到第一个等于x的数
        while(piv && piv->val != x){
            piv = piv->next;
        }
        
        if(piv) high = piv->next;
        else return head; 
        
        while(low != piv){
            if(low->val>=x){ //后移
                if(low == new_head->next) new_head->next = low->next;
                ListNode * temp = low->next;
                low->next = piv->next;
                piv->next = low;
                low = temp;
            }else low = low -> next;
        }
        ListNode * rear = piv;
        ListNode * r = new_head;
        while(high){
            if(high->val < x){
                ListNode* temp = high->next;
                high->next = r->next;
                r->next = high;
                high = temp;
                piv->next = high;
                r = r->next;
            } else {
                high = high->next;
                piv =piv->next;
            }
        }
        return new_head->next;
    }
    ListNode* partition2(ListNode* head, int x){
        ListNode head1(0);
        ListNode head2(0);
        ListNode *curr = head;
        ListNode *h1 = &head1;
        ListNode *h2 = &head2;
        ListNode *r1 = h1;
        ListNode *r2 = h2;
        // ListNode *rear = head;
        while(curr){
            ListNode* temp = curr->next;
            if(curr->val < x) {
                curr->next = r1->next;
                r1->next = curr;
                r1 = r1->next;
            } else {
                curr->next = r2->next;
                r2->next = curr;
                r2 = r2->next;
            }
            curr = temp;
        }
        r1->next = h2->next;
        return h1->next;
    }
};

int main(){
    ListNode head(1);
    ListNode frist(4);
    ListNode second(3);
    ListNode third(2);
    ListNode forth(5);
    ListNode fifth(2);
    head.next = &frist;
    frist.next = &second;
    second.next = &third;
    third.next = &forth;
    forth.next = &fifth;
    Solution sol;
    ListNode* new_head;
    new_head = sol.partition2(&head ,3);
    return 0;
}