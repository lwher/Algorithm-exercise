#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
using namespace std; 
int s[1000010],h[1000010],n,m,prev[1000010],next[1000010],big[1000010],sml[1000010],b[1000010],p[1000010],ans[1000010]; 
int read() 
{ 
    char ch;int x=0; 
    ch=getchar(); 
    while(!(ch>='0' && ch<='9'))  ch=getchar(); 
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();} 
    return x; 
} 
void init() 
{ 
    int i,p; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=n;i++)    
    { 
        //scanf("%d",&p); 
        p=read();s[p]=i; 
    } 
    for(i=1;i<=m;i++)   h[i]=read();//scanf("%d",&h[i]);   
    for(i=1;i<=n;i++)   {b[s[i]]=i;next[i]=i+1;prev[i]=i-1;}   
    for(i=n;i>=1;i--)   
    {   
       if(next[s[i]]!=n+1) big[i]=i-b[next[s[i]]]; else big[i]=-1;   
       if(prev[s[i]]!=0)   sml[i]=i-b[prev[s[i]]]; else sml[i]=-1;   
       prev[next[s[i]]]=prev[s[i]];next[prev[s[i]]]=next[s[i]];    
    }    
} 
bool check(int o[1000010],int i,int j)   
{   
   if(big[j]!=-1 && o[i-big[j]]<o[i]) return false;   
   if(sml[j]!=-1 && o[i-sml[j]]>o[i]) return false;   
   return true;   
}   
void solve() 
{ 
    int i,j=0;p[1]=0;    
    for(i=2;i<=n;i++)   
    {    
       while(j>0 && !check(s,i,j+1))  j=p[j]; 
       if(check(s,i,j+1)) j++;  
       p[i]=j;   
    }   
    j=0; 
    for(i=1;i<=m;i++)   
    {   
       while(j>0 && !check(h,i,j+1))  j=p[j]; 
       if(check(h,i,j+1)) j++;    
       if(j==n) {ans[0]++;ans[ans[0]]=i-n+1;j=p[j];} 
    }   
    printf("%d\n",ans[0]);   
    for(i=1;i<ans[0];i++) printf("%d ",ans[i]);   
    if(ans[0]) printf("%d\n",ans[ans[0]]); 
} 
int main() 
{ 
    //freopen("match.in","r",stdin); 
    //freopen("match.out","w",stdout); 
    init(); 
    solve(); 
//  system("pause"); 
    return 0; 
}