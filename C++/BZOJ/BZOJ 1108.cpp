#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n;long long ans;
int main()
{
    int i,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  {scanf("%d%d",&x,&y); ans+=y-x;}
    for(i=1;i<=n;i++)  {scanf("%d%d",&x,&y); ans+=x-y;}
    cout<<ans<<endl;
    system("pause");
    return 0;
}
