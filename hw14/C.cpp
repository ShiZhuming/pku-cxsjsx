#include<cstdio>
long long int L, N, M;
long long int D[50005];
int main()
{
    scanf("%lld%lld%lld",&L, &N, &M);
    for (long long int i = 0; i < N; i++)
    {
        scanf("%lld",D + i);
    }
    D[N] = L;// 终点
    long long int left = 0;
    long long int right = L;
    long long int middle = left + ((right - left)>>1);
    long long int last = 0;
    long long int count = 0;
    while (left < right)
    {
        middle = left + ((right - left)>>1);
        last = 0;
        count = 0;
        for (long long int i = 0; i < N; i++)
        {
            // 如果下一个石头没有达到最小跳跃距离就把现在的石头移走
            if (D[i] - last < middle)
            {
                count ++;// 移走
            }
            else
            {
                last = D[i];
            }
            // 如果移走的石头数量过多，减小跳跃距离
            if (count > M)
            {
                right = middle - 1;
                break;
            }
            // 如果石头没移完就跳完了，加大距离
            if (i == N - 1)
            {
                left = middle + 1;
                break;
            }
        }
        // if (left == middle)
        // {
        //     break;
        // }
    }
    printf("%lld",left);
    return 0;
}