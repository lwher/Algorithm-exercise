/*
	Floyd求图中的最小环 O(n^3) 
*/
//无向图 map:地图 dist:最短路 
void solve(){
	int i,j,k;
    for(k=1;k<=n;k++){
		for(i=1;i<k;i++) for(j=1;j<i;j++) ans=min(ans,dist[i][j]+map[i][k]+map[k][j]);
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	}
}
//有向图 map:地图 dist:最短路
void solve(){
	int i,j,k;
	for(k=1;k<=n;k++){
		for(i=1;i<k;i++) ans=min(ans,map[i][k]+map[k][i]);
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	}
	for(i=1;i<=n;i++) ans=min(ans,dist[i][i]);
}

