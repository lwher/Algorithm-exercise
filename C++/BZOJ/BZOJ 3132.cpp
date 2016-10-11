#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#define MAXN 2049 
using namespace std; 
int n,m; 
int a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN],d[MAXN][MAXN]; 
// a: a[i][j] b:a[i][j]*i  c:a[i][j]*j d:a[i][j]*i*j 
inline int lowbit(int x) 
{ 
    return x & (-x); 
} 
void gs(int e[][MAXN],int x,int y,int k) 
{ 
    for(int i=x;i<=n;i+=lowbit(i)) 
    for(int j=y;j<=m;j+=lowbit(j)) 
    e[i][j]+=k; 
} 
int ask(int e[][MAXN],int x,int y) 
{ 
    int now=0; 
    for(int i=x;i>0;i-=lowbit(i)) 
    for(int j=y;j>0;j-=lowbit(j)) 
    now+=e[i][j]; 
    return now; 
} 
void updata(int x1,int y1,int x2,int y2,int w) 
{ 
    gs(a,x1,y1,w);gs(a,x2+1,y1,-w);gs(a,x1,y2+1,-w);gs(a,x2+1,y2+1,w); 
    gs(b,x1,y1,w*x1);gs(b,x2+1,y1,-w*(x2+1));gs(b,x1,y2+1,-w*x1);gs(b,x2+1,y2+1,w*(x2+1)); 
    gs(c,x1,y1,w*y1);gs(c,x2+1,y1,-w*y1);gs(c,x1,y2+1,-w*(y2+1));gs(c,x2+1,y2+1,w*(y2+1)); 
    gs(d,x1,y1,w*x1*y1);gs(d,x2+1,y1,-w*(x2+1)*y1);gs(d,x1,y2+1,-w*x1*(y2+1));gs(d,x2+1,y2+1,w*(x2+1)*(y2+1)); 
} 
int getsum(int x,int y) 
{ 
     return ask(a,x,y)*(x+1)*(y+1)-(y+1)*ask(b,x,y)-(x+1)*ask(c,x,y)+ask(d,x,y);     
} 
int main() 
{ 
    int i,x1,y1,x2,y2,w; 
    char s[3]; 
    scanf("%s%d%d",s,&n,&m); 
    while(scanf("%s",s)!=EOF) 
    { 
        if(s[0]=='L') 
        { 
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&w); 
            updata(x1,y1,x2,y2,w); 
        } 
        else
        { 
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2); 
            printf("%d\n",getsum(x2,y2)-getsum(x2,y1-1)-getsum(x1-1,y2)+getsum(x1-1,y1-1)); 
        } 
    } 
    //system("pause"); 
    return 0; 
}