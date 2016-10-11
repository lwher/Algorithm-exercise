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

int n, sz, size[1010], L[1010][510], R[1010][510], pl[1010][510], ans[1010];
bool mark[510];
char S[300010];
string H[510];

int find(string s){
	for(int i = 1; i <= sz; i++) 
		if(s == H[i]) return i;
	H[++sz] = s;
	return sz;
}

int Atoi(string s){
	int res = 0, len = s.size();
	if(s[0] == '-'){
		for(int i = 1; i < len; i++) res = res * 10 + (s[i] - '0');
		return -res;
	}
	else{
		for(int i = 0; i < len; i++) res = res * 10 + (s[i] - '0');
		return res;
	}
}

bool judge(int x, int y){
	int fx, fy, lx, rx, ly, ry;
	for(int i = 1; i <= sz; i++){
		fx = -1; fy = -1;
		for(int j = 1; j <= size[x]; j++){
			if(pl[x][j] == i){
				fx = j; break;
			}
		}
		for(int j = 1; j <= size[y]; j++){
			if(pl[y][j] == i){
				fy = j; break;
			}
		}
		if(fx == -1) lx = -200000, rx = 200000;
		else lx = L[x][fx], rx = R[x][fx];
		
		if(fy == -1) ly = -200000, ry = 200000;
		else ly = L[y][fy], ry = R[y][fy];
		
		if(lx > rx || ly > ry || lx > ry || rx < ly) return 0;
	}
	return 1;
}

int main(){
	string bl, fh, num;
	scanf("%d", &n); getchar();	
	for(int i = 1; i <= n; i++){
		gets(S + 1);
		int len = strlen(S + 1), l, r;
		S[0] = ','; S[++len] = ','; l = 0;
		memset(mark, 0, sizeof(mark));
		for(r = 1; r <= len; r++){
			if(S[r] == ','){
				bl = ""; fh = ""; num = "";
				l++;
				while(S[l] == ' ') l++;
				while(S[l] >= 'a' && S[l] <= 'z'){
					bl += S[l]; l++;
				} 
				while(S[l] == ' ') l++;
				while(S[l] == '<' || S[l] == '>' || S[l] == '='){
					fh += S[l]; l++;
				} 
				while(S[l] == ' ') l++;
				while(S[l] == '-' || (S[l] >= '0' && S[l] <= '9')){
					num += S[l]; l++;
				} 
				l = r;
				
				int Bl = find(bl), Num = Atoi(num), W;
				if(mark[Bl]){
					for(int j = 1; j <= size[i]; j++){
						if(pl[i][j] == Bl){
							W = j; break;
						}
					}
				}
				else{
					W = ++size[i]; pl[i][W] = Bl; L[i][W] = -200000; R[i][W] = 200000; mark[Bl] = 1;
				}
				
				if(fh == ">") L[i][W] = max(L[i][W], Num + 1);
				if(fh == "<") R[i][W] = min(R[i][W], Num - 1);
				if(fh == ">=") L[i][W] = max(L[i][W], Num);
				if(fh == "<=") R[i][W] = min(R[i][W], Num);
				if(fh == "=="){
					L[i][W] = max(L[i][W], Num); R[i][W] = min(R[i][W], Num);
				}
			}
		}		
	}	
	int cnt;	
	for(int i = 1; i <= n; i++){
		cnt = 0;
		for(int j = 1; j < i; j++) if(judge(i, j)){
			ans[++cnt] = j;
		}
		if(!cnt) printf("unique\n");
		else{
			for(int j = 1; j < cnt; j++) printf("%d ", ans[j]);
			printf("%d\n", ans[cnt]);
		}
	}
	return 0;
}

