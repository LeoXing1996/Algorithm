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
    ListNode * addTwoNumber(ListNode * l1, ListNode * l2){
        int count1 = 0, count2 = 0;
        for(ListNode * p1 = l1; p1; p1 = p1->next) ++count1;
        for(ListNode * p2 = l2; p2; p2 = p2->next) ++count2;
        ListNode * newhead = new ListNode(0);
        ListNode * rear = newhead;
        ListNode * p1 = l1;
        ListNode * p2 = l2;

        vector<ListNode*> stack;    //保存高位

        if(count1 > count2){    // 先插入 l1 的高位
            for(int i=0; i< count1 - count2; ++i){
                ListNode * temp = new ListNode(p1->val);
                rear->next = temp;
                rear = temp;
                p1 = p1->next;
                stack.push_back(temp);
            }
        } else if(count1 < count2){ //插入 l2 高位
            for(int i=0; i<count2 - count1;++i){
                ListNode * temp = new ListNode(p2->val);
                rear->next = temp;
                rear = temp;
                p2 = p2->next;
                stack.push_back(temp);
            }
        }
        while(p1){  // p1 p2 同步行动 只记录一个
            int S = p1->val + p2->val;
            ListNode * temp = new ListNode(S);
            rear->next = temp;
            rear = temp;
            stack.push_back(temp);
            p1 = p1->next;
            p2 = p2->next;
        }
        bool curr = false;  //记录进位
        for(vector<ListNode*>::reverse_iterator iter = stack.rbegin(); 
            iter != stack.rend(); ++iter){
                // cout<< (*iter)->val<<' ';
                if(curr) (*iter)->val += 1;
                if((*iter)->val >= 10) {
                    curr = true;
                    (*iter)->val = (*iter)->val % 10;
                }
            }
        if(curr) {
            ListNode * temp = new ListNode(1);
            temp->next = newhead->next;
            newhead->next = temp;
        }
        return newhead->next;
    }
};

int main(){
    ListNode head1(9);
    ListNode frist1(9);
    ListNode second1(9);
    ListNode head2(1);
    head1.next = &frist1;
    frist1.next = &second1;
    Solution sol;
    ListNode* head = sol.addTwoNumber(&head1, &head2);
    return 0;
}