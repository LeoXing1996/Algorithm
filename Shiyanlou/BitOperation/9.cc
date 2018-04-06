#include<iostream>

using namespace std;

class Solution{
public:
    int hashCode(string & key, int HASH_SIZE){
        int len = key.size();
        int code = 0;
        long long temp[len];
        temp[0] = 1;
        for(int i=1; i<len; ++i){
            temp[i] = temp[i-1] % HASH_SIZE * 33 % HASH_SIZE;
            // cout << temp[i] << ' ' ;
        }
        for(int i=0; i<len; ++i){
            code += (int(key[i]) % HASH_SIZE) * temp[len-1-i] % HASH_SIZE;
            code = code % HASH_SIZE;
            // cout << "i: " << len-i-1 <<" temp: "<< temp[len-1-i] << endl;
        }
        return code%HASH_SIZE;
    }
    int hashCode2(string & key, int HASH_SIZE){
        long long hashcode = 0;
        int size = key.size();
        for(int i=0;i<size; ++i){
            hashcode = hashcode * 33 % HASH_SIZE;
            hashcode += key[i];
            hashcode %= HASH_SIZE;
        }
        return int(hashcode);
    }
};

int main(){
    string s = "Wrong answer or accepted?";
    Solution sol;
    // cout << sol.hashCode(s,1000000007) <<endl;
    cout << sol.hashCode2(s, 1000000007) << endl;
    return 0;
}