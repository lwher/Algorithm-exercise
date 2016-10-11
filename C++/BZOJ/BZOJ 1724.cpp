#include <cstdio>
#include <queue>
using namespace std;
const int fin=0;

int n,i,w1,w2;

long long sum;

priority_queue <int,vector<int>,greater<int> > Q;

int main(){

  scanf("%d",&n);

  for (i=1;i<=n;i++) {

    scanf("%d",&w1);

    Q.push(w1);

  }

  sum=0;

  for (i=1;i<n;i++) {

    w1=Q.top();

    Q.pop();

    w2=Q.top();

    Q.pop();

    //printf("%d %d\n",w1,w2);

    sum+=(w1+w2);

    Q.push(w1+w2);

  }

  printf("%lld\n",sum);
  return 0;

}

