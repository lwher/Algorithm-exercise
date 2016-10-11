#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n, d, k, x[1001], y[16], num, temp, len, ans;
void Jeogia(int deep,int from,int sta)
{    
     if (deep == len)    
     {        
              int cnt = 0;        
              for(int i = 0; i < n; i++)            
              if (sta == (sta | x[i]))                
              cnt++;        
              if (cnt > ans) ans = cnt;        
              return;    
     }    
     for(int i=from; i < d; i++)        
     Jeogia(deep+1,i+1,sta|y[i]);
}
int main()
{    
     y[0] = 1;    
     for(int i = 1; i <= 14; i++) 
     y[i] = y[i - 1] * 2;    
     scanf("%d%d%d", &n, &d, &k);    
     for(int i = 0; i < n; i++)    
     {        
              scanf("%d", &num);        
              x[i] = 0;        
              while(num--)        
              {            
                           scanf("%d", &temp);            
                           x[i] |= (1 << (temp - 1));        
              }    
     }    
     ans = 0;    
     for(len = 0;len <= k;len++)        
     Jeogia(0, 0, 0);    
     printf("%d\n", ans);    
     system("pause");
     return 0;
}
