#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int num[20],tt,cur;
int v[2][20][166][166];
long long f[2][20][166][166];
long long calc(bool less,int dep,int left,int rem)
{
     if(!dep)  return (!left && !rem);
     if(v[less][dep][left][rem]==tt)  return f[less][dep][left][rem];
     v[less][dep][left][rem]=tt;f[less][dep][left][rem]=0;
     int i,ed=min(less ? 9 : num[dep],left);
     for(i=max(left-(dep-1)*9,0);i<=ed;i++)
     f[less][dep][left][rem]+=calc(less || i<num[dep],dep-1,left-i,(rem*10+i)%cur);
     return f[less][dep][left][rem];
}
long long count(long long k)
{
     num[0]=0;
     while(k>0)
     {
         num[0]++;num[num[0]]=k%10;
         k/=10;
     }
     long long ans=0;
     for(cur=1;cur<=num[0]*9;cur++)
     {
        tt++;ans+=calc(0,num[0],cur,0);
     }
     return ans;
}
int main()
{
    long long a,b;
    cin>>a>>b;
    cout<<count(b)-count(a-1)<<endl;
    system("pause");
    return 0;
}
