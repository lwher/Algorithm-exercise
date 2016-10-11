#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,f[1000325],fa[1000325],ans;
char ss[500325],s[1000325];
void work()
{
    int i,k,r=0,nr;
    for(i=1;i<=n;i++)
    {
        if(i<=r) k=min(f[2*nr-i],nr-i+f[nr]); else k=1;
        while(s[i+k]==s[i-k])  k++;
        f[i]=k;
        if(i+k-1>r)  {r=i+k-1;nr=i;}
    }
}
int getfa(int x)
{
    if(fa[x]==0)  return x;
    return  fa[x]=getfa(fa[x]);
}
int main()
{
    int i,j,k;
    scanf("%d",&n);scanf("%s",ss+1);
    for(i=1;i<=n;i++)  {s[(i<<1)]=ss[i];s[(i<<1)+1]='#';}
    n=n*2+1;s[1]='#';s[0]='@';s[n+1]='$';
    work();
    for(i=1;i<=n;i++)  if(s[i]!='#')  fa[i]=i+1;
    for(i=3;i<n;i+=2)
    {
        k=max(i-f[i]/2,1);
        for(j=getfa(k);j<i;j=getfa(j+1))
        {
            if(j+f[j]-1>=i)  {ans=max(ans,(i-j)*2);break;}
            else fa[j]=getfa(j+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}