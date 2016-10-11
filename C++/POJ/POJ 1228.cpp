#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<math.h>
#define eps 1e-8
using namespace std;
struct sth
{
       double x,y;
}dian[1010];
int bao[10100];
int top;
int n;
double x1,y11;
double ans;
double juli(sth a,sth b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double chaji(double a,double b,double c,double d)
{
   return a*d-b*c;  
}
inline bool comp(sth a,sth b)
{
   if(a.x==b.x)
   return a.y<b.y;
   else
   return a.x<b.x;
}
int cp3(const void *a, const void *b)
{
    sth *p1=(sth *)a,*p2=(sth *)b;
    if(chaji((*p2).x-x1,(*p2).y-y11,(*p1).x-x1,(*p1).y-y11)<0)
    return -1;
    else
    if(fabs(chaji((*p2).x-x1,(*p2).y-y11,(*p1).x-x1,(*p1).y-y11))<eps && juli(*p1,dian[1])<juli(*p2,dian[1]))
    return -1;
    else 
    return 1;
}
void tubao()
{
     top=0;
     bao[++top]=1;
     bao[++top]=2;
     int i;
     for(i=3;i<=n;i++)
     {
         while(top>=2 && chaji(dian[i].x-dian[bao[top-1]].x,dian[i].y-dian[bao[top-1]].y,dian[bao[top]].x-dian[bao[top-1]].x,dian[bao[top]].y-dian[bao[top-1]].y)>eps)
         top--;
         bao[++top]=i;
     }
}

bool pd()
{
     int i;
     bao[top+1]=1;
     
     for(i=2;i<=top;i++)
     {
        if(fabs(chaji(dian[bao[i-1]].x-dian[bao[i+1]].x,dian[bao[i-1]].y-dian[bao[i+1]].y,dian[bao[i]].x-dian[bao[i+1]].x,dian[bao[i]].y-dian[bao[i+1]].y))>eps)
        if(i+2>top+1 || fabs(chaji(dian[bao[i]].x-dian[bao[i+2]].x,dian[bao[i]].y-dian[bao[i+2]].y,dian[bao[i+1]].x-dian[bao[i+2]].x,dian[bao[i+1]].y-dian[bao[i+2]].y))>eps)
        return 0;
     }
     return 1;
}
int main()
{
    freopen("aa.txt","r",stdin);
    freopen("ans.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
    scanf("%lf%lf",&dian[i].x,&dian[i].y);
    if(n<6)  printf("NO\n");
    else
    {
    sort(dian+1,dian+1+n,comp);
    x1=dian[1].x;y11=dian[1].y;
    qsort(dian+2,n-1,sizeof(dian[1]),cp3);    
    tubao();
    
    int j=bao[top]-1;
    int top1=top;
    while(j>1 && fabs(chaji(dian[j].x-dian[bao[top]].x,dian[j].y-dian[bao[top]].y,dian[bao[1]].x-dian[bao[top]].x,dian[bao[1]].y-dian[bao[top]].y))<eps)
    {top1++;bao[top1]=j;j--;}
    top=top1;
    
    if(j==1)  printf("NO\n");
    else
    if(pd()==0)  printf("NO\n");
    else
    printf("YES\n");
    }
    }
   // system("pause");
    return 0;
}
