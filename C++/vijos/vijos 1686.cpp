#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,T,num[2010],f[2010],ans;
int main()
{
    int i,j,t;
    scanf("%d%d",&n,&T);
    for(i=1;i<=n;i++)  {scanf("%d",&num[i]);f[i]=1;}
    for(i=1;i<=n;i++)
    {
       for(j=1;j<i;j++)
       if(f[j]+1>f[i])
       {
           t=(f[j]-1)%(2*T);
           if((t<T && num[j]>num[i]) || (t>=T && num[j]<num[i]))  f[i]=f[j]+1;  
       }
       if(f[i]>ans)  ans=f[i];
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
