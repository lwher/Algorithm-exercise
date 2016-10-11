#include<iostream>
using namespace std;
int judge(int n)
{
    if(n==1) return 1;
    int i,k=2;
    for(i=2;i<n;i++)
    {if(n%i==0)k++;}
    return k;
}
int main()
{
    int t,a,b,max,i,c,f;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d%d",&a,&b);
            max=judge(a);f=a;
            for(i=a+1;i<=b;i++)
            {   
                c=judge(i);
                if(c>max){max=c;f=i;}
            }
            printf("%d\n",f);
        }
    }
    return 0;
}