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
#define mod 1000000007
using namespace std;
const double PI = acos(-1.0);
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
int n,ans,num[N],sum[N],R[N];
char s[N];
complex A[N],B[N],P[N];
inline int rev(int id,int len){
    int res=0;
    for(int i=0;(1<<i)<len;i++){
        res<<=1;
        if(id & (1<<i)) res|=1;
    }
    return res;
}
inline int quickpow(int a,int b){
    int res=1;a%=mod;
    while(b>0){
        if(b & 1) res=(long long)res*a%mod;
        b>>=1;
        a=(long long)a*a%mod;
    }
    return res;
}
void FFT(complex p[],int len,int DFT){
    for(int i=0;i<len;i++) P[rev(i,len)]=p[i];
    for(int s=0;(1<<s)<=len;s++){
        int m=(1<<s);
        complex wm=complex(cos(2*PI*DFT/m),sin(2*PI*DFT/m));
        for(int j=0;j<len;j+=m){
            complex w=complex(1,0);
            for(int k=0;k<(m>>1);k++){
                complex u=P[j+k];
                complex v=w*P[j+k+(m>>1)];
                P[j+k]=u+v;
                P[j+k+(m>>1)]=u-v;
                w=w*wm;
            }
        }
    }
    if(DFT==-1) for(int i=0;i<len;i++) P[i].re/=len;
    for(int i=0;i<len;i++) p[i]=P[i];
}
void Calc_Manacher(){
    s[0]='&';s[n+1]='*';
    int i,p,r,k;
    p=0;r=0;
    for(i=1;i<=n;i++){
        if(p+r>i) k=min(R[p*2-i],p+r-i); 
        else k=1;
        while(s[i-k]==s[i+k]) k++;
        R[i]=k;ans-=R[i];if(ans<0) ans+=mod;
        if(i+k>p+r) p=i,r=k;
    }
    p=0;r=0;
    for(i=1;i<n;i++){
        if(p+r>i) k=min(R[p*2-i],p+r-i);
        else k=0;
        while(s[i-k]==s[i+k+1]) k++;
        R[i]=k;ans-=R[i];if(ans<0) ans+=mod;
        if(i+k>p+r) p=i,r=k;
    }
}
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    int sa=0;
    while((1<<sa)<n+1) sa++;
    int len=(1<<sa+1);
    for(int i=0;i<len;i++){
        A[i]=complex(0,0);
        B[i]=complex(0,0);
    }
    for(int i=1;i<=n;i++){
        if(s[i]=='a') A[i]=complex(1,0);
        else B[i]=complex(1,0);
    }        
    FFT(A,len,1);
    for(int i=0;i<len;i++) A[i]=A[i]*A[i];
    FFT(A,len,-1);
    for(int i=0;i<len;i++) num[i]=(long long)(A[i].re+0.5);
    for(int i=1;i<=n;i++) if(s[i]=='a') num[i<<1]--;
    for(int i=0;i<len;i++) sum[i]+=(num[i]>>1);
    FFT(B,len,1);
    for(int i=0;i<len;i++) B[i]=B[i]*B[i];
    FFT(B,len,-1);
    for(int i=0;i<len;i++) num[i]=(long long)(B[i].re+0.5);
    for(int i=1;i<=n;i++) if(s[i]=='b') num[i<<1]--;
    for(int i=0;i<len;i++) sum[i]+=(num[i]>>1);        
    for(int i=2;i<=(n<<1);i++){
        if(i & 1)ans=(ans+quickpow(2,sum[i])-1)%mod;
        else ans=(ans+quickpow(2,sum[i]+1)-1)%mod;
    }    
    Calc_Manacher();
    ans=(ans%mod+mod)%mod;
    cout<<ans<<endl;
    return 0;
}
