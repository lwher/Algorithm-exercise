#include <iostream>
 using namespace std;
 
 const int MAXN = 100005;
 int num, sub[MAXN];
 
 int main()
 {
     int n, top;
     while(cin >> n)
     {
         sub[0] = -1; //考虑到第一个元素可能是0
         top = 0;
         for(int i = 0; i < n; i++)
         {
             cin >> num;
             if(num > sub[top])
             {
                 sub[++top] = num;
             }
             else
             {
                 //此处是二分优化
                 int high = top, low = 1, mid;
                 while(low <= high)
                 {
                     mid = (high + low) / 2;
                     if(num > sub[mid])
                     {
                         low = mid + 1;
                     }
                     else
                     {
                         high = mid - 1;
                     }
                 }
                 sub[low] = num;
             }
         }
         cout << top << endl;
     }
     while(1);
     return 0;
 }
