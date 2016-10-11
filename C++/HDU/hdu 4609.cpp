#include<iostream>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define N 300001
using namespace std;
const double PI=acos(-1.0);
struct complex{
    double re,im;
    complex(double r=0,double i=0){
        re=r;im=i;
    } 
    complex operator +(const complex &b){
        return complex(re+b.re,im+b.im);
    }
    complex operator -(const complex &b){
        return complex(re-b.re,im-b.im);
    }
    complex operator *(const complex &b){
        return complex(re*b.re-im*b.im,re*b.im+im*b.re);
    }
};
int n,A[N],len;
long long num[N],sum[N];
complex P[N],size[N];
int rev(int id){
    int res=0;
    for(int i=0;(1<<i)<len;i++){
        res<<=1;
        if(id & (1<<i)) res|=1;
    }
    return res;
}
void FFT(complex p[],int DFT){
    for(int i=0;i<len;i++) P[rev(i)]=p[i];
    for(int s=1;(1<<s)<=len;s++){
        int m=(1<<s);
        complex wm=complex(cos(DFT*2*PI/m),sin(DFT*2*PI/m));
        for(int j=0;j<len;j+=m){
            complex w=complex(1,0);
            for(int k=0;k<(m>>1);k++){
                complex u=P[j+k];
                complex t=w*P[j+k+(m>>1)];
                P[j+k]=u+t;
                P[j+k+(m>>1)]=u-t;
                w=w*wm;
            }
        }
    }
    if(DFT==-1) for(int i=0;i<len;i++) P[i].re/=len;
    for(int i=0;i<len;i++) p[i]=P[i];
}
void init(){
    memset(num,0,sizeof(num));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);num[A[i]]++;
    }
    sort(A+1,A+1+n);
    int sa=0;
    while((1<<sa)<A[n]+1) sa++;
    len=(1<<sa+1);
    for(int i=0;i<len;i++) size[i]=complex(num[i]*1.0,0);
}
void solve(){    
    FFT(size,1);    
    for(int i=0;i<len;i++) size[i]=size[i]*size[i];
    FFT(size,-1);
    for(int i=0;i<len;i++) num[i]=(long long)(size[i].re+0.5);
    for(int i=1;i<=n;i++) num[A[i]<<1]--;
    for(int i=0;i<len;i++) num[i]/=2;    
    long long tot=0;sum[0]=0;
    for(int i=1;i<len;i++) sum[i]=num[i]+sum[i-1];
    for(int i=1;i<=n;i++){
        tot+=sum[len-1]-sum[A[i]];
        tot-=n-1;
        tot-=(long long)(i-1)*(n-i);
        tot-=(long long)(n-i)*(n-i-1)/2;
    }
    double Sum=(long long)n*(n-1)*(n-2)/6;
    printf("%.7lf\n",(double)tot/Sum);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        init();
        solve();
    }
    return 0;
}
