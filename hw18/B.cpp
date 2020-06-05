// 8:49开始
#include<cstdio>
#include<memory.h>
using namespace std;

int n, k;

int s = 0;// 方案数，每组数据清零

char t[10][10];// 棋盘

bool u[10];// 用掉的列

void dfs(int x, int y)// x是行数， y是剩下的棋子数，不包括本行
{
    if (x >= n)
    {
        if (y == 0)
        {
            s ++;
        }
        return;
    }
    dfs(x + 1, y);
    for (int i = 0; i < n; i++)
    {
        if (u[i] == 0 && t[x][i] == '#')
        {
            u[i] = 1;
            dfs(x + 1, y - 1);
            u[i] = 0;
        }
    }
    return;
}

int main()
{
    while (true)
    {
        scanf("%d %d", &n, &k);
        if (n == -1 && k == -1)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%s", t[i]);
        }
        s = 0;
        memset(u, 0, 10*sizeof(bool));
        dfs(0, k);
        printf("%d\n", s);
    }
    return 0;
}