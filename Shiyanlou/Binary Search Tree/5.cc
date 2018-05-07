#include<iostream>
#include<vector>
#include"BiTree.h"

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 }ListNode;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        
        return helper(head, NULL);
    }
private:
    ListNode * findMid(ListNode * start, ListNode * end){
        ListNode * slow = start;
        ListNode * rear;
        ListNode * quick = start->next;
        while(quick!=end && quick->next!=end) {
            rear = slow;
            slow = slow->next;
            quick = quick->next->next;
        }  
        return slow;
        // return rear; // 返回 mid 的前驱
    }
    TreeNode * helper(ListNode * start, ListNode * end){
        if(start == end) return NULL;
        ListNode * mid = findMid(start, end);
        TreeNode * root = new TreeNode(mid->val);
        root->left = helper(start, mid);
        root->right = helper(mid->next, end);
        return root;
    }
};
int main(){}