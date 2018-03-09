#include<iostream>

using namespace std;

class test{
    private:
        int a = 1;
        int b = 2;
        int c;
        int ALL(int, int);
    public:
        test();
        test(int);
        test(int, int);
        ~test();
        void showSum();
};

test::test(){
    test::a=0;
    test::b=0;
}

test::test(int c){
    test::a=test::b = c;
}

test::test(int c, int d){
    test::a=c;
    test::b=d;
}

test::~test(){
    for(int i=0; i<(test::a)+1; ++i){
        cout << '?';
    }
    cout << '\n';
}

void test :: showSum(){
    test::c = test::ALL(test::a, test::b);
    cout << test::c <<endl;
}

int test :: ALL(int a, int b){
    return a+b;
}

int main(){
    test t;
    t.showSum();
    test tt(3);
    tt.showSum();
    test T(2,3);
    T.showSum();
    return 0;
}