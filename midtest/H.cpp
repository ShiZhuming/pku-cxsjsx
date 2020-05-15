#include <iostream>
using namespace std;
// 在此处补充你的代码

class A;
class B;
class C;

class A{
public:
    int n;
    A(int _n):n(_n){}
    int get_value(){
        return n;
    }
    B operator+(const A* a);
//     operator A*(){
//         return this;
//     }
};

// A* operator+(const A* a, const A* b){
//     return (new A(a->n+b->n));
// }

// A* operator+(const A* a, const A* b){
//     return 
// }

class B:public A{
public:
    B(int _n):A(_n){}
    // operator A*(){
    //     return this;
    // }
    A* operator+(A* a){
        return (new A(n+a->n));
    }
};

B A::operator+(const A* a){
    return B(n+a->n);
}

class C:public B{
public:
    C(int _n):B(_n){}
    // operator A*(){
    //     return this;
    // }
};

// end
int main() {
    int t;
    cin >> t;
    while (t --){
        int aa, bb, cc;
        cin >> aa >> bb >> cc;
        A a(aa);
        B b(bb);
        C c(cc);
        A* x = &a;
        A* y = &b;
        A* z = &c;
        cout << (x->get_value() + y->get_value() + z->get_value()) << " ";
        cout << ((*x) + y + z)->get_value() << endl;
    }
    return 0;
}