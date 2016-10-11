#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;
int n;
string color, ans;
map<string, int> p;
map<string, int>::iterator it;
int main(){
    int i, MAX;
    while(scanf("%d", &n)){
        if(!n) break;
        p.clear();
        for(i = 1;i <= n;i++){
            cin >> color;
            p[color]++;
        }
        MAX=0;
        for(it = p.begin();it != p.end();it++){
            if(it->second > MAX){
                MAX = it->second;
                ans = it->first;
            }
        }
        cout << ans << endl;
    }
    return 0;
}