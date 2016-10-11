#include<iostream>
#include<cstdio>
#define searchnext(x,y) y==9? search(x+1,1):search(x,y+1)
using namespace std;
int ans[10][10];
int cpl[10][10],cpr[10][10];
bool usel[10][10],user[10][10],uses[10][10],flag;
void print()
{
     for(int i=1;i<=9;i++)
     {
       for(int j=1;j<=9;j++)
           {
               printf("%d",ans[i][j]);
               if(j!=9)printf(" ");
           }
          printf("\n");
          }
 }
int cmp(int x,int y){return x>y? 1:-1;}
bool pd(int x,int y,int k)
{
     if(usel[x][k]||user[y][k])return 0;
     if(uses[((x-1)/3)*3+(y-1)/3+1][k])return 0;
     if(cmp(k,ans[x][y-1])!=cpl[x][y]&&cpl[x][y]!=0)return 0;
     if(cmp(k,ans[x-1][y])!=cpr[x][y]&&cpr[x][y]!=0)return 0;
     usel[x][k]=user[y][k]=uses[((x-1)/3)*3+(y-1)/3+1][k]=1;
     return 1;
 }
void search(int x,int y)
{
     if(x==10)
     {flag=1;print();return;}
     if(flag)return;
     for(int i=1;i<=9;i++)
     {
             if(pd(x,y,i))
             {
                 ans[x][y]=i;
                 searchnext(x,y);
                 ans[x][y]=0;
                 usel[x][i]=user[y][i]=uses[((x-1)/3)*3+(y-1)/3+1][i]=0;
             }
     }
 }
int main()
{
    char ch[2];
    for(int i=1;i<=9;i++)
    {
            for(int j=1;j<=9;j++)
            {
                    if(j%3!=0)
                    {
                        scanf("%s",ch);
                        if(ch[0]=='>')cpl[i][j+1]=-1;
                        else cpl[i][j+1]=1;
                    }
            }
            if(i%3!=0)
            for(int j=1;j<=9;j++)
            {
                    scanf("%s",ch);
                    if(ch[0]=='v')cpr[i+1][j]=-1;
                    else cpr[i+1][j]=1;
                    }
            }
    search(1,1);
    return 0;
}
