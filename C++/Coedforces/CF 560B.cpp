#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int A,B;
bool check(int c,int d,int a,int b){
	if((a<=c && b<=d)||(a<=d && b<=c)) return 1;
	return 0;
}
bool solve(int a1,int b1,int a2,int b2){
	if(a1<=A && b1<=B){
		if(check(A-a1,B,a2,b2) || check(A,B-b1,a2,b2)) return 1;
	}
	if(a1<=B && b1<=A){
		if(check(A-b1,B,a2,b2) || check(A,B-a1,a2,b2)) return 1;
	}
	return 0;
}
int main(){
	int a1,b1,a2,b2;
	scanf("%d%d",&A,&B);
	scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
	if(solve(a1,b1,a2,b2) || solve(a2,b2,a1,b1)) printf("YES\n");
	else printf("NO\n");
	return 0;
}

