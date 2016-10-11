#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,v[2010][2010],num[2010],f[2010][2010],Log2[2010];
int col[2010][2010],row[2010][2010],RMQ[2010][15];
inline int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9')) ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9') {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
inline int min(int a,int b)
{
    if(a<b) return a; return b;
}
void solve(int ans[2010],int N)
{
    int i,k=0,p;
    for(i=1;i<N;i++)
    {
       p=k+ans[k];
       if(p>i && i+ans[2*k-i]<p) ans[i]=ans[2*k-i];
       else
       {
           if(p>i) ans[i]=p-i;
           while(i-ans[i]-1>=0 && i+ans[i]+1<N && num[i-ans[i]-1]==num[i+ans[i]+1])
           ans[i]++;
           k=i;
       }
    }
}
int main()
{
    int i,j,k,pos,q,p;
    memset(f,127,sizeof(f));
    for(i=1;i<=2000;i++) Log2[i]=log(i)/log(2.00);
    n=read();m=read();
    n=n*2-1;m=m*2-1;
    for(i=0;i<n;i+=2) for(j=0;j<m;j+=2) v[i][j]=read();
    for(i=0;i<n;i++) 
    {
       for(j=0;j<m;j++)  num[j]=v[i][j];
       solve(row[i],m);
    }    
    for(j=0;j<m;j++) 
    {
       for(i=0;i<n;i++) num[i]=v[i][j];
       solve(col[j],n);
    }    
    for(i=0;i<n;i++) 
    {
        for(j=0;j<m;j++) RMQ[j][0]=col[j][i];
        for(k=1;(1<<k)<=m;k++)
        {
           for(j=0;j<m;j++) 
           {
              if(j+(1<<(k-1))>=m) break;
              RMQ[j][k]=min(RMQ[j][k-1],RMQ[j+(1<<(k-1))][k-1]);
           }
        }                        
        pos=0;
        for(j=0;j<m;j++) 
        {
            while(1)
            {
               p=Log2[j-pos+1];
               q=min(RMQ[pos][p],RMQ[j-(1<<p)+1][p]);
               if(q<j-pos) pos++; else break;
            }
            f[i][j]=min(f[i][j],j-pos);
        }
        pos=m-1;
        for(j=m-1;j>=0;j--) 
        {
            while(1)
            {
               p=Log2[pos-j+1];
               q=min(RMQ[j][p],RMQ[pos-(1<<p)+1][p]);
               if(q<pos-j) pos--; else break;
            }
            f[i][j]=min(f[i][j],pos-j);
        }
    }    
    for(j=0;j<m;j++) 
    {
        for(i=0;i<n;i++) RMQ[i][0]=row[i][j];
        for(k=1;(1<<k)<=n;k++)
        {
           for(i=0;i<n;i++) 
           {
              if(i+(1<<(k-1))>=n) break;
              RMQ[i][k]=min(RMQ[i][k-1],RMQ[i+(1<<(k-1))][k-1]);
           }
        }
        pos=0;
        for(i=0;i<n;i++) 
        {
            while(1)
            {
               p=Log2[i-pos+1];
               q=min(RMQ[pos][p],RMQ[i-(1<<p)+1][p]);
               if(q<i-pos) pos++; else break;
            }
            f[i][j]=min(f[i][j],i-pos);
        }
        pos=n-1;
        for(i=n-1;i>=0;i--) 
        {
            while(1)
            {
               p=Log2[pos-i+1];
               q=min(RMQ[i][p],RMQ[pos-(1<<p)+1][p]);
               if(q<pos-i) pos--; else break;
            }
            f[i][j]=min(f[i][j],pos-i);
        }
    }
    int ans=0;
    for(i=0;i<n;i++) for(j=0;j<m;j++)
    {
        if(v[i][j]) ans+=f[i][j]/2+1; 
        else if((i & 1) && (j & 1)) ans+=(f[i][j]+1)/2;
    }     
    cout<<ans<<endl;
    return 0;
}