#include <iostream>
#include <string>
using namespace std;
template <class T> 
class container{
// 在此处补充你的代码

public:
    T p;
    container(T _p):p(_p){}
    container operator+(const container & c)
    {
        return container(p+c.p+c.p);
    }
    container operator+(const T & c)
    {
        return container(p+c);
    }
    friend ostream & operator<<(ostream & op, const container & c)
    {
        return op<<c.p;
    }
};
int main(){
	int n,m;
	cin >> n >> m;
	string s1,s2;
	cin >> s1 >> s2;
    container <int> a = n;
    container <int> b = m;
    cout<<a+b<<endl;// n+2m
    cout<<a+m<<endl;// n + m
    container <string> sa = string(s1);
    container <string> sb = string(s2);
    cout<<sa+sb<<endl;
    cout<< sa + s2<<endl;
}