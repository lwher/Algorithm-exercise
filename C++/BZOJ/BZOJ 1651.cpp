#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct node
{
    int l,r;    
};
struct dui
{
    int first,data;
};
node a[50010];
dui heap[50010];
int p[50010];
int n,tot;
void Qsort(int l,int r)
{
    int i=l,j=r,midl=a[(l+r) / 2].l,midr=a[(l+r) / 2].r;
    node t;
    
    while (i<=j)
    {
        while (a[i].l<midl  ||  (a[i].l==midl  &&  a[i].r<midr) ) i++;
        while (a[j].l>midl  ||  (a[j].l==midl  &&  a[j].r>midr) ) j--;
        if (i<=j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++; j--;
        }         
    }    
    if (i<r) Qsort(i,r);
    if (l<j) Qsort(l,j);    
}
void Init()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r);
    Qsort(1,n);
}
void Swap(dui &x,dui &y)
{
    dui t=x;
    x=y;
    y=t;
}
void Heap_down(int now,int limit)
{
    while (now*2<=limit)
    {
        now*=2;
        if (heap[now+1].data<heap[now].data  &&  now+1<=limit) now++;
        if (heap[now].data<heap[now/2].data) Swap(heap[now],heap[now/2]);
        else break;
    }
}
void Heap_up(int now)
{
    while (now/2>=1)
    {
        if (heap[now].data<heap[now/2].data) Swap(heap[now],heap[now/2]);
        else break;
        now=now/2;
    }
}
void Main()
{
    tot=1; heap[1].data=a[1].r; heap[1].first=1; p[1]=1;
        
    for (int i=2;i<=n;i++)
    {
        if (a[i].l>heap[1].data) 
        {
            heap[1].data=a[i].r;
            p[i]=heap[1].first;
            Heap_down(1,tot);
        }
        else
        {
            tot++;
            heap[tot].first=tot;
            heap[tot].data=a[i].r;
            p[i]=tot;
            Heap_up(tot);
        }
    }    
    printf("%d\n",tot);
}
int main()
{
    Init();
    Main();
    system("pause");
    return 0;
} 
