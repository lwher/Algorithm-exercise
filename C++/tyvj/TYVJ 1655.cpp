#include<iostream>
#include<memory.h>
using namespace std;
long n,m;
int tim[1001];
bool o;
long l,r,mid;
bool t[1001];
void doing()
{
     int i;
     int num=0;long nn=0;
     memset(t,0,sizeof(t));
     for(i=1;i<=m;i++)
     { 
     if((mid-1)%tim[i]==0){num++;t[i]=1;}
     nn+=((mid-2)+tim[i])/tim[i];
    
     }
     
     if(nn>=n)              {r=mid-1;return;}
     if(nn+num<n)           {l=mid+1;return;}
    
      for(i=1;i<=m;i++)
     { 
     if(t[i])
     {
     nn++;
     if(nn==n)
     {cout<<i;o=1;return;}}}}
    int main()
    {
    int i;
    
    cin>>n>>m;
    for(i=1;i<=m;i++)
    cin>>tim[i];
    l=1;r=200000000;
    
    while(l<=r)
    {
    mid=(l+r)/2;
    doing();
    if(o)break;
    }
    system("pause");
    return 0;
}
