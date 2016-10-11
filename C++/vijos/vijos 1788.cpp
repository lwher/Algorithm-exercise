#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int num[100010],n,k;
int main()
{
    scanf("%d%d",&n,&k);
    int i;
    for(i=1;i<=n;i++) scanf("%d",&num[i]);
    sort(num+1,num+1+n);
    cout<<num[n-k+1]<<endl;
    system("pause");
    return 0;
}
