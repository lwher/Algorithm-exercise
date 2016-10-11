#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
struct sth
{
     long  int a,b;
       bool c;
};
sth qj[100001];
bool mark[100001];
int n;
int wei=1;
long int x,y;
long int ax,ay,ans;
int main()
{    
     qj[1].a=0;
     qj[1].b=1000000000;
     qj[1].c=0;
     
    cin>>n;
    int i,j;
    char ch;
    for(i=1;i<=n;i++)
    {
      scanf("%d%d",&x,&y);
      cin>>ch;
      if(ch=='w')
      {
               for(j=1;j<=wei;j++)  
               {
               if(!mark[j] && qj[j].c==1)
               {
                 if(x==qj[j].a && y==qj[j].b)   qj[j].c=1;    else
                 if(x<=qj[j].a && y>qj[j].a)    qj[j].a=y;    else
                 if(x<qj[j].b && y>=qj[j].b)    qj[j].b=x;    else
                 if(x>qj[j].a && y<qj[j].b)    {wei++;qj[wei].a=y;qj[wei].b=qj[j].b;qj[wei].c=1;qj[j].b=x;}
               }
               if(!mark[j] && qj[j].c==0)
               {
                 if(x==qj[j].a && y==qj[j].b)   mark[j]=1;    else
                 if(x<=qj[j].a && y>=qj[j].b)   mark[j]=1;   else
                 if(x<qj[j].a && y>=qj[j].a)   {mark[j]=1; y=max(y,qj[j].b);}  else
                 if(x<=qj[j].b && y>qj[j].b)   {mark[j]=1; x=min(x,qj[j].a);}  else 
                 if(x>qj[j].a && y<qj[j].b)    {mark[j]=1; x=qj[j].a;y=qj[j].b; }   
               }
               }
               wei++;qj[wei].a=x;qj[wei].b=y;qj[wei].c=0;
      }
      if(ch=='b')
      {
               for(j=1;j<=wei;j++)  
               {
               if(!mark[j] && qj[j].c==0)
               {
                 if(x==qj[j].a && y==qj[j].b)  qj[j].c=1;    else
                 if(x<=qj[j].a && y>qj[j].a)    qj[j].a=y;   else
                 if(x<qj[j].b && y>=qj[j].b)    qj[j].b=x;   else
                 if(x>qj[j].a && y<qj[j].b)    {wei++;qj[wei].a=y;qj[wei].b=qj[j].b;qj[wei].c=0;qj[j].b=x;}
               }
               if(!mark[j] && qj[j].c==1)
               {
                 if(x==qj[j].a && y==qj[j].b)  mark[j]=1;  else 
                 if(x<=qj[j].a && y>=qj[j].b)    mark[j]=1;  else 
                 if(x<qj[j].a && y>=qj[j].a)   {mark[j]=1; y=max(y,qj[j].b);} else 
                 if(x<=qj[j].b && y>qj[j].b)   {mark[j]=1; x=min(x,qj[j].a);} else 
                 if(x>qj[j].a && y<qj[j].b)    {mark[j]=1; x=qj[j].a;y=qj[j].b; }
               }
               }
               wei++;qj[wei].a=x;qj[wei].b=y;qj[wei].c=1;
      }
    }
    
    for(i=1;i<=wei;i++)
    {
      if(!mark[i] && qj[i].b-qj[i].a>ans && qj[i].c==0)
      {ans=qj[i].b-qj[i].a;ax=qj[i].a;ay=qj[i].b;}
    }
    cout<<ax<<" "<<ay;
    
    system("pause");
    return 0;
}
