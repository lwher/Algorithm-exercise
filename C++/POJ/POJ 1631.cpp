#include <iostream>
using namespace std;
int a[40001];
int dp[40001];
int b[40001], blen;
int n;
int main()
{ 
    int ca; 
    scanf("%d", &ca); 
    while (ca--) 
    {  
          scanf("%d", &n);  
          for (int i = 1; i <= n; ++i) 
          {   scanf("%d", a+i);  }  
          memset(b,0,sizeof(b));  
          memset(dp,0,sizeof(dp));    
          int left, right, mid;  
          blen = 0;  
          int res = 0;  
          for (int i = 1; i <= n; ++i) 
          {   
              left = 1;   
          right = blen;   
          int num = a[i];   
          while (left <= right) 
          {    
               mid = (left + right)/2;    
               if (b[mid] < a[i]) {     left = mid + 1;    }    
               else {     right = mid - 1;    }   }   
               dp[i] = left;   b[left] = a[i];  
                if (blen < left)   
                 blen = left;  
                  if (res < dp[i])    
                  res = dp[i]; 
                   }  printf("%d\n", res);
                    
                    } return 0;
                    }
