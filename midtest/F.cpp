#include <iostream>
#include <set>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
// 在此处补充你的代码

template<class T>
class MyFunc
{
    public:
    int a;
    T& b;
    T c;
    MyFunc(int _a,T & _b):a(_a),b(_b),c(_b){}
    void operator()(T p){
        c = c + p;
        for (int i = 0; i < a; i++)
        {
            if(i==0)
            {
                b = c;
            }
            else{
                b = b + c;
            }
        }
    }
};

// end

int main(){
    vector<int> v1;
    vector<string> v2;
    int N, val, num_repeat,result_int=0;
    string str,result_str="";
    cin>>N;
    cin>>num_repeat;
    for(int i=0;i<N;++i){
        cin>>val;
        v1.push_back(val);
    }
    for_each(v1.begin(),v1.end(),MyFunc<int>(num_repeat,result_int));
    for(int i=0;i<N;++i){
        cin>>str;
        v2.push_back(str);
    }
    for_each(v2.begin(),v2.end(),MyFunc<string>(num_repeat,result_str));
    cout<<result_int<<endl;
    cout<<"--------------"<<endl;
    cout<<result_str<<endl;
}