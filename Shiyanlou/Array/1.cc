#include<iostream>
#include<vector>
using namespace std;

class solution{
private:
    vector<int> A;
public:
    solution(int *arr, int len){
        for(int* i=(int*)arr; i < (int*)arr + len; ++i){
            A.push_back(*i);
        }
        for(vector<int>::iterator i=A.begin(); i!=A.end(); ++i){
            cout << *i << ' ';   
        }
        cout << endl;
    }
    int remote(int value){
        for(vector<int>::iterator i=A.begin(); i!=A.end(); ++i){
            if(*i==value){
                i = A.erase(i);
                --i;
            }
        }
        for(vector<int>::iterator i=A.begin(); i!=A.end(); ++i){
            cout << *i << ' ';   
        }
        cout << endl;
        return A.size();
    }
};

int main(){
    int value = 4;
    int arr[8] = {0,4,4,0,0,2,4,4};
    solution res(arr, 8);
    int a = res.remote(value);
    cout <<  a;

    return 0;
}

