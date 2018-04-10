#include<iostream>
#include<vector>
#include"LinkList.h"
using namespace std;

class Solution {
private:
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        ListNode * nhead = new ListNode(0);
        ListNode * p = nhead;
        ListNode * p1 = l1;
        ListNode * p2 = l2;
        while(p1 && p2){
            ListNode * temp;
            if(p1->val < p2->val) {
                temp = p1->next;
                p->next = p1;
                p1->next = NULL;
                p1 = temp;
            } else {
                temp = p2->next;
                p->next = p2;
                p2->next = NULL;
                p2 = temp;
            }
            p = p->next;
        }
        if(p1) p->next = p1;
        if(p2) p->next = p2;
        return nhead->next;
    }
    ListNode * binarySort(vector<ListNode*>&lists, int start, int end){
        if(start + 1 == end)
            return mergeTwoLists(lists[start], lists[end]);
        else if(start == end)
            return lists[start];
        
        ListNode * right = binarySort(lists, start, start + (end - start)/2);
        ListNode * left = binarySort(lists, start + (end - start)/2 + 1, end);
        
        return mergeTwoLists(right, left);
    }
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if(lists.empty()) return NULL;
        ListNode * nhead;
        nhead = binarySort(lists, 0, lists.size()-1);
        return nhead;
    }
};

int main(){
    return 0;
}