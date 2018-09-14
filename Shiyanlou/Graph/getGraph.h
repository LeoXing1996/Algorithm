#include<iostream>
#include<fstream>
#include<string>

#include<vector>
#include<utility>
#include<unordered_map>
#include<set>
// #define pair <int, int> adjVex
// #define vector <pair <int, int> > node

using namespace std;

class Node{
public:
    int label;
    vector<pair<int, int> > adjNode;
    
    Node (int label){
        label = label;
    }
};

class Graph{
public:
    Graph(string fileName){
        initGraph(fileName);
    }
    // Graph(){}

    int vexNum = 0;
    set <int> Labels;
    unordered_map <int, Node*> Nodes;

    void initGraph(string fileName){
        ifstream ifs(fileName);
        if (ifs.is_open()) {
            // char ch = ifs.get();
            int start;
            int end;
            int cost;
            while(!ifs.eof()){
                ifs >> start >> end >> cost;
                pair<int, int> Arc (end, cost);
                
                if(Labels.find(start) == Labels.end()){
                    Node * node = new Node(start);
                    (node->adjNode).push_back(Arc);
                    Nodes[start] = node;
                    Labels.insert(start);
                } else 
                    (Nodes[start]->adjNode).push_back(Arc);

                if(Labels.find(end)==Labels.end()){
                    Node * node_ = new Node(end);
                    Nodes[end] = node_;
                    Labels.insert(end);
                }
            }
        } else {
            printf("FILE NAME ERROR!\n");
            return;
        }
        vexNum = Labels.size();
    }
};