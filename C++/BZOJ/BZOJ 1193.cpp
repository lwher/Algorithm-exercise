#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int qx,qy,zx,zy,ans,d,dx,dy;
int main()
{
    scanf("%d%d%d%d",&qx,&qy,&zx,&zy);
    d=abs(qx-zx)+abs(qy-zy);
    dx=abs(qx-zx);dy=abs(qy-zy);
    for(;;ans++)
    {
        if((((qx+qy)&1)^((zx+zy)&1))!=(ans & 1))  continue;
        if(d<=3*ans && dx<=2*ans && dy<=2*ans)  break;
    }
    if(d==1)  ans=3;
    if(d==4 && dx==2 && dy==2)  ans=4;
    printf("%d\n",ans);
    return 0;
}