#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
unsigned long long m,a,c,x0,n,g;
unsigned long long aa[2],b[2][2];
unsigned long long now[2][2];
unsigned long long calc(unsigned long long A,unsigned long long B)
{
     unsigned long long res=0;
     while(B>0)
     {
               if(B & 1)  res=(res+A)%m;
               A=(A<<1)%m;
               B=B>>1;
     }
     return res;
}
void chen1()
{
     int i,j;
     unsigned long long c[2]={0};
     for(i=0;i<=1;i++)
     for(j=0;j<=1;j++)
     {
        c[i]+=calc(aa[j],now[j][i]);
        c[i]%=m;
     }
     for(i=0;i<=1;i++)
     aa[i]=c[i];
}
void chen3()
{
     int i,j,k;
     unsigned long long c[2][2]={0};
     for(i=0;i<=1;i++)
     for(j=0;j<=1;j++)
     for(k=0;k<=1;k++)
     {
        c[i][j]+=calc(now[i][k],b[k][j]);
        c[i][j]%=m;
     }
     for(i=0;i<=1;i++)
     for(j=0;j<=1;j++)
     now[i][j]=c[i][j];
}
void chen2()
{
     int i,j,k;
     unsigned long long c[2][2]={0};
     for(i=0;i<=1;i++)
     for(j=0;j<=1;j++)
     for(k=0;k<=1;k++)
     {
        c[i][j]+=calc(b[i][k],b[k][j]);
        c[i][j]%=m;
     }
     for(i=0;i<=1;i++)
     for(j=0;j<=1;j++)
     b[i][j]=c[i][j];
}
void juzhencheng(unsigned long long x)
{
     while(x>0)
     {
               if(x & 1)
               chen3();
               chen2();
               x=x>>1;
     }
}
int main()
{
    cin>>m>>a>>c>>x0>>n>>g;
    aa[0]=x0;aa[1]=c;
    b[0][0]=a;b[0][1]=0;
    b[1][0]=1;b[1][1]=1;
    now[0][0]=1;now[1][1]=1; 
    juzhencheng(n);
    chen1();
    cout<< aa[0]%g <<endl;
    system("pause");
    return 0;
} 
