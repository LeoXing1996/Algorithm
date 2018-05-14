#include<iostream>
#include<vector>

using namespace std;

class Solution_TEL {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        if(s.empty()) return res;
        res = findSubString(0, s.size(), s);
        return res;
    }
private:
    vector<vector<string> > findSubString(int start, int end, const string & s){
        vector<vector<string> > res;

        if(start == end) {
            vector<string> temp ;
            temp.push_back(s.substr(start,1));
            res.push_back(temp);
        }
        else {
            for(int sub_end = start; sub_end <= end; ++sub_end){
        
                if(isPal(start, sub_end, s)){
                    string subString = s.substr(start, sub_end-start+1);
                    
                    vector<vector<string> > othSubString = findSubString(sub_end+1, end, s);
                    // temp.push_back(subString);
                    for(int i=0; i<othSubString.size(); ++i){
                        vector<string> temp;
                        temp.push_back(subString);

                        for(vector<string>::iterator iter=othSubString[i].begin(); iter!=othSubString[i].end(); ++iter)
                            temp.push_back(*iter);
                        
                        res.push_back(temp);
                    }
                } else 
                    continue;
            }
        }
        return res;
    }
    bool isPal(int start, int end, const string & s){
        if(start == end) return true;
        while(start<end){
            if(s[start] != s[end]) return false;
            ++start;
            --end;
        }
        return true;
    }
};

class Solution{
public:
    vector<vector<string> > partition(string s){
        vector<vector<string> > res;
        if(s.empty()) return res;
        vector<string> pal;
        dfs(0, s, pal, res);
        return res;
    }

private:
    void dfs(int pos, const string & s, vector<string> & pal, vector<vector<string> > & res){
        if(pos == s.size()){
            res.push_back(pal);
            return ;
        }
        for(int i=pos; i<s.size(); ++i){
            if(isPal(pos, i, s)){
                string subString = s.substr(pos, i-pos+1);
                pal.push_back(subString);
                dfs(i+1, s, pal, res);
                pal.pop_back();
            } else 
                continue;
        }
    }
    bool isPal(int start, int end, const string & s){
        if(start == end) return true;
        while(start<end){
            if(s[start] != s[end]) return false;
            ++start;
            --end;
        }
        return true;
    }
};

int main(){
    string s = "aab";
    Solution sol;
    vector<vector<string>> res = sol.partition(s);
    for(int i=0; i<res.size(); ++i){
        for(int j=0; j<res[i].size(); ++j){
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
}
