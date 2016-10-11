#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
using namespace std;
int m, n, ans(0x7FFFFFFF);
typedef std::bitset<16> set;
set a[16], b[16], answer[16];
inline void flip(set& now, set& next, const int col)
{
  now.flip(col), next.flip(col);
  if (col-1 >= 0) now.flip(col-1);
  if (col+1 < n) now.flip(col+1);
}
int main()
{
  scanf("%d%d", &m, &n);
  const int FULL = (1<<n)-1;
  for (int i = 0; i < m; ++i)
    for (int j = 0, x; j < n; ++j)
    {
      scanf("%d", &x);
      a[i].set(j, x);
    }
  for (int first = 0; first <= FULL; ++first)
  {
    int sum = 0;
    b[0] = first;
    std::bitset<16> next(a[0]), now;
    for (int i = 0; i < m; ++i)
    {
      now = next, next = a[i+1];
      for (int j = 0; j < n; ++j)
        if (b[i].test(j))
          flip(now, next, j);
      b[i+1] = now;
    }
    if (now.none() && sum < ans)
    {
      ans = sum;
      memcpy(answer, b, sizeof(answer));
    }
  }
  if (ans == 0x7FFFFFFF)
  {
    printf("IMPOSSIBLE");
    return 0;
  }
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n-1; ++j)
      printf("%d ", answer[i].test(j) ? 1 : 0);
    printf("%d\n",answer[i].test(n-1) ? 1 : 0);
  }
  system("pause");
  return 0;
}
