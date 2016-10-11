#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
#define MAXN 500010 
#define now tree[k] 
#define lson tree[k+k] 
#define rson tree[k+k+1] 
using namespace std; 
struct node 
{ 
    bool p1,p2,p3,p4,p5,p6; 
}; 
struct lwh 
{ 
    int left,right; 
    node p; 
}tree[MAXN]; 
int n; 
bool edge[MAXN][2]; 
void build(int k,int l,int r) 
{ 
    now.left=l;now.right=r; 
    if(l==r)  
    { 
        now.p.p1=now.p.p5=1; 
        return; 
    } 
    int mid=(l+r)>>1; 
    build(k+k,l,mid);build(k+k+1,mid+1,r); 
} 
node updata(const node &l,const node &r,int k) 
{ 
    node ans; 
    ans.p1=(l.p1 & edge[k][1] & r.p1)|(l.p3 & edge[k][0] & r.p4); 
    ans.p2=l.p2 | (l.p1 & l.p5 & edge[k][0] & edge[k][1] & r.p2); 
    ans.p3=(l.p1 & edge[k][1] & r.p3)|(l.p3 & edge[k][0] & r.p5);       
    ans.p4=(l.p4 & edge[k][1] & r.p1)|(l.p5 & edge[k][0] & r.p4);       
    ans.p5=(l.p4 & edge[k][1] & r.p3)|(l.p5 & edge[k][0] & r.p5);       
    ans.p6=r.p6|(r.p1 & edge[k][1] & l.p6 & edge[k][0] & r.p5);       
    return ans; 
} 
void work(int k,int a,int b,int c,int d,bool p) 
{ 
    if(now.left==a && now.right==c) 
    { 
        if(a==c && abs(b-d)==1)  {now.p.p2=now.p.p3=now.p.p4=now.p.p6=p;} 
        if(a==c-1)  now.p=updata(lson.p,rson.p,lson.right); 
        return; 
    } 
    int mid=(now.left+now.right)>>1; 
    if(c<=mid)  work(k+k,a,b,c,d,p); 
    if(a>mid)   work(k+1+k,a,b,c,d,p);  
    now.p=updata(lson.p,rson.p,lson.right); 
} 
node find(int k,int l,int r) 
{ 
    if(now.left==l && now.right==r)   return now.p; 
    int mid=(now.left+now.right)>>1; 
    if(r<=mid)  return find(k+k,l,r); 
    if(l>mid)   return find(k+k+1,l,r); 
    return updata(find(k+k,l,mid),find(k+k+1,mid+1,r),mid); 
} 
void swap(int &a,int &b) 
{ 
    int t=a;a=b;b=t; 
} 
bool ask(int a,int b,int c,int d) 
{ 
    if(a==c && b==d)  return 1; 
    if(a>c)  {swap(a,c);swap(b,d);} 
    node ans1,ans2=find(1,a,c),ans3; 
    if(a>1)  ans1=find(1,1,a-1); 
    if(c<n)  ans3=find(1,c+1,n); 
  
    if(a==c&&ans2.p2)                    return true;       
    if(a!=c && b==1 && d==1 && ans2.p1)  return true;       
    if(a!=c && b==1 && d==0 && ans2.p3)  return true;       
    if(a!=c && b==0 && d==1 && ans2.p4)  return true;       
    if(a!=c && b==0 && d==0 && ans2.p5)  return true; 
  
    if(a>1&&edge[a-1][0]&&edge[a-1][1]&&ans1.p6&&a==c)  return true;       
    if(a>1&&edge[a-1][0]&&edge[a-1][1]&&ans1.p6&&b==0&&d==0&&ans2.p3)  return true;       
    if(a>1&&edge[a-1][0]&&edge[a-1][1]&&ans1.p6&&b==0&&d==1&&ans2.p1)  return true;       
    if(a>1&&edge[a-1][0]&&edge[a-1][1]&&ans1.p6&&b==1&&d==0&&ans2.p5)  return true;       
    if(a>1&&edge[a-1][0]&&edge[a-1][1]&&ans1.p6&&b==1&&d==1&&ans2.p4)  return true;  
  
    if(c<n&&edge[c][0]&&edge[c][1]&&ans3.p2&&a==c)  return true;       
    if(c<n&&edge[c][0]&&edge[c][1]&&ans3.p2&&b==0&&d==0&&ans2.p4)  return true;       
    if(c<n&&edge[c][0]&&edge[c][1]&&ans3.p2&&b==0&&d==1&&ans2.p5)  return true;       
    if(c<n&&edge[c][0]&&edge[c][1]&&ans3.p2&&b==1&&d==0&&ans2.p1)  return true;       
    if(c<n&&edge[c][0]&&edge[c][1]&&ans3.p2&&b==1&&d==1&&ans2.p3)  return true;  
  
    if(a>1&&c<n&&edge[a-1][0]&&edge[a-1][1]&&ans1.p6&&edge[c][0]&&edge[c][1]&&ans3.p2&&a==c)  return true;       
    if(a>1&&c<n&&edge[a-1][0]&&edge[a-1][1]&&ans1.p6&&edge[c][0]&&edge[c][1]&&ans3.p2&&b==0&&d==0&&ans2.p1)  return true;       
    if(a>1&&c<n&&edge[a-1][0]&&edge[a-1][1]&&ans1.p6&&edge[c][0]&&edge[c][1]&&ans3.p2&&b==0&&d==1&&ans2.p3)  return true;       
    if(a>1&&c<n&&edge[a-1][0]&&edge[a-1][1]&&ans1.p6&&edge[c][0]&&edge[c][1]&&ans3.p2&&b==1&&d==0&&ans2.p4)  return true;       
    if(a>1&&c<n&&edge[a-1][0]&&edge[a-1][1]&&ans1.p6&&edge[c][0]&&edge[c][1]&&ans3.p2&&b==1&&d==1&&ans2.p5)  return true;       
    return false;   
} 
int main() 
{ 
    char s[10]; 
    scanf("%d",&n); 
    build(1,1,n);    
    int a,b,c,d;       
    while(scanf("%s",s)&&strcmp(s,"Exit"))       
    {           
        scanf("%d%d%d%d",&b,&a,&d,&c);           
        if(strcmp(s,"Open")==0)           
        {               
            if(a>c)  swap(a,c),swap(b,d);               
            if(a==c-1)  edge[a][b-1]=true;               
            work(1,a,b-1,c,d-1,true);           
        }           
        if(strcmp(s,"Close")==0)           
        {               
            if(a>c)  swap(a,c),swap(b,d);               
            if(a==c-1)  edge[a][b-1]=false;               
            work(1,a,b-1,c,d-1,false);           
        }           
        if(strcmp(s,"Ask")==0)   
        { 
            if(ask(a,b-1,c,d-1))  printf("Y\n"); 
            else printf("N\n"); 
        }   
    }   
    //system("pause"); 
    return 0; 
}