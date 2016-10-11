#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int t,n;
string s;
long long ans=0;
int lx,ly,x,y;
void cl(int i)
{
     if(s[i]=='1')  {x=lx-1;y=ly+1;}
     if(s[i]=='2')  {y=ly+1;}
     if(s[i]=='3')  {x=lx+1;y=ly+1;}
     if(s[i]=='4')  {x=lx-1;}
     if(s[i]=='6')  {x=lx+1;}
     if(s[i]=='7')  {x=lx-1;y=ly-1;}
     if(s[i]=='8')  {y=ly-1;}
     if(s[i]=='9')  {x=lx+1;y=ly-1;}
}
int main()
{
    int i,j;
	cin>>t;
    while(t--)
    {
       lx=0;ly=0; 
       cin>>s;
       ans=0;
       for(i=0;i<s.size();i++)
       {
         if(s[i]=='5')  break;
         cl(i);
         ans+=x*ly-lx*y;
         lx=x;ly=y;
       }
       if(ans<0) ans*=-1;
       if(ans%2==1)  
       printf("%lld.5\n",ans/2);
       else
       printf("%lld\n",ans/2);
    }
	system("pause");
	return 0;
}

