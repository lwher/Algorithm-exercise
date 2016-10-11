#include<iostream>
using namespace std;
int n;
int a[110][110];
bool b[110][10010];
int sum,minn=100000;
int ans;
bool jc(int i)
{
     for(j=1;j<=n;j++)
     if(!b[j][i]) return 0;
     return 1;
}
int main()
{
    int s;
    cin>>n;
    int i,j,k;
    for(i=1;i<=n;i++)
    {
     b[i][0]=1;sum=0;
     while(scanf("%d",&s))
     {
     if(s==-1) break;
     a[i][0]++;
     a[i][a[i][0]]=s;  
     sum+=s;
     }
     if(minn>sum) minn=sum;
    }
    for(i=1;i<=n;i++)
    for(k=1;k<=a[i][0];k++)
    for(j=0;j<=minn;j++)
    {
      if(b[i][j])
      {b[i][j+a[i][k]=1;}
    }
    for(i=minn;i>=1;i--)
    if(jc(i)) {ans=minn;break;}
    cout<<ans;
    system("pause");
    return 0;
}
