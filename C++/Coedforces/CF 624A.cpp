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
int main(){
    int L, d, v1, v2;
    cin >> d >> L >> v1 >> v2;
    double ans = (double)(L - d) / (double)(v1 + v2);
    printf("%.15lf\n", ans);
    return 0;
}
