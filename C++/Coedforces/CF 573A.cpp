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
int n,num[100001];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
        while(num[i]%2==0) num[i]/=2;
        while(num[i]%3==0) num[i]/=3;
    }
    bool OK=1;
    for(int i=2;i<=n;i++) if(num[i]!=num[i-1]) OK=0;
    if(OK) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
