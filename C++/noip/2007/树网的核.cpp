#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,s;
int map[310][310];
int main()
{
    int i,j,k,m,a,b,c;
    cin>>n>>s;
    for(i=1;i<=n;i++) for(j=1;j<=n;j++)  if(i!=j)  map[i][j]=1e8;
    for(i=2;i<=n;i++)  
    {
         scanf("%d%d%d",&a,&b,&c);map[a][b]=c;map[b][a]=c;
    }
    for(k=1;k<=n;k++) for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  
    if(map[i][k]+map[k][j]<map[i][j])  map[i][j]=map[i][k]+map[k][j];
    m=0;for(i=1;i<=n;i++)   if(map[1][i]>m)  {a=i;m=map[1][i];}
    m=0;for(i=1;i<=n;i++)   if(map[a][i]>m)  {b=i;m=map[a][i];}
    m=1e8;    
    for(i=1;i<=n;i++) 
    if(map[a][i]+map[i][b]==map[a][b])
    for(j=1;j<=n;j++) 
    if(map[a][j]+map[j][b]==map[a][b])
    if(map[i][j]<=s && max(min(map[a][i],map[a][j]),min(map[b][i],map[b][j]))<m)
    m=max(min(map[a][i],map[a][j]),min(map[b][i],map[b][j]));
    cout<<m<<endl;
    system("pause");
    return 0;
}
