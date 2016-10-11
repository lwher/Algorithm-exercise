#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;
int n,A,B,num[100010];
map<int, int> p;
bool dfs(int x){
     if(!p[B-x]) return 0;
     if(p[B-x]==1){
         p[B-x]=2;
         if(!dfs(B-x)) return 0;
     }
     if(p[A-x]==1){
         p[A-x]=2;
         if(!dfs(A-x)) return 0;
     }
     return 1;
}
void init(){
    int i;
    scanf("%d%d%d",&n,&A,&B);
    for(i=1;i<=n;i++){
        scanf("%d",&num[i]);
        p[num[i]]=1;
    }
}
void solve(){
    int i;
    for(i=1;i<=n;i++) if(p[num[i]]==1 && !p[A-num[i]]){
        p[num[i]]=2;
        if(!dfs(num[i])){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    for(i=1;i<=n;i++) printf("%d ",p[num[i]]-1);
}
int main(){
    init();
    solve();
    return 0;
}