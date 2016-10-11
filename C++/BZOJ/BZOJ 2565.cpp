#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n,r[300010],tmp[300010];
char s[300010],ch[100010];
int main()
{
    int i,j,len;
    scanf("%s",ch+1);
    len=strlen(ch+1);
    s[n]='@';s[++n]='#';
    for(i=1;i<=len;i++)
    {
       s[++n]=ch[i];
       s[++n]='#';
    }
    s[++n]='$';
    int p=0,mx=0;
    for(i=1;i<n;i++)
    {
       if(mx>i) r[i]=min(r[2*p-i],mx-i); else r[i]=1;
       while(s[i-r[i]]==s[i+r[i]]) r[i]++;
       if(i+r[i]>mx) {p=i;mx=i+r[i];}
    }
    for(i=2,j=3;i<n;i++) for(;j<=i+r[i]-1;j++) if(s[j]=='#') tmp[j]=j-i;
    for(i=n-1,j=n-2;i>1;i--)  for(;j>=i-r[i]+1;j--) if(s[j]=='#') tmp[j]+=i-j;
    int ans=0;
    for(i=2;i<n;i++) ans=max(ans,tmp[i]);
    printf("%d\n",ans);
    return 0;
}