#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,in[30],nowin[30],q[30];
bool map[30][30];
char ch[30010][5];
void init(){
    memset(map,0,sizeof(map));
    memset(in,0,sizeof(in)); 
    for(int i=1;i<=m;i++) scanf("%s",ch[i]);    
}
int topsort(){// 1:OK 2:unknown 3:error
    int i,now,t=1,w=0,cnt=0,res=1;
    for(i=1;i<=n;i++){
        nowin[i]=in[i];
        if(!in[i]){
            q[++w]=i;
            cnt++;
        }
    }
    if(cnt>1) res=2;
    while(t<=w){
        now=q[t];t++;cnt=0;
        for(i=1;i<=n;i++) if(map[now][i]){
            nowin[i]--;
            if(!nowin[i]){
                cnt++;
                q[++w]=i;
            }
        }
        if(cnt>1) res=2;
    }
    if(w<n) res=3;
    return res;
}
void solve(){
   int A,B,type;
   for(int i=1;i<=m;i++){
       A=ch[i][0]-'A'+1;
       B=ch[i][2]-'A'+1;
       map[A][B]=1;
       in[B]++;
       type=topsort();
       if(type==1){
           printf("Sorted sequence determined after %d relations: ",i);  
           for(int j=1;j<=n;j++) printf("%c",q[j]-1+'A');  
           puts(".");  
           return;
       }
       if(type==3){
           printf("Inconsistency found after %d relations.\n",i);
           return;
       }
   }
   puts("Sorted sequence cannot be determined."); 
}
int main(){
    while(scanf("%d%d",&n,&m) && n && m){
        init();
        solve();
    }
    system("pause");
    return 0;
}
