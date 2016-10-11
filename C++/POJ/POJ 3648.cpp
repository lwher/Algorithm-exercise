#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define N 501
#define M 3001
using namespace std;
int n,m,sz,siz,SZ;
int to[M],last[N],pre[M];
int to2[M],last2[N],pre2[M];
bool mark[N];
int fl[N],num[N],kind[N];
int TO[M],LAST[N],PRE[M];
int rd[N];
int dui[N],opp[N];
void Ins(int a,int b)
{
     sz++;
     to[sz]=b;pre[sz]=last[a];last[a]=sz;
     to2[sz]=a;pre2[sz]=last2[b];last2[b]=sz;
}
void ins(int a,int b)
{
	SZ++;
	TO[SZ]=b;PRE[SZ]=LAST[a];LAST[a]=SZ;
}
void dfs1(int x)
{
     int i=last[x];
     mark[x]=1;
     while(i>0)
     {
         if(!mark[to[i]])
         dfs1(to[i]);
         i=pre[i];
     }
     num[0]++;
     num[num[0]]=x;
}
void dfs2(int x)
{
     int i=last2[x];
     mark[x]=1;fl[x]=siz;
     while(i>0)
     {
         if(!mark[to2[i]])
         dfs2(to2[i]);      
         i=pre2[i];
     }
}
void jt(int x,int now)
{
     int i=last[x];
     mark[x]=1;
     while(i>0)
     {
               if(!mark[to[i]] && fl[to[i]]==now)
               {jt(to[i],now);}
               if(fl[to[i]]!=now)
               {ins(fl[to[i]],fl[x]);rd[fl[x]]++;}
               i=pre[i];
     }
}
void build()
{
     int i;
     int a,b;
     int aa,bb;
     char ch1,ch2;
     memset(last,0,sizeof(last));
     memset(last2,0,sizeof(last2));
     sz=0;
     scanf("\n");   
     for(i=1;i<=m;i++)
     {
         scanf("%d%c%d%c",&a,&ch1,&b,&ch2);
         if(ch1=='h') aa=0;
         else  aa=1;
         if(ch2=='h') bb=0;
         else  bb=1;
         if((a==0 && aa==1) || (b==0 && bb==1))  continue;
         if(aa==0 && bb==1) // wh   a+n->b+n,b->a 
         {
			 Ins(a+n,b+n);
			 Ins(b,a);
		 }
		 else
         if(aa==1 && bb==0)   //hw   a->b,b+n->a+n
         {
			 Ins(a,b);
			 Ins(b+n,a+n);
		 }
		 else
		 if(aa+bb==0)    //ww  a+n->b,b+n->a
		 {
			 Ins(a+n,b);
			 Ins(b+n,a);
		 }
		 else   //hh   a->b+n,b->a+n
		 {
			 Ins(a,b+n);
			 Ins(b,a+n);
		 }
     }
     Ins(0,n);
}
void topsort()
{
	 int i,now;
	 int tou=1,wei=0;
	 for(i=1;i<=siz;i++)
	 if(rd[i]==0)
	 {
			wei++;dui[wei]=i;
	 }
	 while(tou<=wei)
	 {
		    now=dui[tou];
		    if(kind[now]==0)
		    {kind[now]=1;kind[opp[now]]=2;}
		    i=LAST[now];
		    while(i>0)
		    {
				rd[TO[i]]--;
				if(rd[TO[i]]==0)
				{wei++;dui[wei]=TO[i];}
				i=PRE[i];
			}
			tou++;
	 }
}
void solve()
{
     int i,j;
     memset(rd,0,sizeof(rd));
     memset(LAST,0,sizeof(LAST));
     memset(kind,0,sizeof(kind));
     memset(opp,0,sizeof(opp));
     SZ=0;
     build();
     memset(mark,0,sizeof(mark));
     memset(fl,0,sizeof(fl));
     num[0]=0;
     for(i=0;i<=2*n-1;i++)
     if(!mark[i])
     dfs1(i);
     memset(mark,0,sizeof(mark));
     siz=0;
     for(i=num[0];i>=1;i--)
     {
		 if(!mark[num[i]])
         {siz++;dfs2(num[i]);}
     }
     for(i=0;i<n;i++)
     {
        if(fl[i] == fl[i+n])
        {
           cout<<"bad luck"<<endl;
           return;
        }
        else
        {
		opp[fl[i]]=fl[i+n];
		opp[fl[i+n]]=fl[i];
		}
     }
     memset(mark,0,sizeof(mark));
     for(i=siz;i>=1;i--)
     {
        for(j=0;j<=2*n-1;j++)
        if(fl[j]==i)  break;
        jt(j,i);
     }
     topsort();
     for(i=1;i<n;i++)
     {
			if(kind[fl[i]]==1)
			cout<<i<<"h"<<" ";
	 		else
	 		cout<<i<<"w"<<" ";
	 }
	 cout<<endl;
}
int main()
{
//	freopen("POJ3648.in","r",stdin);
    int i;
    while(scanf("%d%d",&n,&m) && n && m)
    {
       solve();
    }
    //system("pause");
    return 0;
}

