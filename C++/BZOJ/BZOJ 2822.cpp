#include<iostream> 
#include<cstring> 
#include<cstdio> 
#include<cstdlib> 
using namespace std; 
int f[501][250];; 
int n; 
int now[250],nn[250]; 
void chen(int a[],int b[]) 
{ 
    int ans[250]={0}; 
    int i,j; 
    for(i=1;i<=a[0];i++) 
    for(j=1;j<=b[0];j++) 
    { 
        ans[i+j-1]+=a[i]*b[j]; 
        if(ans[i+j-1]>9999)   
        {ans[i+j]+=ans[i+j-1]/10000;ans[i+j-1]%=10000;} 
    } 
    ans[0]=a[0]+b[0]-1;  
    if(ans[a[0]+b[0]]>0)  ans[0]++; 
    memset(now,0,sizeof(now)); 
    for(i=0;i<=ans[0];i++) 
    now[i]=ans[i]; 
} 
void jia(int a[],int b[]) 
{ 
    int ans[250]={0}; 
    int i,k; 
    k=max(a[0],b[0]); 
    for(i=1;i<=k;i++) 
    {ans[i]+=a[i]+b[i]; if(ans[i]>9999){ans[i+1]++;ans[i]-=10000;}} 
    ans[0]=k; 
    if(ans[k+1]) 
    ans[0]++; 
    for(i=0;i<=ans[0];i++) 
    nn[i]=ans[i]; 
} 
void fz(int s) 
{ 
    int i; 
    for(i=0;i<=nn[0];i++) 
    f[s][i]=nn[i]; 
    memset(nn,0,sizeof(nn)); 
} 
void print() 
{ 
    int i; 
    printf("%d",f[n][f[n][0]]); 
    for(i=f[n][0]-1;i>=1;i--) 
    printf("%.4d",f[n][i]); 
    cout<<endl; 
} 
int main() 
{ 
   // freopen("stair.in","r",stdin); 
    //freopen("stair.out","w",stdout); 
    int i,j,k; 
    scanf("%d",&n); 
    f[0][0]=1;f[0][1]=1; 
    f[1][0]=1;f[1][1]=1;         
    for(i=2;i<=n;i++) 
    { 
        for(j=1;j<=i;j++) 
        { 
            k=i-j+1; 
            chen(f[i-k],f[i-j]); 
            jia(now,nn); 
            //f[i]+=f[i-k]*f[i-j]; 
        } 
        fz(i); 
    } 
    print(); 
    //system("pause"); 
    return 0; 
}