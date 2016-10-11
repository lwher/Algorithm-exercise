#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
struct node
{
    int t[6];
    int c[6][8];
    node()
    {
        memset(t,0,sizeof(t));
        memset(c,0,sizeof(c));
    }
};
int n,ans[6][3];
bool flag,b[6][8],Istrue=false;
node solve(node g)
{
    node h;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=g.t[i];j++)
        {
            if(g.c[i][j]&&!b[i][j])
            {
                h.t[i]++;
                h.c[i][h.t[i]]=g.c[i][j];
            }
        }
    }
    return h;
}
node clear(node g)
{
    node h;
    flag=false;
    memset(b,0,sizeof(b));
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=g.t[i];j++)
        {
            if(i<=3)
            {
                if(g.c[i][j]==g.c[i+1][j]&&g.c[i][j]==g.c[i+2][j])
                {
                    b[i][j]=b[i+1][j]=b[i+2][j]=true;
                    flag=true;
                }
            }
            if(j<=g.t[i]-2)
            {
                if(g.c[i][j]==g.c[i][j+1]&&g.c[i][j]==g.c[i][j+2])
                {
                    b[i][j]=b[i][j+1]=b[i][j+2]=true;
                    flag=true;
                }
            }
        }
    }
    if(flag)
    {
        h=solve(g);
        return clear(h);
    } else return g;
}
void print()
{
    for(int i=1;i<=n;i++)
        printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    Istrue=true;
}
void dfs(node g,int k)
{
    int l;
    node h;
    flag=true;
    for(int i=1;i<=5;i++)
    {
        if(g.t[i])
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        if(k>n) print(); else return;
        }
    if (Istrue) return ;
    if(k>n) return;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=g.t[i];j++)
        {
            if(i<5)
            {
                if(j>g.t[i+1])
                {
                    h=g;
                    h.t[i+1]++;
                    h.c[i+1][h.t[i+1]]=h.c[i][j];
                    h.c[i][j]=0;
                    h.t[i]--;
                    for(l=j;l<=h.t[i];l++)
                        h.c[i][l]=h.c[i][l+1];
                    h=clear(h);
                    ans[k][0]=i-1;
                    ans[k][1]=j-1;
                    ans[k][2]=1;
                    dfs(h,k+1);
                    if (Istrue) return ;
                }
                else
                {
                    h=g;
                    l=h.c[i][j];
                    h.c[i][j]=h.c[i+1][j];
                    h.c[i+1][j]=l;
                    h=clear(h);
                    ans[k][0]=i-1;
                    ans[k][1]=j-1;
                    ans[k][2]=1;
                    dfs(h,k+1);
                    if (Istrue) return ;
                }
            }
            if(i>1)
            {
                if(j>g.t[i-1])
                {
                    h=g;
                    h.t[i-1]++;
                    h.c[i-1][h.t[i-1]]=h.c[i][j];
                    h.c[i][j]=0;
                    h.t[i]--;
                    for(l=j;l<=h.t[i];l++)
                        h.c[i][l]=h.c[i][l+1];
                    
                    h=clear(h);
                    ans[k][0]=i-1;
                    ans[k][1]=j-1;
                    ans[k][2]=-1;
                    dfs(h,k+1);
                    if (Istrue) return ;
                }
            }
        }
    }
}
int main()
{
    int j;
    node g;
    scanf("%d",&n);
    for(int i=1;i<=5;i++)
    {
        scanf("%d",&j);
        while(j)
        {
            g.t[i]++;
            g.c[i][g.t[i]]=j;
            scanf("%d",&j);
        }
    }
    dfs(g,1);
    if (!Istrue) printf("-1\n");
    //system("pause");
    return 0;
}