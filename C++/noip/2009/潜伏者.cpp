#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
string a,b,c;
char ys[27],last[27];
bool used[27],o;
int sz;
int main()
{
    int i,len;
    cin>>a>>b>>c;
    len=a.size();
    for(i=0;i<len;i++)
    {
         if(!used[b[i]-'A'])
         {
              if(!ys[a[i]-'A'])  {used[b[i]-'A']=1;sz++;ys[a[i]-'A']=b[i];last[b[i]-'A']=a[i];}
              else   if(ys[a[i]-'A']!=b[i])  {o=1;break;}
         }
         else
         {
              if(last[b[i]-'A']!=a[i])  {o=1;break;}
         }
    }
    if(o || sz<26)  cout<<"Failed"<<endl;
    else
    {
        len=c.size();
        for(i=0;i<len;i++)  cout<<ys[c[i]-'A'];
        cout<<endl;
    }
    system("pause");
    return 0;
}
