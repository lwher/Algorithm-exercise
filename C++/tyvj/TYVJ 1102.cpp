#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
string k,dc[101];int cd[101];
int f[101];
int n;
bool check(string a,int b)
{
     int i;
     if(a.size()!=cd[b])
     return 0;
     for(i=0;i<=cd[b]-1;i++)
     if(a[i]!=dc[b][i]) 
     return 0;
     return 1;
}
bool hf(string a)
{
     int i;
     for(i=1;i<=n;i++)
     if(check(a,i))
     return 1;
     return 0;
}
int main()
{
    int i,j,l;
    string o;
    memset(f,127,sizeof(f));
    f[0]=0;
    cin>>k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {cin>>dc[i];cd[i]=dc[i].size();}
    j=k.size();
    for(i=1;i<=j;i++)
    {
        for(l=0;l<i;l++)
        {o=k.substr(l,i-l);
        if(hf(o)) 
        f[i]=min(f[i],f[l]+1);}
    }
    cout<<f[j]<<endl;;
    system("pause");
    return 0;
}
