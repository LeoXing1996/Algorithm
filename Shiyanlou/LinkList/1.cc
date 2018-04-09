#include<iostream>

using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int val){
        this->val = val;
        this->next =NULL;
    }
};

class Solution{
public:
    ListNode * deleteDuplicates(ListNode * head) {
        // write your code here
        ListNode * p;
        ListNode * q = head;
        while(q){
            p = q->next;
            while(p != NULL && p->val == q->val) {
                ListNode * temp = p;
                p = p->next;
                delete(temp);
                q->next = p;
            }
            q = p;
        }
        return head;
    }
};

int main(){
    ListNode head(0);
    ListNode first(1);
    ListNode second(2);
    head.next = &first;
    first.next = &second;
    
    Solution sol;
    ListNode* newhead;
    newhead = sol.deleteDuplicates(&head);
    return 0;
}