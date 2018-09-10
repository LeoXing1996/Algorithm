#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    
    bool hasRoute(vector<DirectedGraphNode*> graph, DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        if(s==NULL || t==NULL) return false;
        set<int> isVisited;
        
        return DFS(s, t, isVisited);
    }
    
    bool DFS(DirectedGraphNode* s, DirectedGraphNode* t, set<int> & isVisited){
        if(s==t) return true;
        isVisited.insert(s->label);
        for(vector<DirectedGraphNode*>::iterator iter=(s->neighbors).begin(); 
            iter!=(s->neighbors).end(); ++iter){
    
            if(isVisited.find((*iter)->label) != isVisited.end()) continue;
            if(DFS(*iter, t, isVisited)) return true;
        }
        return false;
    }
};