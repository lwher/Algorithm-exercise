#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
struct sth
{
	int qi,zhong;
	int wei;
	int pre;
	bool used;
}lu[1010];
int last[27];
int in[27],out[27];
string s[1010];
int ans[1010]; 
int sz,ss;
int t,n;
inline bool comp(string a,string b)
{return a>b;}
void add(int i)
{
	sz++;
	int a=int(s[i][0])-96;
	int b=int(s[i][s[i].size()-1])-96;
	lu[sz].wei=i;
	lu[sz].qi=a;
	lu[sz].zhong=b;
	lu[sz].pre=last[a];
	last[a]=sz;
	lu[sz].used=0;
}
void init()
{
	int i,j;
	char ch;
	sz=0;
	scanf("%d",&n);
	scanf("\n");
	memset(last,0,sizeof(last));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	memset(ans,0,sizeof(ans));
	for(i=1;i<=n;i++)
	{
        s[i]="";
		while(scanf("%c",&ch))
		{
			if(ch=='\n')  break;
			s[i]+=ch;
		}
		out[int(s[i][0])-96]++;
		in[int(s[i][s[i].size()-1])-96]++;
	}
	sort(s+1,s+n+1,comp);
	for(i=1;i<=n;i++)
	add(i);
}
bool check()
{
	int cnt1=0,cnt2=0;
	int i,j;
	for(i=1;i<=26;i++)
	{
		if(abs(in[i]-out[i])>1)
		return 0;
		if(in[i]-out[i]==1)
		cnt1++;
		if(out[i]-in[i]==1)
		{ss=i;cnt2++;}
	}
	
	if(cnt1>1 || cnt2>1 || cnt1!=cnt2)
	return 0;
	if(cnt1==0 && cnt2==0)
	for(i=1;i<=26;i++)
	if(out[i])  {ss=i;break;}
	return 1;
}
void dfs(int x,int come)
{
     int i;
     i=last[x];
     while(i>0)
     {
        if(!lu[i].used)
        {
            lu[i].used=1;
            dfs(lu[i].zhong,i);
        }
        i=lu[i].pre;
     }
     if(come!=0)
     {
     ans[0]++;
     ans[ans[0]]=come;
     }
}
int main()
{
    int i,j;
	scanf("%d",&t);
	while(t--)
	{
		init();
		
		if(check())
		{
        dfs(ss,0);
        if(ans[0]==n)
        {
        cout<<s[ans[ans[0]]];
        for(i=ans[0]-1;i>=1;i--)
        cout<<"."<<s[ans[i]];
        printf("\n");
        }
        else
        printf("***\n");
        }
        else
        printf("***\n");
	}
	system("pause");
	return 0;
}
