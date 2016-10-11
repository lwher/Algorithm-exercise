#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[2001][2001];
int a[2001];
int n;
int max(int a,int b){
    if (a>b)return a;
    return b;
}
int main(){
    int i,j;
    while(scanf("%d",&n)!=EOF){
        if (!n)break;
        for (i=1;i<=n;i++)scanf("%d",&a[i]);
        for (i=1;i<=n;i++)f[i][i]=n*a[i];
        for (i=n;i>=1;i--)
            for (j=1;i+j<=n;j++)
                f[i][i+j]=max(f[i+1][i+j]+(n-j)*a[i],f[i][i+j-1]+(n-j)*a[i+j]);
        printf("%d\n",f[1][n]);
    }
    return 0;
}
