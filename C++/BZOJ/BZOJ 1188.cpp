#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,ans,sum,p[30],sg[30],x,y,z;
bool mark[300];
void getsg()
{
    memset(sg,0,sizeof(sg));
    int i,j,k;
    for(i=n;i>=1;i--)
    {
        memset(mark,0,sizeof(mark));
        for(j=i+1;j<=n;j++)  for(k=j;k<=n;k++)  mark[sg[j]^sg[k]]=1;
        j=0;
        while(mark[j])  j++;
        sg[i]=j;
    }
} 
int main()
{
    int i,j,k,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)  scanf("%d",&p[i]);
        getsg();
        ans=0;sum=0;
        for(i=1;i<=n;i++) if(p[i] & 1)  ans^=sg[i];
        if(ans==0)  
        {
            printf("-1 -1 -1\n0\n");
        } 
        else
        {
            for(i=n;i>=1;i--)
            for(j=n;j>=i+1;j--)
            for(k=n;k>=j;k--)
            {
                if((ans ^ sg[i] ^ sg[j] ^ sg[k])==0)   {x=i-1;y=j-1;z=k-1;sum++;}
            }
            printf("%d %d %d\n%d\n",x,y,z,sum);
        }
    }
    //system("pause");
    return 0;
}