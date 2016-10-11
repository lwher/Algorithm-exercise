#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
 
#define N 100010
 
using namespace std;
 
int n, top, sz, root, ls[N], rs[N];
long long num[N];
char s[3], ans[N];
 
void Ins(int &p, long long x){
	if(!p){
		sz++; p = sz; num[p] = x; ls[p] = rs[p] = 0;
		return;
	}
	if(num[p] == x) return;
	if(num[p] < x) Ins(rs[p], x);
	else Ins(ls[p], x);
}
 
bool find(int p, long long x){
	if(!p) return 0;
	if(num[p] == x) return 1;
	if(num[p] < x){
		ans[++top] = 'r'; return find(rs[p], x);
	}
	else{
		ans[++top] = 'l'; return find(ls[p], x);
	}
}
 
void Delete(int &p, long long  x){
	if(!p) return;
	if(num[p] == x){
		if(!rs[p]) p = ls[p];
		else {
			int k = rs[p];
			if(!ls[k]){
				num[p] = num[k]; rs[p] = rs[k]; return;
			}
			while(ls[ls[k]] != 0) k = ls[k];
			int t = ls[k];
			ls[k] = rs[t];
			num[p] = num[t]; 
		}
		return;
	}
	if(num[p] < x) Delete(rs[p], x);
	else Delete(ls[p], x);
}
 
int main(){
	long long x;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		scanf("%s", s);
		scanf("%lld", &x);
		if(s[0] == '+'){
			Ins(root, x);
		} else
		if(s[0] == '-'){
			Delete(root, x);
		}
		else{
			top = 1;
			ans[top] = '*';
			if(find(root, x)){
				for(int j = 1; j <= top; j++){
					printf("%c", ans[j]);
				}
				printf("\n");
			}
			else printf("Nothing.\n");
		}
	}
	return 0;
}
