#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
int n;
int main()
{       
        int i, j, k, l, ans = 0;       
        cin>>n;       
        int m = (int)sqrt(n) + 1;       
        for(i = 0; i <= m; i++)       
        {              
                       if(i * i > n) break;              
                       for(j = 0; j <= m; j++)              
                       {                     
                       if(i * i + j * j > n) break;                     
                       for(k = 0; k <= m; k++)                     
                       {                            
                       if(i * i + j * j + k * k > n) break;                            
                       for(l = 0; l <= m; l++)                                   
                       if(i * i + j * j + k * k + l * l == n) 
                       {++ans; break;}                     
        }              
        }       
        }       
        cout<<ans<<endl;
        system("pause");
        return 0;
}  
