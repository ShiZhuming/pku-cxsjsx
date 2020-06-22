#include<cstdio>
#include<vector>
using namespace std;
int n, x;
int a[12];

void dfs(int depth, vector<int> v, int status){
    if (depth == n)
    {
        for (auto i = v.begin(); i != v.end() ; i++)
        {
            if (i!=v.begin())
            {
                printf(" ");
            }
            printf("%d",*i);
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if ((status>>i)&1==0)
        {
            if (i >= a[depth] + x)
            {
                vector<int> tempv = v;
                tempv.push_back(i);
                dfs(depth+1, tempv, (status|(1<<i)));
            }
        }
        
    }
    
}

int main()
{
    scanf("%d %d",&n, &x);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",a+i);
    }
    vector<int> tv;
    tv.clear();
    dfs(0,tv,0);
    return 0;
}