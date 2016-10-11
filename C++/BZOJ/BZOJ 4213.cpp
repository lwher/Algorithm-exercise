#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
#define Mp(x,y) (x-1)*m+y
using namespace std;
const int N=12,M=N*N,Inf=100000000,D=(1<<10)-1,F[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

class Graph{
	int n,m,tot;
	struct Point{
		int first,dis,pre,flag;
	}po[M+10];
	struct Line{
		int next,l,dis,c;
	}li[M*8+10];
	struct Queue{
		int s,t,a[D+1];
		void Init(){s=t=0;}
		bool Empty(){return s==t;}
		void Push(int x){a[t]=x,t=t+1&D;}
		void Pop(){s=s+1&D;}
		int Front(){return a[s];}
	}q;
	int Spfa(){
		int i,j,k;q.Push(0);
		for (i=0;i<n;i++) po[i].dis=-Inf;po[0].dis=0;
		while (!q.Empty()){
			k=q.Front(),q.Pop();po[k].flag=0;
			if (k==n-1) continue;
			for (i=po[k].first;i;i=li[i].next){
				if (li[i].c && po[j=li[i].l].dis<po[k].dis+li[i].dis){
					po[j].dis=po[k].dis+li[i].dis;
					po[j].pre=i;
					if (!po[j].flag) po[j].flag=1,q.Push(j);
				}
			}
		}
		if (po[n-1].dis<0) return -Inf;
		for (i=po[n-1].pre,k=Inf;i;i=po[li[i^1].l].pre)
			k=min(k,li[i].c);
		for (i=po[n-1].pre;i;i=po[li[i^1].l].pre)
			li[i].c-=k,li[i^1].c+=k;
		tot+=k;
		return k*po[n-1].dis;
	}
public:
	void Init(int _n){n=_n,m=1;}
	void Add(int a,int b,int c,int d){
		li[++m].next=po[a].first,po[a].first=m,li[m].l=b,li[m].c=c,li[m].dis=d;
		li[++m].next=po[b].first,po[b].first=m,li[m].l=a,li[m].c=0,li[m].dis=-d;
	}
	pair<int,int> Work(){
		int tmp,ans=0;
		while ((tmp=Spfa())>=0)
			ans+=tmp;
		return pair<int,int>(tot,ans);
	}
}gp;

char ch[20];
int mp[N+10][N+10];

int main(){
	int i,j,k,x,y,n=0,m,tn,cnt=0,cnt2=0;pair<int,int> tp;
	//freopen("snake.in","r",stdin);
	//freopen("snake.out","w",stdout);
	while (scanf(" %s",ch)!=EOF){
		m=strlen(ch);n++;
		for (i=0;i<m;i++){
			if (ch[i]=='.') mp[n][i+1]=1;
		}
	}
	gp.Init(n*m+2);tn=n*m+1;
	for (i=1;i<=n;i++){
		for (j=1;j<=m;j++){
			if (!mp[i][j]) continue;cnt2++;
			if ((i+j)&1){
				if (i==1 || i==n || j==1 || j==m){
					gp.Add(Mp(i,j),tn,1,1);cnt++;
					gp.Add(Mp(i,j),tn,1,0);
				}else gp.Add(Mp(i,j),tn,2,1),cnt+=2;
				continue;
			}
			if (i==1 || i==n || j==1 || j==m){
				gp.Add(0,Mp(i,j),1,1);cnt++;
				gp.Add(0,Mp(i,j),1,0);
			}else gp.Add(0,Mp(i,j),2,1),cnt+=2;
			for (k=0;k<4;k++){
				x=i+F[k][0],y=j+F[k][1];
				if (mp[x][y]){
					gp.Add(Mp(i,j),Mp(x,y),1,0);
				}
			}
		}
	}
	tp=gp.Work();
	if (tp.second!=cnt) printf("-1");
	else printf("%d\n",cnt2-tp.first);
	return 0;
}
