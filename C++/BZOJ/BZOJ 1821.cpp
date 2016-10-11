#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
struct Node
{
     int x1,x2;double dist;
     bool operator <(const Node &a)const
     {
          return dist<a.dist;
     }
}q[500010];
int tot=0;
double dis(int x1,int x2,int y1,int y2)
{
       return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int p[1010];
int find(int x)
{
    if(x==p[x]) return x;
    return p[x]=find(p[x]);
}
int main()
{
        scanf("%d%d",&n,&k);        
        int x[n+5],y[n+5];        
        for(int i=1;i<=n;i++)        
        {
        scanf("%d%d",&x[i],&y[i]);        
        for(int j=i-1;j>=1;j--)    {q[++tot].x1=j;q[tot].x2=i;q[tot].dist=dis(x[i],x[j],y[i],y[j]);  }    
        }       
        sort(q+1,q+tot+1);
        for(int i=1;i<=n;i++) p[i]=i;        
        int m=n,i=1,xx,yy;     
        while(1)       
        {
            xx=find(q[i].x1),yy=find(q[i].x2);        
            if(xx!=yy)        
            {
                p[xx]=yy;m--;     
                if(m<k)  {printf("%.2lf\n",sqrt(q[i].dist));break;}       
            }
            i++;       
        }    
        system("pause");
        return 0;
}


