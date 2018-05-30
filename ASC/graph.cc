#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<map>
#include<time.h>

using namespace std;

typedef struct adjNode{
    int node;
    adjNode * next=NULL;
} adjNode;

typedef struct Graph{
    int node;
    adjNode * firstNode=NULL;
} Graph;

class Solution{
public:
    void findVertex1(const string & verName, const string & edgName){
        map<int, int> graph;
        
        ifstream ifs(verName);
        string s;
        if(ifs.is_open()){
            int v;
            while(!ifs.eof()){
                ifs >> v;
                graph[v] = 0;
            }
        }
        ifs.close();
        
        ifs.open(edgName);
        if(ifs.is_open()){
            int v1, v2;
            while(!ifs.eof()){
                ifs >> v1 >> v2;
                graph[v1] += 1;
                graph[v2] += 1;
                // graph.find(v1)->second += 1;
                // graph.find(v2)->second += 1;
            }
        }
        ifs.close();
        for(map<int,int>::iterator iter=graph.begin(); iter!=graph.end(); ++iter){
            if(iter->second == 2) 
                cout << iter->first << endl;
        }
    }
    void findVertex2(const string & verName, const string & edgName){
        map<int,int> graph;
        ifstream ifs(edgName);
        if(ifs.is_open()){
            int v1, v2;
            map<int,int>::iterator search;
            while(!ifs.eof()){
                ifs >> v1 >> v2;
                search = graph.find(v1);
                if(search!=graph.end()) search->second += 1;
                else graph[v1] = 1;
                search = graph.find(v2);
                if(search!=graph.end()) search->second += 1;
                else graph[v2] = 1;
            }
        }
        ifs.close();
        for(map<int, int>::iterator iter=graph.begin(); iter!=graph.end(); ++iter){
            if(iter->second == 2) cout << iter->first << endl;
        }
    }
    void findVertex3(const string & verName, const string & edgName){
        ifstream ifs(verName);
        int count = 0;
        if(ifs.is_open()){
            string temp;
            while(getline(ifs, temp)) ++count;
        }
        int graph[count];
        fill(graph, graph+count, 0);
        ifs.close();
        ifs.open(edgName);
        if(ifs.is_open()){
            int v1,v2;
            while(!ifs.eof()){
                ifs >> v1 >> v2;
                graph[v1-1]+=1;
                graph[v2-1]+=1;
            }
        }
        ifs.close();
        for(int i=count-1; i>=0; --i){
            if(graph[i]==2) cout << i << endl;
        }
    }
    void findVertex_true(const string & verName, const string & edgName){
        ifstream ifs(verName);
        int count=0;
        // vector<Graph> g;
        map<int, vector<int>> graph;
        if(ifs.is_open()){
            string temp;
            int v ;
            while(!ifs.eof()){
                ifs >> v;
                // Graph temp_g = {v, NULL};
                vector<int> adjList;
                graph[v] = adjList;
            }
        }
        ifs.close();
        ifs.open(edgName);
        if(ifs.is_open()){
            string temp;
            int v1, v2;
            while(!ifs.eof()){
                ifs >> v1 >> v2;
                graph[v1].push_back(v2);
                graph[v2].push_back(v1);
            }
        }
        ifs.close();

        for(map<int, vector<int> >::iterator iter_map=graph.begin(); 
            iter_map!=graph.end(); ++iter_map){
            int tar_node = iter_map->first; //当前正在搜索的结点
            cout << tar_node << ": " ;
            
            vector<int>::iterator adjList = iter_map->second.begin();
            for( ; adjList!=iter_map->second.end(); ++adjList){
                int firstNode = *adjList;

                vector<int>::iterator adjNode = graph[firstNode].begin();
                for( ; adjNode!=graph[firstNode].end(); ++adjNode){
                    if(*adjNode!=tar_node) cout << *adjNode << " "; 
                }
            }
            cout << endl;
        }
    }
};

int main(){
    // int count = 0;
    Solution sol;
    string verName = "vertex.txt";
    string edgName = "edges.txt";
    sol.findVertex_true(verName, edgName);
    // clock_t s1, e1, s2, e2, s3, e3;
    // s1 = clock();
    // for(int i=0; i<10; ++i)
    //     sol.findVertex1(verName, edgName);
    // e1 = clock();
    
    // s2 = clock();
    // for(int i=0; i<10; ++i)
    //     sol.findVertex2(verName, edgName);
    // e2 = clock();
    
    // s3 = clock();
    // for(int i=0; i<10; ++i)
    //     sol.findVertex3(verName, edgName);
    // e3 = clock();

    // cout << "Algorithm 1 Time Cost:" << (double)(e1 - s1)/CLOCKS_PER_SEC << endl;
    // cout << "Algorithm 2 Time Cost:" << (double)(e2 - s2)/CLOCKS_PER_SEC << endl;
    // cout << "Algorithm 3 Time Cost:" << (double)(e3 - s3)/CLOCKS_PER_SEC << endl;
}

