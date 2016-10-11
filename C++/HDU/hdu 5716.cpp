#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<bitset>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

bitset<501> OK[2301];
bitset<501> work[2];

int n;
char s[8000010], ch[501];

int main(){
	int len;
	bool flag;
	while(gets(s)){
		flag = 0;
		for(int i = 0; i < 130; i++) OK[i].reset();
		for(int i = 0; i < 2; i++) work[i].reset();
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &len);
			scanf("%s", ch);
			for(int j = 0; j < len; j++) OK[ch[j]][i] = 1;
		}
		if(n == 0) {
			getchar();
			printf("NULL\n");
			continue;
		}
		int p = 1, q = 0;
		len = strlen(s);
		work[q][0] = 1;
		for(int i = 0; i < len; i++){
			work[p] = ((work[q] << 1) & OK[s[i]]);
			work[p][0] = 1;
			if(work[p][n] == 1){
				flag = 1;
				printf("%d\n", i - n + 2);
			}
			p ^= 1; q ^= 1;
		}	
		if(!flag) printf("NULL\n");
		getchar();
	}
	return 0;
}

