#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    long long permutationIndex(vector<int> &A) {
        // write your code here
        if(A.empty()) return 0;
        long long index = 1;
        for(int i=0; i<A.size(); ++i){  // find each elements order
            long factor = 1;
            int count = 0;
            for(int j=i+1; j<A.size(); ++j){
                factor *= j-i;
                if(A[j] < A[i]) ++count;
            }
            index += count * factor;
        }
        return index;
    }
};

int main(){}