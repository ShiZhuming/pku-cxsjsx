#include<cstdio>
#include<memory.h>

long long a[260][260];

long long dp(long long i, long long j){
    if (a[i][j] != 0)
    {
        return a[i][j];
    }
    if (i == 1 || j == 0 || j == 1)
    {
        a[i][j] = 1;
        return 1;
    }
    long long minn = i < j ? i : j;
    for (long long k = 1; k <= minn; k++)
    {
        a[i][j] += dp(k, j - k);
    }
    return a[i][j];
}

int main(){
    memset(a, 0, 260*260*sizeof(long long));
    long long n;
    while (true)
    {
        scanf("%lld",&n);
        if (n == 0)
        {
            break;
        }
        long long sum = 0;
        switch (n%2)
        {
        case 0:
            // 偶数
            
            for (long long k = 1; k <= n/2; k++)
            {
                sum += dp(k, n/2 - k);
            }
            
            for (long long k = 1; k <= n; k++)
            {
                if (k % 2 == 1)
                {
                    continue;
                }
                sum += dp(k, (n - k)/2);
            }

            break;
        case 1:

            for (long long k = 1; k <= n; k++)
            {
                if (k % 2 == 0)
                {
                    continue;
                }
                sum += dp(k, (n - k)/2);
            }

            break;
        default:
            break;
        }
        printf("%lld %lld\n", n, sum);
    }
    return 0;
}