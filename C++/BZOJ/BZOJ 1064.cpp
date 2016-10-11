#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
#include<algorithm> 
using namespace std; 
int n,m; 
int circle,sum,num[100010],dui[100010]; 
int sz,to[3000010],v[3000010],pre[3000010],last[100010]; 
bool mark[100010]; 
void Ins(int a,int b,int c) 
{ 
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz; 
} 
int gcd(int a,int b) 
{ 
    if(b==0)  return a; 
    else return gcd(b,a%b); 
} 
int main() 
{ 
    int i,j,k,a,b,maxnum,minnum,now; 
    scanf("%d%d",&n,&m); 
    for(i=1;i<=m;i++) 
    { 
        scanf("%d%d",&a,&b); 
        Ins(a,b,1);Ins(b,a,-1); 
    } 
    for(j=1;j<=n;j++) 
    if(!mark[j]) 
    { 
        int tou=1,wei=1; 
        dui[1]=j;mark[j]=1;num[j]=0; 
        maxnum=0;minnum=0; 
        while(tou<=wei) 
        { 
            now=dui[tou];tou++; 
            if(maxnum<num[now])  maxnum=num[now]; 
            if(minnum>num[now])  minnum=num[now]; 
            i=last[now]; 
            while(i>0) 
            { 
                if(!mark[to[i]]) 
                { 
                    num[to[i]]=num[now]+v[i];mark[to[i]]=1;wei++;dui[wei]=to[i]; 
                } 
                else
                { 
                    circle=gcd(circle,abs(num[now]-num[to[i]]+v[i])); 
                } 
                i=pre[i]; 
            } 
        } 
        sum+=maxnum-minnum+1; 
    } 
    if(circle) 
    { 
        if(circle<3)  printf("-1 -1\n"); 
        else 
        { 
            for(i=3;i<=circle;i++)  if(circle%i==0)  break; 
            printf("%d %d\n",circle,i); 
        } 
    } 
    else
    { 
        if(sum<3)  printf("-1 -1\n"); 
        else  printf("%d 3\n",sum); 
    } 
    //system("pause"); 
    return 0; 
}