#include<cstdio>
// #define _USE_MATH_DEFINES
// #include<math.h>
#include<algorithm>
// #define PAI M_PI
#define PAI 3.14159265358979323846
bool greater(const int a, const int b) {return a > b;}
int main()
{
    // freopen("in.txt","r",stdin);
    int N, F;
    scanf("%d%d",&N,&F);
    double * p = new double[N];// 记录r^2
    int temp;
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&temp);
        p[i] = temp * temp * PAI;
    }
    std::sort(p, p + N, greater);
    double left = 0;
    double right = p[0];
    double middle = left + ((right - left)/2);
    int count = 0;
    // int sum = 0;
    while (right - left >= 0.00005)
    {
        count = 0;
        // sum = 0;
        middle = left + ((right - left)/2);
        for (int i = 0; i < N ; i++)
        {
            count += (int)(p[i]/middle);

            if (count >= F + 1 )// 要的组多了，middle嫌小
            {
                left = middle;
                break;
            }
            if ((count < F + 1 && p[i] < middle) || (count < F + 1 && i == N - 1))// 要的组少了，middle嫌大
            {
                right = middle;
                break;
            }
        }
    }
    printf("%.3lf",left);
    delete [] p;
    return 0;
}