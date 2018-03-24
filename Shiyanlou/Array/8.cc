#include<iostream>
#include<vector>
using namespace std;

class Solution{
// private:
//     int num[4] = {3,4,-1,1};
//     int len = 4;
public:
    int firstPositive(vector<int> &num){
        int len = num.size();
        for(int i=0; i<len; ++i){
            while(num[i]<=len && num[i]!=i+1 && num[i]>0 && num[i]!=num[num[i]-1]){
                int temp = num[num[i]-1];
                num[num[i]-1] = num[i];
                num[i] = temp;
            }
        }
        for(int i=0; i<len; ++i){
            if(num[i]!=i+1)
                return i+1;
        }
        return len;
    }

};

int main(){
    int a[4] = {3,4,-1,1};
    vector <int> num(a, a+4);
    Solution sol;
    int res = sol.firstPositive(num);
    cout << res << endl;
    return 0;
}