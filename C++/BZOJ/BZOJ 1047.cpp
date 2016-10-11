#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
using namespace std; 
int a,b,n; 
int num[1010][1010]; 
int maxx[1010][1010],minn[1010][1010]; 
int adui[1010],idui[1010],weia[1010],weii[1010]; 
int ans=2147483647; 
void getmaxmin() 
{ 
    int i,j,k; 
    int atou=1,awei=0,itou=1,iwei=0; 
    for(k=1;k<=a;k++) 
    { 
    atou=1;awei=0;itou=1;iwei=0; 
    for(i=1;i<=n-1;i++) 
    { 
        while(awei>0 && num[k][i]>adui[awei]) 
        awei--; 
        awei++;adui[awei]=num[k][i];weia[awei]=i; 
        while(iwei>0 && num[k][i]<idui[iwei]) 
        iwei--; 
        iwei++;idui[iwei]=num[k][i];weii[iwei]=i; 
    } 
    for(i=n;i<=b;i++) 
    { 
        while(awei>=atou && num[k][i]>adui[awei]) 
        awei--; 
        awei++;adui[awei]=num[k][i];weia[awei]=i; 
        while(atou<awei && weia[atou]<i-n+1) 
        atou++; 
        maxx[k][i]=adui[atou]; 
          
        while(iwei>=itou && num[k][i]<idui[iwei]) 
        iwei--; 
        iwei++;idui[iwei]=num[k][i];weii[iwei]=i; 
        while(itou<iwei && weii[itou]<i-n+1) 
        itou++; 
        minn[k][i]=idui[itou]; 
    } 
    } 
} 
void hb() 
{ 
    int i,j,k; 
    int atou=1,awei=0,itou=1,iwei=0; 
    for(k=1;k<=b;k++) 
    { 
    atou=1;awei=0;itou=1;iwei=0; 
    for(i=1;i<=n-1;i++) 
    { 
        while(awei>0 && maxx[i][k]>adui[awei]) 
        awei--; 
        awei++;adui[awei]=maxx[i][k];weia[awei]=i; 
        while(iwei>0 && minn[i][k]<idui[iwei]) 
        iwei--; 
        iwei++;idui[iwei]=minn[i][k];weii[iwei]=i; 
    } 
    for(i=n;i<=a;i++) 
    { 
        while(awei>=atou && maxx[i][k]>adui[awei]) 
        awei--; 
        awei++;adui[awei]=maxx[i][k];weia[awei]=i; 
        while(atou<awei && weia[atou]<i-n+1) 
        atou++; 
        maxx[i][k]=adui[atou]; 
          
        while(iwei>=itou && minn[i][k]<idui[iwei]) 
        iwei--; 
        iwei++;idui[iwei]=minn[i][k];weii[iwei]=i; 
        while(itou<iwei && weii[itou]<i-n+1) 
        itou++; 
        minn[i][k]=idui[itou]; 
    } 
    } 
} 
int main() 
{ 
    int i,j; 
    scanf("%d%d%d",&a,&b,&n); 
    for(i=1;i<=a;i++) 
    for(j=1;j<=b;j++) 
    scanf("%d",&num[i][j]); 
    getmaxmin(); 
    hb(); 
    for(i=n;i<=a;i++) 
    { 
        for(j=n;j<=b;j++) 
        if(abs(maxx[i][j]-minn[i][j])<ans) 
        ans=abs(maxx[i][j]-minn[i][j]); 
    } 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}