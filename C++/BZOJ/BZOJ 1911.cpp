#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,x[1000010],dui[1000010];
long long A,B,C,sum[1000010],f[1000010];
double calc(int j,int k)//j>k,jÓÅÓÚk 
{
    return double(f[j]+A*sum[j]*sum[j]-B*sum[j]-(f[k]+A*sum[k]*sum[k]-B*sum[k]))/double(sum[j]-sum[k]);
}
int main()
{
    int i,j;
    scanf("%d",&n);
    cin>>A>>B>>C;
    for(i=1;i<=n;i++)  {scanf("%d",&x[i]);sum[i]=sum[i-1]+x[i];}
    int tou=1,wei=1,now;dui[1]=0;
    for(i=1;i<=n;i++)
    {
        while(tou<wei && calc(dui[tou+1],dui[tou])>2.00*A*sum[i])  tou++;
        now=dui[tou];
        f[i]=f[now]+A*(sum[i]-sum[now])*(sum[i]-sum[now])+B*(sum[i]-sum[now])+C;
        while(tou<wei && calc(i,dui[wei])>calc(dui[wei],dui[wei-1]))  wei--;
        dui[++wei]=i;
    }
    cout<<f[n]<<endl;
    //system("pause");
    return 0;
}