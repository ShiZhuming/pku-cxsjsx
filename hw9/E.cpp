#include<cstdio>
#include<set>
using namespace std;
typedef pair<int, int> member;
// bool operator<(const member & a, const member & b) {
//     return a.second < b.second;
// }
set<member> club;
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
        set<member>::iterator current = club.lower_bound(member(force, id));
        set<member>::iterator stronger = current;
        set<member>::iterator weaker = --current;
        if (stronger == club.end())
        {
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