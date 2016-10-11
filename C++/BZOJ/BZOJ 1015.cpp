#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
using namespace std; 
int fa[400010]; 
int from[400010],last[400010],to[400010],pre[400010]; 
bool mark[400010]; 
int ans[400010],ph[400010]; 
int n,m,q; 
int answer,sz; 
void Ins(int a,int b) 
{ 
    sz++; 
    to[sz]=b; 
    from[sz]=a; 
    pre[sz]=last[a]; 
    last[a]=sz; 
    sz++; 
    from[sz]=b; 
    to[sz]=a; 
    pre[sz]=last[b]; 
    last[b]=sz; 
} 
int getfa(int x) 
{ 
    if(fa[x]==x)  return x; 
    else 
    return fa[x]=getfa(fa[x]); 
} 
int main() 
{ 
    int i,j; 
    int a,b; 
    scanf("%d%d",&n,&m); 
    to[0]=n; 
    for(i=0;i<=n-1;i++) 
    fa[i]=i; 
    for(i=1;i<=m;i++) 
    { 
        scanf("%d%d",&a,&b); 
        Ins(a,b); 
    } 
    answer=n; 
    scanf("%d",&q); 
    for(i=1;i<=q;i++) 
    {scanf("%d",&ph[i]);mark[ph[i]]=1;} 
      
    int x,y; 
    for(i=1;i<=sz;i++) 
    { 
        if(mark[from[i]] || mark[to[i]])  continue; 
        x=getfa(from[i]); 
        y=getfa(to[i]); 
        if(x!=y) 
        { 
            answer--; 
            fa[x]=y; 
        } 
    } 
    answer-=q; 
    ans[q]=answer;       
    for(i=q;i>=1;i--) 
    { 
        j=last[ph[i]]; 
        while(mark[to[j]])  j=pre[j]; 
        if(j==0)  answer++; 
        if(j!=0) 
        {x=getfa(to[j]);fa[x]=ph[i];j=pre[j];} 
        while(j>0) 
        { 
            if(mark[to[j]]){j=pre[j]; continue;} 
            x=getfa(to[j]); 
            if(x!=ph[i]) 
            {fa[x]=ph[i];answer--;} 
            j=pre[j]; 
        } 
        ans[i-1]=answer; 
        mark[ph[i]]=0; 
    } 
    for(i=0;i<=q;i++) 
    printf("%d\n",ans[i]); 
    //system("pause"); 
    return 0; 
}