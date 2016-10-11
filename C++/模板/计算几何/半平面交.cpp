/*
	半平面交 时间复杂度:O(nlogn) POJ 2451
	该代码中半平面的存储方式均为 a->b然后向右转 
*/
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 20010
#define eps 1e-9 
using namespace std;
struct point{
    double x,y;
}Inter[N];
struct bpm{
    point a,b;
    double alp; //极角 
}L[N],Q[N];
int n;
point operator -(const point &a,const point &b){
    point c;c.x=a.x-b.x;c.y=a.y-b.y;
    return c;
}
double operator *(const point &a,const point &b){
    return a.x*b.y-a.y*b.x;
}
double Turnto(point a,point b,point c){//>0 向右 
    return (c-a)*(b-a);
}
void addbpm(int now,point a,point b){
    L[now].a=a;L[now].b=b;
    L[now].alp=atan2(a.y-b.y,a.x-b.x);
}
bool comp(const bpm &a,const bpm &b){
    if(fabs(a.alp-b.alp)<eps){
        if(Turnto(a.a,a.b,b.a)>-eps) return 0;
        else return 1;
    }
    else return a.alp<b.alp;
}
point Get_Interpoint(bpm A,bpm B){
    point Ans;double k1,k2,k3;
    k1=(B.a-A.a)*(A.b-A.a);
    k2=(A.b-A.a)*(B.b-A.a);
    k3=k1/(k1+k2);
    Ans.x=B.a.x+k3*(B.b.x-B.a.x);
    Ans.y=B.a.y+k3*(B.b.y-B.a.y);
    return Ans;
}
void init(){
    point A,B,C,D;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&A.x,&A.y);
        scanf("%lf%lf",&B.x,&B.y);
        addbpm(i,B,A);
    }
    A.x=0;A.y=0;B.x=0;B.y=10000;C.x=10000;C.y=10000;D.x=10000;D.y=0;
    addbpm(++n,A,B);addbpm(++n,B,C);addbpm(++n,C,D);addbpm(++n,D,A);
}
void HalfPlaneInter(){// 求半平面交 
    int i,t=1,w=1;        
    sort(L+1,L+1+n,comp);
    Q[1]=L[1];
    for(i=2;i<=n;i++){
        if(fabs(L[i].alp-L[i-1].alp)<eps) continue;
        bpm now=L[i];
        while(t<w && Turnto(now.a,now.b,Inter[w-1])<eps) w--;
        while(t<w && Turnto(now.a,now.b,Inter[t])<eps) t++;
        Q[++w]=now;Inter[w-1]=Get_Interpoint(Q[w-1],Q[w]);
    }
    int l=-1,r=t+1;
    while(l<t || r>w){
        l=t;r=w;
        while(t<w && Turnto(Q[t].a,Q[t].b,Inter[w-1])<eps) w--;
        while(t<w && Turnto(Q[w].a,Q[w].b,Inter[t])<eps) t++;
    }
    //下面为求半平面交面积部分
    if(w-t<2){
        printf("0.0\n");return;
    }
    double ans=0;
    Q[++w]=Q[t];Inter[w-1]=Get_Interpoint(Q[w-1],Q[w]);    
    Inter[w]=Inter[t];
    for(i=t;i<w;i++) ans+=Inter[i]*Inter[i+1];
    if(ans<0) ans=-ans;
    ans*=0.5;
    printf("%.1lf\n",ans);
}
int main(){
    init();
    HalfPlaneInter();
    return 0;
}
