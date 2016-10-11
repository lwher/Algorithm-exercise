/*
	凸包  Graham扫描算法 极角排序
	时间复杂度：O(nlogn) 
	POJ 1113 求凸包周长+给定R的圆的周长 
*/
#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 1001
using namespace std;
struct point{
	int x,y;
}p[N],stack[N];
int n,R,top;
const double pi=acos(-1);
point operator -(const point &a,const point &b){
	point c;c.x=a.x-b.x;c.y=a.y-b.y;
	return c;
}
int operator *(const point &a,const point &b){
	return a.y*b.x-a.x*b.y;
}
int turnto(point A,point B,point C){//A -> B -> C 的拐向判断 =0 共线，<0 向左，>0 向右 
	return (C-A)*(B-A); 
}
double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool comp_one(const point &a,const point &b){
	if(a.x==b.x) return a.y<b.y;
	else return a.x<b.x;
}
bool comp_two(const point &a,const point &b){
	if(turnto(p[1],a,b)==0 && dist(p[1],a)<dist(p[1],b)) return 1;
	if(turnto(p[1],a,b)<0) return 1;
	return 0;
}
void init(){
	scanf("%d%d",&n,&R);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
}
void Get_tubao(){
	sort(p+1,p+1+n,comp_one);
	sort(p+2,p+1+n,comp_two);
	stack[++top]=p[1];
	stack[++top]=p[2];
	for(int i=3;i<=n;i++){
		while(top>1 && turnto(stack[top-1],stack[top],p[i])>0) top--;
		stack[++top]=p[i];
	}
	//至此，凸包已经求完 
}
void solve(){
	Get_tubao();
	double ans=0;
	stack[++top]=p[1];
	for(int i=1;i<top;i++) ans+=dist(stack[i],stack[i+1]);
	ans+=pi*R*2;
	printf("%.0lf\n",ans);
}
int main(){
	init();
	solve();
	return 0;
}

