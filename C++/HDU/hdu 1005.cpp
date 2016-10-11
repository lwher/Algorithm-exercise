#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int f[10000],A,B,n;
int main(){
	int i;
	while(cin>>A>>B>>n && A && B && n){
		f[1]=1;f[2]=1;
		for(i=3;i<10000;i++){
			f[i]=(A*f[i-1]+B*f[i-2])%7;
			if(f[i]==1 && f[i-1]==1) break;
		}		
		i-=2;n%=i;
		if(!n) n+=i;
		printf("%d\n",f[n]);
	}
	return 0;
}

