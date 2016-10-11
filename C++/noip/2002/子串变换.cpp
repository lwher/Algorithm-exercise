#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

struct node
{
    char s[30];
    int dep;
} list1[5010],list2[5010];
char a[7][30],b[7][30];
int n;
bool check(char *s1,char *s2)
{
    if (strlen(s1)!=strlen(s2)) return false;
    for (int i=0;i<strlen(s1);i++)
        if (s1[i]!=s2[i]) return false;
    return true;
}
bool pan1(char *s,int i,int x)
{
    for (int j=i;j<i+strlen(a[x]);j++)
        if (s[j]!=a[x][j-i]) return false;
    return true;
}
bool pan2(char *s,int i,int x)
{
    for (int j=i;j<i+strlen(b[x]);j++)
        if (s[j]!=b[x][j-i]) return false;
    return true;
}
void bfs()
{
    int head1,tail1,head2,tail2,k;
    head1=tail1=head2=tail2=1;
    while (head1<=tail1 && head2<=tail2)
    {
        if (list1[head1].dep+list2[head2].dep>10)
        {
            printf("NO ANSWER!\n");
            return ;
        }
        for (int i=0;i<strlen(list1[head1].s);i++)
            for (int j=1;j<=n;j++)
                if (pan1(list1[head1].s,i,j))
                {
                  tail1++;
                  for (k=0;k<i;k++) list1[tail1].s[k]=list1[head1].s[k];
                  for (int l=0;l<strlen(b[j]);l++,k++) list1[tail1].s[k]=b[j][l];
                  for (int l=i+strlen(a[j]);l<=strlen(list1[head1].s);l++,k++)
                     list1[tail1].s[k]=list1[head1].s[l];
                  list1[tail1].s[k]='\0';
                  list1[tail1].dep=list1[head1].dep+1;
                  for (k=1;k<=tail1;k++)
                    if (check(list1[tail1].s,list2[k].s))
                    {
                       printf("%d\n",list1[tail1].dep+list2[k].dep);
                       return ;
                     }
                }
        for (int i=0;i<strlen(list2[head2].s);i++)
            for (int j=1;j<=n;j++)
                if (pan2(list2[head2].s,i,j))
                {
                  tail2++;
                  for (k=0;k<i;k++) list2[tail2].s[k]=list2[head2].s[k];
                  for (int l=0;l<strlen(a[j]);l++,k++) list2[tail2].s[k]=a[j][l];
                  for (int l=i+strlen(b[j]);l<=strlen(list2[head2].s);l++,k++)
                    list2[tail2].s[k]=list2[head2].s[l];
                  list2[tail2].s[k]='\0';
                  list2[tail2].dep=list2[head2].dep+1;
                  for (k=1;k<=tail1;k++)
                    if (check(list1[k].s,list2[tail2].s))
                    {
                       printf("%d\n",list1[k].dep+list2[tail2].dep);
                       return ;
                    }
                }
        head1++; head2++;
    }
    printf("NO ANSWER!\n");
}
int main()
{
    //freopen("data.in","r",stdin);
   // freopen("data.out","w",stdout);
    scanf("%s%s",list1[1].s,list2[1].s);
    n=1;
    while (scanf("%s%s",a[n],b[n])!=EOF) n++;
    n--;
    list1[1].dep=list2[1].dep=0;
    bfs();
    return 0;
}