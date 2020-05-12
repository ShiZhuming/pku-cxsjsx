#include<cstdio>
int main()
{
	int K;
	int n;
	int maxx;
	int h[105];
	int l[105];
	int r[105];
	scanf("%d",&K);
	while (K--)
	{
		scanf("%d",&n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d",h+i);
		}
		l[0] = 1;
		for (int i = 1; i < n; i++)
		{
			l[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (h[j] < h[i] && l[j] + 1 > l[i])
				{
					l[i] = l[j] + 1;
				}
			}
		}
		r[n-1] = 1;
		for (int i = n - 2; i >= 0; i--)
		{
			r[i] = 1;
			for (int j = n - 1; j > i; j--)
			{
				if (h[j] < h[i] && r[j] + 1 > r[i])
				{
					r[i] = r[j] + 1;
				}
			}
		}
		maxx = 1;
		for (int i = 0; i < n; i++)
		{
			maxx = l[i] > maxx ? l[i] : maxx;
			maxx = r[i] > maxx ? r[i] : maxx;
		}
		printf("%d\n",maxx);
	}
	return 0;
}
