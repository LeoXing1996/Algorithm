#include<iostream>
#include"LinkList.h"
using namespace std;
class Solution{
public:
    void deleteNode(ListNode * node){
        node->val = node->next->val;
        ListNode * temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};  
int main(){
    ListNode node0(0);
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(0);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    Solution sol;
    sol.deleteNode(&node1);
    return 0;
}