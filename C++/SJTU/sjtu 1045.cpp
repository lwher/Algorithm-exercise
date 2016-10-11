#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int m,ans=1,last[200001],fa[200001];
int sz,to[500001],pre[500001];
bool alive[200001];
inline void add(int a,int b){
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
int main(){
    int i,k,x,y;
    char ch[3];
    alive[1]=1;
    scanf("%d",&m);
    while(m--){
        scanf("%s",ch);
        if(ch[0]=='B'){
            scanf("%d%d",&x,&y);
            alive[y]=1;fa[y]=x;
            add(x,y);
        }
        else{
            scanf("%d",&x);
            if(fa[x]==0) ans--;
            alive[x]=0;fa[x]=0;
            for(i=last[x];i;i=pre[i]){
                k=to[i];
                if(!alive[k] || fa[k]!=x) continue;
                fa[k]=0;ans++;
            }
            last[x]=0;
            printf("%d\n",ans);
        }
    }
    system("pause");
    return 0;
}
