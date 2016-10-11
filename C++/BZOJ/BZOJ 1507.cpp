#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
crope List;
int p,now;
char s[10],ch[3000000];
int main()
{
	//freopen("editor.in","r",stdin);
	//freopen("editor.out","w",stdout);
	int i,k;
	scanf("%d",&p);
	while(p--)
	{
		scanf("%s",s);
		if(s[0]=='M')  scanf("%d",&now);  else
		if(s[0]=='P')  now--;  else
		if(s[0]=='N')  now++;  else
		if(s[0]=='I')
		{
			scanf("%d",&k);
			for(i=0;i<k;i++)
			{
				ch[i]=getchar();
				while(ch[i]=='\n')  ch[i]=getchar();
			}
			ch[k]=0;
			List.insert(now,ch);
		}  else
		if(s[0]=='D')  {scanf("%d",&k); List.erase(now,k);}
		else
		{
			scanf("%d",&k);
			List.copy(now,k,ch);
			ch[k]=0;
			puts(ch);
		}
	}
	//system("pause");
	return 0;
}