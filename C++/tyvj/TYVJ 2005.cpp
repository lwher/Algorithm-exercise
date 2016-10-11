#include<iostream>  
#include<stdio.h>  
#include<string.h>  
#include<cstring>
#include<cmath>  
#include <sstream>
using namespace std;  
int nn,m,tt;  
int sum;
char money[51];  
string q;
int a[30];  
bool f[30][30][30][30];  
int ans;  
int sz=0; 
char aa[10],bb[10]; 
char c[1001]; 


string str(int i)
{
        stringstream ss;
        ss<<i;
        return ss.str();
}
bool pd(int i)  

 {  
   int j,k,l;  
   for(k=1;k<=m;k++)  
   for(l=0;l<=tt;l++)  
   if(f[nn][i][k][l]) 
   return 1;  
   return 0;  
   }  
 char* mul(char a[],char b[])
{
 int lena=strlen(a)-1,lenb=strlen(b)-1,n=0,i,j,t;
 int s[10001]={0};
 for(i=lena;i>=0;i--)
 {
  n=lena-i;t=0;
  for(j=lenb;j>=0;j--)
  {
   s[n]=s[n]+(a[i]-48)*(b[j]-48)%10+t;
   t=(a[i]-48)*(b[j]-48)/10;
   if(s[n]>9)
   {
    t+=s[n]/10;
    s[n]%=10;
   } 
   n++; 
  } 
  if(t>0)
   s[n]=t;
  else
   n--;
 }
 while(!s[n])
  n--;
 if(n<0)
  n=0;
 for(i=0;i<=n;i++)
  c[i]=s[i]+48;
 c[i]=0;
 _strrev(c);
return c;
}

 int main()  

 {  
     int i,j,k,l;  
	 cin>>nn>>m>>tt;  
     cin>>q;
     for(i=0;i<=q.size()-1;i++)
     {
	  if(q[i]<='9' && q[i]>='0')
	  {money[sz]+=q[i];sz++;} 
	 }
     for(i=1;i<=nn;i++)  
     {scanf("%d",&a[i]);  if(a[i]>tt) sum++;}
    if(a[1]<=tt)  
	 f[1][1][1][a[1]]=1;  
     f[1][0][1][0]=1;  
     for(i=1;i<=nn-1;i++)   
      for(j=0;j<=i;j++)  
     for(k=1;k<=min(i,m);k++)  
     for(l=0;l<=tt;l++)  
{  
      if(f[i][j][k][l])  
	  {  
      if(k<m && a[i+1]<=tt) 
	  f[i+1][j+1][k+1][a[i+1]]=1;  
      if(l+a[i+1]<=tt)  
	  f[i+1][j+1][k][l+a[i+1]]=1;  
      f[i+1][j][k][l]=1; 
	  }  
}  
     for(i=nn;i>=0;i--)  
     if(pd(i)) 
	 {ans=i;break;}  
	 
	 q=str(ans); 
	 for(i=0;i<=q.size();i++) 
	 aa[i]=q[i]; 
     cout<<mul(aa,money)<<" ";
	 q=str(nn-ans-sum);
	for(i=0;i<=q.size();i++) 
	 bb[i]=q[i]; 
     cout<<mul(bb,money);
     //system("pause");  
     return 0;  
} 