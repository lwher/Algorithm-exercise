#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,s,t,map[11][11];
int main(){
    int i,j,k,a,b,p;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) map[i][j]=3000000;
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&p);
        map[a][b]=min(map[a][b],p);
    }
    for(i=1;i<=n;i++) map[i][i]=0;
    for(k=1;k<=n;k++) for(i=1;i<=n;i++) for(j=1;j<=n;j++)
        if(map[i][k]+map[k][j]<map[i][j]) map[i][j]=map[i][k]+map[k][j];
    printf("%d\n",map[s][t]);
    system("pause");
    return 0;
}
