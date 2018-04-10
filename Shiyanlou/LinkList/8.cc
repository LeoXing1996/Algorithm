#include<iostream>
#include "LinkList.h"

using namespace std;

class Solution{
public:
    ListNode * detectCycle(ListNode * head) {
        ListNode * q1;
        ListNode * s1;
        int count = 1;
        if(head && head->next){
            q1 = head->next;
            s1 = head;
        } else return NULL;
        while(q1 && q1->next && q1 != s1){
            s1 = s1->next;
            q1 = q1->next->next;
        }
        if(q1 != s1) return NULL;
        q1 = q1->next;
        while(q1!=s1){
            ++count;
            q1 = q1->next;
        }
        ListNode * q2 = head;
        ListNode * s2 = head;
        for(int i=0; i<count; ++i) q2 = q2->next;
        while(s2 != q2){
            s2 = s2->next;
            q2 = q2->next;
        }
        return q2;
    }
};

int main(){

    return 0;
}