#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int len,num[5];
long long ans=1,sum[300001];
void calc(int H,int a,int b,int c){
	int used,ymax,last;
	used=H-a;
	if(used>len) return;
	last=len-used;
	ymax=H-b-c;
	if(ymax<0) return;
	ymax=min(ymax,last);
	ans-=sum[ymax];
}
int main(){
	scanf("%d%d%d%d",&num[1],&num[2],&num[3],&len);
	for(int i=1;i<=len;i++) ans+=1LL*(i+1)*(i+2)/2;
	sort(num+1,num+4);	
	sum[0]=1;
	
	for(int i=1;i<=len;i++) sum[i]=sum[i-1]+i+1;								
	for(int i=num[3];i<=num[3]+len;i++){
		calc(i,num[1],num[2],num[3]);
		calc(i,num[2],num[1],num[3]);
		calc(i,num[3],num[2],num[1]);
	}
	cout<<ans<<endl;
	return 0;
}

