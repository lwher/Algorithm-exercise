/*
	FFT 快速傅里叶变换
	nlogn解决多项式乘法
	hdu 3743
	大整数高精度乘法 
*/ 
#include<iostream>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define N 150010
using namespace std;
const double PI=acos(-1.0);
struct complex{
    double re,im;
    complex(double r=0.0,double i=0.0){
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
int rev(int id,int len){
    int res=0;
    for(int i=0;(1<<i)<len;i++){
        res<<=1;
        if(id & (1<<i)) res|=1;
    }
    return res;
}
complex P[N];
void FFT(complex p[],int len,int DFT){
    for(int i=0;i<len;i++) P[rev(i,len)]=p[i];
    for(int s=1;(1<<s)<=len;s++){
        int m=(1<<s);
        complex wm=complex(cos(DFT*2*PI/m),sin(DFT*2*PI/m));
        for(int k=0;k<len;k+=m){
            complex w=complex(1,0);
            for(int j=0;j<(m>>1);j++){
                complex t=w*P[k+j+(m>>1)];
                complex u=P[k+j];
                P[k+j]=u+t;
                P[k+j+(m>>1)]=u-t;
                w=w*wm;
            }
        }
    }
    if(DFT==-1) for(int i=0;i<len;i++) P[i].re/=len;
    for(int i=0;i<len;i++) p[i]=P[i];
}
char A[N],B[N];
int la,lb,len,ans[N];
complex numA[N],numB[N];
int main(){
    while(scanf("%s",A)!=EOF){
        scanf("%s",B);
        la=strlen(A);lb=strlen(B);
        int sa=0,sb=0;
        while((1<<sa)<la) sa++;
        while((1<<sb)<lb) sb++;
        len=(1 << max(sa,sb)+1); 
        for(int i=0;i<len;i++){
            if(i<la) numA[i]=complex(A[la-i-1]-'0',0); else numA[i]=complex(0,0);
            if(i<lb) numB[i]=complex(B[lb-i-1]-'0',0); else numB[i]=complex(0,0);
        }
        FFT(numA,len,1);
        FFT(numB,len,1);
        for(int i=0;i<len;i++) numA[i]=numA[i]*numB[i];
        FFT(numA,len,-1);
        for(int i=0;i<len;i++) ans[i]=(int)(numA[i].re+0.5);
        for(int i=0;i<len-1;i++) ans[i+1]+=ans[i]/10,ans[i]%=10;
        bool iszero=1;
        for(int i=len-1;i>=0;i--){
            if(ans[i]) printf("%d",ans[i]),iszero=0; else 
            if(!iszero || i==0) printf("0");
        }
        printf("\n");
    }
    return 0;
}
