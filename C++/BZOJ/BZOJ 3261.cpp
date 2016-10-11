#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<cmath>  
using namespace std;  
int sz,root[700010],c[15000000][2],s[15000000];  
int n,m,a[700010],b[700010];  
void Ins(int y,int &x,int d,int num)  
{  
    x=++sz;s[x]=s[y]+1;  
    if(d<0) return;  
    c[x][0]=c[y][0];c[x][1]=c[y][1];  
    int t=((num>>d) & 1);  
    Ins(c[y][t],c[x][t],d-1,num);  
}  
int query(int x,int y,int num,int d)  
{  
    if(d<0) return 0;  
    int p=((num>>d) & 1);  
    if(s[c[y][p^1]]-s[c[x][p^1]])  return (1<<d)+query(c[x][p^1],c[y][p^1],num,d-1);  
    return query(c[x][p],c[y][p],num,d-1);  
}  
int main()  
{  
    int i,l,r,x;char ss[3];  
    scanf("%d%d",&n,&m);n++;  
    Ins(root[0],root[1],24,0);  
    for(i=2;i<=n;i++)  
    {  
        scanf("%d",&a[i]);  
        b[i]=b[i-1]^a[i]; Ins(root[i-1],root[i],24,b[i]);  
    }         
    for(i=1;i<=m;i++)  
    {  
        scanf("%s",ss);  
        if(ss[0]=='A')   
        {  
            n++;  
            scanf("%d",&a[n]);  
            b[n]=b[n-1]^a[n];  Ins(root[n-1],root[n],24,b[n]);    
        }  
        else
        {  
            scanf("%d%d%d",&l,&r,&x);  
            printf("%d\n",query(root[l-1],root[r],x^b[n],24));  
        }  
    }  
    //system("pause");  
    return 0;  
}