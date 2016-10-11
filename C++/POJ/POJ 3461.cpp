#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
char b[1000010],a[10010];
int aa,bb;
int next[10010];
int n;
int ans;
void getnext()
{
     int k=-1,j=0;
     next[0]=-1;
     while(j<aa)
     {
       if(k==-1 || a[j]==a[k])
       {
         k++;
         j++;
         next[j]=k;
       }
       else
       k=next[k];
     }
}
int main()
{
    scanf("%d",&n);
    int i,j,l;
    while(n--)
    {
       scanf("\n%s\n%s",a,b);
       aa=strlen(a);       
       bb=strlen(b);
       
       getnext();
       i=0;j=0;
       ans=0;
       
       while(i<bb)
       {
          if(j==-1 || b[i]==a[j])
          {
             i++;
             j++;
             
          }
          else
          j=next[j];
          
          if(j==aa)  {ans++;j=next[j];}
       }
       printf("%d\n",ans);
    }
    system("pause");
    return 0;
}
