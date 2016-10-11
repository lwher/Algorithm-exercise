#include<iostream>
using namespace std;
long a[3001],b[3001],f[3001];
long maxx,ans;
int main()
{
     long i,n;
     cin>>n;
     for(i=1;i<=n;i++)
     cin>>a[i];
     for(i=1;i<=n;i++)
     cin>>b[i];
     long j;
     for(i=1;i<=n;i++)
     {
     maxx=0;
     for(j=1;j<=n;j++)
     {
            //  if(a[i]==b[j]) cout<<a[i]<<" ";        
        if((a[i]>b[j])&&(maxx<f[j])) maxx=f[j];
        if((a[i]==b[j])&&(f[j]<maxx+1))  f[j]=maxx+1;  
     }
     }
      for(j=1;j<=n;j++)
      if(f[j]>ans) ans=f[j];
      cout<<ans<<endl;
     system("pause");
     return 0;
}
