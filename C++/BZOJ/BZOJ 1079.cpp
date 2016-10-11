#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
using namespace std; 
long long f[16][16][16][16][16][5]; 
int sum[6],k; 
int n; 
int main() 
{ 
    int i,j,now; 
    scanf("%d",&k); 
    for(i=1;i<=k;i++) 
    {scanf("%d",&j);sum[j]++;} 
    f[sum[1]][sum[2]][sum[3]][sum[4]][sum[5]][0]=1; 
    int i1,i2,i3,i4,i5,v; 
    for(i5=k;i5>=0;i5--) 
    for(i4=k;i4>=0;i4--) 
    for(i3=k;i3>=0;i3--) 
    for(i2=k;i2>=0;i2--) 
    for(i1=k;i1>=0;i1--) 
    for(v=0;v<=4;v++) 
    if(f[i1][i2][i3][i4][i5][v]) 
    { 
        if(i1) 
        { 
            if(v==1)  now=i1-1; 
            else  now=i1; 
            f[i1-1][i2][i3][i4][i5][0]+=(f[i1][i2][i3][i4][i5][v]*now)%1000000007; 
            f[i1-1][i2][i3][i4][i5][0]%=1000000007; 
        } 
        if(i2) 
        { 
            if(v==2)  now=i2-1; 
            else  now=i2; 
            f[i1+1][i2-1][i3][i4][i5][1]+=(f[i1][i2][i3][i4][i5][v]*now)%1000000007; 
            f[i1+1][i2-1][i3][i4][i5][1]%=1000000007; 
        } 
        if(i3) 
        { 
            if(v==3)  now=i3-1; 
            else  now=i3; 
            f[i1][i2+1][i3-1][i4][i5][2]+=(f[i1][i2][i3][i4][i5][v]*now)%1000000007; 
            f[i1][i2+1][i3-1][i4][i5][2]%=1000000007; 
        } 
        if(i4) 
        { 
            if(v==4)  now=i4-1; 
            else  now=i4; 
            f[i1][i2][i3+1][i4-1][i5][3]+=(f[i1][i2][i3][i4][i5][v]*now)%1000000007; 
            f[i1][i2][i3+1][i4-1][i5][3]%=1000000007; 
        } 
        if(i5) 
        { 
            now=i5; 
            f[i1][i2][i3][i4+1][i5-1][4]+=(f[i1][i2][i3][i4][i5][v]*now)%1000000007; 
            f[i1][i2][i3][i4+1][i5-1][4]%=1000000007; 
        } 
    } 
    cout<<f[0][0][0][0][0][0]<<endl; 
      
    //system("pause"); 
    return 0; 
}