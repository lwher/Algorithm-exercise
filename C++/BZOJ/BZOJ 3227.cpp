#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int fmax[5010][16][2],fmin[5010][16][2];
int n,ansmax=-1,ansmin=-1;
void checkmax(int &t,int num)
{
    if(t==-1 || t<num)  t=num;
}
void checkmin(int &t,int num)
{
    if(t==-1 || t>num)  t=num;
}
int main()
{
    int i,j,k,l,p;
    scanf("%d",&n);
    memset(fmax,-1,sizeof(fmax));
    memset(fmin,-1,sizeof(fmin));
    fmax[1][0][0]=1;fmin[1][0][0]=1;
    fmax[0][0][1]=0;fmin[0][0][1]=0;
    for(j=1;(1<<j)<=n+1;j++)
    {
        for(i=1;i<=n;i++)
        {
            for(k=0;k*2+1<=i;k++)
            {
                if(fmax[k][j][1]!=-1 && fmax[i-k-1][j][1]!=-1)
                {
                    checkmax(fmax[i][j][0],fmax[k][j][1]+fmax[i-k-1][j][1]+1);
                    checkmin(fmin[i][j][0],fmin[k][j][1]+fmin[i-k-1][j][1]+1);
                }
            }
            for(k=0;k*2+1<=i;k++)
            for(l=0;l<2;l++)
            for(p=0;p<2;p++)
            {
                if(fmax[k][j-1][l]!=-1 && fmax[i-k-1][j-1][p]!=-1)
                {
                    checkmax(fmax[i][j][1],fmax[k][j-1][l]+fmax[i-k-1][j-1][p]);
                    checkmin(fmin[i][j][1],fmin[k][j-1][l]+fmin[i-k-1][j-1][p]);
                }
            }
        }
        if(fmax[n][j][0]!=-1)  checkmax(ansmax,fmax[n][j][0]);
        if(fmax[n][j][1]!=-1)  checkmax(ansmax,fmax[n][j][1]);
        if(fmin[n][j][0]!=-1)  checkmin(ansmin,fmin[n][j][0]);
        if(fmin[n][j][1]!=-1)  checkmin(ansmin,fmin[n][j][1]);
    }
    printf("%d\n%d\n",ansmin,ansmax);
    return 0;
}