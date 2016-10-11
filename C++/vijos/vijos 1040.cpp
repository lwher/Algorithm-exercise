#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
string A,B,C;
int a[30001],b[30001];
int ans[60001];
void mul()
{
     int i,j;
     for(i=1;i<=a[0];i++)
     for(j=1;j<=b[0];j++)
     {
         ans[i+j-1]+=a[i]*b[j];
         ans[i+j]+=ans[i+j-1]/10000;
         ans[i+j-1]%=10000;
     }
     ans[0]=a[0]+b[0]-1;
     if(ans[ans[0]+1])  ans[0]++;
}
void print()
{
     int i;
     printf("%d",ans[ans[0]]);
     for(i=ans[0]-1;i>=1;i--)  printf("%.4d",ans[i]);
     printf("\n");
}
int main()
{
    int i,len,j;
    cin>>A>>B;
    len=A.size()-1;    
    for(i=len;i>=0;i-=4)
    {
        if(i-4+1>=0)  j=i-4+1; else j=0;
        C=A.substr(j,i-j+1);
        a[0]++;a[a[0]]=atoi(C.c_str());
    }
    len=B.size()-1;    
    for(i=len;i>=0;i-=4)
    {
        if(i-4+1>=0)  j=i-4+1; else j=0;
        C=B.substr(j,i-j+1);
        b[0]++;b[b[0]]=atoi(C.c_str());
    }
    
    mul();
    print();
    system("pause");
    return 0;
}

/*
231321 51321230321
*/





