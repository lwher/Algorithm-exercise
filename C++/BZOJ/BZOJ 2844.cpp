#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,a[100010],q;
long long rk;
void swap(int &aa,int &bb)
{
     int t=aa;aa=bb;bb=t;
}
int guass()
{
    int i,k,j,ans=0;
    for(k=31;k>=0;k--)
    {
        for(i=ans+1;i<=n;i++)  
        if((a[i]>>k) & 1)   break;
        if(i<=n)
        {
            if(i!=ans+1) swap(a[i],a[ans+1]);
            for(j=1;j<=n;j++)
            if(j!=ans+1 && ((a[j]>>k)&1))  a[j]^=a[ans+1];
            ans++;
        }  
    }
    return ans;
}
int main()
{
    int i,now=0,c;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%d",&a[i]);    
    c=guass();    
    scanf("%d",&q);
    for(i=1;i<=c;i++) 
    if((now^a[i])<=q)   
    {now^=a[i];rk+=((long long)1<<(c-i))%10086;rk%=10086;}
    for(i=n-c;i>=1;i--)  rk=(rk<<1)%10086;
    rk++;rk%=10086;
    cout<<rk<<endl;
    system("pause");
    return 0;
}
