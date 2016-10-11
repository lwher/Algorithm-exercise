#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char s[30];
int num1[30], num2[30];

int getID(char t){
    if((t >= 'a' && t <= 'c') || (t >= 'A' && t <= 'C')) return 2;
    if((t >= 'd' && t <= 'f') || (t >= 'D' && t <= 'F')) return 3;
    if((t >= 'g' && t <= 'i') || (t >= 'G' && t <= 'I')) return 4;
    if((t >= 'j' && t <= 'l') || (t >= 'J' && t <= 'L')) return 5;
    if((t >= 'm' && t <= 'o') || (t >= 'M' && t <= 'O')) return 6;
    if((t >= 'p' && t <= 's') || (t >= 'P' && t <= 'S')) return 7;
    if((t >= 't' && t <= 'v') || (t >= 'T' && t <= 'V')) return 8;
    if((t >= 'w' && t <= 'z') || (t >= 'W' && t <= 'Z')) return 9;
}

bool Same(int L){
    for(int i = 1; i <= L; i++)
        if(num1[i] != num2[i]) return 0;
    return 1;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        scanf("%s", s + 1);
        int L = strlen(s + 1);
        for(int i = 1; i <= L; i++){
            num1[i] = getID(s[i]);
        }
        for(int i = 1; i <= L; i++) num2[L - i + 1] = num1[i];
        if(Same(L)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
