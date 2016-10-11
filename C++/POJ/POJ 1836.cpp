#include<iostream>

#include<cstdio>

#include<cstring>

using namespace std;

double b[1010],a[1010];

int f[1010],g[1010],n;

int main()

{

scanf("%d",&n);

for(int i=1;i<=n;i++)

scanf("%lf",&a[i]);

memset(b,0,sizeof b);

int len(0);

for(int i = 1; i <= n; i++)

{

if(a[i] > b[len]) b[++len] = a[i],f[i] = len;

else 

{

int l(0),r(len);

while(l <= r)

{

int mid = (l+r)>>1;

if(a[i] > b[mid])l = mid+1;

else r = mid-1;

}

b[l] = a[i];

f[i] = l;

}

}

memset(b,0,sizeof b);

len = 0;

for(int i = n; i >= 1; i--)

{

if(a[i] > b[len]) b[++len] = a[i],g[i] = len;

else 

{

int l(0),r(len);

while(l <= r)

{

int mid = (l+r)>>1;

if(a[i] > b[mid])l = mid+1;

else r = mid-1;

}

b[l] = a[i];

g[i] = l;

}

}

int ans(0);

for(int i=1;i<=n;i++)

{

int ff=f[i],gg=g[i];

for(int j=i-1;j>=1;j--)

if((a[j]==a[i]))

ff=max(ff,f[j]+1);

for(int j=i+1;j<=n;j++)

if(a[j]==a[i])

gg=max(gg,g[j]+1);

ans = max(ans,ff+gg-1);

}

printf("%d\n",n-ans);

return 0;

}

