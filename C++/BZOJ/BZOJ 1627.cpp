#include<stdio.h>  
#include<iostream>  
#include<queue>  
#include<string.h>  
using namespace std;  
bool hash[1009][1009];  
int diri[4]={0,-1,0,1};  
int dirj[4]={-1,0,1,0};  
struct data  
{    int ni;    int nj;    int step;};  
void bfs(int ei,int ej)  
{    queue<data>q;      
data f,s,t;    f.ni=500;     
 f.nj=500;    f.step=0;      
q.push(f);    int i,j;      
while(!q.empty())    
  {        s=q.front();          
q.pop();         
 for(i=0;i<=3;i++)         
 {            t.ni=s.ni+diri[i];             
 t.nj=s.nj+dirj[i];             
 if(hash[t.ni][t.nj]==1)continue;         
     t.step=s.step+1;            
  if(t.ni==ei&&t.nj==ej)           
   {                printf("%d\n",t.step);                return ;            }     
         q.push(t);            hash[t.ni][t.nj]=1;        }   
   }}int main(){    int ei,ej,n;      
while(scanf("%d%d%d",&ei,&ej,&n)!=EOF)    
  {        ei+=500;        ej+=500;        int i;         
 memset(hash,0,sizeof(hash));         
 for(i=0;i<n;i++)        
  {            int a,b;            
  scanf("%d%d",&a,&b);         
     a+=500;            b+=500;     
         hash[a][b]=1;         
 }        bfs(ei,ej);      
}  
}