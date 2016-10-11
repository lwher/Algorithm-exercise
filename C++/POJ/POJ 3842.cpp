#include<iostream>
#include<string>
#include<stdio.h>
#include<cmath>
#include<stdlib.h>
using namespace std;
bool mark[8];
bool sss[10000000],pp[10000000];
int aa[500000];
int c;
string s;
int ans;
bool  ss(int ii)
{
      if((ii==1)||(ii==0)) return 0;
      int i;
      for(i=2;i<=sqrt(ii);i++)
      if(ii%i==0){sss[ii]=1; return 0;}
      return 1;
}
void doing(int ii)
{
    // int ii;
     int o;
     if((!sss[ii])&&(!pp[ii])&&(ss(ii)))
     {pp[ii]=1;ans++;aa[ans]=ii;}
     int i;
     for(i=0;i<=s.size()-1;i++)
     {
        if(!mark[i])
        {mark[i]=1;o=s[i]-'0';
        doing(ii*10+o);
        mark[i]=0;
        }
     }
}
int main()
{
    string o="";
    int i,j;
    
    cin>>c;
    for(i=1;i<=c;i++)
    {
    cin>>s;
    doing(0);
    printf("%d\n",ans);
    for(j=1;j<=ans;j++)
    pp[aa[j]]=0;
    ans=0;
    }
    system("pause");
    return 0;
}
