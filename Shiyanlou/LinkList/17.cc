#include<iostream>
#include<vector>
#include"LinkList.h"
using namespace std;

class Solution{
public:
    bool isPalindrome(ListNode * head) {
        if(!head) return true;
        vector<ListNode*> stack;
        for(ListNode * pt = head; pt; pt = pt->next) stack.push_back(pt);
        ListNode * pt = head;
        for(vector<ListNode*>::reverse_iterator iter = stack.rbegin(); iter != stack.rend(); ++iter){
                if((*iter)->val == pt->val) pt = pt->next;
                else break;
        }
        if(!pt) return true;
        return false;
    }
    bool isPalindrome2(ListNode * head){
        if(!head) return true;
        ListNode * slow = head;
        ListNode * quick = head->next;
        while(quick && quick->next){
            slow = slow->next;
            quick = quick->next->next;
        }
        //slow 对应中间位置
        if(quick) //偶数个结点
            if(slow->val != slow->next->val) return false;
        ListNode * rstart = slow->next;
        slow->next = NULL;
        ListNode * nhead = new ListNode(0);
        while(rstart){
            ListNode * temp = rstart->next;
            rstart->next = nhead->next;
            nhead->next = rstart;
            rstart = temp;
        }
        ListNode * right = nhead->next;
        ListNode * left = head;
        while(right && right->val == left->val){
            right = right->next;
            left = left->next;
        }
        if(!right) return true;
        else return false;
    }
};

int main(){
    ListNode node0(1);
    ListNode node1(1);
    ListNode node2(1);
    ListNode node3(0);
    // ListNode node4(4);
    node0.next = &node1;
    node1.next = &node2;
    // node2.next = &node3;
    Solution sol;
    cout << sol.isPalindrome2(&node0);
    return 0;
}