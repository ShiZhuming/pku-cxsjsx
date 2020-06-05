#include<cstdio>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

int maze[5][5] = {
    0, 1, 0, 0, 0,

    0, 1, 0, 1, 0,

    0, 0, 0, 0, 0,

    0, 1, 1, 1, 0,

    0, 0, 0, 1, 0,

};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

typedef pair<int,vector<pair<int, int> > > path;

vector<path> q;

bool compare(const path & a, const path & b)
{
    return a.first < b.first;
}

void dfs(int x, int y, path p){
    p.first += 1;
    p.second.push_back(pair<int,int>(x,y));
    if (x < 0 || x >= 5 || y < 0 || y >= 5)// 在迷宫外面了
    {
        return;
    }
    if (x == 4 && y == 4)// 到达终点
    {
        q.push_back(p);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (maze[x + dx[i]][y + dy[i]] == 0)
        {
            maze[x + dx[i]][y + dy[i]] = 1;
            dfs(x + dx[i], y + dy[i], p);
            maze[x + dx[i]][y + dy[i]] = 0;
        }
    }
    return;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d",maze[i]+j);
        }
    }
    q.empty();
    path p;
    p.first = -1;
    p.second.clear();
    dfs(0, 0, p);
    sort(q.begin(), q.end(), compare);
    p = *(q.begin());
    for (auto i = p.second.begin(); i != p.second.end(); ++i)
    {
        printf("(%d, %d)\n", i->first, i->second);
    }
    return 0;
}