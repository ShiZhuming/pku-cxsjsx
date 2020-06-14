#include<cstdio>
#include<queue>
#include<set>
#include<map>
#include<memory.h>
using namespace std;

// status为二进制32位数
// 四个字节从左到右依次为第一维x，第二维y，snake状态s，已经有的最大编号的钥匙k
#define getX(s) (((s)>>24)&(0xFF))// 第一维x，整数
#define getY(s) (((s)>>16)&(0xFF))// 第二维y，整数
#define getS(s) (((s)>>8)&(0xFF))// snake的状态s，从右往左每一位0为一个snake，死了就是1
#define getK(s) ((s)&(0xFF))// 最大已有钥匙k，整数

#define isKilled(s,t) (((s)>>(t))&1)// t号snake是否被杀死
#define killS(s,t) ((s)|(1<<(t)))// 杀死t号snake,t从0开始计数

#define makeStatus(x,y,s,k)  ((((x)<<24)&0xFF000000)|(((y)<<16)&0xFF0000)|(((s)<<8)&0xFF00)|((k)&0xFF))

int N, M;

char palace[105][105];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// set<int> visited;
char v[105][105][33][10];

queue<pair<int,int> > q;// first为时间，second为状态

int main()
{
    while (true)
    {
        // 初始化
        // visited.clear();
        memset(v, 0, 105*105*33*10*sizeof(char));
        while (!q.empty())
        {
            q.pop();
        }
        // 输入
        scanf("%d %d",&N, &M);
        getchar();
        if (N == 0 && M == 0)
        {
            break;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%c",palace[i]+j);
            }
            getchar();// 去掉'\n'
        }
        // 确定snake位置,编号，从'a'到'e',设定初始状态
        int countSnake = 0;
        int status;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (palace[i][j] == 'S')
                {
                    palace[i][j] = countSnake + 'a';
                    countSnake++;
                }
                if (palace[i][j] == 'K')
                {
                    status = makeStatus(i,j,0,0);
                    q.push(pair<int,int>(0,status));
                    // visited.insert(status);
                    v[i][j][0][0] = 1;
                }
            }
        }
        pair<int,int> curr;
        int currX, currY, currS, currK, currT;
        bool flag = false;
        while (!q.empty())
        {
            curr = q.front();
            q.pop();

            currX = getX(curr.second);
            currY = getY(curr.second);
            currS = getS(curr.second);
            currK = getK(curr.second);
            currT = curr.first;

            currT += 1;
            // 接下来有两种行为模式：杀死房间里的snake，或者向下一个房间前进
            // 检查房间里有没有未杀死的snake，有的话就杀死它
            if (palace[currX][currY] >= 'a' && palace[currX][currY] <= 'f' && isKilled(currS, (palace[currX][currY] - 'a')) == 0)
            {
                currS = killS(currS, (palace[currX][currY] - 'a'));
                status = makeStatus(currX, currY, currS, currK);
                // if (visited.find(status) == visited.end())
                // {
                //     q.push(pair<int,int>(currT, status));
                //     visited.insert(status);
                // }
                if (v[currX][currY][currS][currK] == 0)
                {
                    q.push(pair<int,int>(currT, status));
                    v[currX][currY][currS][currK] = 1;
                }
            }
            // 否则向下一个房间前进
            else
            {
                for (int i = 0; i < 4; i++)// 探索四个方向
                {
                    currX = getX(curr.second);
                    currY = getY(curr.second);
                    currS = getS(curr.second);
                    currK = getK(curr.second);
                    currT = curr.first;

                    currX += dx[i];
                    currY += dy[i];

                    currT += 1;

                    if (currX >= N || currX < 0 || currY >= N || currY < 0)
                    {
                        continue;
                    }
                    if (palace[currX][currY] == '#')
                    {
                        continue;
                    }
                    // 下面都是可以进入房间的情况
                    // status = makeStatus(currX, currY, currS, currK);
                    if (palace[currX][currY] >= '1' && palace[currX][currY] <= '9')
                    {
                        if (currK == (palace[currX][currY] - '0') - 1)
                        {
                            currK ++;
                        }
                    }
                    if (palace[currX][currY] == 'T' && currK == M)
                    {
                        printf("%d\n",currT);
                        flag = true;
                        break;
                    }
                    status = makeStatus(currX, currY, currS, currK);
                    // if (visited.find(status) == visited.end())
                    // {
                    //     q.push(pair<int,int>(currT, status));
                    //     visited.insert(status);
                    // }
                    if (v[currX][currY][currS][currK] == 0)
                    {
                        q.push(pair<int,int>(currT, status));
                        v[currX][currY][currS][currK] = 1;
                    }
                }
            }
            // 搜到终点
            if (flag)
            {
                break;
            }
        }
        if (flag == false)
        {
            printf("impossible\n");
        }
    }
    return 0;
}