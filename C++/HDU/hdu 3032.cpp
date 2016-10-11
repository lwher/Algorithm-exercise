#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int t,n,k;
int main()
{
    int i,ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&k);
            if(k % 4 == 1 || k % 4 == 2)
            {ans^=k;}
            else
            if(k % 4 == 0)
            ans^=(k-1);
            else
            ans^=(k+1);
        }
        if(ans)  printf("Alice\n");
        else printf("Bob\n");
    }
    //system("pause");
    return 0;
}
