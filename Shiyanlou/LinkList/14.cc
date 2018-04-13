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
    RandomListNode * copyRandomList2(RandomListNode * head){
        map<RandomListNode *, RandomListNode *>hash;

        RandomListNode * nhead = new RandomListNode(0);
        RandomListNode * rear = nhead;
        for(RandomListNode * pt = head; pt; pt = pt->next){
            auto search = hash.find(pt);
            RandomListNode * temp;
            temp = (search == hash.end()) ? new RandomListNode(pt->label) : search->second ;

            // if(search == hash.end()) temp = new RandomListNode(pt->label);
            // else temp = search->second;
            rear->next = temp;
            rear =temp;
            if(pt->random){
                auto seaR = hash.find(pt->random);
                RandomListNode * nrand;
                if(seaR == hash.end()){
                    nrand = new RandomListNode(pt->random->label);
                    temp->random = nrand;
                    hash[pt->random] = nrand;
                } else {
                    temp->random = seaR->second;
                }
            }
        }
        return nhead->next;
    }
    RandomListNode * copyRandomList3(RandomListNode * head){
        
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

    RandomListNode * nhead = sol.copyRandomList2(&n1);
    return 0;
}