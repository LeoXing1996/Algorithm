#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size()-1;
        bool cont = true;
        for(vector<int>::reverse_iterator iter=digits.rbegin(); iter!=digits.rend() && cont; ++iter){
            if(*iter == 9){
                *iter = 0;
                // cont = true;
            } else {
                *iter += 1;
                cont = false;
            }
        }
        if(cont){
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};

int main(){
    vector<int> digits = {9,9};
    Solution sol;
    vector<int> plus1 = sol.plusOne(digits);
    for(vector<int>::iterator iter = plus1.begin(); iter != plus1.end(); ++iter){
        cout << *iter << ' ' ;
    }
    cout <<endl;
    return 0;
}