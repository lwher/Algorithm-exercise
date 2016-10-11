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
	int num[501];
	bool operator >(const HPC &b) const{
		if(num[0] < b.num[0]) return 0;
		if(num[0] > b.num[0]) return 1;
		for(int i = num[0]; i > 0; i--){
			if(num[i] < b.num[i]) return 0;
			if(num[i] > b.num[i]) return 1;
		}
		return 0;
	}
	HPC operator /(int b) const{
		HPC ans;int &len = ans.num[0];
		memset(ans.num,0,sizeof(ans.num));
		len = num[0];
		for(int i = len; i > 1; i--){
			ans.num[i - 1] += (ans.num[i] + num[i]) % b * 10000;
			ans.num[i] = (ans.num[i] + num[i]) / b; 
		}
		ans.num[1] = (ans.num[1] + num[1]) / b; 
		while(len > 0 && ans.num[len] == 0) len--;
		if(len == 0) len++;
		return ans;
	}
	HPC operator -(const HPC &b) const{
		HPC ans;int &len = ans.num[0];
		memset(ans.num,0,sizeof(ans.num));
		len = num[0];
		for(int i = 1; i <= len; i++){
			ans.num[i] = num[i] + ans.num[i] - b.num[i];
			if(ans.num[i] < 0){
				ans.num[i + 1]--;
				ans.num[i] += 10000;
			}
		}
		while(len > 0 && ans.num[len] == 0) len--;
		if(len == 0) len++;
		return ans;
	}
};
inline bool iszero(HPC a){
	if(a.num[0] == 1 && a.num[1] == 0) return 1;
	else return 0;
}
inline bool bin(HPC a){
	if(a.num[1] % 2) return 0; 
	else return 1;
}
void print(HPC x){
	printf("%d", x.num[x.num[0]]);
	for(int i = x.num[0]-1; i > 0; i--) printf("%.4d", x.num[i]);
	printf("\n");
}
inline void swap(HPC &a, HPC &b){
	HPC t = a;a = b;b = t;
}
char numA[501], numB[501];
HPC A, B;
int Bin, top, Ans[5001];
HPC itoa(char s[]){
	HPC res;int L = strlen(s + 1), &len = res.num[0];
	memset(res.num,0,sizeof(res.num));
	for(int i = L; i > 0; i -= 4){
		int num = 0, k = max(0, i - 4);
		for(int j = k + 1; j <= i; j++) num = num * 10 + (s[j] - '0');
		res.num[++len] = num;
	}
	return res;
}
void solve(){
	scanf("%s", numA+1);
	scanf("%s", numB+1);
	A = itoa(numA); 
	B = itoa(numB);
	if(B > A) swap(A, B);	
	while(!iszero(B)){//A > B
		if(bin(A) && bin(B)){
			Bin++;
			A = A / 2;
			B = B / 2;
			continue;
		}
		if(bin(A)){
			A = A / 2;
			continue;
		}
		if(bin(B)){
			B = B / 2;
			continue;
		}
		A = A - B;
		if(B > A) swap(A, B);
	}
	while(!iszero(A)){
		if(bin(A)) Ans[++top] = 0;
		else Ans[++top] = 1; 
		A = A / 2;
	}
	if(!top) printf("0\n");
	else{
		for(int i = top; i > 0; i--) printf("%d", Ans[i]);
		while(Bin--) printf("0");
		cout<<endl;
	}
}
int main(){
	solve();
	return 0;
}

