#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define mod 100000000
using namespace std;
int A[1260],B[1260],C[1260],ans[1260];
int g;
void read(char s[10010],int p[1260])
{
     int i,j,len=strlen(s+1),k;
     for(i=len;i>0;i-=8)
     {
        p[0]++;k=0;
        for(j=max(1,i-7);j<=i;j++) k=k*10+(s[j]-'0');
        p[p[0]]=k;
     }
}
void jian(int aa[1260],int b[1260],int now[1260])
{
     int i,c[1260]={0},a[1260];
     for(i=0;i<=aa[0];i++) a[i]=aa[i];
     for(i=1;i<=a[0];i++)
     {
        if(i>b[0]) b[i]=0;
        if(a[i]<b[i])  {a[i]+=mod;a[i+1]--;}
        c[i]=a[i]-b[i];
     }
     i=a[0];
     while(i>0 && !c[i]) i--;
     if(!i) {c[0]=1;c[1]=0;} else c[0]=i;
     for(i=0;i<=c[0];i++)  now[i]=c[i];
}
void div(int a[1260],int b,int now[1260])
{
     int i,c[1260]={0};
     for(i=a[0];i>=1;i--)
     {
        if(i!=1)  a[i-1]+=(a[i]%b)*mod;
        c[i]=a[i]/b;
     }
     i=a[0];
     while(i>0 && !c[i])  i--;
     if(!i) {c[0]=1;c[1]=0;} else c[0]=i;
     for(i=0;i<=c[0];i++)  now[i]=c[i];
     
}
void chen(int a[1260],int b,int now[1260])
{
     int i,c[1260]={0};
     for(i=1;i<=a[0];i++)
     {
        c[i]+=(a[i]*2)%mod;
        c[i+1]+=(a[i]*2)/mod;
     }
     c[0]=a[0];
     if(c[c[0]+1])  c[0]++;
     for(i=0;i<=c[0];i++)  now[i]=c[i];
}
bool check(int a[1260],int b[1260]) // 0 : a´ó  
{
     int i;
     if(a[0]>b[0]) return 0;
     if(a[0]<b[0]) return 1;
     for(i=a[0];i>=1;i--)  
     {
        if(a[i]>b[i]) return 0;
        if(a[i]<b[i]) return 1;
     }
     return 1;
} 
bool iszero(int a[1260])
{
     if(a[0]==1 && a[1]==0) return 1; return 0;
}
void fz(int a[1260],int b[1260])
{
     for(int i=0;i<=a[0];i++)  b[i]=a[i];
}
void print(int a[1260])
{
     printf("%d",a[a[0]]);
     for(int i=a[0]-1;i>=1;i--)  printf("%.8d",a[i]);
     printf("\n");
}
void GCD()
{
     while(!iszero(A) && !iszero(B))
     {
          if(!(A[1] & 1) && !(B[1] & 1))  {g++;div(A,2,A);div(B,2,B);}  else
          if(!(A[1] & 1))  div(A,2,A);  else
          if(!(B[1] & 1))  div(B,2,B);  else
          {
             if(check(A,B))  jian(B,A,B); 
             else  jian(A,B,A);
          }
     }
     if(!iszero(A)) fz(A,ans); else fz(B,ans);
     while(g--)  chen(ans,2,ans);
     print(ans);
}
int main()
{
    char s[10010];
    scanf("%s",s+1);read(s,A);
    scanf("%s",s+1);read(s,B);    
    GCD();        
    return 0;
}