#include <cstdio>
#include <map>
#include <deque>
#include <algorithm>
using namespace std;
int n,m,k,cnt,ans;
map<int,int> h;
deque<int> q;
int main() 
{
    scanf("%d%d",&n,&m);
    while(n--) 
    {
        scanf("%d",&k);
        h[k]++;
        q.push_back(k);
        while(h.size()>m+1) 
        {
            ans=max(ans,h[q.front()]);
            if(!--h[q.front()])  h.erase(q.front());
            q.pop_front();
        }
        ans=max(ans,h[q.front()]);
    }
    while (q.size()) 
    {
        ans=max(ans,h[q.front()]);
        h[q.front()]--;
        q.pop_front();
    }
    printf("%d\n",ans);
    return 0;
}