#include<iostream>
#include<cstdlib>
#include<cstdio> 
#include<cstring>
#include<cmath> 
#define N 6000 
int f[N],rank[N],head[N],next[N],st[N],n,m,rear; 
inline void init()
{ 
    rear=0; 
    memset(head,-1,sizeof(head)); 
    for(int i=0;i<N;i++)  f[i]=i,rank[i]=0; 
} 
int insert_hash(int num)
{ 
    int h=num%N; 
    int u=head[h]; 
    while(u!=-1)
	{ 
        if(st[u]==num) return u; 
        u=next[u]; 
    } 
    st[rear]=num; 
    next[rear]=head[h]; 
    head[h]=rear++; 
    return rear-1; 
} 
int find(int x)
{ 
    if(x==f[x]) return x; 
    int fa=f[x]; 
    f[x]=find(f[x]); 
    rank[x]^=rank[fa]; 
    return f[x]; 
}  
inline bool Union(int x, int y, int d)
{ 
    int ra=find(x),rb=find(y); 
    if(ra==rb)
	{ 
        if(rank[x]^rank[y]!=d) return 0;  return 1; 
    } 
    f[ra]=rb; 
    rank[ra]=rank[x]^rank[y]^d; 
    return 1; 
}
int main()
{ 
	//freopen("Parity.in","r",stdin);
	//freopen("Parity.out","w",stdout);
    scanf("%d%d",&n,&m); 
    init(); 
    int ans=0,a,b,d; 
    char str[10]; int i=0; 
    for(i=0;i<m;i++)
	{ 
        scanf("%d%d%s",&a,&b,str); 
        a=insert_hash(a-1); 
        b=insert_hash(b); 
        d=0; 
        if(str[0]=='o') d=1; 
        if(!Union(a,b,d))  break;
    } 
    printf("%d\n", i); 
    return 0; 
} 


