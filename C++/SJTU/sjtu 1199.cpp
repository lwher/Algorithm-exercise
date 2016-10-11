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

struct HPC{
	int num[510];
};

void print(const HPC &A){// 输出函数	
	printf("%d",A.num[A.num[0]]);
	for(int i=A.num[0]-1;i>0;i--) printf("%.4d",A.num[i]);
	printf("\n");
}

HPC operator +(const HPC &a,const HPC &b){//高精 + 高精 
	HPC ans;int &len=ans.num[0],L=max(a.num[0],b.num[0]);
	memset(ans.num,0,sizeof(ans.num));
	for(int i=1;i<L;i++){
		ans.num[i]+=a.num[i]+b.num[i];ans.num[i+1]+=ans.num[i]/10000;ans.num[i]%=10000;
	}
	len=L;ans.num[len]+=a.num[len]+b.num[len];
	for(;ans.num[len]>=10000;len++){
		ans.num[len+1]+=ans.num[len]/10000;ans.num[len]%=10000;
	}
	return ans;
}

HPC operator *(const HPC &a,const HPC &b){//高精 * 高精 
	HPC ans;int &len=ans.num[0];
	memset(ans.num,0,sizeof(ans.num));
	if((a.num[0]==1 && a.num[1]==0) || (b.num[0]==1 && b.num[1]==0)){
		ans.num[0]=1;return ans;
	}
	for(int i=1;i<=a.num[0];i++)
		for(int j=1;j<=b.num[0];j++){
			ans.num[i+j-1]+=a.num[i]*b.num[j];ans.num[i+j]+=ans.num[i+j-1]/10000;ans.num[i+j-1]%=10000;
		}
	len=a.num[0]+b.num[0]-1;
	if(ans.num[len+1]>0) len++; 
	for(;ans.num[len]>=10000;len++){
		ans.num[len+1]+=ans.num[len]/10000;ans.num[len]%=10000;
	}
	return ans;
}

int n, C, num[11000];
HPC dp[110][110], f[110];

int main(){
	int x;
	scanf("%d%d",&n, &C);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		num[x]++;
	}
	for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) dp[i][j].num[0] = 1;
	dp[0][1].num[1] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			for(int k = 1; k <= j; k++)
				dp[i][j] = dp[i][j] + dp[i - j][k];
		}
	}
	for(int i = 1; i <= n; i++){
		f[i].num[0] = 1;
		for(int j = 1; j <= i; j++)
			f[i] = f[i] + dp[i][j];
	}
	HPC ans;
	ans.num[1] = 1; ans.num[0] = 1;
	for(int i = 1; i <= C; i++){
		if(num[i])
			ans = ans * f[num[i]];
	}
	print(ans);
	return 0;
}

