#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,f[30010];
int A[6010],B[6010],C[6010];
int main()
{
    int i,j,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&A[i],&B[i],&C[i]);
        t=1e9;
        if(A[i]>0 && A[i]<t)  t=A[i];
        if(B[i]>0 && B[i]<t)  t=B[i];
        if(C[i]>0 && C[i]<t)  t=C[i];
        m+=t;
    }
    for(i=1;i<=n;i++)
    {
        for(j=m;j>=0;j--)
        {
            t=1e8;
            if(A[i]>0 && j-A[i]>=0)  t=min(t,f[j-A[i]]);
            if(B[i]>0)  t=min(t,f[j]+B[i]);
            if(C[i]>0 && j-C[i]>=0)  t=min(t,f[j-C[i]]+C[i]);
            f[j]=t;
        }
    }   
    int ans=1e9;
    for(i=0;i<=m;i++)  ans=min(ans,max(i,f[i]));
    printf("%d\n",ans);
    return 0;
}