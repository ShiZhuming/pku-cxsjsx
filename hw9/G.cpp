#include<cstdio>
#include<queue>
#include<math.h>
using namespace std;

vector<int> prime;

void PrimeList() {
    prime.clear();
    prime.insert(2);
    int maxnum = sqrt(1000000.0);
    bool flag;
    for (int i = 3; i < maxnum; i++)
    {
        flag = true;
        for (vector<int>::iterator j = prime.begin(); j != prime.end(); ++j)
        {
            if (i%(*j) == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            prime.insert(i);
        }
    }
}

int PrimeNumber(int x) {
    int count = 0;
    for (vector<int>::iterator j = prime.begin(); j != prime.end(); ++j)
    {
        if(x < (*j)) {
            break;
        }
        while (x % (*j) == 0)
        {
            count ++;
            x /= (*j);
        }
    }
    return count;
}

// bool less(int a, int b) {
//     int na = PrimeNumber(a);
//     int nb = PrimeNumber(b);
//     return na != nb ? na < nb : a < b; 
// }

int main() {
    PrimeList();
    
    
    return 0;
}