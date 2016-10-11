#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int num[110],need[110];
int n,sum;
int ans;
int main()
{
    int i,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  {scanf("%d",&num[i]);sum+=num[i];}
    sum/=n;
    for(i=1;i<n;i++)
    {
        if(num[i]!=sum)
        {
           t=sum-num[i];
           num[i]+=t;
           num[i+1]-=t;
           ans++; 
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
