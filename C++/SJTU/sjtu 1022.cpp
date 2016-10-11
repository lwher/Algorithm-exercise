#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define mod 2010
using namespace std;
struct matrx{
    int num[2][2];
}A,B;
long long n;
matrx operator *(const matrx &a,const matrx &b){
    int i,j,k;
    matrx c;
    for(i=0;i<2;i++) for(j=0;j<2;j++) c.num[i][j]=0;
    for(i=0;i<2;i++) for(j=0;j<2;j++) for(k=0;k<2;k++){
        c.num[i][j]=(c.num[i][j]+a.num[i][k]*b.num[k][j])%mod;
    }
    return c;
}
void qpow(long long x){
    while(x>0){
        if(x & 1) B=B*A;
        A=A*A;
        x>>=1;
    }
}
int main(){
    cin>>n;
    if(n==1) printf("1\n"); else 
    if(n==2) printf("1\n"); else
    {
        n-=2;
        A.num[0][0]=0;A.num[0][1]=1;A.num[1][0]=1;A.num[1][1]=1;
        B.num[0][0]=1;B.num[1][0]=0;B.num[0][1]=0;B.num[1][1]=1;
        qpow(n);
        printf("%d\n",(B.num[0][1]+B.num[1][1])%mod);
    }
    system("pause");
    return 0;
}
