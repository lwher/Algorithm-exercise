#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<string.h>
using namespace std;
int t,n;
string ss[4010];
int len[4010];
int next[210];
string s;
int sz;
int ans;
int minn;
string answer;
int chang;
void getnext()
{
     
     int j=0,k=-1;
     next[0]=-1;
     while(j<chang)
     {
         if(k==-1 || s[j]==s[k])
         {
           j++;
           k++;
           next[j]=k;
         }
         else
         k=next[k];
     }
}
bool kmp(int top)
{
     int i=0,j=0;
     while(i<len[top])
     {
           if(j==-1 || s[j]==ss[top][i])
           {
                    i++;
                    j++;
           }      
           else
           j=next[j];
           if(j==chang)  return 1;
     }
     return 0;
}
bool check()
{
     int i,j;
     getnext();
     for(i=2;i<=n;i++)
     {
        if(!kmp(i))  return 0;
     }
     return 1;
}
int main()
{
    
             
              char ch;
              while(scanf("%d",&n))
    {
              if(n==0) break;
              ans=0;answer="";minn=2147483647;
              int i,j;
              for(i=1;i<=n;i++)
              {
              cin>>ss[i];
              len[i]=ss[i].size();
              if(len[i]<minn)minn=len[i];
              }
              
              sz=ss[1].size();
              for(i=0;i<sz;i++)
              {
              for(j=1;i+j<=sz;j++)
              {
                 if(j>minn) break;
                 if(j<ans)  continue;
                 s=ss[1].substr(i,j);
                 if(j==ans && s>answer) continue;
                 chang=j;
                 if(check())
                 {ans=chang;answer=s;}
              }
              }
              if(ans==0) printf("IDENTITY LOST\n");
              else
              cout<<answer<<endl;
    }
    system("pause");
    return 0;
}
