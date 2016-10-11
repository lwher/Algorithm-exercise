#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
#include<iostream>
#include<cstring>
using namespace std;
struct node 
{

    int data;
    int num;
};
int phonenum[100001];
node record[100001];
char oritemp[200];
char midtemp[200];
char destemp[200];
void collect(char a[])
{
    int len=strlen(a);
    int pos=0;
    int i;
    for(i=0;i<len;i++)
    {
        if(a[i]!='-')
        {    
            midtemp[pos]=a[i];
            pos++;
        }
    }
    midtemp[pos]='\0';
}
void convert(char a[])
{
    int i;
    for(i=0;i<7;i++)
    {
        if(a[i]=='A'||a[i]=='B'||a[i]=='C')
            destemp[i]='2';
        else if(a[i]=='D'||a[i]=='E'||a[i]=='F')
            destemp[i]='3';
        else if(a[i]=='G'||a[i]=='H'||a[i]=='I')
            destemp[i]='4';
        else if(a[i]=='J'||a[i]=='K'||a[i]=='L')
            destemp[i]='5';
        else if(a[i]=='M'||a[i]=='N'||a[i]=='O')
            destemp[i]='6';
        else if(a[i]=='P'||a[i]=='R'||a[i]=='S')
            destemp[i]='7';
        else if(a[i]=='T'||a[i]=='U'||a[i]=='V')
            destemp[i]='8';
        else if(a[i]=='W'||a[i]=='X'||a[i]=='Y')
            destemp[i]='9';
        else
            destemp[i]=a[i];
    }
}
int main ()
{
    int n;
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",oritemp);
        collect(oritemp);
        convert(midtemp);
        sscanf(destemp,"%d",&phonenum[i]);
    }
    sort(phonenum+1,phonenum+1+n);
    int flag=0;
    int pos=0;
    for(i=1;i<=n;i++)
    {
        if(i==1)
        {
            pos++;
            record[pos].data=phonenum[i];
            record[pos].num++;
        }
        else if(phonenum[i]==phonenum[i-1])
        {
            record[pos].num++;
            flag=1;
        }
        else
        {
            pos++;
            record[pos].data=phonenum[i];
            record[pos].num++;
        }
    }
    if(flag==0)
        printf("No duplicates. \n");
    else if(flag==1)
        for(i=1;i<=pos;i++)
        {
            if(record[i].num!=1)
            {
                char temp[200];
                sprintf(temp,"%07d",record[i].data);
                int j;
                int flag=0;
                for(j=0;j<strlen(temp);j++)
                {
                    if(j==3&&flag==0)
                    {
                        printf("-");
                        flag=1;
                    }
                    printf("%c",temp[j]);
                }
                printf(" %d\n",record[i].num);
            }
        }
        system("pause");
        return 0;
}
