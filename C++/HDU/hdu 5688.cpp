#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int num[50];
char s[50];
std::map<string, int> Q;

int main(){
	int n;
	scanf("%d", &n);
	for(int t = 1; t <= n; t++){
		scanf("%s", s);
		for(int i = 0; i < strlen(s); i++) num[i + 1] = s[i];
		sort(num + 1, num + 1 + strlen(s));
		string p = "";
		for(int i = 1; i <= strlen(s); i++) p += (char)(num[i]);
		printf("%d\n", Q[p]);
		Q[p]++;
	}
	return 0;
}

