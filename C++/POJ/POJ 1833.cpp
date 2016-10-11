#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int t,n,a[1025],k;
    scanf("%d",&t);
    while(t--){
       scanf("%d%d",&n,&k);
       for(int i=1;i<=n;i++)
          scanf("%d",&a[i]);
       while(k--)next_permutation(a+1,a+n+1);
       for(int i=1;i<=n;i++)
          printf("%d%s",a[i],i==n?"\n":" ");
    }
    //system("pause");
    return 0;
}

