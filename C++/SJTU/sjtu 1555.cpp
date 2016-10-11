#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
#include<cmath>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
struct sth {  
    int x ,y ,x2 ,y2 ,w, bh, wt, qian;  
}xw[1000010], d[1000010];  
 
int num[1000010], shu[1000010], top, TOT;
int sz;  
int n;
long long ans[1000010], s[1000010];  
 
void swap(int &a, int &b) {  
    int t = a; a = b; b = t;  
}  
 
inline bool comp(sth a, sth b){  
    if(a.x == b.x)  return a.wt < b.wt;     
    return a.x < b.x;  
}  
 
int lowbit(int x){  
    return x & (-x);  
}  
 
void updata(int x, long long w){  
    while(x <= TOT)  {  
        s[x] += w;  
        x += lowbit(x);  
    }  
}  
long long getsum(int x) {  
    long long now = 0;  
    while(x > 0) {  
        now += s[x];  
        x -= lowbit(x);  
    }  
    return now;  
}  
void solve(int l, int r) {  
    if(l == r) return;  
    int mid = (l + r) >> 1;  
    solve(l, mid); 
	solve(mid + 1, r);  
    int i, tot = 0, bo = 0;  
	long long tmp;
    for(i = l; i <= mid; i++)  
    if(xw[i].wt == 0)  {  
        tot++; d[tot] = xw[i]; bo = 1;  
    }  
    if(bo == 0) return;  
    for(i = mid + 1; i <= r; i++)  
    if(xw[i].wt == 1)  {  
        tot++; d[tot] = xw[i]; d[tot].x--;d[tot].x2 = xw[i].x - 1; d[tot].bh = i;d[tot].qian = 1;  
        tot++; d[tot] = xw[i]; d[tot].x = xw[i].x2; d[tot].bh = i; d[tot].qian = 0;  
        bo = 2;  
    }  
    if(bo == 1) return;  
    sort(d + 1, d + 1 + tot, comp);  
    for(i = 1; i <= tot; i++) {  
        if(d[i].wt == 0)   updata(d[i].y, d[i].w);  
        else{  
            tmp = getsum(d[i].y2) - getsum(d[i].y - 1);  
            if(d[i].qian == 1)  ans[d[i].bh] -= tmp;  
            else  ans[d[i].bh] += tmp;  
        }  
    }  
    for(i = 1; i <= tot; i++) {  
        if(d[i].wt == 0){
			updata(d[i].y, -d[i].w);  
		}
    }
}  
 
int find(int x){
	int l = 1, r = TOT, mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(num[mid] == x) return mid;
		if(num[mid] < x) l = mid;
		else r = mid;
	}
	if(num[l] == x) return l;
	else return r;
}
 
int main()  
{  
    int t,a,b,c,d;  
    scanf("%d",&n);  
    for(int i = 1; i <= n; i++){
		scanf("%d",&t);
	    if(t == 1)  {  
	        sz++;scanf("%d%d%d",&a, &b, &c);  
	        xw[sz].x=a; xw[sz].y=b; xw[sz].w=c; xw[sz].wt=0;  
	        shu[++top] = a; shu[++top] = b;
	    }    
	    else{  
	        sz++;scanf("%d%d%d%d",&a,&b,&c,&d);  
	        if(a > c || (a == c && b > d))  swap(a,c), swap(b,d);  
	        xw[sz].x=a; xw[sz].y=b; xw[sz].x2=c; xw[sz].y2=d; xw[sz].wt = 1;  
	        shu[++top] = a; shu[++top] = b; shu[++top] = c; shu[++top] = d;
	    }  
	}  
	sort(shu + 1, shu + 1 + top);
	num[++TOT] = shu[1];
	for(int i = 2; i <= top; i++) if(shu[i] != shu[i - 1]) num[++TOT] = shu[i];
	
	for(int i = 1; i <= sz; i++){
		if(xw[i].wt == 1){
			xw[i].x = find(xw[i].x); xw[i].y = find(xw[i].y);
			xw[i].x2 = find(xw[i].x2); xw[i].y2 = find(xw[i].y2);
		}
		else{
			xw[i].x = find(xw[i].x); xw[i].y = find(xw[i].y);
		}
	}	
		
    solve(1, sz);  
    for(int i = 1; i <= sz;i++)  if(xw[i].wt == 1)  printf("%lld\n",ans[i]);  
    //system("pause");  
    return 0;  
}
