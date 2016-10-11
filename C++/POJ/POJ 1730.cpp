#include<cstdio>

long long n;

inline long long mabs(long long x)

{return x>0?x:-x;}

int main()

{

while(scanf("%lld",&n),n)

{

int ans=1;

for(long long i=2;i*i<=mabs(n);i++)

{

long long temp=1;

int cnt=0;

while(temp!=n)

{

if(mabs(temp)>mabs(n)) break;

temp*=i;

cnt++;

}

if(temp==n) { ans=cnt; break;}

temp=1;cnt=0;

while(temp!=n)

{

if(mabs(temp)>mabs(n)) break;

temp*=-i;

cnt++;

}

if(temp==n) { ans=cnt; break;}

}

printf("%d\n",ans);

}

return 0;

}


