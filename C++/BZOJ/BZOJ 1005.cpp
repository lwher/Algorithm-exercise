#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int ans[2000],du[2001];
int n,m,tot;
void mul(int now[],int k)
{
     int i;
     int answer[2000]={0};
     for(i=1;i<=now[0];i++)
     {answer[i]+=now[i]*k;answer[i+1]+=answer[i]/10000;answer[i]%=10000;}
     while(answer[now[0]+1])
     {
        now[0]++;
        answer[now[0]+1]+=ans[now[0]]/10000;
        answer[now[0]]%=10000;
     }
     answer[0]=now[0];
     for(i=0;i<=answer[0];i++)
     ans[i]=answer[i];
}
void div(int now[],int k)
{
     int i,p=0;
     int answer[2000]={0};
     for(i=now[0];i>=1;i--)
     {answer[i]=(p*10000+now[i])/k;p=(p*10000+now[i])%k;}
     while(!answer[now[0]])
     now[0]--;
     if(now[0]==0)
     now[0]=1;
     answer[0]=now[0];
     for(i=0;i<=answer[0];i++)
     ans[i]=answer[i];
}
void print(int now[])
{
     int i;
     printf("%d",now[now[0]]);
     for(i=now[0]-1;i>=1;i--)
     printf("%.4d",now[i]);
     cout<<endl;
}
int main()
{
    cin>>n;
    int i,j;
    for(i=1;i<=n;i++)
    {
       cin>>j;
       if(!j)
       {
          if(n==1)  cout<<1<<endl;
          else
          cout<<0<<endl;
          return 0;
       }
       if(j==-1)  m++;
       else
       if(j>n-1)  {cout<<0<<endl;return 0;}
       else
       {du[0]++;du[du[0]]=j-1;tot+=du[du[0]];}
    }
    if(tot>n-2 || (m==0&&tot<n-2))  {cout<<0<<endl;return 0;}
    
    ans[0]=1;ans[1]=1;
    for(i=2;i<=tot;i++)
    mul(ans,i);
    for(i=1;i<=du[0];i++)
    for(j=2;j<=du[i];j++)
    div(ans,j);
    for(i=1;i<=n-2-tot;i++)
    mul(ans,m);
    if(tot>0)
    {
    for(i=2;i<=n-2;i++)
    mul(ans,i);    
    for(i=2;i<=tot;i++)
    div(ans,i);
    for(i=2;i<=n-2-tot;i++)
    div(ans,i);
    }
    print(ans);
    return 0;
}
