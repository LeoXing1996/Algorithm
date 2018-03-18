#include<istream>

using namespace std;

class djset{
    private:
        int *s;
        
    public:
        djset(int);
        void unit(int, int);
        int find(int);
};

djset::djset(int num){
    s = new int[num];
    fill(s, s+num, -1);
}

void djset::unit(int a,int b){
    int A = djset::find(a);
    int B = djset::find(b);
    if(A!=B){
        if(s[A]<=s[B]){
            s[B] = A;
            --s[A];
        }else{
            s[A] = B;
            --s[B];
        }
    }
    
}

int djset::find(int a){
    if(s[a]<0)
        return a;
    else {
        s[a] = djset::find(s[a]);
        return s[a];
    }
}