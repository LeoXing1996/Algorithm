#include<iostream>
#include<vector>

using namespace std;

class ListNode{
public:
    int val;
    ListNode * next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

class Solution{
public:
    ListNode * removeNth(ListNode * head, int n){
        vector<ListNode*> stack;
        int count = 0;
        ListNode * point = head;
        while(point){
            stack.push_back(point);
            point = point ->next;
            ++count;
        }
        ListNode * rear = stack[count-n-1];
        ListNode * temp = stack[count-n];
        rear->next = temp->next;
        delete temp;
        return head;
    }
    ListNode * removeNth2(ListNode* head, int n){
        ListNode * nhead = new ListNode(0);
        nhead->next = head;
        ListNode * p1 = head;
        ListNode * p2 = head;
        ListNode * rear = nhead;
        for(int i=0; i<n; ++i){
            p1 = p1->next;
        }
        while(p1){
            p1 = p1->next;
            p2 = p2->next;
            rear = rear->next;
        }
        rear->next = p2->next;
        delete p2;
        return nhead->next;
    }
};

int main(){
    ListNode Node1(1);
    ListNode Node2(2);
    ListNode Node3(3);
    ListNode Node4(4);
    ListNode Node5(5);

    Node1.next = &Node2;
    Node2.next = &Node3;
    Node3.next = &Node4;
    Node4.next = &Node5;
    Solution sol;
    ListNode* node = sol.removeNth2(&Node1, 2);
    return 0;
}