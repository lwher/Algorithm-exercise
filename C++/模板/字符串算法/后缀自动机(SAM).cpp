/*
	后缀自动机 SPOJ 1811 裸模板 
*/ 
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 500001
using namespace std;
int lena,lenb,ans;
int sz,last,step[N],trans[N][26],next[N];
char A[N],B[N];
void SAM_Add(int id){
	int p=last,np=++sz;step[np]=step[p]+1;
	last=np;
	for(;p!=-1 && !trans[p][id];p=next[p]) trans[p][id]=np;
	if(p==-1) next[np]=0;
	else{
		int q=trans[p][id];
		if(step[q]==step[p]+1) next[np]=q;
		else{
			int nq=++sz;step[nq]=step[p]+1;
			next[nq]=next[q];next[np]=next[q]=nq;
			for(int i=0;i<26;i++) trans[nq][i]=trans[q][i];
			for(;p!=-1 && trans[p][id]==q;p=next[p]) trans[p][id]=nq;
		}
	}
}
void init(){
	next[0]=-1;
	scanf("%s",A+1);lena=strlen(A+1);
	scanf("%s",B+1);lenb=strlen(B+1);
	for(int i=1;i<=lena;i++) SAM_Add(A[i]-'a');
}
void solve(){
	int i,k,p=0,len=0;
	for(i=1;i<=lenb;i++){
		k=B[i]-'a';
		if(trans[p][k]){
			p=trans[p][k];len++;
		}
		else{
			for(;p!=-1 && !trans[p][k];p=next[p]);
			if(p==-1){
				p=0;len=0;
			}
			else{
			    len=step[p]+1;p=trans[p][k];
			}
		}
		if(len>ans) ans=len;
	}
	printf("%d\n",ans);
}
int main(){
	init();
	solve();
	return 0;
}

