#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1000000009; 
int d[1000005],h[65],p[1000005],tot=0,L=inf,R=-1,An=inf; 
typedef struct gift
{     
      int x,y;     
      gift(){}     
gift(int _x,int _y):x(_x),y(_y){}     
inline bool operator < (gift b)const
          {         
          if(d[x]==d[b.x])
          {             
                        if(y==-1)   return 0;   
                        if(b.y==-1) return 1;             
                        return d[y]>d[b.y];         
          }
          return d[x]>d[b.x];     
          } 
}; priority_queue<gift>Q; 
inline void read(int &x)
{     
      char ch;    
      for(ch=getchar();ch<'0'||ch>'9';ch=getchar());     
      x=ch-'0';   
      for(ch=getchar();ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0'; 
}
int main()
{     
      int n,k,t,x;    
      read(n);    read(k);    memset(p,0xff,sizeof(p));     
      while(!Q.empty())   Q.pop();     
      for(int i=1;i<=k;i++)
      {         
                read(t);    read(d[h[i]=tot++]);         
                for(int x=h[i],j=2;j<=t;j++,x=p[x])    p[x]=tot++, 
                read(d[p[x]]);         
                Q.push(gift(h[i],p[h[i]]));   
                L=min(L,d[h[i]]),    
                R=max(R,d[h[i]]);     
      }
      An=R-L;     
      while(Q.top().y!=-1)
      {         
                gift u=Q.top();    
                Q.pop();         
                if(d[u.y]>R)   R=d[u.y];  Q.push(gift(u.y,p[u.y]));         
                if(R-d[Q.top().x]<An)    An=R-d[Q.top().x];     
      }
      printf("%d\n",An);     
      return 0; 
} 
