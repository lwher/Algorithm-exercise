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
long long calc(int x){
	long long res=1;
	for(int i=1;i<x;i++) res<<=1;
	return res;
}
int main(){
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		cout<<calc(n)<<endl;
	} 
	return 0;
}

