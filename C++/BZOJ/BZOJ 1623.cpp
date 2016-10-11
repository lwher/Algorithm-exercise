#include<iostream>
#include<cstdio>
#include<queue>
#include<functional>
#include<algorithm>
#define maxn 50010
using namespace std;
priority_queue<int, vector<int>, greater<int> > seq;
int N, M, D, L, a[maxn];

int main()
{
    scanf("%d%d%d%d",&N,&M,&D,&L);
    for (int i=0; i<M; i++) seq.push(0);
    for (int i=0; i<N; i++) scanf("%d",&a[i]);
    sort(a, a+N); int ans=0;
    for (int i=0; i<N; i++)
    {
        int t=seq.top();
        if (a[i]-t*D>=L) ans++, seq.pop(), seq.push(t+1);
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}

