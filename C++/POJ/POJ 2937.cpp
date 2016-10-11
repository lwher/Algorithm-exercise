#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, P, top, t[100010];
bool rev;
char s[100010], ch[100010];

int Atoi(char S[]){
	int res = 0, L = strlen(S);
	for(int i = 0; i < L; i++) res = res * 10 + (S[i] - '0');
	return res;
}

void print(){
	if(!rev){
		if(!P){
			printf("\n"); return;
		}
		else{
			if(P > n - P + 2) printf("m1 r%d m1\n", n - P);
			else printf("r%d\n", P); 
			return;
		}
	}
	else{
		if(!P){
			printf("m1\n"); return;
		}
		else{
			if(n - P < P) printf("m1 r%d\n", n - P);
			else printf("r%d m1\n", P);
			return;
		}
	}
}

int main(){
	scanf("%s", ch);
	while(1){
		n = Atoi(ch);
		top = 0;
		if(!n) break;
		while(scanf("%s", ch) != EOF){
			if(ch[0] == 'r'){
				int p = Atoi(ch + 1);
				p %= n;
				if(p){
					s[++top] = 'r'; t[top] = p;

				}
			} else 
			if(ch[0] == 'm'){
				int p = Atoi(ch + 1);
				p %= 2;
				if(p){
					s[++top] = 'm'; t[top] = p;
				}
			}
			else break;
		}
		rev = 0; P = 0;
		for(int i = 1; i <= top; i++){
			if(s[i] == 'm') rev ^= 1;
			else{
				if(!rev){
					P += t[i]; P %= n;
				}
				else{
					P += n - t[i]; P %= n;	
				}
			}
		}
		print();
	}
	return 0;
}
