#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,len[21],used[21],ans;
string s[21];
char ch[3];
bool pipei(string a,int x2,int l)
{
     int LEN=a.size();
     if(len[x2]<l)  return 0;
     for(int i=0;i<l;i++)  if(a[LEN-l+i]!=s[x2][i]) return 0;
     return 1;
}
int ggc(string a,int b)
{
    int i,LEN=a.size();
    for(i=1;i<=LEN;i++)  if(pipei(a,b,i))  return i;
    return 0;
}
void dfs(string now,int nlen)
{
     if(nlen>ans)  ans=nlen;
     int i,chang;
     string k;
     for(i=1;i<=n;i++)
     if(used[i]<=1)
     {
           chang=ggc(now,i);
           if(chang>0 && chang!=now.size() && chang!=len[i]) 
           {
               used[i]++;
               dfs(s[i],nlen+len[i]-chang);
               used[i]--;  
           }   
     }
}
int main()
{
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)  {cin>>s[i];len[i]=s[i].size();}
    scanf("%s",ch);
    for(i=1;i<=n;i++)
    if(ch[0]==s[i][0])
    {
        memset(used,0,sizeof(used));
        used[i]++;
        dfs(s[i],len[i]);
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
