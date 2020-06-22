#include<cstdio>
#include<set>
using namespace std;

set<pair<int,int> > p;

int main()
{
    int T;
    int n;
    int x, y;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d",&x, &y);
            p.insert(pair<int,int>(x,y));
        }
        int count = 0;
        for (auto i = p.begin(); i != p.end(); ++i)
        {
            for (auto j = i; j != p.end(); ++j)
            {
                for (auto k = j; i != p.end(); ++i)
                {
                    for (auto l = k; l != p.end(); ++i)
                    {
                        
                    }
                }
            }
        }
        
        printf("%d\n",count);
    }
    return 0;
}