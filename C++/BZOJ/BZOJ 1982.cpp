#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int n;char ch[10001];
string s[100001];
int main()
{
    scanf("%d",&n);
    if(n&1){printf("first player");return 0;}
    for(int i=1;i<=n;i++)  {scanf("%s",ch);s[i]=ch;}  
    for(int i=1;i<=n;i+=2)  if(s[i]!=s[i+1]){printf("first player");return 0;}
    printf("second player");
    return 0;
} 