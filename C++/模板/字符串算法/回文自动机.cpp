/*
	回文自动机 BZOJ 3676 APIO2014 T1
	支持求出一个字符串本质不同的回文串个数，各个回文串出现次数以及以i位置结尾的回文串的个数
	结合回文串本质不同的个数与各个回文串的出现次数，可以得出该串所有回文串个数
	空间复杂度O(n*字符集大小)，时间复杂度O(n*log(字符集大小)) 
*/
#include<iostream>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 300010
using namespace std;
int n;
long long ans;
char s[N];
struct pam{
	int sz,last;
	int trans[N][26],fail[N],len[N],num[N];
	pam(){
		sz=1;fail[0]=fail[1]=1;len[1]=-1;last=0;
	}
	void extend(int k,int w){
		int p=last;
		while(s[w-len[p]-1]!=s[w]) p=fail[p];
		if(!trans[p][k]){
			int now=++sz,q=fail[p];
			len[now]=len[p]+2;
			while(s[w-len[q]-1]!=s[w]) q=fail[q];
			fail[now]=trans[q][k];trans[p][k]=now;
		}
		last=trans[p][k];
		num[last]++;
	}
	void calc(){
		for(int i=sz;i;i--){
			num[fail[i]]+=num[i];
			ans=max(ans,(long long)num[i]*len[i]);
		}
	}
}pam;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);	
	s[0]='#';
	for(int i=1;i<=n;i++) pam.extend(s[i]-'a',i);
	pam.calc();
	cout<<ans<<endl;
	return 0;
}

