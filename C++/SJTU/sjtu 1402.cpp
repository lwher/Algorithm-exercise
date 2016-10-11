#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 600010
using namespace std;
int n, Q, sz, root, c[N][2], fa[N], size[N], shu[N], cover[N], dx[N];
long long sum[N], num[N], first[N]; 
void update(int x){
	int ls = c[x][0], rs = c[x][1];
	size[x] = size[ls] + size[rs] + 1;
	sum[x] = sum[ls] + sum[rs] + num[x];
}
inline void downpush(int x){
	int ls = c[x][0], rs = c[x][1];
	if(cover[x] != 0){
		if(ls){
			cover[ls] = cover[x];
			num[ls] = cover[x];
			first[ls] = 0; dx[ls] = 0;
			sum[ls] = num[ls] * size[ls]; 
		}
		if(rs){
			cover[rs] = cover[x];
			num[rs] = cover[x];
			first[rs] = 0; dx[rs] = 0;
			sum[rs] = num[rs] * size[rs]; 
		}
		cover[x] = 0;
	}
	if(first[x] || dx[x]){
		if(ls){
			num[ls] += first[x] + (long long)dx[x] * size[c[ls][0]];
			first[ls] += first[x]; dx[ls] += dx[x];
			sum[ls] += (first[x] * 2 + (long long)(dx[x]) * (size[ls] - 1)) * size[ls] / 2;
		}
		if(rs){
			first[x] += (long long)dx[x] * size[ls] + dx[x];
			num[rs] += first[x] + (long long)dx[x] * size[c[rs][0]];
			first[rs] += first[x]; dx[rs] += dx[x];
			sum[rs] += (first[x] * 2 + (long long)(dx[x]) * (size[rs] - 1)) * size[rs] / 2;
		}
		first[x] = 0; dx[x] = 0;
	}
}
void rotate(int &root, int x){
	int y = fa[x], z = fa[y], p, q;
	if(c[y][0] == x) p = 0; else p = 1;
	q = p ^ 1;
	if(y == root) root = x;
	else {
		if(c[z][0] == y) c[z][0] = x;
		else c[z][1] = x;
	}
	fa[x] = z; fa[y] = x; fa[c[x][q]] = y;
	c[y][p] = c[x][q]; c[x][q] = y;
	update(y); update(x);
}
void splay(int &root, int x){
	int y, z;
	while(x != root){
		y = fa[x]; z = fa[y];
		if(y != root){
			if((c[z][0] == y) ^ (c[y][0] == x)) rotate(root, x);
			else rotate(root, y);
		}
		rotate(root, x);
	}
}
int find(int x, int k){
	downpush(x);
	int y = c[x][0];
	if(size[y] + 1 == k) return x;
	if(size[y] >= k) return find(c[x][0], k);
	else return find(c[x][1], k - size[y] - 1);
}
void build(int last, int l, int r){
	if(l > r) return;
	int mid = (l + r) >> 1;
	fa[mid] = last; size[mid] = 1; num[mid] = shu[mid];
	if(mid < last) c[last][0] = mid;
	else c[last][1] = mid;
	build(mid, l, mid - 1);
	build(mid, mid + 1, r);
	update(mid);
}
void add(int l, int r, int F){
	int x = find(root, l);
	splay(root, x);
	x = find(root, r + 2);
	splay(c[root][1], x);
	x = c[c[root][1]][0];
	if(x){
		first[x] += F; dx[x] += F;
		num[x] += F + (long long)F * size[c[x][0]];
		sum[x] += (F + F + (long long)(F) * (size[x] - 1)) * size[x] / 2;
		update(c[root][1]);
		update(root);
	}
	
}
void Cover(int l, int r, int X){
	int x = find(root, l);
	splay(root, x);
	x = find(root, r + 2);
	splay(c[root][1], x);
	x = c[c[root][1]][0];
	if(x){
		cover[x] = X;
		first[x] = 0; dx[x] = 0;
		num[x] = X; sum[x] = (long long)(X) * size[x];
		update(c[root][1]);
		update(root);
	}
}
void Insert(int w, int X){
	int x = find(root, w);
	splay(root, x);
	x = find(root, w + 1);
	splay(c[root][1], x);
	c[c[root][1]][0] = ++sz;
	x = sz;
	num[x] = X; size[x] = 1; sum[x] = X; fa[x] = c[root][1];
	update(c[root][1]);
	update(root);
}
long long getsum(int l, int r){
	int x = find(root, l);
	splay(root, x);
	x = find(root, r + 2);
	splay(c[root][1], x);
	x = c[c[root][1]][0];
	return sum[x];
}
int main(){
	int ty, l, r, b;
	scanf("%d %d", &n, &Q);
	for(int i = 1; i <= n; i++){
		scanf("%d", &shu[i + 1]);
	}
	n += 2; sz = n;
	root = (n + 1) >> 1;
	build(0, 1, n);		
	c[0][0] = c[0][1] = 0; size[0] = 0;
	for(int i = 1; i <= Q; i++){
		scanf("%d %d %d", &ty, &l, &r);
		if(ty == 1){
			scanf("%d", &b);
			Cover(l, r, b);
		} else
		if(ty == 2){
			scanf("%d", &b);
			add(l, r, b);
		} else
		if(ty == 3){
			Insert(l, r);
		}
		else{
			printf("%lld\n", getsum(l, r));
		}
	}
	return 0;
}
