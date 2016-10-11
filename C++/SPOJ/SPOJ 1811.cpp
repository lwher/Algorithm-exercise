#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int to[500010][26],next[500010],step[500010];
int la,lb,ans,len,root,sz,last;
char A[250010],B[250010];
void add(int id)
{
     int p=last,np=++sz;step[np]=step[p]+1;
     last=np;
     for(;p!=-1 && !to[p][id];p=next[p])   to[p][id]=np;
     if(p==-1) next[np]=0;
     else
     {
         int q=to[p][id];
         if(step[q]==step[p]+1)   next[np]=q;
         else
         {
             int nq=++sz;step[nq]=step[p]+1;
             next[nq]=next[q];
             next[q]=nq;next[np]=nq;
             for(int i=0;i<26;i++)  to[nq][i]=to[q][i];
             for(;p!=-1 && to[p][id]==q;p=next[p])  to[p][id]=nq;  
         }
     }
}
int main()
{
    int i,now,k;
    next[0]=-1;
    scanf("%s",A+1); la=strlen(A+1);
    scanf("%s",B+1); lb=strlen(B+1);
    for(i=1;i<=la;i++)  add(A[i]-'a');
    now=0;
    for(i=1;i<=lb;i++)
    {
         k=B[i]-'a';
         if(to[now][k])  {now=to[now][k];len++;}
         else
         {
            for(;now!=-1 && !to[now][k];now=next[now]);
            if(now==-1)  {now=0;len=0;}
            else
            {
                len=step[now]+1;
                now=to[now][k];
            }
         }
         if(len>ans)  ans=len;
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}
