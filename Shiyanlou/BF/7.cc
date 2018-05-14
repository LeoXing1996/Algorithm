#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

using namespace std;
class Solution{
public:
    long long permutationIndexII(vector<int> &A) {
        // write your code here
        if(A.empty()) return 0;
        map<int, int > hash;
        int index = 1;
        for(int i=0; i<A.size(); ++i){
            if(hash.find(A[i]) == hash.end())
                hash[A[i]] = 1;
            else ++hash[A[i]];
        }
        for(int i=0; i<A.size(); ++i){
            set<int>S;
            long long base =  calBase(A.size()-1-i);

            for(int j=i+1; j<A.size(); ++j){
                if(A[j]<A[i] && S.find(A[j]) == S.end()){
                    S.insert(A[j]);
                    int newbase = base;
                    --hash[A[j]];
                    for(map<int,int>::iterator iter = hash.begin(); iter!=hash.end(); ++iter)    
                        newbase = newbase / calBase(iter->second);
                    ++hash[A[j]];
                    index += newbase;
                }
            }
            --hash[A[i]];
            if(hash[A[i]]==0) hash.erase(A[i]); 
        }
        return index;
    }
private:
    long long calBase(int pos){
        int base = 1;
        for(int i=pos; i>0; --i)
            base *= i;
        return base;
    }
};

int main(){
    vector<int> test = {4,3,1};
    Solution sol;
    long long res = sol.permutationIndexII(test);
    cout << res;
    
}