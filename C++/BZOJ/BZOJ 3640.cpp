#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-10
using namespace std;
int n,m,hp,B[151],A[151];
int sz,to[10010],pre[10010],last[151];
double x[160][160],num[160][160],ans,f[10010][160],cs[160];
void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
inline void swap(double &a,double &b)
{
    double t=a;a=b;b=t;
}
void gauss()
{
    int i,j,k;double t;
    for(i=1;i<=n;i++) 
    {
        for(j=i;j<=n;j++) if(fabs(x[j][i])>eps) break;
        if(j!=i) for(k=1;k<=n;k++) {swap(x[i][k],x[j][k]);swap(num[i][k],num[j][k]);}
        t=x[i][i];
        for(k=1;k<=n;k++) {x[i][k]/=t;num[i][k]/=t;}
        for(j=1;j<=n;j++) if(j!=i)
        {
            t=x[j][i];
            for(k=1;k<=n;k++) {x[j][k]-=x[i][k]*t;num[j][k]-=num[i][k]*t;}
        }
    }
}
int main()
{
    int i,j,k,a,b,c,s;double p;
    scanf("%d%d%d",&n,&m,&hp);
    for(i=1;i<=n;i++) scanf("%d",&A[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        if(a==b){B[a]++;Ins(a,b);}
        else
        {
            B[a]++;B[b]++;
            Ins(a,b);Ins(b,a);
        }
    }
    for(i=1;i<n;i++) for(j=last[i];j;j=pre[j]) if(!A[to[j]]) x[to[j]][i]+=1/(double)(B[i]);
    for(i=1;i<=n;i++) x[i][i]-=1,num[i][i]=1;            
    gauss();        
    f[hp][1]=1;    
    for(s=hp;s;s--)
    {
        for(i=1;i<n;i++) for(j=last[i];j;j=pre[j])
        if(A[to[j]] && s+A[to[j]]<=hp)
        {
            f[s][to[j]]+=f[s+A[to[j]]][i]/(double)(B[i]);
        }
        memset(cs,0,sizeof(cs));
        for(i=1;i<=n;i++) for(j=1;j<=n;j++)
        if(fabs(x[i][j])>eps)
        {
           cs[i]-=x[i][j]*f[s][j];
        }
        for(i=1;i<=n;i++) if(!A[i]) 
        {
            f[s][i]=0;
            for(j=1;j<=n;j++) f[s][i]+=num[i][j]*cs[j];
        }
        ans+=f[s][n];
    }
    printf("%.8lf\n",ans);
    return 0;
}
