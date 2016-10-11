#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
using namespace std;
struct sth
{
    int son[26];
    int next;
    int wei;
}tree[1200005];
int sz;
int n;
int t,chang;
char ch[60];
int dui[1200005];
char chuan[1000005];
int ans;
void Ins(int now,int top)
{
    if(top==chang)
    {tree[now].wei++;return;}
    int i=int(ch[top])-97;
    if(tree[now].son[i])
    Ins(tree[now].son[i],top+1);
    else
    {
        sz++;
        memset(tree[sz].son,0,sizeof(tree[sz].son));
        tree[sz].wei=0;
        tree[sz].next=0;
        tree[now].son[i]=sz;
        Ins(sz,top+1);
    }
}
void getnext()
{
    sth now;
    int tou=1,tail=1;
    tree[0].next=-1;
    dui[tou]=0;
    int i,j;
    for(i=25;i>=0;i--)
    {
        if(tree[0].son[i])
        {
            tail++;
            dui[tail]=tree[0].son[i];
            tree[tree[0].son[i]].next=0;
        }
    }
    tou=2;
    
    while(tou<=tail)
    {
        now=tree[dui[tou]];
        for(i=25;i>=0;i--)
        {
            if(now.son[i])
            {
                j=now.next;
                while(1)
                {
                    if(j==-1) {tree[now.son[i]].next=0; break;}
                    if(tree[j].son[i])
                    {tree[now.son[i]].next=tree[j].son[i];break;}
                    j=tree[j].next;
                }
                tail++;dui[tail]=now.son[i];
            }
        }
        tou++;
    }
}
void find()
{
    int now=0;
    int i=0,j;
    while(i<chang)
    {
        j=int(chuan[i])-97;
        while(now!=0 && !tree[now].son[j])
        {now=tree[now].next;}
        now=tree[now].son[j];
        int tp=now;
        while (tp!=0 && tree[tp].wei!=-1)
        {
            ans+=tree[tp].wei;
            tree[tp].wei=-1;
            tp=tree[tp].next;
        }
        i++;
    }
}
int main()
{
    int i,j;
    scanf("%d",&t);
    while(t--)
    {
    ans=0;
    sz=0;
    memset(tree[0].son,0,sizeof(tree[0].son));
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    scanf("\n%s",ch);
    chang=strlen(ch);
    Ins(0,0);
    }
    getnext();
    scanf("\n%s",chuan);
    chang=strlen(chuan);
    find();
    printf("%d\n",ans);
    }
    system("pause");
    return 0;
}
