#include<iostream>
#include<cmath>
#include<string.h>
#include<memory.h>
using namespace std;
int n,m,total;
int d[300],w[300],l[300];
int b[300][300],a[300][300];
int head,tail;
bool mark[300];
int k;
int qi,zhong;
void init()
{
     int aa,c,io;
    
     int i;
     for(i=1;i<=m;i++)
     {
     cin>>aa>>c>>io;  
      if((a[c][aa]==0)&&(a[aa][c]==0))
      {
      b[aa][0]++; b[aa][b[aa][0]]=c;a[aa][c]=io;
      b[c][0]++; b[c][b[c][0]]=aa;a[c][aa]=io;
      }  else
     if((a[c][aa]>0)&&(a[aa][c]>0)&&(io<a[aa][c]))
     {b[aa][0]++; b[aa][b[aa][0]]=c;a[aa][c]=io;
     b[c][0]++; b[c][b[c][0]]=aa;a[c][aa]=io;}}
   
     cin>>qi>>zhong;
     
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
    while(cin>>n>>m)
    {
    memset(l,0,sizeof(l));
    memset(w,0,sizeof(w));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    init();
    if(qi==zhong)
    {memset(a,0,sizeof(a));
     memset(b,0,sizeof(b));
     cout<<0<<endl;}
     else
    {
    for(i=0;i<=n;i++)
    d[i]=1000000;
    doing(qi);
    if(l[zhong]>0)
    {cout<<l[zhong]<<endl;}
    else cout<<-1<<endl;
    }
    }
    
    system("pause");
    return 0;
}
