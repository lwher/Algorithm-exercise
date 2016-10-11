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

struct point{
	int x, y;
};

int n, R;
point p[10010];

int sqr(int x){
	return x * x;
}

double dist(point a, point b){
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));	
}

point operator -(point a, point b){
	point res;
	res.x = a.x - b.x;
	res.y = a.y - b.y;
	return res;
}

int operator *(point a, point b){
	return a.x * b.y - a.y * b.x;
}

int Turnto(point a, point b, point c){ // A->B->C >0 œÚ”“ 
	return (c - a) * (b - a);
}

inline bool cmp(point a, point b){
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

inline bool comp(point a, point b){
	if(Turnto(p[1], a, b) == 0) return dist(p[1], a) < dist(p[1], b);
	if(Turnto(p[1], a, b) > 0) return 1;
	else return 0; 
}

point stack[10010];
int top;

int main(){
	while(scanf("%d%d", &n, &R) != EOF){
		for(int i = 1; i <= n; i++){
			scanf("%d%d", &p[i].x, &p[i].y);
		}
		sort(p + 1, p + 1 + n, cmp);
		sort(p + 2, p + 1 + n, comp);
		top = 0;
		stack[++top] = p[1];
		for(int i = 2; i <= n; i++){
			while(top > 1 && Turnto(stack[top - 1], stack[top], p[i]) < 0) top--;
			stack[++top] = p[i];
		}
		double ans = 0;
		stack[top + 1] = p[1];
		for(int i = 1; i <= top; i++) 
			ans += dist(stack[i], stack[i + 1]);
		ans += acos(-1) * 2 * R;
		printf("%.2lf\n", ans);
	}
	return 0;
}

