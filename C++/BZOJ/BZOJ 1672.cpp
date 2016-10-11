#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 2000000000
int n,M,E,x,flag,ans;
struct node{int l,r,mx,mark;}tree[500050],a[10100];
int cmp(node i,node j){return i.l < j.l;}
inline int min(int x,int y){return x < y ? x : y;}
void build(int k,int l,int r){
   tree[k].l = l,tree[k].r = r;
   tree[k].mx = INF;tree[k].mark = 0;
   if (l == r) return;
   int m = l + r >> 1;
   build(k * 2,l,m);
   build(k * 2 + 1,m + 1,r);
}
int get(int k,int pos){
   if (tree[k].l == tree[k].r) {tree[k].mark = 0;return tree[k].mx;}
   if (tree[k].mark) {
       tree[k * 2].mx = min(tree[k * 2].mx,tree[k].mark);
       tree[k * 2 + 1].mx = min(tree[k * 2 + 1].mx,tree[k].mark);
       if (!tree[k * 2].mark) tree[k * 2].mark = tree[k].mark;
       else tree[k * 2].mark = min(tree[k * 2].mark,tree[k].mark);
       if (!tree[k * 2 + 1].mark) tree[k * 2 + 1].mark = tree[k].mark;
       else tree[k * 2 + 1].mark = min(tree[k * 2 + 1].mark,tree[k].mark);
       tree[k].mark = 0;
   }
   int m = tree[k].l + tree[k].r >> 1;
   if (pos <= m) return get(k * 2,pos);
   return get(k * 2 + 1,pos);
}
void add(int k,int l,int r,int mark){
   tree[k].mx = min(tree[k].mx,mark);
   if (tree[k].l == l && tree[k].r == r) {
       if (!tree[k].mark) tree[k].mark = mark;
       else tree[k].mark = min(tree[k].mark,mark);
       return;
   }
   int m = tree[k].l + tree[k].r >> 1;
   if (r <= m) add(k * 2,l,r,mark);
   else if (l > m) add(k * 2 + 1,l,r,mark);
   else{
       add(k * 2,l,m,mark);
       add(k * 2 + 1,m + 1,r,mark);
   }
}
int main(){
   scanf("%d%d%d",&n,&M,&E);
   build(1,M,E);
   for (int i = 1;i <= n;i ++) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].mx);
   sort(a + 1,a + 1 + n,cmp);
   flag = 1;
   add(1,M,M,0);
   for (int i = 1;i <= n;i ++){
       x = get(1,max(M,a[i].l - 1));
       if (x >= INF) {flag = 0;break;}
       add(1,max(M,a[i].l),min(E,a[i].r),x + a[i].mx);
   }
   ans = get(1,E);
   if (ans >= INF) flag = 0;
   if (flag) cout << ans << endl;
   else cout << -1 << endl;
   system("pause");
   return 0;
}
