#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;
struct sth
{
       double a,b;
       int bh;
}xian[50010];
int n;
int top,bpm[50010];
bool ok[50010];
inline bool comp(sth aa,sth bb)
{
       if(fabs(aa.a-bb.a)<eps)  return aa.b>bb.b;
       return aa.a<bb.a;
}
double jiaox(sth aa,sth bb)
{
       return ((bb.b-aa.b)/(aa.a-bb.a));
}
void solvebpm()
{
     top=1;
     bpm[top]=1;
     int i;
     for(i=2;i<=n;i++)
     {
        if(fabs(xian[i].a-xian[i-1].a)<eps)  continue;
        while(top>1 && (jiaox(xian[i],xian[bpm[top]])<jiaox(xian[bpm[top]],xian[bpm[top-1]]) || fabs(jiaox(xian[i],xian[bpm[top]])-jiaox(xian[bpm[top]],xian[bpm[top-1]]))<eps))
        top--;
        top++;bpm[top]=i;
     }
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {scanf("%lf%lf",&xian[i].a,&xian[i].b);xian[i].bh=i;}
    sort(xian+1,xian+1+n,comp);
    solvebpm();
    for(i=1;i<=top;i++)
    ok[xian[bpm[i]].bh]=1;
    for(i=1;i<=n;i++)
    if(ok[i])
    printf("%d ",i);
    system("pause");
    return 0;
}
