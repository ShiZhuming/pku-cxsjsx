// 9:27开始
#include<cstdio>
#include<memory.h>
using namespace std;

int N;

int island[20][20];

int t[16][65550];

int dp(int current, int status)// 站在current，从status到最终状态的最短时间
{
    if (t[current][status] != 0)
    {
        return t[current][status];
    }
    if (status == ((1 << (N - 1)) - 1))// 还差最后一步
    {
        t[current][status] = island[current][N - 1];
        return t[current][status];
    }
    for (int i = 1; i < N - 1; i++)
    {
        if (((status >> i) & 1) == 0 && i != current)// 可以迈出下一步
        {
            // printf("i = %d and ((status >> i) & 1) = %d\n",i,((status >> i) & 1));
            if (t[current][status] == 0 || t[current][status] > dp(i, status | (1 << i)) + island[current][i])
            {
                t[current][status] = dp(i, status | (1 << i)) + island[current][i];
            }
        }
    }
    return t[current][status];
}

int main()
{
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d",island[i] + j);
        }
    }
    memset(t, 0, 16*65550*sizeof(int));
    printf("%d", dp(0, 1));
    return 0;
}