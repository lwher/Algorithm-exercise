/*
    AC自动机 HDU 2222
    此代码支持输入一堆短单词，然后输入一个长字符串，处理出这些短单词中有多少个被长字符串包含。 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 500001
using namespace std;
int n,T,L,sz,ans,son[N][26],fail[N],danger[N],Q[N];
char p[51],s[N<<1];
void Trie_clear(int x){
    fail[x]=0;danger[x]=0;
    memset(son[x],0,sizeof(son[x]));
}
void Trie_Ins(char S[]){
    int i,k,len=strlen(S+1),now=0;
    for(i=1;i<=len;i++){
        k=S[i]-'a';
        if(!son[now][k]){
            son[now][k]=++sz;
            Trie_clear(sz);
        }
        now=son[now][k];
    }
    danger[now]++;
}
void Get_fail(){
    int i,k,p,now,t=1,w=1;
    Q[1]=0;fail[0]=-1;
    while(t<=w){
        now=Q[t];t++;
        for(i=0;i<26;i++){
            p=son[now][i];
            if(!p) continue;
            for(k=fail[now];k!=-1 && !son[k][i];k=fail[k]);
            if(k==-1) fail[p]=0;
            else fail[p]=son[k][i];
            Q[++w]=p;
        }
    }
}
void init(){
    sz=0;danger[0]=0;
    memset(son[0],0,sizeof(son[0]));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",p+1);
        Trie_Ins(p);
    }
    scanf("%s",s+1);
    L=strlen(s+1);
}
void solve(){
    int i,p,k,now=0;ans=0;
    Get_fail();
    for(i=1;i<=L;i++){
        k=s[i]-'a';
        for(p=now;p!=-1 && !son[p][k];p=fail[p]);
        if(p==-1) now=0;
        else now=son[p][k];
        for(p=now;p!=-1 && danger[p]!=-1;p=fail[p]){
            ans+=danger[p];
            danger[p]=-1;
        }
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--){
        init();
        solve();
    }
    system("pause");
    return 0;
}
