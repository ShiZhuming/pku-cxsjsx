// C:第四周程序填空题1
// 查看提交统计提问
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 下面程序的输出是：

// 3+4i

// 5+6i

// 请补足Complex类的成员函数。不能加成员变量。

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
    Complex & operator=(const string & str){
        r=str[0]-'0';
        i=str[2]-'0';
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
// 输入
// 无
// 输出
// 3+4i
// 5+6i
// 样例输入
// None
// 样例输出
// 3+4i
// 5+6i