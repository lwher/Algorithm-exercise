#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int w,l,f[1000];
string s,a[610];
void solve()
{
     int i,j,k,len,t;
     bool can;
     scanf("%d %d\n",&w,&l);
     cin>>s;
     for (i=1;i<=w;i++)
     cin>>a[i];
     for (i=0;i<=l-1;i++)
     {
         for (j=1;j<=w;j++)
         if (a[j].length()<=i+1)
         {
             len=a[j].length()-1;
             k=i;
             t=a[j].length()-1;
             while ((k>=0)&&(t>=0))
             {
                   if (s[k]==a[j][t]) t--;
                   k--;
             }
             if (t==-1)
             {
                 if ((k==-1)&&(f[i]<a[j].length())) f[i]=a[j].length();
                 if ((k>=0)&&(f[k]+a[j].length()>f[i]))
                 f[i]=f[k]+a[j].length();
             }
         }
     }
     printf("%d\n",s.length()-f[l-1]);
}
int main(int argc, char *argv[])
{
    solve();
    system("pause");
    return 0;
}

