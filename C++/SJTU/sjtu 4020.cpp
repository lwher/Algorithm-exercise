#include<iostream>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,ans,num[1001],f[1010][1010];
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++) scanf("%d",&num[i]);
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(i>j) f[i][j]=f[i-1][j];
				f[i][j]=max(f[i][j],f[i-1][j-1]);
				if(num[i]==j) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
			}
		}
		for(int i=1;i<=n;i++) ans=max(ans,f[n][i]);
		cout<<ans<<endl;
	}
	return 0;
}

