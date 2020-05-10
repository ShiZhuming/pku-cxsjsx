#include <iostream>
#include <iterator>
using namespace std;

template<class T1, class T2>
void Copy(T1 s, T1 e, T2 x) {
    for(; s != e; ++s, ++x)
        *x = *s;
}
// 在此处补充你的代码

class Fib
{
public:
    int l;// 序号
    int n;// 该项
    int m;// 前1项
    Fib(int _l, int _n = 1, int _m = 1):l(_l),n(_n),m(_m){}
    bool operator!=(const Fib & e){
        return l!=e.l;
    }
    int operator*(){
        return n;
    }
    Fib & operator++(){
        if(l == 1){
            l += 1;
            return *this;
        }
        l += 1;
        int temp = m;
        m = n;
        n = n + temp;
        return *this;
    }
};

// end
int main() {
	while(true) {
		int n;
		cin >> n;
		if(n == 0)
			break;
		
	    Fib f1(1), f2(n);
	    ostream_iterator<int> it(cout, " ");
	    Copy(f1, f2, it);
	    cout << endl;
	}
	return 0;
}