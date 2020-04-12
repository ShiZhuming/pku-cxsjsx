#include<cstdio>
#include<map>
#include<set>
using namespace std;


int main()
{
    int n;
    char commond[10];
    int id, num, id1, id2;
    int temp;
    map<int,multiset<int>> mymap;
    scanf("%d",&n);
    while (n--)
    {
        getchar();
        scanf("%s",commond);
        switch (commond[0])
        {
        case 'n':
            scanf("%d",&id);
            mymap.insert(pair<int,multiset<int>>(id,multiset<int>()));
            mymap[id].clear();
            break;
        case 'a':
            scanf("%d %d",&id, &num);
            mymap[id].insert(num);
            break;
        case 'm':
            scanf("%d %d",&id1, &id2);
            if (id1 == id2)
            {
                break;
            }
            mymap[id1].insert(mymap[id2].begin(), mymap[id2].end());
            mymap[id2].clear();
            break;
        case 'u':
            scanf("%d", &id);
            for (multiset<int>::iterator i = mymap[id].begin(); i != mymap[id].end(); ++i)
            {
                temp = *i;
                if (mymap[id].count(temp) > 1)
                {
                    mymap[id].erase(mymap[id].lower_bound(temp), mymap[id].upper_bound(temp));
                    mymap[id].insert(temp);
                }
            }
            break;
        case 'o':
            scanf("%d", &id);
            for (multiset<int>::iterator i = mymap[id].begin(); i != mymap[id].end(); ++i)
            {
                if (i != mymap[id].begin())
                {
                    printf(" ");
                }
                printf("%d",*i);
            }
            printf("\n");
            break;

        default:
            break;
        }
    }
    return 0;
}