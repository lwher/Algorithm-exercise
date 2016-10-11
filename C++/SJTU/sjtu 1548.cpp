#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
 
#define N 30010
 
using namespace std;

struct sth{
	char fh;
	int level;
}stack_f[N];
 
struct sss{
	int kind, num; // 0:Êý×Ö 1:·ûºÅ 
	char fh;
}B[N];
 
int n, mod, stack_n[N], tot, top_n, top_f, len[1001], np, shuzi[1001];
char s[N], split_res[N], split_name[N];
char Name[1001][3010];
 
int getlevel(char s){
	if(s == '#') return 1;
	if(s == '(' || s == ')') return 2;
	if(s == '+' || s == '-') return 3;
	if(s == '*' || s == '/') return 4;
	return -1;
}
 
int A_toI(char s[]){
	int res = 0, L = strlen(s);
	for(int i = 0; i < L - 1; i++)
		res = res * 10 + (s[i] - '0');
	return res;
}
 
int AtoI(char s[], int l, int r){
	int res = 0;
	for(int i = l; i <= r; i++)
		res = res * 10 + (s[i] - '0');
	return res;
}
 
bool the_same(char p[], char s[]){
	int lp = strlen(p), ls = strlen(s);
	if(lp != ls) return 0;
	for(int i = 0 ; i < lp; i++) if(p[i] != s[i])  return 0;
	return 1;
}
 
int getID(char s[]){
	for(int i = 1; i <= np; i++){
		if(the_same(Name[i], s)) return i;
	}
	++np;
	for(int i = 0; i <strlen(s); i++) Name[np][i] = s[i];
	return np;
}
 
void split(char A[]){
	memset(split_res, '\0', sizeof(split_res));
	memset(split_name, '\0', sizeof(split_name));
	int i, L = strlen(A);
	for(i = 0; i < L; i++){
		if(A[i] == '=') break;
	}
	for(int j = 0; j < i; j++){
		split_name[j] = A[j];
	}
	for(int j = i + 1; j < L; j++){
		split_res[j - i - 1] = A[j];
	}
}

int calc(char s[]){
	int L = strlen(s);
	char t[1001];
	tot = 0;
	B[++tot].kind = 1; B[tot].fh = '#';
	s[L - 1] = '#';
	for(int i = 0; i < L; i++){
		if(!(s[i] >= '0' && s[i] <= '9')){
			if(!(s[i] >= 'a' && s[i] <= 'z')){
				B[++tot].kind = 1;
				B[tot].fh = s[i];
			}
			else{
				int j = i + 1;
				while(s[j] >= 'a' && s[j] <= 'z') j++;
				memset(t,'\0',sizeof(t));
				for(int k = i; k < j; k++) 
					t[k - i] = s[k];
				B[++tot].kind = 0;
				B[tot].num = shuzi[getID(t)];
				i = j - 1;
			}
		}
		else{
			int j = i + 1;
			while(s[j] >= '0' && s[j] <= '9') j++;
			B[++tot].kind = 0;
			B[tot].num = AtoI(s, i, j - 1);
			i = j - 1;
		}
	}
	top_n = top_f = 0;
	bool flag;
	for(int i = 1; i <= tot; i++){
		if(B[i].kind == 0){
			stack_n[++top_n] = B[i].num % mod;
		}
		else{
			if(B[i].fh == '('){
				stack_f[++top_f].fh = '(';
				stack_f[top_f].level = getlevel(B[i].fh);
			}
			else{
				int level = getlevel(B[i].fh); flag = 0;
				while(top_f > 0 && stack_f[top_f].level >= level){
					if(stack_f[top_f].fh == '(' && B[i].fh == ')'){
						top_f--; flag = 1; break;
					}
					if(stack_f[top_f].fh == '+'){
						stack_n[top_n - 1] = (stack_n[top_n - 1] + stack_n[top_n]) % mod; top_n--;
					}
					if(stack_f[top_f].fh == '-'){
						stack_n[top_n - 1] = (stack_n[top_n - 1] - stack_n[top_n]) % mod; top_n--;
					}
					if(stack_f[top_f].fh == '*'){
						stack_n[top_n - 1] = (stack_n[top_n - 1] * stack_n[top_n]) % mod; top_n--;
					}
					top_f--;
				}
				if(!flag){
					stack_f[++top_f].fh = B[i].fh;
					stack_f[top_f].level = getlevel(B[i].fh);
				}
			}
		}
	}
	stack_n[top_n] %= mod;
	if(stack_n[top_n] < 0) stack_n[top_n] += mod;
	return stack_n[top_n] % mod;
}
 
int main(){
	scanf("%s", s);
	split(s);
	mod = A_toI(split_res);
	int n = 1;
	while(scanf("%s", s) != EOF){
		split(s);
		int p = getID(split_name);
		shuzi[p] = calc(split_res);
		printf("%d\n",shuzi[p]);
	}
	return 0;
}
