#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        if(word.empty()) return false;
        if(board.empty() || (*board.begin()).empty()) return false;

        rows = board.size()-1;
        cols = (*board.begin()).size()-1;
        lens = word.size();

        return isExist(board, word);
    }
private:
    int rows;
    int cols;
    int lens;
    bool isExist(const vector<vector<char> > & board, const string & word){
        vector<vector<int> > visited(rows+1, vector<int>(cols+1, 0));
        for(int r=0; r<=rows; ++r){
            for(int c=0; c<=cols; ++c){
                if(findNext(r, c, 0, board, word, visited)) 
                    return true;
            }
        }
        return false;
    }
    bool findNext(int r, int c, int ind, const vector<vector<char> > & board, const string & word, vector<vector<int> > & visited){
        if(ind == lens) return true;
        if(r>rows || r<0 || c>cols || c<0 || board[r][c] != word[ind])
            return false;

        if(visited[r][c]==1) return false; 
        visited[r][c] = 1;
        // bool isUp = findNext(r-1, c, ind+1, board, word, visited);
        // bool isRight = findNext(r, c+1, ind+1, board, word, visited);
        // bool isDown = findNext(r+1, c, ind+1, board, word, visited);
        // bool isLeft = findNext(r, c-1, ind+1, board, word, visited);
        // visited[r][c] = 0;
        // return isUp || isRight || isDown || isLeft;
        if(findNext(r, c+1, ind+1, board, word, visited)){
            visited[r][c] = 0;
            return true;
        }   
        else if(findNext(r+1, c,ind+1, board, word, visited)){
            visited[r][c] = 0;
            return true;
        }
        else if(findNext(r, c-1, ind+1, board, word, visited)){
            visited[r][c] = 0;
            return true;
        }
         
        else if(findNext(r-1, c, ind+1, board, word, visited)){
            visited[r][c] = 0;
            return true;
        }
        else {
            visited[r][c] = 0;
            return false;
        }
    }
    
};

int main(){
    vector<char> r1 = {'A', 'B', 'C', 'E'} ;
    vector<char> r2 = {'S', 'F', 'E', 'S'} ;
    vector<char> r3 = {'A', 'D', 'E', 'E'} ;
    vector<vector<char>> board = {r1, r2, r3};
    string word = "ABCEFSADEESE";
    Solution sol;
    cout << sol.exist(board, word);
}