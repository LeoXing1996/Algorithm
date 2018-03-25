#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution{
public:
    int removeDuplications(vector<int>& A){
        if(A.size()==0)
            return 0;
        bool flag = false;
        for(vector<int>::iterator iter=A.begin(); iter<A.end()-1; ++iter){
            if(*iter==*(iter+1) && !flag){
                flag = true;
            } else if(*iter==*(iter+1) && flag){
                iter = A.erase(iter);
                --iter;
                if(*iter != *(iter+1))
                    flag = false;
            } else{
                flag = false;
            }
        }
        // for(vector<int>::iterator iter=A.begin(); iter<A.end(); ++iter){
        //     cout << *iter << ' ';
        // }
        return A.size();
    }
};

int main(){
    int a[6] = {1,1,1,2,2,3};
    vector<int>A(a, a+6);
    Solution sol;
    int res = sol.removeDuplications(A);
    cout << res << endl;
    return 0;
}