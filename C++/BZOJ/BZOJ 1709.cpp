#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
bool map[110][110];
int n,k,ans,num[110][110],sumx[110],sumy[110],sumxjy[510],sumxay[510];
int main()
{
    int i,j,x,y;
    scanf("%d%d",&n,&k);
    for(i=1;i<=k;i++)
    {
        scanf("%d%d",&x,&y);
        map[x][y]=1;num[x][y]++;
        sumx[x]++;sumy[y]++;sumxjy[x-y+200]++;sumxay[x+y]++;
    }
    for(i=1;i<=n;i++) for(j=1;j<=n;j++)
    {
        if(map[i][j])
        {
            if(sumx[i]+sumy[j]+sumxjy[i-j+200]+sumxay[i+j]-3*num[i][j]==k)  ans++;
        }  
        else if(sumx[i]+sumy[j]+sumxjy[i-j+200]+sumxay[i+j]==k)  ans++;
    }
    cout<<ans<<endl;
    return 0;
}