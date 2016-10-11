#include <cstdio>
#include <set>
#include <deque>
#include <algorithm>
using namespace std;
#define df pop_front()
const int max_n = 100000 + 10;
struct node
{
    int x, y, self;
    node(){}
    node(int X,int Y, int SELF):
    x(X + Y), y(X - Y), self(SELF){}
    inline bool operator < (const node &A) const
    {
        if (y == A.y)   return x < A.x;
        return y < A.y;
    }
  
}dot[max_n];
set<node>::iterator it, sb;
set<node>g;
deque<node>q;
int n, D;
inline void read(int &x)
{
  char ch;
  while (ch=getchar(),ch>'9' || ch<'0');
  x=ch-48;
  while (ch=getchar(),ch<='9' && ch>='0') x=x*10+ch-48; 
} 
inline int cmp(node A, node B)
{
    return A.x < B.x;
}
int fa[max_n] = {0};
int have[max_n];
int find_father(int k)
{
    if (!fa[k]) return k;
    fa[k] = find_father(fa[k]);
    have[k] = 0;
    return fa[k];
}
int main()
{
    int x, y;
    read(n);    read(D);
    for (int i = 1; i <= n; ++ i)
    {
        read(x);   read(y);
        dot[i] = node(x, y, i);
    }
    for (int i = 1; i <= n; ++ i)    have[i] = 1;
    sort(dot + 1, dot + 1 + n, cmp);
    q.push_back(dot[1]);
    g.insert(dot[1]);
    for (int i = 2; i <= n; ++ i)
    {
        while (!q.empty() && dot[i].x - q[0].x > D)  
        {
            g.erase(q[0]);
            q.df;
        }
        q.push_back(dot[i]);
        g.insert(dot[i]);
        it = g.find(dot[i]);
        ++ it;
        if (it != g.end() && (*it).y - dot[i].y <= D)
        {
            int a = find_father(dot[i].self);
            int b = find_father((*it).self);
            if (a != b) 
            {
                int da = b, xiao = a;
                if (have[a] > have[b])
                {
                    da = a;
                    xiao = b;
                }
                fa[xiao] = da;
                have[da] += have[xiao];
                have[xiao] = 0;
            }
        }
        -- it;
        if (it != g.begin())
        {
            -- it;
            if (dot[i].y - (*it).y > D)  continue;
            int a = find_father(dot[i].self);
            int b = find_father((*it).self);
            if (a != b) 
            {
                int da(b), xiao(a);
                if (have[a] > have[b])
                {
                    da = a;
                    xiao = b;
                }
                fa[xiao] = da;
                have[da] += have[xiao];
                have[xiao] = 0;
            }
        }
    }
    int tot = 0, ans = 0;
    for (int i = 1; i <= n; ++ i)
    {
        ans = max(ans, have[i]);
        if (have[i])    ++ tot;
    }
    printf("%d %d\n", tot, ans);
    system("pause");
    return 0;
}
