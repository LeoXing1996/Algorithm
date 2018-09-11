#include<iostream>
#include<vector>
#include<set>

using namespace;

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution{
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        unordered_map<int, int> degree;
        for(int i=0; i<graph.size(); ++i) degree[i] = 0;
        
        for(vector<DirectedGraphNode*>::iterator iter=graph.begin();
        iter!=graph.end(); ++iter){
            initInDegree(*iter, degree);
        }
        
        vector<DirectedGraphNode*> res;
        
        while(res.size()!=graph.size()){
            for(unordered_map<int, int>::iterator iter=degree.begin(); 
            iter!=degree.end(); ++iter){
                if(iter->second == 0) {
                    res.push_back(graph[iter->first]);
                    freshInDegree(graph[iter->first], degree);
                    break;
                }
            }
        }
        return res;
    }
    void initInDegree(DirectedGraphNode * node, unordered_map<int, int> & degree){
        for(vector<DirectedGraphNode*>::iterator iter=(node->neighbors).begin();
        iter!=(node->neighbors).end() ;++iter)
            degree[(*iter)->label] += 1;
    }
    
    void freshInDegree(DirectedGraphNode * node , unordered_map<int, int> & degree){
        for(vector<DirectedGraphNode*>::iterator iter=(node->neighbors).begin();
        iter!=(node->neighbors).end() ;++iter)
            degree[(*iter)->label] -= 1;
        degree.find(node->label)->second = -1;
    }
}