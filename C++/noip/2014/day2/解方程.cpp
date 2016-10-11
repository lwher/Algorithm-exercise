#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
struct sth{
	char num[10010];
	int len;
}A[101];
int n, m, a[101], ans;
bool mark[1000010];
int mod=10007;
int mod2[10]={100000007,23333333,54325520,1234567,17654321,13211331,12356547,100000009,20516541,25333333};
int operator %(sth a, int b){
	int i, res=0, k;
	if(a.num[0]=='-') k = 1; else k = 0;
	for(i = k;i < a.len;i ++)
		res = (res * 10 + (a.num[i] - '0')) % b;
	return res;
}
void init(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i <= n;i ++){
		scanf("%s", A[i].num);
		A[i].len = strlen(A[i].num);
	}
}
void solve_work_one(int x){
	int i, j, resz, resf, mi;
	for(i = 0;i <= n;i ++) a[i] = A[i] % x;
	for(i = 1;i < x;i ++) {
		if(!mark[i]){
			resz = 0; resf = 0; mi = 1;
			for(j = 0;j <= n;j ++){
				if(A[j].num[0]=='-') resf = (resf + (mi * a[j]) % x) % x;
				else resz = (resz + (mi * a[j]) % x) % x;
				mi = (mi * i) % x;
			}
			if(resz != resf) mark[i] = 1;
		}
		if(mark[i]){
			for(j = i + x;j <= m;j += x) mark[j] = 1;
		}
	}
}
void solve_work_two(int x){
	int i, j;
	long long resz, resf, mi;
	for(i = 0;i <= n;i ++) a[i] = A[i] % x;
	for(i = 1;i <= m;i ++) {
		if(!mark[i]){
			resz = 0; resf = 0; mi = 1;
			for(j = 0;j <= n;j ++){
				if(A[j].num[0]=='-') resf = (resf + (mi * a[j]) % x) % x;
				else resz = (resz + (mi * a[j]) % x) % x;
				mi = (mi * i) % x;
			}
			if(resz != resf) mark[i] = 1;
		}
	}
}
void solve(){
	solve_work_one(mod);
	for(int i = 0;i < 10;i ++) solve_work_two(mod2[i]);
	for(int i = 1;i <= m;i ++) if(!mark[i]) ans++;
	printf("%d\n", ans);
	for(int i = 1;i <= m;i ++) if(!mark[i]) printf("%d\n", i);
}
int main(){
	init();
	solve();
	return 0;
} 
