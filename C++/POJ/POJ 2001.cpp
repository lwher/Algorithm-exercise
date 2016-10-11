#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char a[1010][31];
int tot,size;
int sz,t[30001][26],s[30001];
void insert(char ss[])
{
    int k,p=1,len=strlen(ss+1),now=0;
    while(p<=len)
    {
    	  s[now]++;
    	  k=ss[p]-'a';
    	  if(t[now][k]==0) t[now][k]=++sz;
          now=t[now][k];
          p++; 
    }
    s[now]++;
}
void ask(char ss[])
{
	int now=0,k,p=1,len=strlen(ss+1);
	while(p<=len)
	{
		if(s[now]==1 && now!=0)  break;
		k=ss[p]-'a';
		printf("%c",ss[p]);
		now=t[now][k];
		p++;
   }
}
int main()
{
    while(scanf("%s",a[++tot]+1)!=EOF)insert(a[tot]);
    for(int i=1;i<tot;i++)
    {
            printf("%s ",a[i]+1);            
            ask(a[i]);
            printf("\n");
    }
    return 0;
} 