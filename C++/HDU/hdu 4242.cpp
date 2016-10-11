#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define eps 1e-8

using namespace std;

struct point{
    double x, y;
};

struct line{
    point a, b;
};

double myfabs(double x){
    if(x < 0) return -x;
    else return x;
}

double dist(point a, point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

point operator +(point a, point b){
    point c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

point operator -(point a, point b){
    point c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

double operator *(point a, point b){
    return a.y * b.x - a.x * b.y;
}

point Get(line A, line B){
    double k1, k2, k3;
    point Ans;
    k1 = (A.b - A.a) * (B.a - A.a);
    k2 = (B.b - A.a) * (A.b - A.a);
    k3 = k1 / (k1 + k2);
    Ans.x = B.a.x + (B.b.x - B.a.x) * k3;
    Ans.y = B.a.y + (B.b.y - B.a.y) * k3;
    return Ans;
}

int main(){
    int T, X;
    double a, b, c, d, e, sa, sb, sc, sd ,se, length;
    cin >> T;
    point A, B, C, D, AB, BC, CD, DA;
    while(T--){
        scanf("%d", &X);
        scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);
        A.x = 0; A.y = 0;
        B.x = a; B.y = 0;
        C.x = b; C.y = c;
        D.x = d; D.y = e;
        point mid;

        line AA;
        mid = B + C;
        mid.x *= 0.5; mid.y *= 0.5;
        AA.a = A; AA.b = mid;

        line BB;
        mid = C + D;
        mid.x *= 0.5; mid.y *= 0.5;
        BB.a = B; BB.b = mid;

        line CC;
        mid = D + A;
        mid.x *= 0.5; mid.y *= 0.5;
        CC.a = C; CC.b = mid;

        line DD;
        mid = A + B;
        mid.x *= 0.5; mid.y *= 0.5;
        DD.a = D; DD.b = mid;

        AB = Get(AA, BB);
        sa = (AB - A) * (B - A);
        if(sa < 0) sa = -sa;

        BC = Get(BB, CC);
        sb = (BC - B) * (C - B);
        if(sb < 0) sb = -sb;

        CD = Get(CC, DD);
        sc = (CD - C) * (D - C);
        if(sc < 0) sc = -sc;

        DA = Get(DD, AA);
        sd = (DA - D) * (A - D);
        if(sd < 0) sd = -sd;

        se = myfabs((CD - DA) * (BC - DA)) + myfabs((BC - DA) * (AB - DA));

        length = dist(AB, BC) + dist(BC, CD) + dist(CD, DA) + dist(DA, AB);

        sa /= 160.0 * 2; sb /= 160.0 * 2; sc /= 160.0 * 2; sd /= 160.0 * 2; se/= 160.0 * 2;
        length *= 16.5;
        int L = ceil(length);
        printf("%d %.3f %.3f %.3f %.3f %.3f %d\n", X, sa, sb, sc, sd, se, L);
    }
    return 0;
}
