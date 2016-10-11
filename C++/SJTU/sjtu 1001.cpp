#include<iostream>
#include<cstdio>
using namespace std;
int n, m, h, yz, ans, apple[1010]; 
int main(){
    scanf("%d%d%d", &h, &yz, &n);
    for(int i = 1;i <= n; i++)
            scanf("%d", &apple[i]);
    for(int i = 1;i <= n; i++){
            if(h + yz >= apple[i]) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
