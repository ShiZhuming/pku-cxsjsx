#include<cstdio>
#include<set>
using namespace std;
// template<class T1, class T2>
// class member:public pair<T1,T2>
// {
// public:
//     operator<(const member & m) {
//         if (first != m.first)
//         {
//             return first < m.first;
//         }
//         return second < m.second;
//     }
// };

typedef pair<int, int> member;
multiset<member> club;
int main() {
    int n;
    int id;
    int force;
    scanf("%d",&n);
    id = 1;
    force = 1000000000;
    club.insert(member(force, id));
    while (n--)
    {
        scanf("%d %d", &id, &force);
        set<member>::iterator current = club.upper_bound(member(force, id));
        set<member>::iterator stronger = current;
        current = club.lower_bound(member(force, id));
        set<member>::iterator weaker = --current;
        if (stronger == club.end())
        {
            for ( current = 0; current < count; current++)
            {
                
            }
            
            printf("%d %d", id, (*weaker).second);
        }
        else if (stronger == club.begin())
        {
            printf("%d %d", id, (*stronger).second);
        }
        else if ((*stronger).first - force < force - (*weaker).first)
        {
            printf("%d %d", id, (*stronger).second);
        }
        else
        {
            printf("%d %d", id, (*weaker).second);
        }
        printf("\n");
        club.insert(member(force, id));
    }
    return 0;
}