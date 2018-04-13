#include<iostream>
#include<map>
// #include"LinkList.h"
using namespace std;

typedef struct RandomListNode{
    int label;
    RandomListNode * next, * random;
    RandomListNode(int x){
        label = x;
        next = NULL;
        random = NULL;
    }
}RandomListNode;

class Solution{
public:
    RandomListNode *copyRandomList(RandomListNode * head) {
        map<RandomListNode*, RandomListNode*> hash;

        RandomListNode * nhead = new RandomListNode(0);
        RandomListNode * rear = nhead;
        for(RandomListNode * pt = head; pt; pt = pt->next){
            int S = pt->label;
            RandomListNode * temp = new RandomListNode(S);
            rear->next = temp;
            rear = temp;
            hash[pt] = temp;
        }
        for(RandomListNode * pt = head; pt; pt = pt->next){
            if(pt->random) hash[pt]->random = hash[pt->random];
        }
        return nhead->next;
    }
};

int main(){
    RandomListNode n1(1);
    RandomListNode n2(2);
    RandomListNode n3(3);
    RandomListNode n4(4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n1.random = &n3;
    n2.random = &n4;

    Solution sol;

    RandomListNode * nhead = sol.copyRandomList(&n1);
    return 0;
}