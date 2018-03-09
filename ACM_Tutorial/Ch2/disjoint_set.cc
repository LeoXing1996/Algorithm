#include<iostream>

using namespace std;

class DisjSets{
    private:
        int s[];
        int count;

    public:
     DisjSets(int numElements){
        s = new int[numElements];
        count = numElements;
        for(int i=0; i<s.length; ++i)
            s[i] = -1;
    }

    void unionByHeight(int root1, int root2){
        if(find(root1)==find(root2))    //已经在相同集合中
            return ;
        else if(s[root2]<s[root1])
            s[root1] = root2;
        else{
            if(s[root1]==s[root2])
                --root1;
            s[root2] = root1;
        }
        --count;
    }

    int find(int x){
        if(s[x]<0)
            return x;
        else
            return s[x]=find(s[x]);
    }

    int size(){
        return count;
    }
}

int main(){
    int set1[3] = {1,2,5};
    int set2[3] = {4,6,7};
    
    return 0;
}