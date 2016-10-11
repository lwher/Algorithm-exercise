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
 
int n, top, stack[3010], sum[5];// stack: 1:red 2:yellow 3:blue 5:char
string tag[10];
char s[3010];
 
bool Is_letter(char p){
	return ((p >= 'a' && p <= 'z') || (p >= 'A' && p <='Z'));
}
 
bool Same(int w,int p){
	if(n - w + 1 < tag[p].size()) return 0;
	for(int i = 0; i < tag[p].size(); i++){
		if(tag[p][i] != s[w + i]) return 0;
	}
	return 1;
}
 
int check(int w){
	for(int i = 1; i <= 6; i++){
		if(Same(w, i)) return i;
	}
	return 0;
}
 
void stack_pop(int k){
	top--;
}
 
int main(){
	gets(s + 1);
	n = strlen(s + 1);
	
	tag[2] = "<yellow>";
	tag[5] = "</yellow>";
	tag[3] = "<blue>";
	tag[6] = "</blue>";
	tag[1] = "<red>";
	tag[4] = "</red>";
	
	for(int i = 1; i <= n; i++){
		if(s[i] == '<'){
			int k = check(i);
			if(k >= 1 && k <= 3) stack[++top] = k;
			if(k >= 4 && k <= 6) stack_pop(k - 3);
			if(k) i += tag[k].size() - 1;
		} 
		else{
			if(Is_letter(s[i]) && top) ++sum[stack[top]];
		}
	}
	
	cout << sum[1] << " " << sum[2] << " " << sum[3] << endl;
	return 0;
}
