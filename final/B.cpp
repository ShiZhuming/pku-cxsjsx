#include<cstdio>
#include<memory.h>
using namespace std;

int n, k;

int p[1005];

int dp[105][1005];

int main()
{
    while (true)
    {
        scanf("%d %d",&n, &k);
        if (n==0 && k==0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d",p + i);
        }
        // memset(p, 0, 105*1005*sizeof(int));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                dp[i][j] = -1;
            }
        }
        
        // dp[1][p[0]] = 1;
        
        for (int i = 1; i <= (k/p[0]); i++)
        {
            dp[1][i*p[0]] = i;
        }
        dp[0][0] = 0;
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if (dp[i-1][j] != -1)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = 0x7fffffff;
                }
                for (int q = 1; q <= (j/p[i-1]); q++)
                {
                    if (dp[i-1][j-q*p[i-1]]!=-1)
                    {
                        dp[i][j] = dp[i][j] < dp[i-1][j-q*p[i-1]]+q ? dp[i][j] : dp[i-1][j-q*p[i-1]]+q;
                    }
                }
                if (dp[i][j] == 0x7fffffff)
                {
                    dp[i][j] = -1;
                }
                
                // / dp[i][j] = dp[i-1][j] < dp[i-1][j-p[i-1]]+1 ? dp[i-1][j] : dp[i-1][j-p[i-1]]+1;
            }
        }
        if (dp[n][k] == -1 || dp[n][k] == 0x7fffffff)
        {
            printf("%d\n",-1);
        }
        else
        {
            printf("%d\n",dp[n][k]);
        }
    }
    return 0;
}