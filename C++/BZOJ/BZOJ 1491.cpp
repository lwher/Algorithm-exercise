#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
using namespace std; 
int n,m; 
long long map[101][101],sum[101][101]; 
double v[101]; 
int main() 
{ 
    int i,j,k,a,b,c; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  map[i][j]=1e15; 
    for(i=1;i<=n;i++)  map[i][i]=0; 
    for(i=1;i<=m;i++) 
    { 
        scanf("%d%d%d",&a,&b,&c); 
        map[a][b]=c;map[b][a]=c; 
        sum[a][b]=1;sum[b][a]=1; 
    } 
    for(k=1;k<=n;k++) 
    for(i=1;i<=n;i++) 
    for(j=1;j<=n;j++) 
    { 
        if(i==j || i==k || j==k)  continue; 
        if(map[i][k]+map[k][j]<map[i][j])  map[i][j]=map[i][k]+map[k][j],sum[i][j]=0; 
        if(map[i][k]+map[k][j]==map[i][j]) sum[i][j]+=sum[i][k]*sum[k][j]; 
    }    
    for(k=1;k<=n;k++) 
    for(i=1;i<=n;i++) 
    for(j=1;j<=n;j++) 
    { 
        if(sum[i][j]==0) continue; 
        if(i==j || i==k || j==k)  continue; 
        if(map[i][j]==map[i][k]+map[k][j])v[k]=v[k]+double(sum[i][k]*sum[k][j])/sum[i][j]; 
    } 
    for(i=1;i<=n;i++) printf("%.3lf\n",v[i]); 
//  system("pause"); 
    return 0; 
}