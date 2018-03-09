#include<iostream>

using namespace std;

struct member{
    int age;
    char name[10];
};

template <typename any>
void swapp(any &, any &);

template<> void swapp(member&, member&);

int main(){
    int a = 0;
    int b = 1;
    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';
    cout << "============================================\n";
    swapp(a, b);
    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';
    cout << "============================================\n";
    member c = {10,"aaa"};
    member d = {20,"bbb"};
    cout << "c -> age: " << c.age << ' ' << "c -> name: " << c.name << '\n';
    cout << "d -> age: " << d.age << ' ' << "d -> name: " << d.name << '\n';
    cout << "============================================\n";
    swapp(c,d);
    cout << "c -> age: " << c.age << ' ' << "c -> name: " << c.name << '\n';
    cout << "d -> age: " << d.age << ' ' << "d -> name: " << d.name << '\n';
    return 0;
}

template <typename any>
void swapp(any & a, any & b){
    any temp = a;
    a = b;
    b = temp;
}

template<> void swapp(member & m1, member & m2){
    int t = m1.age;
    m1.age = m2.age;
    m2.age = t;
}