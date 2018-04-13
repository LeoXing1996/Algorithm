#include<iostream>
#include"LinkList.h"
using namespace std;

class Solution {
private:
    ListNode * Merge(ListNode * p1, ListNode * p2){
        ListNode * nhead = new ListNode(0);
        nhead->next = p1;
        p1 = nhead;
        while(p1->next && p2){
            if(p1->next->val <= p2->val) p1 = p1->next;
            else {
                ListNode * rear = p2->next;
                p2->next = p1->next;
                p1->next = p2;
                p1 = p2;
                p2 = rear;
            }
        }
        if(p2) p1->next = p2;
        return nhead->next;
    }
    
    ListNode * MergeSort(ListNode * start){
        // start 待排序序列的前驱
        // end 待排序序列的后继
        if(start->next == NULL || !start) return start;
        // if(start->next->next == NULL){
        //     if(start->val > start->next->val){
        //         int temp = start->val;
        //         start->val = start->next->val;
        //         start->next->val = temp;
        //     }
        //     return start;
        // }
        ListNode * slow = start;
        ListNode * quick = start->next;
        while(quick && quick->next){
            slow = slow->next;
            quick = quick->next->next;
        }
        
        ListNode * rstart = MergeSort(slow->next);
        slow->next = NULL;
        ListNode * lstart = MergeSort(start);
        
        return Merge(rstart, lstart);
    }
public:
    /**
     * @param head: The head of linked list.
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */
    ListNode * sortList(ListNode * head) {
        // write your code here
        if(!head) return head;
        return MergeSort(head);
    }
};

int main{
    Solution sol;
    
    return 0;
}