#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N,H,D,f[4050][4050],a[2050][2050],M[4050];
inline void read(int &x)
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
}
int main()
{
    read(N);read(H);read(D);
    for(int i=1;i<=N;++i)
    {
        int num,x;
        read(num);
        for(;num--;)
        {
            read(x); ++a[i][x];
        }
    }
    for(int i=H;i>=0;--i)
    {
        for(int j=1;j<=N;++j)
        {
            f[i][j]=max(f[i+1][j],M[i+D])+a[j][i];
        }
        for(int j=1;j<=N;++j)  if(f[i][j]>M[i]) M[i]=f[i][j];
    }
    printf("%d\n",M[0]);
    system("pause");
    return 0;
}

