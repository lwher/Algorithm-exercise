#include <iostream>
#include <cstring>
using namespace std;
int T;
int lenx,leny;
char x[101],y[101];
int dp[101][101];
int m[6][6] = { 
{0, 0, 0, 0, 0, 0}, 
{0, 5, -1, -2, -1, -3}, 
{0, -1, 5, -3, -2, -4}, 
{0, -2, -3, 5, -2, -2}, 
{0, -1, -2, -2, 5, -1}, 
{0, -3, -4, -2, -1, 0},
};
int d(char x,char y) {
int i,j;
switch(x) {
case 'A' : i = 1;break;
case 'C' : i = 2;break;
case 'G' : i = 3;break;
case 'T' : i = 4;break;
case '-' : i = 5;break;
}
switch(y) {
case 'A' : j = 1;break;
case 'C' : j = 2;break;
case 'G' : j = 3;break;
case 'T' : j = 4;break;
case '-' : j = 5;break;
}
return m[i][j];
}
int solve() {
memset(dp,0,sizeof(dp));
dp[0][0] = 0;
for (int i = 1;i <= lenx;i++)
dp[i][0] = dp[i-1][0]+d('-',x[i-1]);
for (int i = 1;i <= leny;i++)
dp[0][i] = dp[0][i-1]+d('-',y[i-1]);
for (int i = 1;i <= lenx;i++)
for (int j = 1;j <= leny;j++) {
int yy = dp[i-1][j]+d(x[i-1],'-');
int xx = dp[i][j-1]+d('-',y[j-1]);
int none = dp[i-1][j-1]+d(x[i-1],y[j-1]);
int max = xx > yy ? xx : yy;
dp[i][j] = max > none ? max : none;

}
return dp[lenx][leny];
}
int main() 
{
cin >> T;
while(T--) {
cin >> lenx;
cin >> x;
cin >> leny;
cin >> y;
cout << solve() << endl;
}
while(1);
return 0;
}
