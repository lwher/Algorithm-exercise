#include <iostream>
#include <queue>
using namespace std;
#define min(a,b) (a>b?b:a)
#define MAXV 372
#define MAXINT INT_MAX

int rc[MAXV][10];			//1到7为星期几,8是拍摄几天,9是在多少周内完成
int r[372][372];		//容量
int s,t,n,max_flow;		//表示s源点与t汇点,n部电影

int parent[MAXV];
int dis[MAXV];

void read_graph(){
	int i,j,k;
	for(i=1;i<=n;i++){
		r[0][i+350]=rc[i][8];
		
		for(j=1;j<=7;j++){
			if(rc[i][j]){
				for(k=0;k<rc[i][9];k++)
					r[i+350][j+k*7]=1;
			}
		}
	}
	
	for(i=1;i<=350;i++)	r[i][371]=1;
}

int bfs(){
	int k;
	queue<int> q;
    memset(dis,-1,sizeof(dis));
    dis[t]=0;
	
    q.push(t);
    while(!q.empty()){
		k=q.front();
		q.pop();
        for(int i=0;i<372;i++){
            if(dis[i]==-1 && r[i][k]){
                dis[i]=dis[k]+1;
                q.push(i);
            }
        }
        if(k==s) return 1;
    }
	return 0;
}

int dfs(int cur,int cp){
    if(cur==t)	return cp;
	
    int tmp=cp,t;
    for(int i=0;i<372 && tmp;i++){
        if(dis[i]+1==dis[cur] && r[cur][i]){
            t=dfs(i,min(r[cur][i],tmp));
            r[cur][i]-=t;
            r[i][cur]+=t;
            tmp-=t;
        }
    }
    return cp-tmp;
}

void dinic(){
    max_flow=0;
    while(bfs()){
		max_flow+=dfs(s,MAXINT);
    }
}

int main(){
	int i,j,ans,cnt;
	scanf("%d",&cnt);
	while(cnt--){
		ans=0;s=0;t=371;
		memset(r,0,sizeof(r));

		scanf("%d",&n);
		for(i=1;i<=n;i++){
			for(j=1;j<=9;j++)
				scanf("%d",&rc[i][j]);
			ans+=rc[i][8];
		}
	
		read_graph();		//建图
		dinic();

		if(ans==max_flow) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}