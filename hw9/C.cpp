#include<cstdio>
#include<map>
#include<set>
using namespace std;


int main()
{
    int n;
    char commond[10];
    int x;
    int temp;
    multiset<int> now;
    set<int> history;
    scanf("%d",&n);
    while (n--)
    {
        getchar();
        scanf("%s",commond);
        switch (commond[1])
        {
        case 'd':
            scanf("%d",&x);
            now.insert(x);
            history.insert(x);
            printf("%d\n",now.count(x));
            break;
        case 'e':
            scanf("%d",&x);
            printf("%d\n",now.count(x));
            now.erase(now.lower_bound(x),now.upper_bound(x));
            break;
        case 's':
            scanf("%d",&x);
            printf("%d %d\n",history.find(x) != history.end(), now.count(x));
            break;
        default:
            break;
        }
    }
    return 0;
}