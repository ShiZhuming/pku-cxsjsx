#include<cstdio>

#define MAXSIZE 10005
int N;
int a[MAXSIZE];
int b[MAXSIZE];
int c[MAXSIZE];

int main()
{
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d",a + i);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d",b + i);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d",c + i);
    }
    
    return 0;
}