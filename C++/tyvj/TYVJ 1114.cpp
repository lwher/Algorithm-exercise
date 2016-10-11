#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n;
int f[101][2001];
bool k[101][2001];
int high[101];
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%d",&high[i]);
    k[1][0]=1;
    k[1][high[1]]=1;
    for(i=1;i<=n-1;i++)
    {
       for(j=0;j<=2000;j++)
       if(k[i][j])
       {
           k[i+1][j]=1;           f[i+1][j]=max(f[i+1][j],f[i][j]);
           k[i+1][j+high[i+1]]=1; f[i+1][j+high[i+1]]=max(f[i+1][j+high[i+1]],f[i][j]);
           if(j-high[i+1]>=0)
           {k[i+1][j-high[i+1]]=1; f[i+1][j-high[i+1]]=max(f[i+1][j-high[i+1]],f[i][j]+high[i+1]);}
           if(j-high[i+1]<0)
           {k[i+1][high[i+1]-j]=1; f[i+1][high[i+1]-j]=max(f[i+1][j-high[i+1]],f[i][j]+j);}
       }
    }
    if(f[n][0]) cout<<f[n][0]<<endl;
    else
    cout<<"Impossible"<<endl;
    system("pause");
    return 0;
}
