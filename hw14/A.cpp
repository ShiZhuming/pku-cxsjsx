#include<cstdio>
int N, M;
int main()
{
    // freopen("in.txt","r",stdin);
    scanf("%d%d",&N,&M);
    int * p = new int[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d",p + i);
    }
    int left = 0;
    int right = 1<<30;
    int middle = left + ((right - left)>>1);
    int count = 0;
    int sum = 0;
    while (left < right)
    {
        count = 1;
        sum = 0;
        middle = left + ((right - left)>>1);
        for (int i = 0; i < N; i++)
        {
            if (sum + p[i] <= middle)
            {
                sum += p[i];
            }
            else   
            {
                count ++;
                sum = p[i];
            }
            if (count > M || p[i] > middle)// 要的组多了，middle嫌小
            {
                left = middle + 1;
                break;
            }
            if (i == N - 1)// 要的组少了，middle嫌大
            {
                right = middle;
                break;
            }
        }
    }
    printf("%d",left);
    delete [] p;
    return 0;
}