#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
#include<algorithm> 
using namespace std; 
char nn[1000010],mm[1000010]; 
int N[1000010],M[1000010]; 
long long n,m; 
long long mod=1000000006,a,b,c,d; 
long long now[1000010]; 
long long daan[3],jza[3][3],jzc[3][3]; 
int qumo(int shu[]) 
{ 
    int i; 
    for(i=0;i<=shu[0];i++) 
    now[i]=shu[i];i=1; 
    while(!now[i]) {now[i]=9;i++;} 
    now[i]--; 
    for(i=now[0];i>=2;i--) 
    now[i-1]+=(now[i]%mod)*10; 
    return now[1]%mod; 
} 
void init() 
{ 
    int i,len; 
    scanf("%s",nn+1); 
    scanf("%s",mm+1); 
    cin>>a>>b>>c>>d; 
    if(a==1 && c==1)  mod=1000000007; 
    else mod=1000000006; 
      
    len=strlen(nn+1); 
    for(i=len;i>=1;i--)  N[len-i+1]=nn[i]-'0'; 
    N[0]=len;n=qumo(N); 
    len=strlen(mm+1); 
    for(i=len;i>=1;i--)  M[len-i+1]=mm[i]-'0'; 
    M[0]=len;m=qumo(M); 
      
    mod=1000000007; 
    daan[0]=1;daan[1]=b;daan[2]=d; 
    jza[0][0]=a;jza[1][0]=1;jza[1][1]=1;jza[2][2]=1; 
    jzc[0][0]=c;jzc[2][0]=1;jzc[1][1]=1;jzc[2][2]=1; 
} 
void jzchen(long long A[][3],long long B[][3],long long ans[3][3]) 
{ 
     int i,j,k; 
     long long nans[3][3]={0}; 
     for(i=0;i<=2;i++) 
     for(j=0;j<=2;j++) 
     { 
         for(k=0;k<=2;k++) 
         nans[i][j]=(nans[i][j]+(A[i][k]*B[k][j])%mod)%mod; 
     } 
     for(i=0;i<=2;i++)  for(j=0;j<=2;j++)  ans[i][j]=nans[i][j]; 
} 
void getans(long long A[],long long B[][3],long long ans[3]) 
{ 
     int i,j; 
     long long nans[3]={0}; 
     for(i=0;i<=2;i++) 
     { 
        for(j=0;j<=2;j++) 
        nans[i]=(nans[i]+(A[j]*B[j][i])%mod)%mod; 
     } 
     for(j=0;j<=2;j++)  ans[j]=nans[j]; 
} 
void qpow(long long mi,long long jz[3][3]) 
{ 
     long long nans[3][3]={0}; 
     nans[0][0]=1;nans[1][1]=1;nans[2][2]=1; 
     while(mi>0) 
     { 
          if(mi & 1)  jzchen(nans,jz,nans); 
          jzchen(jz,jz,jz);mi=mi>>1; 
     } 
     int i,j; 
     for(i=0;i<=2;i++)  for(j=0;j<=2;j++)  jz[i][j]=nans[i][j]; 
} 
void solve() 
{    
     qpow(m,jza); 
     getans(daan,jza,daan);              
     jzchen(jzc,jza,jza); 
     qpow(n,jza); 
     getans(daan,jza,daan); 
     qpow(mod-1,jza); 
     cout<<daan[0]<<endl; 
} 
int main() 
{ 
    //freopen("matrix.in","r",stdin); 
   // freopen("matrix.out","w",stdout); 
    init(); 
    solve(); 
    //system("pause"); 
    return 0; 
}