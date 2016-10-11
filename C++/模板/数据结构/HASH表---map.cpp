//1、HASH表 判断一个数是否出现过 
#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
std::map<int,int> have;
void init(){
	int i,num;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&num);
		have[num]=1;
	}
}
void solve(){
	int i,num;
	for(i=1;i<=m;i++){
		scanf("%d",&num);
		if(have[num]) printf("YES\n");
		else printf("NO\n");
	}
}
int main(){
	init();
	solve();
	return 0;
}

//2、给出一堆单词，统计哪个单词出现次数最多 HDU 1004
#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
std::map<string,int> num;
std::map<string,int>:: iterator it;
int n,sum;
string ans,s;
int main(){
	while(scanf("%d",&n) && n){
		num.clear();
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>s;
			num[s]++;
		}
		for(it=num.begin();it!=num.end();it++){
			if(it->second>sum){
				sum=it->second;
				ans=it->first;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


