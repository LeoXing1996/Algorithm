#include<iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    ListNode * deleteDuplicates(ListNode * head) {
        // write your code here
        ListNode *p = head; //检查结点
        ListNode *q; //检查结点
        ListNode *r = head; //待拼接结点
        while(p && r->next){
            bool del = false;
            q = p->next;
            while(q!=NULL && q->val==p->val){
                del = true;
                ListNode* temp = q;
                q = q->next;
                p->next = q;
                delete(temp);
            }
            p = q;
            if(del) {
                if(r->next == p){
                    ListNode *temp = r;
                    r = p;
                    head = r;
                    delete(temp);
                }else{
                    delete(r->next);
                    r->next = p;
                }
            } else {
                if(r->next != p)
                    r = r->next;
            }
        }
        return head;
    }
};

int main(){
    ListNode head(1);
    ListNode first(1);
    ListNode second(2);
    ListNode third(2);
    ListNode forth(3);
    head.next = &first;
    first.next = &second;
    second.next = &third;
    third.next = &forth;
    Solution sol;
    ListNode*newhead =  sol.deleteDuplicates(&head);
    cout << newhead->val;
    return 0;
}