#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
double e[100010];
int fly[100010];
int n,m;
int main()
{
    int i,j,a,b;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)  break;
        memset(e,0,sizeof(e));
        memset(fly,-1,sizeof(fly));
        //for(i=0;i<=n;i++)  e[i]=0,fly[i]=-1;
        for(i=1;i<=m;i++) 
        {
            scanf("%d%d",&a,&b);
            fly[a]=b;
        }
        for(i=n-1;i>=0;i--)
        {
            if(fly[i]!=-1)   e[i]=e[fly[i]];
            else
            {
                for(j=1;j<=6;j++)
                {
                   if(i+j<n)  e[i]+=(1.0/6.0)*e[i+j];
                }
                e[i]+=1;
            }
        }
        printf("%.4lf\n",e[0]);
    }
    system("pause");
    return 0;
}
