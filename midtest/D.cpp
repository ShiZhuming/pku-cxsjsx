#include <iostream>
using namespace std;
int gcd(int a, int b) { // 计算两个数的最大公约数
    return (!b) ? a : gcd(b, a % b);
}
class Fraction {
    int p, q;
public:
// 在此处补充你的代码

friend ostream & operator<<(ostream & os, const Fraction & f){
    if (f.q == 1)
    {
        return  os<<f.p;
    }
    
    return os<<f.p<<"/"<<f.q;
}

friend istream & operator>>(istream & os, Fraction & f){
    os>>f.p>>f.q;
    int minn = f.p < f.q ? f.p:f.q;
    for (int i = minn; i >= 2; i--)
    {
        while (f.p%i==0&&f.q%i==0)
        {
           f.p/=i;
           f.q/=i; 
        }
    }
    return os;
}

Fraction(int _p = 0, int _q = 1){
    p = _p;
    q = _q;
    
    int minn = p < q ? p:q;
    for (int i = minn; i >= 2; i--)
    {
        while (p%i==0&&q%i==0)
        {
           p/=i;
           q/=i; 
        }
    }
}

Fraction operator*(const Fraction & f){
    int pp = p*f.p;
    int qq = q*f.q;
    int minn = pp < qq ? pp:qq;
    for (int i = minn; i >= 2; i--)
    {
        while (pp%i==0&&qq%i==0)
        {
           pp/=i;
           qq/=i; 
        }
    }
    return Fraction(pp,qq);
}

// end
};

int main(){
    int testcases;
    cin >> testcases;
    while (testcases --) {
        Fraction a, b, two(2);
        cin >> a >> b;
        cout << a << " * " << b << " = " << a * b << endl;
        cout << "2 * " << a << " = " << two * a << endl;
        cout << b << " * 3 = " << b * 3 << endl;
    }
    return 0;
}