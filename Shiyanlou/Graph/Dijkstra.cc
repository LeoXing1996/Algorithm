#include<iostream>
#include<string>
#include<deque>
#include<stdlib.h>
#include"getGraph.h"

using namespace std;

class Dijkstra{
public:
    Graph * graph;
    int start;
    int end;
    set <int> isFind;
    deque <int> Que;
    int ** cost; //cost[m][n] 为 m->n 的最短路径

    Dijkstra(Graph * g){graph = g;}
    // Dijkstra();

    void getCost(int start_, int end_){
        if(!init(start_, end_)) return ;

        while(!Que.empty()){
            freshStruct(Que[0]);
            Que.pop_front();
        }
        if(cost[start][end]==-1) printf("ERROR: NO PARH\n");
        else printf("%d\n", cost[start][end]);
    }

private:
    bool init(int start_, int end_){   
        if((graph->vexNum)==0) return false;
        if(!nodeInLabes(start_) || !nodeInLabes(end_)) {
            printf("ERROR TARGET NODE(s)\n");
            return false;
        }
        start = start_;
        end = end_;

        // init structs
        initStruct();
        return true;
    }

    bool nodeInLabes(int node){
        // check if target Node (start or end) 
        // is in graph
        return ((graph->Labels).find(node)!=(graph->Labels).end()) ? true : false;
    }
    
    void freshStruct(int node){
        // AdjNodes : node的邻结点 <end, cost>
        vector<pair<int, int> > AdjNodes = (graph->Nodes[node])->adjNode;
        for(vector<pair<int, int> >::iterator iter=AdjNodes.begin(); 
                iter!=AdjNodes.end(); ++iter) {
            cost[node][iter->first] = iter->second;

            int oldCost = cost[start][iter->first];
            int newCost = cost[start][node]+iter->second;

            if(oldCost == -1 || oldCost > newCost)
                cost[start][iter->first] = cost[start][node]+iter->second;
            
            if(isFind.find(iter->first)==isFind.end()){
                isFind.insert(node);
                Que.push_back(iter->first);
            }
        }
    }
    
    void initStruct(){
        int num = graph->vexNum;
        cost = new int *[num];
        for(int i=0; i<num; ++i) {
            cost[i] = new int[num];
            fill_n(cost[i], num, -1);
        }
        vector<pair<int, int> > AdjNodes = (graph->Nodes[start])->adjNode;
        for(vector<pair<int, int> >::iterator iter=AdjNodes.begin(); 
                iter!=AdjNodes.end(); ++iter){
            cost[start][iter->first] = iter->second;
            isFind.insert(iter->first);
            Que.push_back(iter->first);
        }
        isFind.insert(start);
    }
    
};

void test(string fileName);

int main(){
    string fileName = "test.txt";
    Graph * g = new Graph(fileName);
    Dijkstra alg(g);
    // for(set<int>::iterator iter=(alg.graph->Labels).begin(); iter!=(alg.graph->Labels).end();++iter ) cout << *iter << ' ';
    alg.getCost(0, 5);
}

void test(string fileName){
    Graph graph(fileName);
    for(unordered_map<int,Node*>::iterator iter=graph.Nodes.begin();
        iter!=graph.Nodes.end(); ++iter){
            
            for(vector<pair<int, int> >::iterator iter_=(iter->second->adjNode).begin();
                iter_!=(iter->second->adjNode).end(); ++iter_){
                    cout << "Start:" << iter->first;
                    cout << " ---- " << iter_->second << " ---- ";
                    cout << "End: " << iter_->first << " \n";
                }
        }
}