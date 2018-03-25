#include<iostream>
#include<limits.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution{
public:
    int threeSumCloset(vector<int>& S, int value){
        sort(S.begin(), S.end());
        int closet = INT_MAX;
        for(int i=0; i<S.size()-2; ++i){
            int low = i+1;
            int high = S.size()-1;
            int closet_i = S[i] + S[low] + S[high];
            while(high-low>1){
                if(closet_i==value) return closet_i;
                else if(closet_i>value) --high;
                else if(closet_i<value) ++low;
                if(abs(S[i]+S[low]+S[high]-value)>abs(closet_i-value))
                    break;
                closet_i = S[i]+S[low]+S[high];
            }
            if(abs(closet_i-value)<abs(closet-value))
                closet = closet_i;
        }
        return closet;
        
    }
};

int main(){
    int s[4] = {-1,2,1,4};
    int target = 1;
    vector<int> S(s,s+4);
    Solution sol;
    int closet = sol.threeSumCloset(S,target);
    cout << closet << endl;
    return 0;
}