#include<cstdio>
#include<algorithm>


int main()
{
    int a, b, i, j;
    scanf("%d%d%d%d",&a,&b,&i,&j);
    int bit = 0;
    for (int k = i; k <= j; k++)
    {
        bit += 1<<k;
    }
    b = (~b)&bit;
    // b = 
    bit = ~bit;
    a = a&bit;
    printf("%d",(a|b));
    return 0;
}

// 10001
// 01110
// 