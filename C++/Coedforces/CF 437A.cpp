#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
   string s;int len,bh;
}c[5];
inline bool comp(sth a,sth b)
{
   return a.len<b.len;
}
int gs;char Ans;
int main()
{
    for(int i=1;i<=4;i++) 
    {
       cin>>c[i].s;c[i].len=c[i].s.size()-2;
       c[i].bh=i;
    }
    sort(c+1,c+1+4,comp);
    if(c[1].len*2<=c[2].len) {gs++;Ans=c[1].bh-1+'A';}
    if(c[3].len*2<=c[4].len) {gs++;Ans=c[4].bh-1+'A';}
    if(gs==1) cout<<Ans<<endl;
    else cout<<"C"<<endl;
    return 0;
}