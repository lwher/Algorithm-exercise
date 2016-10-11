#include<iostream>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,ans;
char s[200001];
std::map<pair<int,int>,int> pos;
int main(){
    int i,x,y,J=0,I=0,O=0;
    scanf("%d",&n);
    scanf("%s",s+1);
    pos[make_pair(0,0)]=1;
    for(i=1;i<=n;i++){
        if(s[i]=='J') J++;
        if(s[i]=='I') I++;
        if(s[i]=='O') O++;
        x=I-J;y=O-J;
        pair<int,int> Q=make_pair(x,y);
        if(pos[Q]>0) ans=max(ans,i+1-pos[Q]);
        else pos[Q]=i+1;
    }
    cout<<ans<<endl;
    return 0;
}
