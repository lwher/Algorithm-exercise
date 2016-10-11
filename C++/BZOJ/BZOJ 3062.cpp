#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int A[100010],B[100010],n,m;
long long ans;
int main()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&A[i],&B[i]);
        ans+=abs(A[i]-B[i]);
    }
    ++n;
    A[n]=m;B[n]=0;
    sort(A+1,A+1+n);
    sort(B+1,B+1+n);
    for(i=1;i<=n;i++)  ans+=abs(A[i]-B[i]);
    cout<<ans<<endl;
    //system("pause");
    return 0;
}