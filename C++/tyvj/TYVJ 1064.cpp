#include<iostream>
#include<cstdio>
#include<cstring>
#define max 20000000
struct ads
{
    short c;    
    short g;   
    short s;    
    bool use;
     
}r[5001],temp;
int min(int a,int b)
{
    return a>b?b:a;
}
short father[301];
int find(int x) 
{
    if(x!=father[x])
    {
       father[x]=find(father[x]);
    }
    return father[x];
}
short check[52][52][5001]={ 0 }; 
int main()
{
    int m,n,t,v,k,i,j,p,l,w;
    int t1,t2,x1,y1;
    int tot;
    int ans,cost;
    
    int day[52]={ 0 };
    short city[301][301]={ 0 };
    
    scanf("%d %d %d %d %d/n",&n,&m,&t,&v,&k);
    for(i=1;i<=m;i++)
    {
       scanf("%d %d %d/n",&r[i].c,&r[i].g,&r[i].s);
       r[i].s*=v;
       r[i].use=1;      
    } 
    for(i=0;i<=t+1;i++)
    {
       day[i]=max;
    }
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
       {
            city[i][j]=-1;
       }
    }
    for(i=1;i<=m;i++)
    {
       for(j=1;j<=m-1;j++)
       {
           if(r[j].s>r[j+1].s)
           {
                 temp=r[j];
                 r[j]=r[j+1];
                 r[j+1]=temp;
           }
       }
    }
    day[0]=0;
    for(i=1;i<=m;i++)
    {
        city[r[i].c][r[i].g]=i;
        city[r[i].g][r[i].c]=i;
    }
    scanf("%d/n",&p);
    for(w=1;w<=p;w++)
    {
        scanf("%d %d %d %d/n",&x1,&y1,&t1,&t2);
        if(city[x1][y1]!=-1)
        {
           for(i=0;i<=t2;i++)
           {
               for(j=t1;j<=t;j++)
               {
                   if(j>=i)
                   {
                      check[i][j][city[x1][y1]]=1;
                   }
               }
           }
        }
        
    }
    for(i=1;i<=t;i++)
    {
       for(j=0;j<i;j++)
       {
           cost=0;                                           
           for(w=1;w<=n;w++)                             
           {
               father[w]=w;
           }       
           for(w=1;w<=m;w++)
           {
               if(find(r[w].c)!=find(r[w].g) && check[j+1][i][w]!=1)
               {
                     father[father[r[w].g]]=father[r[w].c];
                     cost+=r[w].s;
               }
           }                                  
           day[i]=min(day[i],day[j]+cost*(i-j)+k);
       }
    }
    printf("%d\n",day[t]);
    //while(1);
    return 0;    
}
