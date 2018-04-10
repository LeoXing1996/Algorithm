#include<iostream>
#include "LinkList.h"
using namespace std;

class Solution{
public:
    bool hasCycle(ListNode* head){
        ListNode * quick;
        ListNode * slow ;
        if(head && head->next) {
             quick = head->next;
             slow = head;
        }else return false;
        while(quick && quick != slow){
            if(quick->next && quick->next->next) quick = quick->next->next;
            else return false;
            slow = slow->next;
        }
        return quick ? true : false;
    }
};

int main(){
    ListNode head(1);
    ListNode first(2);
    head.next = &first;
    Solution sol;
    cout << sol.hasCycle(&head);
    return 0;
}