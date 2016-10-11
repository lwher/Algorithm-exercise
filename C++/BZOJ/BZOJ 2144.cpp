#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct sth
{
    int x,y,z;
}s,t;
void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
void check(sth &a)
{
    if(a.x>a.y) swap(a.x,a.y);
    if(a.x>a.z) swap(a.x,a.z);
    if(a.y>a.z) swap(a.y,a.z);
}
bool same(sth a,sth b)
{
    if(a.x==b.x && a.y==b.y && a.z==b.z) return 1;
    return 0;
}
sth getroot(sth a)
{
    int p,q,k;
    p=a.y-a.x;q=a.z-a.y;
    while(p!=q)
    {
        if(p>q)
        {
            k=(p-1)/q;a.y-=k*q;a.z-=k*q;
        }
        else
        {
            k=(q-1)/p;a.x+=k*p;a.y+=k*p;
        }
        p=a.y-a.x;q=a.z-a.y;
    }
    return a;
}
int getdep(sth a)
{
    int p,q,k,res=0;
    p=a.y-a.x;q=a.z-a.y;
    while(p!=q)
    {
        if(p>q)
        {
            k=(p-1)/q;res+=k;a.y-=k*q;a.z-=k*q;
        }
        else
        {
            k=(q-1)/p;res+=k;a.x+=k*p;a.y+=k*p;
        }
        p=a.y-a.x;q=a.z-a.y;
    }
    return res;
}
sth upgo(sth a,int len)
{
    int p,q,k;
    p=a.y-a.x;q=a.z-a.y;
    while(len)
    {
        if(p>q)
        {
            k=(p-1)/q;
            if(k>len) k=len;
            len-=k;a.y-=k*q;a.z-=k*q;
        }
        else
        {
            k=(q-1)/p;
            if(k>len) k=len;
            len-=k;a.x+=k*p;a.y+=k*p;
        }
        p=a.y-a.x;q=a.z-a.y;
    }
    return a;
}
bool OK(sth a,sth b,int len)
{
    return same(upgo(a,len),upgo(b,len));
}
int main()
{
    scanf("%d%d%d",&s.x,&s.y,&s.z);
    scanf("%d%d%d",&t.x,&t.y,&t.z);
    check(s);check(t);    
    if(!same(getroot(s),getroot(t))) printf("NO\n");
    else
    {
        int s1=getdep(s),t1=getdep(t),ans=0,k;
        if(s1>t1) s=upgo(s,s1-t1); else t=upgo(t,t1-s1);
        ans+=abs(s1-t1);
        int l=0,r=min(s1,t1),mid;
        while(l+1<r)
        {
            mid=(l+r)>>1;
            if(OK(s,t,mid)) r=mid;
            else l=mid; 
        }        
        if(!OK(s,t,r)) k=r+1; else k=l+1;
        if(same(s,t)) k=0; 
        ans+=k*2;
        printf("YES\n%d\n",ans);
    }
    system("pause");
    return 0;
}
