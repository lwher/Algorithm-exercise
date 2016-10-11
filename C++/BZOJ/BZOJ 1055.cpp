#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
using namespace std; 
int dp[210][210][4]; 
bool map[5][5][5]; 
int a,b,n,c,d; 
char ch[10],s[210]; 
int id(char aa) 
{ 
    if(aa=='W')  return 0; 
    if(aa=='I')  return 1; 
    if(aa=='N')  return 2; 
    if(aa=='G')  return 3; 
} 
void dfs(int l,int r) 
{ 
    int i,j,k,p; 
    if(dp[l][r][0]!=-1)  return; 
    if(l+1==r) 
    { 
        for(i=0;i<4;i++)   
        { 
            if(map[id(s[l])][id(s[r])][i])  dp[l][r][i]=1; 
            else  dp[l][r][i]=0; 
        } 
        return; 
    } 
    for(i=l;i<r;i++) 
    { 
        dfs(l,i);dfs(i+1,r); 
        for(j=0;j<4;j++) if(dp[l][i][j]==1) 
        for(k=0;k<4;k++)  
        if(dp[i+1][r][k]==1) 
        for(p=0;p<4;p++) 
        if(map[j][k][p])  dp[l][r][p]=1; 
    } 
    for(i=0;i<4;i++)  if(dp[l][r][i]==-1)  dp[l][r][i]=0; 
} 
char cc(int x) 
{ 
    if(x==0)  return 'W'; 
    if(x==1)  return 'I'; 
    if(x==2)  return 'N'; 
    if(x==3)  return 'G'; 
} 
int main() 
{ 
    int i,j; 
    scanf("%d%d%d%d",&a,&b,&c,&d); 
    for(i=1;i<=a;i++) {scanf("%s",ch);map[id(ch[0])][id(ch[1])][0]=1;} 
    for(i=1;i<=b;i++) {scanf("%s",ch);map[id(ch[0])][id(ch[1])][1]=1;} 
    for(i=1;i<=c;i++) {scanf("%s",ch);map[id(ch[0])][id(ch[1])][2]=1;} 
    for(i=1;i<=d;i++) {scanf("%s",ch);map[id(ch[0])][id(ch[1])][3]=1;} 
    scanf("%s",s+1);n=strlen(s+1); 
    memset(dp,-1,sizeof(dp)); 
    for(i=1;i<=n;i++) 
    { 
        for(j=0;j<4;j++)  dp[i][i][j]=0; 
        dp[i][i][id(s[i])]=1; 
    } 
    dfs(1,n); 
    bool ok=0; 
    for(i=0;i<4;i++) 
    { 
        if(dp[1][n][i])  ok=1,printf("%c",cc(i)); 
    } 
    if(!ok)  printf("The name is wrong!\n"); 
    //system("pause"); 
    return 0; 
}