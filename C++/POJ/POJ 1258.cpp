#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,d[110],ans;
int map[110][110];
bool mark[110];
int main()
{
    int i,j,k,nmin;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  scanf("%d",&map[i][j]);
        memset(d,127,sizeof(d));
        memset(mark,0,sizeof(mark));
        d[1]=0;ans=0;
        for(i=1;i<=n;i++)
        {
            nmin=1e9;
            for(j=1;j<=n;j++)
            {
               if(!mark[j] && nmin>d[j])
               {nmin=d[j];k=j;}
            }
            mark[k]=1;ans+=d[k];
            for(j=1;j<=n;j++)
            if(!mark[j])
            {
               d[j]=min(d[j],map[k][j]);
            }
        }
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}
