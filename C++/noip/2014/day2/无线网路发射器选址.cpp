#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct point{
	int x,y,num;
}p[30];
int n,D,maxans=0,sum=0;
void init(){
	scanf("%d%d",&D,&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].num);
}
void solve(){
	int i,j,k,nsum;
	for(i=0;i<=128;i++) for(j=0;j<=128;j++){
		nsum=0;
		for(k=1;k<=n;k++) if(abs(p[k].x-i)<=D && abs(p[k].y-j)<=D) nsum+=p[k].num;
		if(nsum>maxans) {
			maxans=nsum;
			sum=1;
		}
		else if(nsum==maxans) sum++;
    }
    cout<<sum<<" "<<maxans<<endl;
}
int main(){
	freopen("wireless.in","r",stdin);
	freopen("wireless.out","w",stdout);
	init();
	solve();
	return 0;
}
