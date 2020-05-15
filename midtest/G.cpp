#include<cstdio>
#include<queue>
using namespace std;

int N;
int X,Y,Z;
int M;
// int W;// 等待交割的石油
char C[10];

class comp
{
public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        if (a.first != b.first)
        {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};


priority_queue<pair<int,int>,vector<pair<int,int>>,comp> q;

int main()
{
    scanf("%d",&N);
    while (!q.empty())
    {
        q.pop();
    }
    while (N--)
    {
        scanf("%s",C);
        switch (C[0])
        {
        case 'B':
            scanf("%d",&Z);
            M = 0;
            while (!q.empty() && Z>0)
            {
                int price = q.top().first;
                int barrel = q.top().second;
                q.pop();
                if (Z >= barrel)
                {
                    M += price*barrel;
                    Z -= barrel;
                }
                else
                {
                    M += price*Z;
                    q.push(pair<int,int>(price,barrel-Z));
                    Z = 0;
                    break;
                }
            }
            if (Z > 0)
            {
                M += Z*40;
            }
            printf("%d\n",M);
            break;
        case 'S':
            scanf("%d%d",&X,&Y);
            q.push(pair<int,int>(Y,X));
            break;
        default:
            break;
        }
    }
    return 0;
}

// 6 BUY 5 SELL 10 10 BUY 5 SELL 10 5 BUY 5 BUY 15