#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
    long long v;
};
bool operator <(const node &a,const node &b){
     return a.v>b.v;
}
int n;
long long ans,V;
priority_queue<node> q;
int main(){
    node A,B;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
            scanf("%I64d",&V);
            A.v=V;
            q.push(A);
    }
    for(int i=1;i<n;i++){
            A=q.top();q.pop();
            B=q.top();q.pop();
            A.v+=B.v;
            ans+=A.v;
            q.push(A);
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
