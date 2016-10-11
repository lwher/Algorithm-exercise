#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100001
int N,m,c[maxn],tp[maxn],V[maxn],M;
struct Sort{int id,val;}a[maxn];
struct OPT{int opt,x;}test[maxn];
inline void read(int &x){scanf("%d",&x);}
inline void print(int x){printf("%d\n",x);}
inline int lowbit(int x){return x&-x;}
inline bool cmp(const Sort &a,const Sort &b){return a.val<b.val;}
inline void Disp(){
   sort(a+1,a+1+m,cmp),a[0].val=123456789;M=0;
   for(int i=1;i<=m;++i)if(a[i].val==a[i-1].val)test[a[i].id].x=M;else test[a[i].id].x=++M,tp[M]=i;
}
inline int getkth(int k){
     int ans=0,cnt=0,i;
     for(i=20;i>=0;--i){ans+=1<<i;if(ans>=M||cnt+c[ans]>=k)ans-=1<<i;else cnt+=c[ans];
     }return ans+1;
}

int main(){
   read(N);
   for(int i=1;i<=N;++i){
       read(test[i].opt),read(test[i].x);
       if(test[i].opt^4)a[++m].id=i,a[m].val=test[i].x;
   }
   Disp();
   for(int i=1;i<=N;++i){
       OPT f=test[i];
       if(f.opt==1){for(int j=f.x;j<=m;j+=lowbit(j))c[j]++;V[f.x]++;continue;}
       if(f.opt==2){for(int j=f.x;j<=m;j+=lowbit(j))c[j]--;V[f.x]--;continue;}
       if(f.opt==3){int sum=0;
           for(int j=f.x;j>=1;j-=lowbit(j))sum+=c[j];
           print(sum-V[f.x]+1);continue;
       }
       if(f.opt==4){print(a[tp[getkth(f.x)]].val);continue;}
       int sum=0;
       for(int j=f.x;j>=1;j-=lowbit(j))sum+=c[j];
       if(f.opt==5)sum-=V[f.x];else sum++;
       print(a[tp[getkth(sum)]].val);
   }
   system("pause");
   return 0;
}
