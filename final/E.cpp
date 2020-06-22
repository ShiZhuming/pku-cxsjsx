#include<cstdio>
#include<queue>
#include<memory.h>
using namespace std;

int c;
int n;
int a[12][12];

queue<pair<int,int> > q;
char visited[(1<<12)];

int main()
{
    scanf("%d",&c);
    while (c--)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d",a[i]+j);
            }
        }
        while (!q.empty())
        {
            q.pop();
        }
        memset(visited, 0, (1<<12)*sizeof(char));
        visited[1] = 1;
        q.push(pair<int,int>(1,0));
        bool found = false;
        while (!q.empty())
        {
            int status = q.front().first;
            int pos = q.front().second;
            q.pop();
            for (int i = 0; i < n; i++)
            {
                if (a[pos][i] > 0)
                {
                    if (i == n - 1)
                    {
                        found = true;
                        break;
                    }
                    int tempstatus = (status | (1<<i));
                    if (visited[tempstatus] == 1)
                    {
                        continue;
                    }
                    else
                    {
                        visited[tempstatus] = 1;
                        q.push(pair<int,int>(tempstatus, i));
                    }
                }
                if (found)
                {
                    break;
                }
            }
            
        }
        if (found)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        
        
    }
    
}