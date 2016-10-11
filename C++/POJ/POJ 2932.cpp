#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
#define N 40010
using namespace std;
struct yuan{
    double x,y,r;
}p[N];
struct sth{
    double x;
    int pos;
}q[N<<1];
bool mark[N];
int n,ans;
set<pair<double,int> > t;
set<pair<double,int> >::iterator it;
inline bool comp(const sth &a,const sth &b){
    return a.x<b.x;
}
void init(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf%lf%lf",&p[i].r,&p[i].x,&p[i].y);
}
double dist(const yuan &a,const yuan &b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cir_inside(const yuan &a,const yuan &b){
    if(dist(a,b)<=b.r) return 1;
    return 0;
}
void solve(){
    for(int i=1;i<=n;i++){
        q[i].x=p[i].x-p[i].r;q[i].pos=i;
        q[i+n].x=p[i].x+p[i].r;q[i+n].pos=i+n;
    }
    int nn=n<<1;
    sort(q+1,q+1+nn,comp);    
    for(int i=1;i<=nn;i++){
        int now=q[i].pos;
        if(now<=n){
            it=t.lower_bound(make_pair(p[now].y,now));
            if(it!=t.end() && cir_inside(p[now],p[it->second]))   continue;
            if(it!=t.begin() && cir_inside(p[now],p[(--it)->second]))  continue;
            ans++;mark[now]=1;
            t.insert(make_pair(p[now].y,now));
        }
        else t.erase(make_pair(p[now-n].y,now-n));
    }
}
void output(){
    printf("%d\n",ans);
    for(int i=1;i<=n;i++) if(mark[i]) printf("%d ",i);
}
int main(){
    init();
    solve();
    output();
    return 0;
}