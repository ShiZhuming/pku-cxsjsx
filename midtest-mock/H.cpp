#include<iostream>
#include<string>
#include<queue>
#include<set>
#include<map>
using namespace std;

int main()
{
    int T;
    while (T--)
    {
        int N;
        string C, X, Y;
        while (N--)
        {
            cin >> C >> X >> Y;
            map<string,set<string>> computer;
            map<string,queue<string>> bag;

            switch (C[0])
            {
            case 'C':
                if(bag.find(X)!=bag.end())
                {
                    if(bag[X].size < 6){
                        bag[X].push(Y);
                    }
                    else
                    {
                        auto temp = bag[X].front();
                        bag[X].pop();
                        bag[X].push(Y);
                        if (computer.find(X)!=computer.end())
                        {
                            computer[X].insert(temp);
                        }
                        else 
                        {
                            computer.insert(pair<string,set<string>>())
                        }
                    }
                    
                }

                break;
            case 'T':
                break;
            default:
                break;
            }
        }
    }
    return 0;
}