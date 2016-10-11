#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
map<int,int> Q1,Q2;	
int n,de,tou,wei,dui[2000000],kind[2000000];
string a,b;
inline int Stoi(string p){
	int res=0;
	for(int i=0;i<n;i++){
		res=res*10+(p[i]-'0');
	}
	return res;
}
inline string itos(int p){
	string res="";
	while(p>0){
		res+=(p%10)+'0';
		p/=10;
	}
	while(res.size()<n){
		res+='0';
	}
	string o="";
	for(int i=n-1;i>=0;i--) o+=res[i];
	return o;
}
int BFS(){//1:-> 2:<-
	Q1.clear();Q2.clear();
	tou=1;wei=2;
	if(a==b) return 0;
	de=Stoi(b);
	dui[1]=Stoi(a);kind[1]=1;
	dui[2]=Stoi(b);kind[2]=2;
	Q1[dui[1]]=1;Q2[dui[2]]=1;
	while(tou<=wei){
		string x,now=itos(dui[tou]);
		tou++;
		if(kind[tou-1]==1){
			int len=Q1[dui[tou-1]];
			for(int i=0;i<n;i++){
				x=now;
				int k=(now[i]-'0')+1;
				if(k==10) k=0;
			    x[i]=k+'0';
			    int y=Stoi(x);
			    if(Q2[y]!=0) return len+Q2[y]-1;
			    if(Q1[y]==0){
					Q1[y]=len+1;
					dui[++wei]=y;
					kind[wei]=1;
				}
			}
			for(int i=0;i<n-1;i++){
				x=now;
				swap(x[i],x[i+1]);
			    int y=Stoi(x);
			   if(Q2[y]!=0) return len+Q2[y]-1;
			    if(Q1[y]==0){
					Q1[y]=len+1;
					dui[++wei]=y;
					kind[wei]=1;
				}
			}
		}
		else{
			int len=Q2[dui[tou-1]];
			for(int i=0;i<n;i++){
				x=now;
				int k=(now[i]-'0');
				if(k==0) k=10;
				k--;
			    x[i]=k+'0';
			    int y=Stoi(x);
			    if(Q1[y]!=0) return len+Q1[y]-1;
			    if(Q2[y]==0){
					Q2[y]=len+1;
					dui[++wei]=y;
					kind[wei]=2;
				}
			}
			for(int i=0;i<n-1;i++){
				x=now;
				swap(x[i],x[i+1]);
			    int y=Stoi(x);
			    if(Q1[y]!=0) return len+Q1[y]-1;
			    if(Q2[y]==0){
					Q2[y]=len+1;
					dui[++wei]=y;
					kind[wei]=2;
				}
			}
		}
	}
}
int main(){
	for(int i=1;i<=3;i++){
		scanf("%d",&n);
		cin>>a>>b;	
		printf("%d\n",BFS());
	}
	return 0;
}

