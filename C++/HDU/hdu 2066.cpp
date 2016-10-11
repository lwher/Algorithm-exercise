#include<iostream>
#include<cmath>
#include<string.h>
#include<memory.h>
using namespace std;
int s,D,t;
int a[2003][2003],b[2003][2003];
bool mark[2003];
int qi,zhong;
int d[2003],l[2003],w[100000];
int head,tail;
void init()
{
    int i,aa,bb,time;
    for(i=1;i<=t;i++) 
    {
    cin>>aa>>bb>>time;
    if((a[aa][bb]==0)&&(a[bb][aa]==0))
    {b[aa][0]++;b[aa][b[aa][0]]=bb;a[aa][bb]=time;
     b[bb][0]++;b[bb][b[bb][0]]=aa;a[bb][aa]=time;}
    if((a[aa][bb]>0)&&(a[bb][aa]>0)&&(time<a[aa][bb]))
    {a[aa][bb]=time;a[bb][aa]=time;}}
     for(i=1;i<=s;i++)
     {cin>>qi;b[2002][0]++;b[2002][b[2002][0]]=qi;}
     for(i=1;i<=D;i++)
     {cin>>zhong;b[zhong][0]++;b[zhong][b[zhong][0]]=2003;}
     
     
}
void doing(int s)
{
     int i,now;
     head=1;tail=1;
     w[1]=s;
     mark[s]=1;
     while(head<=tail)
     {
      now=w[head];
      for(i=1;i<=b[now][0];i++)
      {
        if(d[b[now][i]]>l[now]+a[now][b[now][i]])
        {
        d[b[now][i]]=l[now]+a[now][b[now][i]];
        l[b[now][i]]=l[now]+a[now][b[now][i]];
        
        if(!mark[b[now][i]])
        {tail++;w[tail]=b[now][i];mark[b[now][i]]=1;}
        }
      }
      mark[w[head]]=0;
      head++;
      }
    
} 
int main()
{
    int i,j;
    while(cin>>t>>s>>D)
    {
    for(i=0;i<=2003;i++)
    {d[i]=10000000;}
    memset(l,0,sizeof(l));
    memset(w,0,sizeof(w));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    init();
    if((D!=0)&&(s!=0)&&(t!=0))
    {doing(2002);
    cout<<l[2003]<<endl;}
    else cout<<0<<endl;
    }
    system("pause");
    return 0;
}
