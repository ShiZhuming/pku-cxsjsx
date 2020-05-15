#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include <math.h>
using namespace  std;

priority_queue<double,vector<double>,greater<double>> m;
stack<double> o;
double value()
{
    while (!o.empty())
    {
        o.pop();
    }
    while (true)
    {
        char a = cin.peek();
        double b, c;
        switch (a)
        {
        case '*':
            // cin >> a;
            scanf("%c",&a);
            getchar();
            b = o.top();
            o.pop();
            c = o.top();
            o.pop();
            o.push(b*c);
            break;
        case '/':
            // cin >> a;
            scanf("%c",&a);
            getchar();
            b = o.top();
            o.pop();
            c = o.top();
            o.pop();
            o.push(c/b);
            break;
        case '+':
            // cin >> a;
            scanf("%c",&a);
            getchar();
            b = o.top();
            o.pop();
            c = o.top();
            o.pop();
            o.push(b+c);
            break;
        case '^':
            // cin >> a;
            scanf("%c",&a);
            getchar();
            b = o.top();
            o.pop();
            c = o.top();
            o.pop();
            o.push(pow(c,b));
            break;
        case '=':
            // cin >> a;
            scanf("%c",&a);
            getchar();
            return o.top();
        case '-':
            // cin >> a;
            scanf("%c",&a);
            a = cin.peek();
            if (a == ' ')
            {
                getchar();
                b = o.top();
                o.pop();
                c = o.top();
                o.pop();
                o.push(c-b);
                break;
            }
            else {
                scanf("%lf",&b);
                getchar();
                o.push(-1*b);
                break;
            }
            
        default:
            // cin >> b;
            scanf("%lf",&b);
            getchar();
            o.push(b);
            break;
        }
    }
}
    
    


int main()
{
    // cin.sync_with_stdio(false);
    int n;
    double t;
    double u;
    scanf("%d",&n);
    // cin.get();
    getchar();
    while (!(m.empty()))
    {
        m.pop();
    }
    while (n--)
    {
        // cin >> t;
        scanf("%lf",&t);
        m.push(t);
    }
    // cin.get();
    getchar();
    while (cin.peek()!=EOF)
    {
        u = value();
        m.pop();
        m.push(u);
        printf("%e\n",u);
    }
    printf("\n");
    int count = 0;
    while (!m.empty())
    {
        if (count != 0)
        {
            if (count%10==0)
            {
                printf("\n");
            }
            else
            {
                printf(" ");
            }
        }
        printf("%e",m.top());
        m.pop();
        count ++;
    }
    return 0;
}

// 4 1e6 1e-6 0.001 1000 1 2 + 3 4 + * = 1 0.1 / 8 ^ =