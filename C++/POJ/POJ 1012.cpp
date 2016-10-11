#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int m,k,n;
int calced[15];
int ans[30];
int main()
{
    int i;
    while(scanf("%d",&k))
    {
        if(!k)  break;
        if(calced[k]) 
        {
            printf("%d\n",calced[k]);continue;
        }
        n=2*k;
        ans[0]=0;
        m=1;
        for(i=1;i<=k;i++)   
        {
             ans[i]=(ans[i-1]+m-1)%(n-i+1);
             if(ans[i]<k)
             {
                i=0;m++;
             }
        }
        calced[k]=m;
        printf("%d\n",m);
    }
    system("pause");
    return 0;
}
