/*
    生成树计数 基尔霍夫矩阵-树定理 SPOJ 104
    基尔霍夫矩阵 = 度矩阵 - 邻接矩阵
    将其删掉任意一行一列以后的子矩阵行列式的绝对值就是生成树的数量
    行列式可以用高斯消元来求解：
    1、矩阵的任意两行或两列互换，行列式结果变号
    2、某一行加上另外一行乘以实数k以后，行列式结果不变 
    结果比较小可以使用double,结果要取模则要使用乘法逆元
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-9
using namespace std;
int n,m;
double A[15][15];
void swap(double &a,double &b){
    double t=a;a=b;b=t;
}
double calc(int N){
    int i,j,k;
    double res=1,p;
    for(i=1;i<=N;i++){
        if(fabs(A[i][i])<eps){
           for(j=i+1;j<=N;j++) if(fabs(A[j][i])>eps){
               res*=-1;
               for(k=1;k<=N;k++) swap(A[i][k],A[j][k]);
               break;
           }
        }
        res*=A[i][i];
        for(j=i+1;j<=N;j++)
        if(fabs(A[j][i])>eps){
            p=A[j][i]/A[i][i];
            for(k=1;k<=N;k++) A[j][k]-=A[i][k]*p;
        }
    }
    return res;
}
int main(){
    int T,i,j,a,b;
    scanf("%d",&T);    
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++) for(j=1;j<=n;j++) A[i][j]=0.00;
        for(i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            A[a][b]-=1;A[b][a]-=1;
            A[a][a]+=1;A[b][b]+=1;
        }    
        printf("%.0lf\n",calc(n-1));
    }
    return 0;
}
