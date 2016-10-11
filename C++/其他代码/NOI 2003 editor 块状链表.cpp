#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
struct sth
{
       int next,pre,size;
       char buff[2500];
}kuai[2000];
int m,tot,sz,now;
int zhan[50000];
void split(int p,int k) 
{
     int q;
     if(zhan[0]>0)  {q=zhan[zhan[0]];zhan[0]--;}   else {sz++;q=sz;}
     kuai[q].size=0;kuai[q].pre=p;kuai[q].next=kuai[p].next;kuai[p].next=q;
     for(int i=k+1;i<=kuai[p].size;i++)
     {  
          kuai[q].size++;kuai[q].buff[kuai[q].size]=kuai[p].buff[i];
     } 
     kuai[p].size=k;
}
void balance(int cur)
{
     if(cur==-1 || cur==0)  return;
     int q=kuai[cur].next,limt=sqrt(tot);limt=max(limt,1000);
     if(q!=-1 && kuai[cur].size+kuai[q].size<=1.5*limt)
     { 
        zhan[0]++;zhan[zhan[0]]=q;
        for(int i=1;i<=kuai[q].size;i++)   kuai[cur].buff[i+kuai[cur].size]=kuai[q].buff[i];
        kuai[kuai[q].pre].next=kuai[q].next;
        if(kuai[q].next!=-1) kuai[kuai[q].next].pre=kuai[q].pre;
        kuai[cur].size+=kuai[q].size;
     }
}
void INS(int k)
{
     tot+=k;int q=-1,p=now,cur=0,limt=sqrt(tot),x,y;char ch;
     limt=max(limt,1000);
     while(p>kuai[cur].size && kuai[cur].next!=-1)  {p-=kuai[cur].size;cur=kuai[cur].next;}
     if(p<kuai[cur].size)  split(cur,p);   q=kuai[cur].next;
     if(zhan[0]>0)  {x=zhan[zhan[0]];zhan[0]--;}   else {sz++;x=sz;}
     kuai[x].size=0;kuai[x].pre=cur;kuai[cur].next=x;
     while(k)
     {
         ch=getchar();
         while(ch=='\n' || ch<32 || ch>126)  ch=getchar();
         kuai[x].size++;kuai[x].buff[kuai[x].size]=ch;
         if(kuai[x].size>=limt)  
         {
         if(zhan[0]>0)  {y=zhan[zhan[0]];zhan[0]--;}   else {sz++;y=sz;}
         kuai[y].size=0;kuai[y].pre=x;kuai[x].next=y;
         x=y;
         }
         k--; 
     }
     kuai[x].next=q;  if(q!=-1) kuai[q].pre=x;
     balance(x);balance(cur);
}
void SHANCHU(int k)
{
     if(k==0)  return;tot-=k;
     int p=now,q,cur=0;
     while(p>kuai[cur].size && kuai[cur].next!=-1)  {p-=kuai[cur].size;cur=kuai[cur].next;}
     if(p<kuai[cur].size)  split(cur,p);   q=kuai[cur].next;
     while(k>kuai[q].size && kuai[q].next!=-1)
     {
         k-=kuai[q].size;
         zhan[0]++;zhan[zhan[0]]=q;
         kuai[kuai[q].pre].next=kuai[q].next;
         kuai[kuai[q].next].pre=kuai[q].pre;
         q=kuai[q].next;
     }
     if(k>0)
     {
         if(k==kuai[q].size)   
         {
             zhan[0]++;zhan[zhan[0]]=q;
             kuai[kuai[q].pre].next=kuai[q].next;
             if(kuai[q].next!=-1)
             kuai[kuai[q].next].pre=kuai[q].pre;
         }
         else
         {
             split(q,k);
             zhan[0]++;zhan[zhan[0]]=q;
             kuai[kuai[q].pre].next=kuai[q].next;
             if(kuai[q].next!=-1)
             kuai[kuai[q].next].pre=kuai[q].pre;
         }
     }
     balance(cur);
}
void PRINT(int k)
{
     int i,p=now,cur=0;
     while(p>kuai[cur].size && kuai[cur].next!=-1)  {p-=kuai[cur].size;cur=kuai[cur].next;}
     if(p==kuai[cur].size)  {cur=kuai[cur].next;p=0;} i=p+1;
     while(k>0)
     {
         putchar(kuai[cur].buff[i]);
         i++;k--;
         while(i>kuai[cur].size)
         {
             cur=kuai[cur].next;i=1;
         }
     }
     printf("\n");
}
int main()
{
    freopen("editor.in","r",stdin);
    freopen("editor.out","w",stdout);
    kuai[0].next=-1;
    char s[10];int p;
    scanf("%d",&m);
    while(m--)
    {
              scanf("%s",s);
              if(s[0]=='M') {scanf("%d",&p);now=p;}  else
              if(s[0]=='P') {now--;}  else
              if(s[0]=='N') {now++;}  else
              if(s[0]=='I') {scanf("%d",&p);INS(p);}  else
              if(s[0]=='D') {scanf("%d",&p);SHANCHU(p);}  else
              if(s[0]=='G') {scanf("%d",&p);PRINT(p);} 
    }
    return 0;
}
