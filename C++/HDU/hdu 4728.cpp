#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long limt=100010;
const long long MAX=1000000000000000010LL;
int n,root,sz,size[100010],c[100010][2],fa[100010];
long long A,B,C,a[100010],b[100010],ans;
inline void updata(int x)
{
    size[x]=size[c[x][0]]+size[c[x][1]]+1;
}
void rotate(int x,int &root)
{
     int y=fa[x],z=fa[y],p,q;
     if(c[y][0]==x) p=0; else p=1;
     q=p^1;
     if(y==root)  root=x;
     else
     {
         if(c[z][0]==y) c[z][0]=x;
         else  c[z][1]=x;
     }
     fa[x]=z;fa[y]=x;fa[c[x][q]]=y;
     c[y][p]=c[x][q];c[x][q]=y;
     updata(y);updata(x);
}
void splay(int x,int &root)
{
     int y,z;
     while(x!=root)
     {
         y=fa[x];z=fa[y];
         if(y!=root)
         {
             if((c[y][0]==x)^(c[z][0]==y)) rotate(x,root);
             else  rotate(y,root);
         }
         rotate(x,root);
     }
}
void Ins(int x,int &w,int last)
{
     if(!w) 
     {
         w=x;fa[w]=last;
         splay(w,root);
         return;
     }
     Ins(x,c[w][1],w);
}
long long calc(int i,long long x,long long y)
{
     long long now=0;
     while(1)
     {
          if(x>=y) return now;
          if(x>=a[i+1]) {i++;x++;} else 
          if(y>a[i+1])
          {
              now+=(a[i+1]-a[i])/i+((x-a[i])<((a[i+1]-a[i])%i));
              x=a[i+1]+i-(a[i+1]-x-1)%i;
              i++;
          }
          else  return now+(y-a[i])/i+((x-a[i])<((y-a[i])%i));
     }
}
int find(int x,int k)
{
    int y=c[x][0],z=c[x][1];
    if(size[y]+1==k)  return x;
    if(size[y]>=k)  return find(y,k);
    else return find(z,k-size[y]-1);
}
int main()
{
    int T,top,o=0;
    long long p,L,R;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case #%d: ",++o);
        cin>>A>>B>>C;
        top=0;
        long long x=0,y=B/C,z=B%C;
        while(x<=MAX && y<=limt)
        {
            if(y>=top)
            {
                a[++top]=x++;
                y=y+A/C+(z+A%C)/C;
                z=(z+A)%C;
            }
            else
            {
                if(!A) break;
                p=(long long)ceil((double)(C-z)/A);
                x=x+p;
                y=y+p*A/C+(z+p*A%C)/C;
                z=(z+p*A)%C;
            }
        }
        a[++top]=MAX;
        scanf("%d",&n);
        for(int i=1;i<n;i++)  scanf("%I64d",&b[i]);
        sort(b+1,b+n);
        root=0;sz=0;
        long long res=0;        
        for(int i=1,j=1;i<=top&&j<n;i++)
        {
            sz++;c[sz][0]=c[sz][1]=0;size[sz]=1;Ins(sz,root,0);
            while(j<=n && a[i]<=b[j] &&(i==top || b[j]<a[i+1]))
            {
                int k=(b[j]-a[i])%i;
                if(!k) k+=i;
                res^=(find(root,k)-1);
                j++;
            }
            if(i<top && (a[i+1]-a[i]-1)%i!=0)
            {
                int aa=find(root,((a[i+1]-a[i]-1)%i)+1);
                splay(aa,root);
                int bb=c[aa][0];
                fa[bb]=0;c[aa][0]=0;updata(aa);
                splay(sz,root);
                c[sz][1]=bb;fa[bb]=sz;updata(sz);
            }
        }        
        scanf("%I64d%I64d",&L,&R);
        ans=-calc(res+1,a[res+1],L);        
        ans+=calc(res+1,a[res+1],R+1);
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}
