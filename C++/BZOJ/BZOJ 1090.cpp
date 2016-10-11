#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
char s[110];
int f[110][110];
int count(int x)
{
    int ans=0;
    while(x>0)
    {
       ans++;
       x/=10;
    }
    return ans;
}
int main()
{
    int i,j,k,l,p;
    gets(s);
    n=strlen(s)-1;
    for(l=1;l<=n+1;l++)
    for(i=0;i+l-1<=n;i++)
    {
        j=i+l-1;
        f[i][j]=l;
        for(k=i;k<j;k++)
        f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
        for(k=1;k<l;k++)
        if(l%k==0)
        {
             bool b=1;
             for(p=i+k;p+k-1<=j;p+=k)
             {
                 if (strncmp(s + i, s + p, k))
                 b = 0;
                 if(!b)  break;
             }
             if(b)
             f[i][j]=min(f[i][j],f[i][i+k-1]+2+count(l/k));
        }
    }
    cout<<f[0][n]<<endl;
    system("pause");
    return 0;
}
