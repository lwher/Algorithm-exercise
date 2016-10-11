#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define eps 1e-6
using namespace std;

struct circle{
    double x, y, r;
}p[201];
int n, ans;

double dist(const circle &A, const circle &B){
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

int Count(const circle &A){
    int res = 0;
    for(int i = 1; i <= n; i++)
        if(dist(p[i], A) < 2.500 + eps) res++;
    return res;
}

void getpoint(circle a, circle b, circle &A, circle &B){
    double d, k; circle t;
    d = dist(a,b);
    k = (a.r*a.r + d*d - b.r*b.r)/(2.000 * d * a.r);
    k = acos(k);
    t.x = (b.x - a.x)/d; t.y = (b.y - a.y)/d;
    double cosk = cos(k), sink = sin(k);
    A.x = a.x + a.r*(t.x * cosk - t.y * sink); A.y = a.y + a.r*(t.y * cosk + t.x * sink);
    B.x = a.x + a.r*(t.x * cosk + t.y * sink); B.y = a.y + a.r*(t.y * cosk - t.x * sink);
}

int main(){
    while(scanf("%d", &n) != EOF){
        if(!n){
            printf("0\n"); continue;
        }
        ans = 1;
        for(int i = 1; i <= n; i++){
            scanf("%lf %lf", &p[i].x, &p[i].y);
            p[i].r = 2.500;
        }
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++){
                if(dist(p[i], p[j]) < eps) continue;
                if(dist(p[i], p[j]) > 5.00 + eps) continue;
                circle A, B;
                getpoint(p[i], p[j], A, B);
                ans = max(ans, Count(A));
                ans = max(ans, Count(B));
            }
        for(int i = 1; i <= n; i++){
            ans = max(ans, Count(p[i]));
        }
        printf("%d\n", ans);
    }
    return 0;
}
