#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
using namespace std; 
int n,m,q,ans; 
int map[310][310]; 
int t[110][310][310]; 
int lowbit(int x) 
{ 
    return x & (-x); 
} 
void updata(int a,int x,int y,int z) 
{ 
    int p; 
    while(x<=n) 
    { 
        p=y; 
        while(p<=m)  {t[a][x][p]+=z;p+=lowbit(p);} 
        x+=lowbit(x); 
    } 
} 
int get(int a,int x,int y) 
{ 
    int sum=0,p; 
    while(x>0) 
    { 
        p=y; 
        while(p>0)  {sum+=t[a][x][p];p-=lowbit(p);} 
        x-=lowbit(x); 
    } 
    return sum; 
} 
int main() 
{ 
    //freopen("count.in","r",stdin); 
    //freopen("count.out","w",stdout); 
    int k,i,j,x1,y1,x2,y2,c; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)   
    { 
        scanf("%d",&map[i][j]); 
        updata(map[i][j],i,j,1); 
    } 
    scanf("%d",&q); 
    while(q--) 
    { 
        scanf("%d",&k); 
        if(k==1) 
        { 
            scanf("%d%d%d",&x1,&y1,&c); 
            updata(map[x1][y1],x1,y1,-1); 
            map[x1][y1]=c; 
            updata(map[x1][y1],x1,y1,1); 
        } 
        else
        { 
            ans=0; 
            scanf("%d%d%d%d%d",&x1,&x2,&y1,&y2,&c); 
            printf("%d\n",get(c,x2,y2)-get(c,x1-1,y2)-get(c,x2,y1-1)+get(c,x1-1,y1-1)); 
        } 
    } 
    //system("pause"); 
    return 0; 
}