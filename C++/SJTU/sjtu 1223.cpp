#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 200001
using namespace std;
struct sth{
	int score, power, id;
	bool operator >(const sth &b)const {
		if(score == b.score) return id < b.id;
		return score > b.score;
	}
}p[N], win[N], lose[N];
inline bool comp(const sth &a, const sth &b){
	if(a.score == b.score) return a.id < b.id;
	return a.score > b.score;
}
int n, R;
int main(){
	scanf("%d %d", &n, &R);
	n <<= 1;
	for(int i = 1; i <= n; i++) scanf("%d", &p[i].score);
	for(int i = 1; i <= n; i++) scanf("%d", &p[i].power),p[i].id = i;
	sort(p + 1, p + 1 + n, comp);
	for(int i = 1; i <= R; i++){
		int top = 0;
		for(int j = 1; j <= n; j += 2){
			if(p[j].power > p[j+1].power){
				p[j].score++;
				win[++top] = p[j];
				lose[top] = p[j + 1];
			}
			else{
				p[j + 1].score++;
				win[++top] = p[j + 1];
				lose[top] = p[j];
			}
		}
		int x = 1, y = 1;
		for(int j = 1; j <= n; j++){
			if(y > top || (x <= top && win[x] > lose[y])){
				p[j] = win[x];
				x++;
			}
			else{
				p[j] = lose[y];
				y++;
			}
		}
	}
	for(int i = 1; i < n; i++) printf("%d ", p[i].id);
	printf("%d\n", p[n].id);
	return 0;
}

