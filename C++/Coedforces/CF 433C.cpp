#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,h[100010],stack[100010],top;
int pre[100010],last[100010];
long long ans,tmp1,tmp2,tmp;
long long min(long long a,long long b) 
{
     if(a<b) return a; return b;
}
int main()
{
    int i,j,k;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;i++)
    {
       scanf("%d",&h[i]);
       pre[i]=last[h[i]];last[h[i]]=i;
       if(i!=1) ans+=abs(h[i]-h[i-1]);
    }
    for(i=1;i<=m;i++)
    {
        tmp1=0;tmp2=0;top=0;
        for(j=last[i];j;j=pre[j])
        {
            if(j>1 && h[j-1]!=i)  {stack[++top]=h[j-1];tmp1+=abs(i-h[j-1]);}
            if(j<n && h[j+1]!=i)  {stack[++top]=h[j+1];tmp1+=abs(i-h[j+1]);}
        }
        sort(stack+1,stack+1+top);
        k=stack[top/2+1];
        for(j=1;j<=top;j++) tmp2+=abs(stack[j]-k);
        tmp=min(tmp,tmp2-tmp1);
    }
    cout<<ans+tmp<<endl;
    system("pause");
    return 0;
}
