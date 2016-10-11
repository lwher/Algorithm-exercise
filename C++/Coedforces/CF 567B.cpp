#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x,ans,num[101];
bool mark[1000001];
int main(){
	char s[3];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s%d",s,&x);
		if(s[0]=='-'){
			if(!mark[x]){
				mark[x]=1;num[0]++;num[i]--;
			}
			else num[i]--;
		}
		else{
			mark[x]=1;num[i]++;
		}
	}
	ans=num[0];
	for(int i=1;i<=n;i++){
		num[i]=num[i-1]+num[i];
		ans=max(ans,num[i]);
	}
	cout<<ans<<endl;
	return 0;
}

