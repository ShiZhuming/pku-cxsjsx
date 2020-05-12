#include<cstdio>
#include<queue>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    priority_queue<int> p;
    int q;
    while (n--)
    {
        scanf("%d",&q);
        p.push(q);
    }
    scanf("%d",&n);
    while (n--)
    {
        printf("%d\n",p.top());
        p.pop();
    }
    return 0;
}