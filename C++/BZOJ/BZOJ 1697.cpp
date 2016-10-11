#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<algorithm> 
#define INF 1e9 
using namespace std; 
int n,a[10010],b[10010],c[100010];// a: 原数列 b: 排序后的数列  c[i]: 值为i的数在数列a中的位置.  
long long ans; 
bool vis[10010]; 
int main() 
{ 
    int i,j,sz,mi; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++)  {scanf("%d",&a[i]);b[i]=a[i];} 
    sort(b+1,b+1+n); 
    for(i=1;i<=n;i++)  c[a[i]]=i; 
    for(i=1;i<=n;i++) 
    if(!vis[i]) 
    { 
        j=i;sz=0;mi=INF; 
        while(!vis[j]) 
        { 
            sz++;vis[j]=1;mi=min(a[j],mi); 
            ans+=a[j];j=c[b[j]]; 
        } 
        ans-=mi; 
        ans+=min((sz-1)*mi,(sz-1)*b[1]+2*(b[1]+mi)); 
    } 
    cout<<ans<<endl; 
    //system("pause");  
    return 0; 
}