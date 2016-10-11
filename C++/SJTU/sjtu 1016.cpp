#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 510

using namespace std;

struct HPC{
	int num[N];
};
char NA[510], NB[510];


bool operator >(const HPC &a,const HPC &b){// 比较大小 
	if(a.num[0]>b.num[0]) return 1;
	if(a.num[0]<b.num[0]) return 0;
	for(int i=a.num[0];i;i--){
		if(a.num[i]>b.num[i]) return 1;
		if(a.num[i]<b.num[i]) return 0;
	}
	return 0;
}

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

HPC operator /(const HPC &a,int b){//高精 / 单精 
	HPC ans;int &len=ans.num[0];
	memset(ans.num,0,sizeof(ans.num));
	for(int i=a.num[0];i>1;i--){
		ans.num[i-1]+=(ans.num[i]+a.num[i])%b*10000;ans.num[i]=(ans.num[i]+a.num[i])/b;
	}
	ans.num[1]=(ans.num[1]+a.num[1])/b;
	for(len=a.num[0];!ans.num[len];len--);
	return ans;
}

HPC StoI(char s[]){
	int L = strlen(s + 1);
	HPC res;
	memset(res.num, 0, sizeof(res.num));
	for(int i = L; i > 0; i -= 4){
		int p = 0, k = max(1, i - 3);
		for(int j = k; j <= i; j++)
			p = p * 10 + (s[j] - '0');
		res.num[++res.num[0]] = p;
	}
	return res;
}

HPC Chu(const HPC &a, const HPC &b){
	HPC l, r = a, mid, step;
	memset(l.num, 0, sizeof(l.num));
	memset(step.num, 0, sizeof(step.num));
	l.num[0] = 1;
	step.num[0] = step. num[1] = 1;
	while(r > l + step){
		mid = (l + r) / 2;
		if(mid * b > a) r = mid;
		else l = mid;
	}
	if(r * b > a) return l;
	else return r;
}
int main(){
	scanf("%s", NA + 1);
	scanf("%s", NB + 1);
	HPC A, B;
	A = StoI(NA);
	B = StoI(NB);
	print(Chu(A, B));
	return 0;
}

