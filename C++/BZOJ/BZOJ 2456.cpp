#include <cstdio> 
#include <cstdlib> 
   
int n, num; 
   
int main() 
{ 
scanf("%d%d", &n, &num); 
int cnt = 1; 
for (int i = 2; i <= n; i++) 
{ 
int tmp; scanf("%d", &tmp); 
if (cnt == 0) 
{ 
cnt = 1; 
num = tmp; 
continue; 
} 
if (tmp == num) cnt++; 
else cnt--; 
} 
printf("%d\n", num); 
return 0; 
}