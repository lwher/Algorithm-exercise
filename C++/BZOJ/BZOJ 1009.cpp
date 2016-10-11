#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
using namespace std; 
int n,m,MOD; 
string chuan; 
int next[21]; 
int a[21][21]; 
int ans[21][21]; 
int now[21][21]; 
int answer; 
int f[21]; 
void getnext() 
{ 
    int i=0,j=-1; 
    next[0]=-1; 
    int chang=chuan.size(); 
    while(i<chang) 
    { 
        if(j==-1 || chuan[j]==chuan[i]) 
        { 
            i++; 
            j++; 
            next[i]=j; 
        } 
        else
        j=next[j]; 
    } 
} 
void sqra() 
{ 
    int i,j,k; 
    int cc[21][21]={0}; 
    for(i=0;i<=m-1;i++) 
    for(j=0;j<=m-1;j++) 
    for(k=0;k<=m-1;k++) 
    { 
        cc[i][j]+=a[i][k]*a[k][j]; 
        cc[i][j]%=MOD; 
    } 
    for(i=0;i<=m-1;i++) 
    for(j=0;j<=m-1;j++) 
    a[i][j]=cc[i][j]; 
} 
void chen() 
{ 
    int i,j,k; 
    int cc[21][21]={0}; 
    for(i=0;i<=m-1;i++) 
    for(j=0;j<=m-1;j++) 
    for(k=0;k<=m-1;k++) 
    { 
        cc[i][j]+=ans[i][k]*a[k][j]; 
        cc[i][j]%=MOD; 
    } 
    for(i=0;i<=m-1;i++) 
    for(j=0;j<=m-1;j++) 
    ans[i][j]=cc[i][j]; 
} 
void pow(int x) 
{ 
    while(x>0) 
    { 
        if(x & 1) 
        chen(); 
        sqra(); 
        x=x>>1; 
    } 
} 
void solve() 
{ 
    int i,j,k; 
    int aaa[21]={0}; 
    for(i=0;i<=m-1;i++) 
    for(k=0;k<=m-1;k++) 
    {aaa[i]+=f[k]*ans[k][i]; 
    aaa[i]%=MOD; 
    } 
    for(i=0;i<=m-1;i++) 
    {answer+=aaa[i]; 
    answer%=MOD; 
    } 
} 
int main() 
{ 
    int i,j,l; 
    scanf("%d%d%d",&n,&m,&MOD); 
    cin>>chuan; 
    f[0]=1; 
    getnext(); 
    for(i=0;i<=m-1;i++) 
    ans[i][i]=1; 
    bool o; 
    for(i=0;i<=m-1;i++) 
    { 
       for(j=0;j<=9;j++) 
       {    
            o=0;  
            l=next[i]; 
            if(i<m-1 && chuan[i]==(j+'0')) 
            {a[i][i+1]++;continue;}  
            if(chuan[i]==(j+'0')) 
            continue;        
            while(l!=-1) 
            { 
                if(chuan[l]==(j+'0')) 
                {a[i][l+1]++;o=1;break;} 
                else
                l=next[l]; 
            } 
            if(!o) 
            a[i][0]++; 
       } 
    } 
      
    pow(n); 
      
    solve(); 
    cout<<answer<<endl; 
    //system("pause"); 
    return 0; 
}