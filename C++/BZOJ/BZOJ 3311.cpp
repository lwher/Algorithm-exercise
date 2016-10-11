#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
#define maxn 100010 
#define eps 1e-10 
using namespace std; 
typedef long long LL; 
const double pi=acos(-1); 
int dcmp(double p) 
{ 
    if(abs(p)<eps)  return 0; 
    return p>0?1:-1; 
} 
struct Point 
{ 
    double x,y; 
    Point() {} 
    Point(double x,double y): x(x),y(y) {} 
    friend Point operator - (Point a,Point b) 
    { 
        return Point(a.x-b.x,a.y-b.y); 
    } 
    void Read() 
    { 
        scanf("%lf %lf",&x,&y); 
    } 
}p[maxn],o; 
typedef Point Vector; 
double Dot(Vector a,Vector b) 
{ 
    return a.x*b.x+a.y*b.y; 
} 
double Len(Vector a) 
{ 
    return sqrt(Dot(a,a)); 
} 
double r;int n; 
void read() 
{ 
    scanf("%d %lf",&n,&r); 
    for(int i=1;i<=n;++i) 
        p[i].Read(); 
} 
void work() 
{ 
    static pair<double,double> rad[maxn]; 
    static double R[maxn]; 
    int m=0; 
    LL ans=0; 
    for(int i=1;i<=n;++i) 
    { 
        double len=Len(p[i]),r1=acos(r/len),r2=atan2(p[i].y,p[i].x); 
        rad[i]=make_pair(r2-r1,r2+r1); 
        if(dcmp(rad[i].first+pi)<=0) 
            rad[i].first=rad[i].first+2*pi; 
        if(dcmp(rad[i].second-pi)>=0) 
            rad[i].second=rad[i].second-2*pi; 
        if(rad[i].first>=rad[i].second&&dcmp(rad[i].first-rad[i].second-pi)<=0) 
            swap(rad[i].first,rad[i].second); 
        if(rad[i].first<=rad[i].second&&dcmp(rad[i].second-rad[i].first-pi)>=0) 
            swap(rad[i].first,rad[i].second); 
        R[++m]=rad[i].first,R[++m]=rad[i].second; 
    } 
    sort(R+1,R+m+1); 
    for(int i=1;i<=n;i++) 
    { 
        int l=lower_bound(R+1,R+m+1,rad[i].first)-R,r=lower_bound(R+1,R+m+1,rad[i].second)-R; 
        if(l<=r) 
            ans=ans+r-l-1; 
        else
            ans=ans+m+r-l-1; 
    } 
    cout<<ans/2<<endl; 
} 
int main() 
{ 
    read(); 
    work(); 
    //system("pause"); 
    return 0; 
}