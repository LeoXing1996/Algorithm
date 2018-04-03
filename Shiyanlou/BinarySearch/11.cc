#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
private:
    int countK(vector<int>& L, int len){
        int count = 0;
        for(vector<int>::iterator iter=L.begin(); iter!=L.end(); ++iter){
            count += (*iter)/len;
        }
        return count;
    }

public:
    int woodCut(vector<int>& L, int k){
        if(L.empty())
            return 0;
        sort(L.begin(), L.end());
        int count;
        int lb = 0;
        int hb = L[L.size()-1];
        int len;
        if(countK(L, hb) >= k)
            return hb;
        while(lb + 1 < hb){
            len = lb + (hb - lb)/2;
            count = countK(L, len);
            if(count >= k) lb = len;
            else hb = len;
        }
        return lb;
    }
};

class Solution2{
public:
    int woodCut(vector<int> L, int k) {
        // write your code here
        int lb = 0, ub = 0;
        for (auto l : L) 
            if (l + 1 > ub) ub = l + 1;

        while (lb + 1 < ub) {
            int mid = lb + (ub - lb) / 2;
            if (C(L, k, mid)) lb = mid;
            else ub = mid;
        }
        return lb;
    }

    int C(vector<int> L, int k, int mid) {
        int sum = 0;
        for (auto l : L) {
            sum += l / mid;
        }
        return sum >= k;
    }
};

int main(){
    vector<int>L = {232, 124, 456};
    int k = 7;
    Solution2 sol;
    cout <<sol.woodCut(L, k) << endl;

    return 0;
}