#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,K,top,A[100010];
int next[100010],b[5000010];
int main()
{
    int i,j,k,R=1,x;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++) scanf("%d",&A[i]),next[i]=i+1;;
    sort(A+1,A+1+n);    
    for(k=0;k<=30 && top<=K;k++) 
    {
        for(i=1;i<=n;i++)
        {
            j=next[i];
            for(;j<=n;j++)
            {
                x=A[i]^A[j];
                if(x<=R) b[++top]=x;
                else break;
            }
            next[i]=j;
           ;
        } 
        R<<=1;
    }
    sort(b+1,b+1+top);
    for(i=1;i<=K;i++) printf("%d ",b[i]);
    //system("pause");
    return 0;
}
