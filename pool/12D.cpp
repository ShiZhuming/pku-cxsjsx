#include<cstdio>
#include<queue>
#include<memory.h>
using namespace std;
// 从右到左每两个字节：x，y，生命值l
#define getX(s) ((s)&(0xff))
#define getY(s) (((s)>>8)&(0xff))
#define getL(s) (((s)>>16)&(0xff))
#define makeS(x,y,l) (((x)&(0xff))|(((y)<<8)&(0xff00))|(((l)<<16)&(0xff0000)))

char visited[0x6ffff];

char map[256][256];

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

queue<pair<int,int> > q;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m, n, h;
        scanf("%d %d %d",&m, &n, &h);
        getchar();// 去掉'\n'
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%c", map[i]+j);
            }
            getchar();// 去掉'\n'
        }
        memset(visited, 0, (0x6ffff)*sizeof(char));
        while (!q.empty())
        {
            q.pop();
        }
        q.push(pair<int,int>(0,makeS(1,1,h)));
        int step;
        int status;
        int currX;
        int currY;
        int currL;
        bool found = false;
        while (!q.empty())
        {
            step = q.front().first + 1;
            status = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                currX = getX(status) + dx[i];
                currY = getY(status) + dy[i];
                currL = getL(status);
                if (currX > m || currY > n || currX < 1 || currY < 1)
                {
                    continue;
                }
                if (currX == m && currY == n)
                {
                    printf("%d\n",step);
                    found = true;
                    break;
                }
                if (map[currX][currY] == '#')
                {
                    continue;
                }
                if (map[currX][currY] == '*' && currL > 1)
                {
                    if (visited[makeS(currX,currY,(currL-1))] == 0)
                    {
                        q.push(pair<int,int>(step, makeS(currX,currY,(currL-1))));
                        visited[makeS(currX,currY,(currL-1))] = 1;
                    }
                    else
                    {
                        continue;
                    }
                }
                if (map[currX][currY] == '.')
                {
                    if (visited[makeS(currX,currY,currL)] == 0)
                    {
                        q.push(pair<int,int>(step, makeS(currX,currY,currL)));
                        visited[makeS(currX,currY,currL)] = 1;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            if (found)
            {
                break;
            }
        }
    }
    return 0;
}