#include<iostream>
#include<map>
#include<ctime>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define N 200001
using namespace std;
int n,root,sz,to[N],pre[N],last[N],f[N][2];
std::vector<int> size[N];
void Ins(int a,int b){
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
inline bool comp(int a,int b){
    return f[a][0]<f[b][0];
}
void DP(int x,int fa){
    f[x][0]=f[x][1]=1;size[x].clear();
    for(int i=last[x];i;i=pre[i]){
        if(to[i]==fa) continue;
        DP(to[i],x);
        size[x].push_back(to[i]);
    }
    int tot=size[x].size();
    if(!tot) return;
    if(tot==1){
        f[x][0]=f[x][1]=min(f[size[x][0]][1],f[size[x][0]][0]+1);return;
    }
    sort(size[x].begin(),size[x].end(),comp);
    for(int i=0;i<tot-2;i++){
        f[x][0]=max(f[x][0],f[size[x][i]][0]+1);
        f[x][1]=max(f[x][1],f[size[x][i]][0]+1);
    }
    f[x][0]=max(f[x][0],min(f[size[x][tot-2]][0]+1,f[size[x][tot-2]][1]));
    f[x][0]=max(f[x][0],min(f[size[x][tot-1]][0]+1,f[size[x][tot-1]][1]));
    
    f[x][1]=max(f[x][1],f[size[x][tot-2]][0]+1);
    f[x][1]=max(f[x][1],min(f[size[x][tot-1]][0]+1,f[size[x][tot-1]][1]));
}
int main(){
    int a,b;
    srand(time(NULL));
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
    }
    if(n<=3000)for(int i=1;i<=n;i++){
        root=i;
        DP(root,0);
        if(f[root][0]<3){
            printf("Yes\n");return 0;
        }       
    }
    else{
        for(int i=1;i<=101;i++){
            root=rand()%n+1;
            DP(root,0);
            if(f[root][0]<3){
                printf("Yes\n");return 0;
            }
        }
    }
    printf("No\n"); 
    return 0;
}
