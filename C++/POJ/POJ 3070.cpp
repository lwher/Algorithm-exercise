#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define mod 10000
using namespace std;
struct Matrix
{
    int matrix[2][2];
};
Matrix operator *(const Matrix &a,const Matrix &b)
{
    Matrix ans={0,0,0,0};
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) 
    ans.matrix[i][j]=(ans.matrix[i][j]+a.matrix[i][k]*b.matrix[k][j])%mod;
    return ans;
}
int n;
int main()
{
    while(scanf("%d",&n) && n!=-1)
    {
        if(n==0) 
        {
            printf("0\n");
            continue;
        }
        Matrix A={0,1,0,0};Matrix B={0,1,1,1};Matrix C={1,0,0,1};
        n--;
        while(n>0)
        {
           if(n & 1) C=C*B;
           B=B*B;
           n>>=1;
        }
        A=A*C;
        printf("%d\n",A.matrix[0][1]);
    }
    system("pause");
    return 0;
}
