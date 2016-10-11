#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n;
int cnt[5];
int ans;
int getans()
{
    int s;
    if(cnt[1]<cnt[2])
    {
        s=cnt[1];
        cnt[1]-=s;cnt[2]-=s;cnt[3]+=s;
        ans+=s;
        s=cnt[2]/3;
        ans+=s*2;
        cnt[3]+=s*2;
        cnt[2]-=s*3;
    }
    else
    {
        s=cnt[2];
        ans+=s;
        cnt[1]-=s;cnt[2]-=s;cnt[3]+=s;
        s=cnt[1]/3;
        ans+=s*2;
        cnt[1]-=3*s;
        cnt[3]+=s;
    }
    if(cnt[1] && cnt[4])
    {
         s=min(cnt[1]/2,cnt[4]);
         ans+=s*2;
         cnt[1]-=s*2;cnt[4]-=s;cnt[3]+=s*2;
    }
    if(cnt[1] && cnt[3])
    {
         s=min(cnt[1],cnt[3]);
         ans+=s;
         cnt[1]-=s;cnt[3]-=s;cnt[4]+=s;
    }
    if(cnt[1] && cnt[4])
    {
         s=min(cnt[1],cnt[4]/2);
         ans+=2*s;
         cnt[1]-=s;cnt[4]-=2*s;cnt[3]+=3*s;
    }
    if(cnt[2])
    {
        s=cnt[2]/2;
        ans+=s*2;
        cnt[2]-=2*s;cnt[4]+=s;
    }
    if(cnt[2] && cnt[4])
    {
        s=min(cnt[2],cnt[4]);
        ans+=s;
        cnt[2]-=s;cnt[4]-=s;cnt[3]+=2*s;
    }
    if(cnt[2] && cnt[3])
    {
        s=min(cnt[2],cnt[3]/2);
        ans+=2*s;
        cnt[2]-=s;cnt[3]-=2*s;cnt[4]+=2*s;
    }
    if(cnt[1] || cnt[2])  return -1;
    return ans;
}
int main()
{
    int i,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  {scanf("%d",&k);cnt[k]++;}
    cout<<getans()<<endl;
    system("pause");
    return 0;
}
