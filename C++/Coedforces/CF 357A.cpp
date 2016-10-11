#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int m,x,y;
bool o;
int c[110];
inline bool comp(int a,int b)
{
       return a>b;
}
int main()
{
    int i,j,sum=0,now=0;
    scanf("%d",&m);
    for(i=1;i<=m;i++) {scanf("%d",&c[i]);sum+=c[i];}
    scanf("%d%d",&x,&y);
    for(i=1;i<=m;i++)
    {
        now+=c[i-1];
        if(now>=x && now<=y && sum-now>=x && sum-now<=y) {o=1;cout<<i<<endl;break;} 
    }
    if(!o)
    cout<<0<<endl;
    system("pause");
    return 0;
}
