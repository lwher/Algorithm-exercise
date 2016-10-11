#include<string> 
#include <cstdio>
#include<vector> 
#include<cmath> 
#include<sstream> 
#include<iostream> 
#include<set> 
#define swap(a,b) {a^=b;b^=a;a^=b;} 
using namespace std; 
class ChangingSounds{ 
public: 
int maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel){ 
    long len=changeIntervals.size(); 
    bool opt[1001],dp[1001]; 
    long i,j; 
    for (i=0;i<=maxLevel;i++) opt[i]=dp[i]=false; 
    dp[beginLevel]=true; 
    for (j=0;j<len;j++){ 
        for (i=0;i<=maxLevel;i++) 
            if (dp[i]){ 
                if (i+changeIntervals[j]<=maxLevel) opt[i+changeIntervals[j]]=true; 
                if (i-changeIntervals[j]>=0) opt[i-changeIntervals[j]]=true; 
            } 
        for (i=0;i<=maxLevel;i++) {dp[i]=opt[i];opt[i]=false;} 
    } 
    for (j=maxLevel;j>=0;j--) if (dp[j]) return j; 
    return -1; 
} 

}; 

int main() {
   // freopen("changingsounds.in","r",stdin);
    //freopen("changingsounds.out","w",stdout);
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    printf("%d\n", ChangingSounds().maxFinal(v, a, b));
    system("pause");
    return 0;
}
