// E:别叫，这个大整数已经很简化了!
// 查看提交统计提问
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 程序填空，输出指定结果

#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
private:
int p[2*MAX];
int size;
public:
CHugeInt(char * s) {
    size = strlen(s);
    for (int i = 0; i < size; i++)
    {
        p[i] = s[size - 1 - i] - '0';
    }
    for (int i = size; i < 2*MAX; i++)
    {
        p[i] = 0;
    }
    
}
CHugeInt(int n) {
    size = 0;
    while (n)
    {
        p[size++] = n%10;
        n/=10;
    }
    for (int i = size; i < 2*MAX; i++)
    {
        p[i] = 0;
    }
}
CHugeInt(const CHugeInt & n) {
    size = n.size;
    for (int i = 0; i < size; i++)
    {
        p[i] = n.p[i];
    }
    for (int i = size; i < 2*MAX; i++)
    {
        p[i] = 0;
    }
}
CHugeInt operator+(const CHugeInt & n) {
    CHugeInt temp(0);
    for (int i = 0; i < 2*MAX; i++)
    {
        temp.p[i] = p[i] + n.p[i];
    }
    for (int i = 0; i < 2*MAX; i++)
    {
        temp.p[i+1] += temp.p[i]/10;
        temp.p[i]%=10;
    }
    for (int i = 2*MAX - 1; i >= 0; i--)
    {
        if(temp.p[i]) {
            temp.size = i + 1;
            break;
        }
    }
    return temp;
}
CHugeInt operator+(const int & n) {
    CHugeInt temp(*this);
    temp.p[0] += n;
    for (int i = 0; i < 2*MAX; i++)
    {
        temp.p[i+1] += temp.p[i]/10;
        temp.p[i]%=10;
    }
    for (int i = 2*MAX - 1; i >= 0; i--)
    {
        if(temp.p[i]) {
            temp.size = i + 1;
            break;
        }
    }
    return temp;
}
friend CHugeInt operator+(const int & n, const CHugeInt & m) {
    CHugeInt temp(m);
    temp.p[0] += n;
    for (int i = 0; i < 2*MAX; i++)
    {
        temp.p[i+1] += temp.p[i]/10;
        temp.p[i]%=10;
    }
    for (int i = 2*MAX - 1; i >= 0; i--)
    {
        if(temp.p[i]) {
            temp.size = i + 1;
            break;
        }
    }
    return temp;
}
friend ostream & operator<<(ostream & op,CHugeInt n) {
    if(!n.size) {
        return op << 0;
    }
    for (int i = n.size - 1; i >= 0; i--)
    {
        op << n.p[i];
    }
    return op;
}
CHugeInt & operator++() {
    p[0] += 1;
    for (int i = 0; i < 2*MAX; i++)
    {
        p[i+1] += p[i]/10;
        p[i]%=10;
    }
    for (int i = 2*MAX - 1; i >= 0; i--)
    {
        if(p[i]) {
            size = i + 1;
            break;
        }
    }
    return *this;
}
CHugeInt operator++(int) {
    CHugeInt temp(*this);
    p[0] += 1;
    for (int i = 0; i < 2*MAX; i++)
    {
        p[i+1] += p[i]/10;
        p[i]%=10;
    }
    for (int i = 2*MAX - 1; i >= 0; i--)
    {
        if(p[i]) {
            size = i + 1;
            break;
        }
    }
    return temp;
}
CHugeInt & operator+=(const int & n) {
    p[0] += n;
    for (int i = 0; i < 2*MAX; i++)
    {
        p[i+1] += p[i]/10;
        p[i]%=10;
    }
    for (int i = 2*MAX - 1; i >= 0; i--)
    {
        if(p[i]) {
            size = i + 1;
            break;
        }
    }
    return *this;
}
};
int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
// 输入
// 多组数据，每组数据是两个非负整数s和 n。s最多可能200位， n用int能表示
// 输出
// 对每组数据，输出6行，内容分别是：
// 样例输入
// 99999999999999999999999999888888888888888812345678901234567789 12
// 6 6
// 样例输出
// 99999999999999999999999999888888888888888812345678901234567801
// 99999999999999999999999999888888888888888812345678901234567801
// 99999999999999999999999999888888888888888812345678901234567801
// 25
// 25
// 26
// 12
// 12
// 12
// 13
// 13
// 14
// 来源
// Guo Wei