#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string s,ans;
int n;
char ch;
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {scanf("\n%c",&ch);s+=ch;}
    int l=0,r=n-1;
    
    while(l<r)
    {
        if(s[l]!=s[r])
        {
           if(s[l]<s[r]) {ans+=s[l];l++;}
           else {ans+=s[r];r--;}
        }
        else
        {
            if(l+1==r)   {ans+=s[r];r--; continue;}
            int x=l+1,y=r-1;
            while(x<y && s[x]==s[y])
            {
               x++;y--;
            }
            if(x==y+1)   {x--;y++;}
            if(s[x]<s[y])
            {ans+=s[l];l++;}
            else
            {ans+=s[r];r--;}
        }
    }
    ans+=s[l];
    for(i=1;i<=n;i++)
    {
       cout<<ans[i-1];
       if(i%80==0)  cout<<endl;
    }
    system("pause");
    return 0;
}
