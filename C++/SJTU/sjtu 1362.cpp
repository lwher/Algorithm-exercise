#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int n, top, ans, num[50][7], now[7], trans[7];
int head, tail, Q[50][7];
void copy(int w, int p[]){
	for(int i = 1; i <= 6; i++) num[w][i] = p[i];
}

bool same(int w, int p[]){
	for(int i = 1; i <= 6; i++) if(num[w][i] != p[i]) return 0;
	return 1;
}

bool check(int p[]){
	for(int i = 1; i <= top; i ++)
		if(same(i, p)) return 1;
	return 0;
}

void bfs(){
	int trans[7];
	head = 1; tail = 1;
	for(int i = 1; i <= 6; i++) Q[1][i] = now[i];
	copy(++top, now);
	while(head <= tail){
		for(int i = 1; i <= 6; i++) trans[i] = Q[head][i];
		swap(trans[1], trans[3]);
		swap(trans[2], trans[4]);
		swap(trans[1], trans[2]);
		if(!check(trans)){
			copy(++top, trans);
			tail++;
			for(int i = 1; i <= 6; i++) Q[tail][i] = trans[i];
		}
		
		for(int i = 1; i <= 6; i++) trans[i] = Q[head][i];
		swap(trans[1], trans[5]);
		swap(trans[2], trans[6]);
		swap(trans[1], trans[2]);
			if(!check(trans)){
			copy(++top, trans);
			tail++;
			for(int i = 1; i <= 6; i++) Q[tail][i] = trans[i];
		}
		head++;
	}
}

int main(){
	cin >> n;
	for(int i = 1; i <= 6; i++) scanf("%d", &now[i]);
	bfs();
	for(int i = 2; i <= n; i++){
		for(int i = 1; i <= 6; i++) scanf("%d", &now[i]);
		if(check(now)) ans++;
	}
	cout << ans << endl;
	return 0;
}

