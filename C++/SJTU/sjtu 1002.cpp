#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,A,B,ans,sum[1010][1010];
inline int calc(int a,int b,int c,int d){
       return sum[c][d]-sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1];
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%d",&sum[i][j]);
    scanf("%d%d",&A,&B);
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) sum[i][j]+=sum[i][j-1];
    for(j=1;j<=m;j++) for(i=1;i<=n;i++) sum[i][j]+=sum[i-1][j];
    for(i=A;i<=n;i++) for(j=B;j<=m;j++) ans=max(ans,calc(i-A+1,j-B+1,i,j));
    printf("%d\n",ans);
    system("pause");
    return 0;
}
