#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
string s,k,l;
string ans="";
int chang,jia,zc;
int x,y;
char ch;
char dx[100];
char xx[100];
int main()
{
    
    //freopen("vigenere.in","r",stdin);
    //freopen("vigenere.out","w",stdout);
    int i;
    for(i=1;i<=26;i++)
    {
       dx[i]=i+64;
       xx[i]=i+96;
    }
    for(i=27;i<=52;i++)
    {
       dx[i]=dx[i-26];
       xx[i]=xx[i-26];
    }
    cin>>k;
    cin>>s;
    l=k;
    zc=s.size();
    chang=k.size();
    jia=chang;
    while(chang<zc)
    {
       l+=k;
       chang+=jia;
    }
    
    for(i=0;i<=zc-1;i++)
    {
       y=int(s[i]);
       if(int(l[i])>=65 &&  int(l[i])<=90)
       {
          x=int(l[i])-65;
          if(y>=65 && y<=90)
          {
             ch=dx[y-64+26-x];
          }
          else
          {
             ch=xx[y-96+26-x];
          }
       }
       else 
       if(int(l[i])>=97 &&  int(l[i])<=122)
       {
          x=int(l[i])-97;
          if(y>=65 && y<=90)
          {
             ch=dx[y-64+26-x];
          }
          else
          {
             ch=xx[y-96+26-x];
          }
       }
       ans+=ch;
    }
   
    cout<<ans<<endl;
    
    
    //system("pause");
    return 0;
}