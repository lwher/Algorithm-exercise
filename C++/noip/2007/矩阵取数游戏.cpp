#include<iostream>  
#include<memory.h>  
#include<stdio.h>  
using namespace std;  
int n,m,a[81];  
int f[81][81][31];  
int ys[81][31];  
int ans[31];  
int c[31];  
void mul(int *x,int *y,int z){  
    memset(c,0,sizeof(c));  
    c[0]=y[0];  
    for(int i=1;i<=c[0];++i)  
        c[i]=y[i]*z;  
    for(int i=1;i<=c[0];++i){  
        c[i+1]+=c[i]/100000;  
        c[i]%=100000;  
    }  
    while(c[c[0]+1]){  
        c[0]++;  
        c[c[0]+1]+=c[c[0]]/100000;  
        c[c[0]]%=100000;  
    }  
    for(int i=0;i<=30;++i) x[i]=c[i];  
}  
void add(int *x,int *y,int *z){  
    memset(c,0,sizeof(c));  
    if(y[0]>z[0]) c[0]=y[0];  
    else c[0]=z[0];  
    for(int i=1;i<=c[0];++i)  
        c[i]=y[i]+z[i];  
    for(int i=1;i<=c[0];++i){  
        c[i+1]+=c[i]/100000;  
        c[i]%=100000;  
    }  
    if(c[c[0]+1]) c[0]++;  
    for(int i=0;i<=30;++i) x[i]=c[i];  
}  
bool MAX(int *x,int *y){  
    if(x[0]>y[0]) return 1;  
    else if(y[0]>x[0]) return 0;  
    else{  
        for(int i=x[0];i>=1;--i)  
        if(x[i]>y[i]) return 1;  
        else if(y[i]>x[i]) return 0;  
    }  
    return 1;  
}  
int main()  
{  
    scanf("%d%d",&n,&m);  
    ys[0][0]=1; ys[0][1]=1;  
    for(int i=1;i<=m;++i)  
        mul(ys[i],ys[i-1],2);  
    ans[0]=1; ans[1]=0;  
    for(int i=1;i<=n;++i){  
        for(int j=1;j<=m;++j){  
            scanf("%d",&a[j]);  
            mul(f[j][j],ys[m],a[j]);  
        }  
        for(int k=2;k<=m;++k)  
            for(int lx=1;lx<=m-k+1;++lx){  
                int ly=lx+k-1,ll;  
                int xm[31],ym[31],cm[31];  
                ll=ly;  
                mul(cm,ys[m-k+1],a[lx]);  
                ly=ll;//不记录一下ly会莫名的变成0，xm的值也是一样。???  
                add(xm,cm,f[lx+1][ly]);  
                mul(ym,ys[m-k+1],a[ly]);  
                add(ym,ym,f[lx][ly-1]);  
                if(MAX(xm,ym))  
                    memcpy(f[lx][ly],xm,sizeof(int)*31);  
                else  
                    memcpy(f[lx][ly],ym,sizeof(int)*31);  
            }  
        add(ans,ans,f[1][m]);  
    }  
    printf("%d",ans[ans[0]]);  
    for(int i=ans[0]-1;i>=1;--i) printf("%05d",ans[i]);  
    printf("\n");  
    return 0;  
}  