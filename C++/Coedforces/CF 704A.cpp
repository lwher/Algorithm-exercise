#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, t, top = 1, l[300010], r[300010], notice[300010], read2, read3;

vector<int> Q[300010];

int main(){
	int ty, x;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d %d", &ty, &x);
		if(ty == 1){
			Q[x].push_back(++t);
			++r[x];
			notice[t] = x;
		} 
		else if(ty == 2){
			read3 += r[x] - l[x]; 
			l[x] = r[x];
		}
		else {
			while(top <= x){
				int p = notice[top];
				if(l[p] < r[p] && Q[p][l[p]] == top){
					++read2; ++l[p];
				}
				++top;
			}
		}
		printf("%d\n", t - (read2 + read3));
	}
	return 0;
}

