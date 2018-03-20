#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
//#include<pair>
using namespace std;

class Solution{
    private:
        vector<int> num;
    public:
        Solution(){
            num.push_back(-3);
            num.push_back(1);
            num.push_back(2);
            num.push_back(-3);
            num.push_back(4);
        }
        vector<int> subarraySum(){
            vector<int> res;
            vector<int> f;
            int sum = 0;
            for(int i=0; i<num.size(); ++i){
                sum += num[i];
                if(sum==0){
                    res.push_back(0);
                    res.push_back(i);
                    return res;
                }
                vector<int>::iterator iter = std::find(f.begin(), f.end(), sum);
                if(iter !=f.end()){
                    res.push_back(iter - f.begin()+1);
                    res.push_back(i);
                }
            }
        }
};

class Solution2{
    private:
        int A[5] = {-3,1,2,-3,4};
    public:
        int* subarraySum(){
            map<int, int> hash;
            hash[0] = 0;
            int curSum = 0;
            int *res = new int[2];
            for(int i=0; i<5; ++i){
                curSum += A[i];
                if(hash.find(curSum)!=hash.end()){
                    res[0] = hash[curSum];
                    res[1] = i;
                } else
                    hash[curSum] = i+1;
                
            }
            return (int*)res;
        }
};

class Solution3{
    private:
        int A[5] = {-3,1,2,-3,4};
    public:
        int* subarraySum(){
            int* res = new int[2];
            vector<pair<int, int>> Sum (5);
            Sum[0].first = 0;
            Sum[0].second = 1;
            for(int i=1; i<5; ++i){
                Sum[i].first = Sum[i-1].first + A[i];
                Sum[i].second = i;
            }
            sort(Sum.begin(), Sum.end());
            
            for(int i=0; i<4; ++i){
                if(Sum[i].first==Sum[i+1].first){
                    res[0] = Sum[i].second;
                    res[1] = Sum[i+1].second;
                }
            }
            return res;
        }
};

int main(){
    Solution sol;
    vector<int>res = sol.subarraySum();
    cout << *(res.begin()) << ' ' << *(res.begin()+1) << endl;

    Solution2 sol2;
    Solution3 sol3;
    int* res2 = sol2.subarraySum();
    int* res3 = sol3.subarraySum();
    cout << res2[0] << ' ' << res2[1] << endl;
    cout << res3[0] << ' ' << res3[1] << endl;
    return 0;
}