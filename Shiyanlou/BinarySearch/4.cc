#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(rows==0||cols==0)
            return false;
        int rh = rows;
        int rl = 0;
        int ch = cols;
        int cl = 0;
        int rm = rl+(rh-rl)/2;
        int cm = cl+(ch-cl)/2;

        while((rh==rl && cl<ch) || rh!=rl){
            int mid = matrix[rm][cm];
            if(mid==target) return true;
            if(mid>target){
                // high 减小
                if(cm==0){
                    ch = cols-1;
                    --rh;
                }else{
                    ch = cm-1;
                    rh = rm;
                }
            }else{
                // low 变大
                if(cm==cols-1){
                    cl = 0;
                    ++rl;
                }else{
                    cl = cm+1;
                    rl = rm;
                }
            }
            rm = rl+(rh-rl)/2;
            cm = cl+(ch-cl)/2;
        }
        if(matrix[rh][ch]!=target)
            return false;
        else    
            return true;
    }
};

class Solution2{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int ROW = matrix.size(), COL = matrix[0].size();
        int lb = -1, ub = ROW * COL;
        while (lb + 1 < ub) {
            int mid = lb + (ub - lb) / 2;
            if (matrix[mid / COL][mid % COL] < target) {
                lb = mid;
            } else {
                if (matrix[mid / COL][mid % COL] == target) return true;
                ub = mid;
            }
        }
        return false;
    }
};

int main(){
    int a1[4] = {1,3,5,7};
    int a2[4] = {10,11,16,20};
    int a3[4] = {23, 30, 34, 50};
    vector<int>A1(a1,a1+4);
    vector<int>A2(a2,a2+4);
    vector<int>A3(a3,a3+4);
    vector<int> a[3] = {A1,A2,A3};
    vector<vector<int>>A(a, a+3);
    // for(vector<vector<int>>::iterator iter=A.begin(); iter!=A.end(); ++iter){
    //     vector<int >temp_vec = *iter;
    //     for(vector<int>::iterator ite=temp_vec.begin(); ite!=temp_vec.end(); ++ite){
    //         cout << *ite << ' ';
    //      }
    //      cout << endl;
    // }
    Solution sol;
    bool res = sol.searchMatrix(A, 3);
    cout << res << endl;
    return 0;
}