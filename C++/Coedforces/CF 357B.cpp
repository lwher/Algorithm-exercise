#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m;
int k[300010];
int main()
{
    int i,aa,bb,cc;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&aa,&bb,&cc);
        if(k[aa])
        {
             k[bb]=(k[aa]+1)%3;if(!k[bb]) k[bb]++;
             k[cc]=6-k[aa]-k[bb];
        }
        else
        if(k[bb])
        {
             k[aa]=(k[bb]+1)%3;if(!k[aa]) k[aa]++;
             k[cc]=6-k[aa]-k[bb];
        }
        else
        if(k[cc])
        {
             k[aa]=(k[cc]+1)%3;if(!k[aa]) k[aa]++;
             k[bb]=6-k[aa]-k[cc];
        }
        else
        {
            k[aa]=1;k[bb]=2;k[cc]=3;
        }
    }
    for(i=1;i<=n;i++) printf("%d ",k[i]);
    system("pause");
    return 0;
}
