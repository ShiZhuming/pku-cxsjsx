// D:第四周程序填空题3
// 查看提交统计提问
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 写一个二维数组类 Array2,使得下面程序的输出结果是：

// 0,1,2,3,

// 4,5,6,7,

// 8,9,10,11,

// next

// 0,1,2,3,

// 4,5,6,7,

// 8,9,10,11,

// 程序：

#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
private:
int ** p;
int m;
int n;
public:
Array2(int x = 0, int y = 0) {
    m = x;
    n = y;
    if (x&&y)
    {
        p = new int*[x];
        for (int i = 0; i < x; i++)
        {
            p[i] = new int[y];
        }
    }
    else
    {
        p = NULL;
    }
}
Array2(const Array2 & a) {
    if (p)
    {
        for (int i = 0; i < m; i++)
        {
            if (p[i])
            {
                delete [] p[i];
            }
        }
        delete [] p;
    }
    m = a.m;
    n = a.m;
    if (m&&n)
    {
        p = new int*[m];
        for (int i = 0; i < m; i++)
        {
            p[i] = new int[n];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                p[i][j] = a.p[i][j];
            }
        }
    }
    else
    {
        p = NULL;
    }
}
~Array2() {
    if (p)
    {
        for (int i = 0; i < m; i++)
        {
            if (p[i])
            {
                delete [] p[i];
            }
        }
        delete [] p;
    }
}
int* & operator[](int i) {
    return p[i];
}
int operator()(int i, int j) {
    return p[i][j];
}
Array2 & operator=(const Array2 & a) {
    if (p)
    {
        for (int i = 0; i < m; i++)
        {
            if (p[i])
            {
                delete [] p[i];
            }
        }
        delete [] p;
    }
    m = a.m;
    n = a.n;
    if (m&&n)
    {
        p = new int*[m];
        for (int i = 0; i < m; i++)
        {
            p[i] = new int[n];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                p[i][j] = a.p[i][j];
            }
        }
    }
    else
    {
        p = NULL;
    }
    return *this;
}
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
// 输入
// 无
// 输出
// 0,1,2,3,
// 4,5,6,7,
// 8,9,10,11,
// next
// 0,1,2,3,
// 4,5,6,7,
// 8,9,10,11,
// 样例输入
// None
// 样例输出
// 0,1,2,3,
// 4,5,6,7,
// 8,9,10,11,
// next
// 0,1,2,3,
// 4,5,6,7,
// 8,9,10,11,