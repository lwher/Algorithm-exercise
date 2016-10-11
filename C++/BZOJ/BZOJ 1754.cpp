#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
char A[50],B[50];
int a[50],b[50],c[110];
void mul()
{
     int i,j;
     c[0]=a[0]+b[0]-1;
     for(i=1;i<=a[0];i++)  for(j=1;j<=b[0];j++)   c[i+j-1]+=a[i]*b[j];
     for(i=1;i<=c[0];i++)  
     {
         c[i+1]+=c[i]/10;
         c[i]%=10;
     }
     if(c[c[0]+1])  c[0]++;
     while(c[0]>0 && !c[c[0]])  c[0]--;
}
int main()
{
    int i;
    scanf("%s",A+1);scanf("%s",B+1);
    a[0]=strlen(A+1);
    for(i=1;i<=a[0];i++)  a[i]=A[a[0]-i+1]-'0';
    b[0]=strlen(B+1);
    for(i=1;i<=b[0];i++)  b[i]=B[b[0]-i+1]-'0';
    mul();    
    if(!c[0])  printf("0");
    else for(i=c[0];i>=1;i--)  printf("%d",c[i]);
    printf("\n");
    system("pause");
    return 0;
}
