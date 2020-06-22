#include<cstdio>
#include<string.h>

#define MAX 0x7fffffff

char p[1005];

int dp[1005];

bool isRev(int s, int e)// [s,e)
{
    for (int i = 0; i < (e-s)/2; i++)
    {
        if (p[s+i] != p[e-1-i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",p);
        int l = strlen(p);
        dp[1] = 0;
        dp[0] = -1;
        for (int i = 2; i <= l; i++)
        {
            dp[i] = MAX;
            for (int j = 0; j < i; j++)
            {
                if (isRev(j, i))
                {
                    dp[i] = dp[i] > dp[j] + 1 ? dp[j] + 1 : dp[i];
                }
            }
        }
        printf("%d\n",dp[l]);
    }
    return 0;
}